#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hpd_log.h"
#include "hpd_string_api.h"
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>

/* To do list
  - Support header
*/

/***********************************for headers***************************************************/
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

static int check_and_set_http_hdr(char *query_param_name, int decode_option)
{
char query_val[4096], http_hdr[4096]; 
int ret;
    ret = ns_get_url_query_param_val(query_param_name, query_val, decode_option);
    if(ret >= 0) // query parameter found, So send in the response
    {
      sprintf(http_hdr, "%s", query_val);
      ns_set_http_hdr(http_hdr);
    }
    return 0;
}
static void set_header()
{
char hdr_var[4096];
int i;
 
  for(i=0; i < 50; i++)
  {
    sprintf(hdr_var, "Hdr%d", i);
    check_and_set_http_hdr(hdr_var, HPD_CODE_DECODE);
  }

}
/**************************************************************************************/



// Return status code filled
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

// Return status code filled
static int get_svc_time()
{
char query_val[4096], hdr_val[4096], http_hdr[4096];
int ret;
int svc_time = -1; // As per service.conf SVC_TIME keyword which we will not set, so 0

  ret = ns_get_url_query_param_val("SvcTime", query_val, HPD_CODE_NONE);
  if(ret >= 0) // SvcTime found in query parameter
  {
    svc_time = atoi(query_val);
  }
  return svc_time;
}       


// return size of body if known
static int fill_body()
{
char query_val[4096];
int ret;
int resp_size = 0;

  char *resp_buf;

  // Same as request
  ret = ns_get_url_query_param_val("RespSameAsReq", query_val, HPD_CODE_NONE);
  if(ret >= 0) 
  {
    if(!strcmp(query_val, "Y"))
    {
      resp_buf = ns_get_request_buf(&resp_size);
      ns_save_binary_val(resp_buf, "Body", resp_size);
      return resp_size;
    }
  }

  // Get value of query parameter - RespFile
  ret = ns_get_url_query_param_val("RespFile", query_val, HPD_CODE_NONE);
  if(ret >= 0) // RespFile found in query parameter
  {
    ns_save_value_from_file(query_val, "Body");
    return 0; // Size if not known so return 0 as it is not used
  }

  // Response size given. Generate data of that size
  ret = ns_get_url_query_param_val("RespSize", query_val, HPD_CODE_NONE);
  if(ret >= 0) // RespSize found in query parameter
  {
    resp_size = atoi(query_val);
  }

  //This is the default case so this should be at last.  
  if(resp_size == 0)
  {
    ns_save_string("", "Body"); // make Body variable empty
    return 0;
  }

  int malloc_done = 0;

  resp_buf = malloc(resp_size + 1);
  if(resp_buf == NULL)
  {
    resp_buf = "Error in malloc";
    resp_size = strlen(resp_buf);
  }
  else
  {
    memset(resp_buf, 'A', resp_size);
    malloc_done = 1;
  }
  // Use ns_save_binary_val so that we can fill binary value in future
  // E.g. to send compressed data
  ns_save_binary_val(resp_buf, "Body", resp_size);

  if(malloc_done)
    free(resp_buf);

  return resp_size;
}

// To set keep alive time for the url
void set_keep_alive_timeout()
{
  int ret;
  int keep_alive_time;
  char query_val[1024];

  ret = ns_get_url_query_param_val("KeepAliveTime", query_val, HPD_CODE_NONE);
  if(ret >= 0) // keep alive rime found in query 
  {
    keep_alive_time = atoi(query_val);
  }
  HPDDL1_API(NULL, "keep_alive_time = %d", keep_alive_time);
  ns_ka_time(keep_alive_time);
}

//to redirect url
//Sample request http://hostname.com/url?BODY=thisIsBody&http_status=302&Location=http://www.cavisson.com/index.php
 
static int prepare_redirect_reply()
{
  int http_status = 100,ret = 0;
  char query_string[1024];
  char http_hdr[1024];
  //Set redirect status and Location header if any
  ret = ns_get_url_query_param_val("http_status", query_string, HPD_CODE_NONE);
  if(ret >= 0)
  {
    http_status = atoi(query_string);
    if((http_status == 301) || (http_status == 302))
    { //set http status code to 301 or 302
      ns_set_http_status_code(http_status);
      ret = ns_get_url_query_param_val("Location", query_string, HPD_CODE_NONE);
      if(ret >= 0){
        sprintf(http_hdr, "%s%s", "Location: ", query_string);
        ns_set_http_hdr(http_hdr);  //set Location header 
      }

    }
  }
  //make body
  ret = ns_get_url_query_param_val("BODY", query_string, HPD_CODE_NONE);
  if(ret >= 0)
  {
    ns_save_string(query_string, "Body");
  }
}






/*-------------------------------------------
  Name: GenericURLService_on_request_callback
  Purpose: This method is called on receiving the service request and after all search and conditional parameters are processed and before applying service delay time.
  Input:   None
  Return:  The function controls service time. Return values can be:
           0 - No service delay time. Override service delay time configure if any
          -1 - Use service delay time as configured
          >0 - Use service delay time in milli-seconds returned by this method
 ------------------------------------------------*/

/*

This uses following query paramters

SvcTime - Service time in milli-seconds
Status - HTTP Status code e.g. 404
Location - If status is 301 or 302, then Location is used and set in the repsonse 

e.g http://192.168.1.40/url_service/url_test.xml?SvcTime=150&Status=301&Location=/tours/index.html

RespSize - Size of response body
  Or
RespFile - File name which is send in the resp bodyS
  Or
RespSameAsReq - Y/N. If Y, then whatever comes in Req body, it is send back in response

Header  (Upto 50 headers)
  Hdr??=<headername: hdr value>

e.g http://192.168.1.40/url_service/url_test.xml?SvcTime=150&Status=404&RespSize=128&Hdr1=MyHdr: MyHdrValue
e.g http://192.168.1.40/url_service/url_test.xml?SvcTime=150&Status=404&RespFile=/tmp/a.txt


*/

int GenericURLService_on_request_callback() 
{
  int status = check_and_set_status_code();

  int svc_time = get_svc_time();

  fill_body();

  set_header(); 

  set_keep_alive_timeout();
  
  prepare_redirect_reply(); 

  return svc_time;
}





