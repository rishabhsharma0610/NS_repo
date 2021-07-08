#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hpd_log.h"
#include "hpd_string_api.h"
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char docroot_prefix[];

/*-------------------------------------------
  Name: savePostData_on_request_callback
  Purpose: This method is called on receiving the service request and after all search and conditional parameters are processed and before applying service delay time.
  Input:   None
  Return:  The function controls service time. Return values can be:
           0 - No service delay time. Override service delay time configure if any
          -1 - Use service delay time as configured
          >0 - Use service delay time in milli-seconds returned by this method
 ------------------------------------------------*/
int savePostData_on_request_callback() 
{
   char *body;
   int len;
   if((body = ns_get_request_buf(&len)) == NULL) return 0;
   if(len == 0) return 0;

   //save post data to file.
   //check if host is given or not..
   char host[128] = "";
   char file_name[256] = "";
   strcpy(host, ns_eval_string("{CAV_host}")) ;
   if(host[0])
   {
     sprintf(file_name, "%s_", host);
   }
   //get tm.
   time_t tloc;
   struct tm *lt;
   (void)time(&tloc);
   lt = localtime(&tloc); 
   sprintf(file_name, "%s%02d_%02d_%02d_%02d_%02d", file_name, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);

   //now check if ext is given then set as per that.
   char ext[64] = "";
   strcpy(ext, ns_eval_string("{CAV_ext}"));
   if(ext[0])   
     sprintf(file_name, "%s.%s", file_name, ext);

   //check if upload folder present or not, if not then create.
   char dir[512] = "";
   sprintf(dir, "%s/logs/upload", docroot_prefix);
   struct stat fstat;
   if(stat(dir, &fstat)){
     //now just save this data.
     if(mkdir(dir, 0777)) return 0;
   }
   
   //now save file.
   char full_file_name[512] = "";
   FILE *fp;
   sprintf(full_file_name, "%s/%s", dir, file_name);
   fp = fopen(full_file_name, "w");
   if(fp == NULL) return 0;
  
   fwrite(body, len, 1, fp); 
   fflush(fp);    
   return -1;
}
