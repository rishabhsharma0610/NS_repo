#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <stdarg.h>
#include <stdlib.h>
#define __USE_GNU
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/param.h>

#include "hpd_log.h"
#include "hpd_string_api.h"
/* global variables */
char errorBuf[BUFSIZ];

enum {READ_SELECT, WRITE_SELECT};
#define DEFAULT_CONNECT_TIMEOUT 10
#define DEFAULT_SEND_TIMEOUT 10
#define MAX_UDP_SEND_SIZE 1024

/*macros*/

/*
 * translate error returned by system call 
 * f - format for args (eg., "foo = %d name =%s")
 * args - eg., foo_val, name_val)
 * errno is already known, so its not passed in
 */

#define LOG_STRERROR(f, args ...)   {\
  sprintf(errorBuf, "errno = %d (%s)" f, errno, strerror(errno), ## args);  \
  hpd_error_log(0, 0, _FLN_, NULL, "%s", errorBuf);       \
} 

/*
 * translate error returned by getnameinfo, getaddrinfo. errno is passed into this macro
 * f - format for args (eg., "foo = %d name =%s")
 * args - eg., foo_val, name_val)
 * y - errno to be translated
 */

#define LOG_GAI_STRERROR(f,y,args ...)   {\
  sprintf(errorBuf, "errno = %d (%s)" f, (y), gai_strerror(y), ## args);  \
  hpd_error_log(0, 0, _FLN_, NULL, "%s", errorBuf);     \
} 


#define ERROR(f, args ...)  \
do {  \
  hpd_error_log(0, 0, _FLN_, NULL, f, ## args);       \
} while(0)

#define DEBUG(f, args ...)  \
do {  \
  HPDDL1_API(NULL, f, ## args);     \
} while(0)


/*
 * set send timeout on the socket
 * if we're using blocking calls, it doesnt make sense to do a select with timeout. we could
 * just set a timeout for send, as we need to timeout within a given amt of time (doesnt matter
 * whether we're waiting in select or send itself)
 */

int
setSendTimeout(int fd, struct timeval *tv)
{
  if (setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, (char *)tv,  sizeof(struct timeval)) == -1) {
    LOG_STRERROR("setsockopt error");
    return(-1);
  }
  return(0);
} 


/*
 * select with timeout on a read socket
 * return
 * -1 - error
 *  0 - socket is ready for read
 *  1 - timeout
 *
 *  Inputs
 * fd - read or write fd as the case may be
 * mode - READ_SELECT/WRITE_SELECT
 *
 */

int
selectTimeout(int fd, int mode, struct timeval *tv )
{
  fd_set fdset;
  int ret, closed =0;

  DEBUG("select timeout value: tv_sec %ld tv_usec %ld\n",tv->tv_sec, tv->tv_usec);
  while(1) {
    FD_ZERO(&fdset);
    FD_SET (fd, &fdset);
    if (mode == READ_SELECT)
      ret = select (fd+1, &fdset, NULL, NULL, tv);
    else if (mode == WRITE_SELECT)
      ret = select (fd+1, NULL, &fdset, NULL, tv);
    else {
      ERROR("error: invalid mode %d for select\n", mode);
      return(-1);
    }

    //0 is timeout, -1 is error,  > 0 is success
    if (ret <0) {
      if (errno == EAGAIN) {    //shouldn't get EAGAIN for blocking, but check anyway 
        if (getNonBlocking(fd))
          continue;
        else {// this is an error in case of blocking socket
          LOG_STRERROR("select error on fd %d\n",fd);
          return(-1);
        }
      }
      if (errno == EINTR) {    //comment out if we dont want to ignore EINTR
        DEBUG("select got EINTR. continuing\n");
        continue;
      }
      LOG_STRERROR("select error");
      return(-1);

    } else if (ret >0) {
      if (!FD_ISSET(fd, &fdset)) {
        ERROR("error: select returned > 0 but fd is not ready");
        return(-1);
      }
      if (mode == READ_SELECT) {
        //select could also return > 0 if connection is closed
        IS_READ_CONN_CLOSED(fd, closed);
        if (closed) {
          ERROR("client closed connection on fd %d\n",fd);
          return(-1);
        }
      } else if (mode == WRITE_SELECT) {
        //we cant check if conn is closed with out writing 
      }
      return(0);
    } else if (ret == 0) { //timeout
      ERROR("error: select timeout\n");
      return(1);
    }
  } //while(1)
}

/*
 * Description: convert name to address
 * inputs
 * name - node name
 * return
 * addr - pointer to a linked list of addresses or
 * NULL on error
 *
 */

struct addrinfo *
nameToAddr (char *name, char* port, int type)
{
  struct addrinfo hints;
  struct addrinfo *result;
  int ret;

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
  hints.ai_socktype = type; /* tcp socket */
  hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
  hints.ai_protocol = 0;          /* Any protocol */
  hints.ai_canonname = NULL;    /* official name if AI_CANONNAME is set in ai_flags */
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

  /* args to getaddrinfo
   * name - node name
   * NULL - service name
   * hints -specifications of the addresses to be returned
   * result - linked list of addresses (type addrinfo) 
   */
  ret = getaddrinfo(name, port, &hints, &result);
  if (ret != 0) {
    LOG_GAI_STRERROR("getaddrinfo",ret);
    return(NULL);
  }
  return(result);
}

/* 
 * Description: use select to timeout connect on a socket
 * Inputs: 
 * fd - socket to use for connect
 * addr - server address to connect to 
 * timeout - timeout 
 *
 * Outputs :
 *
 * Algo: 
 * Connect will return EINPROGRESS or EAGAIN if not immediate
 * Do a select with timeout until socket is ready for write, which
 * Indicates connect complete
 * Loop if select returns EINTR
 * 
 */

int 
connectTimeout (int fd, struct sockaddr *addr, int addrLen, struct timeval *tv)
{
  fd_set wr_set;
  socklen_t len;
  int val, err, ret;

  //use non blocking call
  //setNonBlocking(fd);
  DEBUG("fd=%d  addr %s port %d \n",fd, inet_ntoa( ((struct sockaddr_in*)addr)->sin_addr), ntohs(((struct sockaddr_in*)addr)->sin_port) );

  err = connect (fd, (struct sockaddr*)addr, addrLen);
  if (err < 0) {
    if (errno == EINPROGRESS) {
      do {
        FD_ZERO(&wr_set);
        FD_SET (fd, &wr_set);
        ret = select (fd+1, NULL, &wr_set, NULL, tv);
        //0 is timeout, -1 is error but we break only if not EINTR, > 0 is success
        if ((ret <0) & (err != EINTR)) {
          LOG_STRERROR("select");
          return(-1);
        } else if (ret >0) {
          len = sizeof(val);
          if (getsockopt(fd, SOL_SOCKET, SO_ERROR, &val, &len) < 0)  {
            LOG_STRERROR("getsockopt");
            return(-1);
          }
          if (val != 0) {
            ERROR("got socket error %d (%s)\n",val, strerror(val));
            return(-1); 
          } else {
            break;
          }
        } else if (ret == 0) { //timeout
          LOG_STRERROR("select");
          return(-1);
        }
      } while (1);
    } else {
      LOG_STRERROR("connect"); //error other than EINPROGRESS
      return(-1);
    }
  } //connect returned < 0
  //unsetNonBlocking(fd);
  DEBUG("connect to remote host succeeded \n");
  return(0);
}

 

int
sendData(int fd, int type, char*dataVal, int dataLen, struct sockaddr *addr, int sendFlags)
{
  struct timeval tv;
  int nSend;
  int total_bytes_sent, bytes_sent, bytes_to_send, bytes_left, offset =0;

  DEBUG("sendData entry: fd=%d  type %d dataLen %d addr %s port %d flags 0x%x\n",fd, type, dataLen, inet_ntoa( ((struct sockaddr_in*)addr)->sin_addr), ntohs(((struct sockaddr_in*)addr)->sin_port), sendFlags );

 
  tv.tv_sec = DEFAULT_SEND_TIMEOUT;
  tv.tv_usec = 0;

  if (setSendTimeout (fd, &tv) == -1) {
    return(-1);
  }
  bytes_left = dataLen;

  if (type == SOCK_DGRAM) {
    while (bytes_left > 0) {    //UDP must send in smaller sizes
      bytes_to_send = MIN(bytes_left, MAX_UDP_SEND_SIZE);
      bytes_sent = sendto (fd, dataVal+offset, bytes_to_send, sendFlags, addr, sizeof(struct sockaddr));
      if (bytes_sent < 0) {
        LOG_STRERROR("UDP sendto");
        return(-1);
      }
      DEBUG("UDP sendto loop: bytes_left %d bytes_to_send %d bytes_sent %d\n", bytes_left,bytes_to_send, bytes_sent);

      bytes_left -= bytes_sent;
      offset += bytes_sent;
    }//while
    total_bytes_sent = offset;
  } else {  //TCP
    if ( (bytes_sent = send (fd, dataVal, bytes_left, sendFlags)) == -1) {
      LOG_STRERROR("TCP send");
      return(-1);
    }
    DEBUG("TCP: total bytes sent %d bytes\n",total_bytes_sent);
  }
  //closing fd  will result in the connection closing right away -this may result in an error
  //on the client
  //close(fd);
  DEBUG("UDP: total bytes sent %d bytes\n",total_bytes_sent);
  return (total_bytes_sent);
}

void 
*do_mmap(char *filename, int *length)
{
	int fd;
	struct stat sb;
	off_t offset, pa_offset;
	void *addr;

	if ( (fd = open(filename, O_RDONLY)) == -1) {
		LOG_STRERROR("error opening file %s\n",filename);
		return(NULL);
	}

	if (fstat(fd, &sb) == -1) {           /* To obtain file size */
		LOG_STRERROR("fstat failed");
		return(NULL);
	}

	offset = 0;
	pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) - 1);
	*length = sb.st_size;
	if (! (*length)) {
		ERROR("file %s is empty\n",filename);
    return(NULL);
	}

	addr = mmap(NULL, *length + offset - pa_offset, PROT_READ,
                       MAP_PRIVATE, fd, pa_offset);
	if (addr == MAP_FAILED){
		LOG_STRERROR("mmap");
		return(NULL);
	}
	return((void*)addr);

}

/*
 http://192.168.1.40/url_service/url_tcp_udp_test.xml?proto=tcp&port=1234&file=/tmp/junk
*/

int 
TCP_UDP_Service_on_request_callback() 
{

  char query_val[4096];
  char file[1024], port[8], proto[4], host[1024];
  int sd, ret, flags =0;
  int family = AF_INET;   //hardcoded for now
  int sockType, size;
  struct addrinfo *haddr;
	char *file_buf ;
  struct timeval tv;
  struct sockaddr_in localAddr;


  HPDDL1_API(NULL, "method called");
  ret = ns_get_url_query_param_val("host", query_val, HPD_CODE_NONE);
  if(ret >= 0)
  {
    strncpy(host, query_val, sizeof(host));
    HPDDL1_API(NULL, "host from query = %s",host);
  }
  ret = ns_get_url_query_param_val("proto", query_val, HPD_CODE_NONE);
  if(ret >= 0)
  {
    strncpy(proto, query_val, sizeof(proto));
    HPDDL1_API(NULL, "proto from query = %s",proto);
  }
 
  ret = ns_get_url_query_param_val("port", query_val, HPD_CODE_NONE);

  if(ret >= 0)
  {
    strncpy(port, query_val, sizeof(port));
    HPDDL1_API(NULL, "port from query = %s",port);
  }

  ret = ns_get_url_query_param_val("file", query_val, HPD_CODE_NONE);
  if(ret >= 0)
  {
    strncpy(file, query_val, sizeof(file));
    HPDDL1_API(NULL, "file from query = %s",file);
  }


  //validate type // must be “TCP” or “UDP”
  if (!strncasecmp(proto, "TCP", 3) )
    sockType = SOCK_STREAM;
  else if (!strncasecmp(proto, "UDP", 3))
    sockType = SOCK_DGRAM;
  else { 
    ERROR("wrong value for type %s\n",proto);
    return(-1);
  }

  //get address
  if ( (haddr = nameToAddr (host, port, sockType)) == NULL) {
    return(-1);
  }
  if ( (sd = socket(haddr->ai_family, haddr->ai_socktype, haddr->ai_protocol)) == -1) {
    LOG_STRERROR("socket");
    return(-1);
  }

#if 0
  bcopy ((char*)haddr->ai_addr, (char*)&(remoteAddr.sin_addr.s_addr), haddr->ai_addrlen);
  remoteAddr.sin_family = family;
  remoteAddr.sin_port = htons(remoteHostPort);
#endif
  if (sockType == SOCK_STREAM) { //connect only for TCP
    /*bind any port for now locally just for testing. this is so that we could change later 
     *to bind a specific
     *port, if needed
     */
    memset (&localAddr, 0, sizeof(struct sockaddr_in));
    localAddr.sin_family = family;
    localAddr.sin_port = htons(0);
    localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind (sd, (struct sockaddr*)&localAddr, sizeof(localAddr)) == -1) {
      LOG_STRERROR("bind to local addr before connect");
      return(-1);
    }
    tv.tv_sec = DEFAULT_CONNECT_TIMEOUT;
    tv.tv_usec = 0;

    // connect with a timeout if provided
    if (connectTimeout (sd, haddr->ai_addr, haddr->ai_addrlen, &tv) == -1) {
      //error is logged in above func
      return(-1);
    }
  }

  file_buf = (char*)do_mmap(file, &size);
	if (file_buf == NULL) {
		ERROR("error in do_mmap");
    return(-1);
	}

  ret = sendData(sd, sockType, file_buf, size, haddr->ai_addr, flags);
  return(ret);

}
