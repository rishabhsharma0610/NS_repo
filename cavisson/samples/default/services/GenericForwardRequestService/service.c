#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hpd_log.h"
#include "hpd_string_api.h"
#include <errno.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0 

static int check_and_set_http_hdr_ex(char *query_param_name, char *hdr_name, int decode_option)
{
char query_val[4096], http_hdr[4096];
int ret;

  ret = ns_get_url_query_param_val(query_param_name, query_val, decode_option);
  if(ret >= 0) // query parameter found, So send in the response
  {
    sprintf(http_hdr, "%s%s", hdr_name, query_val);
    ns_set_http_hdr(http_hdr);
  }
  return 0;
}

static int check_and_set_status_code()
{
char query_val[4096], hdr_val[4096], http_hdr[4096];
int ret;
int status = 200;

  ret = ns_get_url_query_param_val("Status", query_val, HPD_CODE_NONE);
  if(ret >= 0) // Status found in query parameter
  {
    status = atoi(query_val);
    ns_set_http_status_code(status);
  }

  // In case of redirection, check if location is passed, Then set location
  if((status == 301) || (status == 302))
  {
    check_and_set_http_hdr_ex("Location", "Location: ", HPD_CODE_NONE);
  }
  return status;
}

static int isForward() 
{
char *serviceMode = ns_eval_string("{ServiceModeDP}");
int status ;  
  
  if ( strcmp(serviceMode,"Forward") == 0 )
    status = 1;
  else 
    status = 0;

  return status ;
}

static int isQueryRequested(char *query) 
{
char *q = ns_eval_string("{query_type}") ;
int status ;
   if ( strcmp(q,query) == 0 )
    status = 1;
  else
    status = 0;
 
  return status ;
} 


static int check_and_set_http_header()
{
  char *req_type;
  req_type = ns_eval_string("{query_type}");
  
  if ( strcmp(req_type,"Compressed") == 0 ) 
      ns_set_http_hdr("Content-Encoding: gzip");

  if (strcmp(req_type,"Chunked") == 0 )
      ns_set_http_hdr("Transfer-Encoding: chunked");

  if ( strcmp(req_type,"Hessian") == 0 )
     ns_set_content_type_hdr("Content-Type: application/x-hessian");

  if ( strcmp(req_type,"CheckSumCookie") == 0 )
     ns_set_http_hdr("Set-Cookie: CavBodyCheckSum=bc7d68d64657be327b3f1bde2290c9c7;");  
 
  if ( strcmp(req_type,"XML") == 0 )
     ns_set_content_type_hdr("Content-Type: text/xml");

  return 0;
}

static int get_svc_time()
{
char query_val[4096];
int ret;
int svc_time = -1; // As per service.conf SVC_TIME keyword which we will not set, so 0

  ret = ns_get_url_query_param_val("SvcTime", query_val, HPD_CODE_NONE);
  if(ret >= 0) // SvcTime found in query parameter
  {
    svc_time = atoi(query_val);
  }
  return svc_time;
}      
 
int GenericForwardRequestService_on_request_callback() 
{
  HPDDL2_CR(NULL,"In Callback");
  if ( isForward() == FALSE ) 
  {
    HPDDL2_CR(NULL,"SERVICEMODEDP=%s",ns_eval_string("{ServiceModeDP}"));
    check_and_set_status_code();
    check_and_set_http_header();
    return get_svc_time(); 
  }
  else
  //return get_svc_time() ; 
  return -1 ;
}

/*-------------------------------------------
  Name: GenericForwardRequestService_after_request_callback
  Purpose: This method is called on just before sending the response of the service.
  Input:   None
  Return:  None
 ------------------------------------------------*/
void GenericForwardRequestService_after_request_callback() 
{
char *resp_buffer ; 
int resp_len ; 

if ( isForward() == TRUE )
{
    HPDDL2_CR(NULL,"SERVICEMODEDP=%s",ns_eval_string("{ServiceModeDP}"));
    HPDDL1_API(NULL,"Method Called ns_http_forward_req");
     
    if ( isQueryRequested("UseAPIToForwardAndReplyToClient") == TRUE )
    {
        resp_buffer = ns_http_forward_req("localhost", 1, &resp_len);
        ns_save_string(resp_buffer,"NS_API_BUFFER");
    }
    
    if ( isQueryRequested("UseAPIToForward") == TRUE )
    {
      resp_buffer = ns_http_forward_req("localhost", 1, &resp_len);
      HPDDL1_API(NULL, "Response from backend server (len = %d) (Upto 10000 bytes) = %10000.10000s", resp_len, resp_buffer);
      int ret = ns_http_send_forward_rep_to_client(resp_buffer, resp_len);
      HPDDL1_API(NULL, "return value of ns_http_send_forward_rep_to_client = %d", ret);
    }
}
}

