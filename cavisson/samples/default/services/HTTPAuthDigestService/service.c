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

#define AUTH_FAILURE_RESPONSE1 "401 - Unauthorized: Access is denied due to invalid credentials."
#define AUTH_FAILURE_RESPONSE2 "HTTP Error 401. The requested resource requires user authentication."
#define AUTH_OK_RESPONSE "Authentication done"
#define AUTH_ERROR_RESPONSE "Authentication error"

// Return status code filled
static int check_and_set_status_code()
{
char query_val[4096];
int ret;
int status = 200;

  ret = ns_get_url_query_param_val("Status", query_val, HPD_CODE_NONE);
  if(ret >= 0) // Status found in query parameter
  {
    status = atoi(query_val);
    ns_set_http_status_code(status);
  }
  return status;
}       

static int set_location()
{
char query_val[4096];
char http_hdr[4096];
int ret;

  ret = ns_get_url_query_param_val("Location", query_val, HPD_CODE_DECODE);
  if(ret >= 0) // found in query parameter
  {
    //sprintf("Location: %s", query_val);
    sprintf(http_hdr, "Location: %s", query_val);
  }
  else
  {
     sprintf(http_hdr, "Location: %s", "/tours/index.html"); // Default location
     HPDDL2_CR(NULL, " ns_eval_string param value = %s", http_hdr); 
   }
  ns_set_http_hdr(http_hdr);
  return 0;
}       

// return size of body if known
static int fill_body(char *in_resp_buf)
{
char query_val[4096];
int ret;
char *resp_buf = in_resp_buf;
int resp_size = strlen(resp_buf);

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


static void set_response()
{
  char test_case[128] = "OK";

  int ret = ns_get_url_query_param_val("TestCase", test_case, HPD_CODE_NONE);
  
  char *cookie_val = ns_eval_string("{AuthMsgCookieParam}");

  if(!strcmp(cookie_val, ""))
  {
   ns_set_http_status_code(401);
    if(!strcmp(test_case, "MainReqFail"))
    {
      ns_set_http_hdr("WWW-Authenticate: Digest");
    } else{
      ns_set_http_hdr("Set-Cookie: AuthMsg=1");
      ns_set_http_hdr("WWW-Authenticate: Digest realm=cavisson-server");
    } 
    fill_body(AUTH_FAILURE_RESPONSE1);
  }
  else if(!strcmp(cookie_val, "1"))
  {
  ns_set_http_hdr("Set-Cookie: AuthMsg=");
      if(!strcmp(test_case, "DigestRealmFail"))   
    {
    ns_set_http_status_code(401);
      ns_set_http_hdr("WWW-Authenticate: Digest");
      fill_body(AUTH_ERROR_RESPONSE);
    }
    else		
    {
      if(!strcmp(test_case, "DigestRedirect"))
      {
        ns_set_http_status_code(301);
        set_location();
      } else if(!strcmp(test_case, "DigestStatus")){
        check_and_set_status_code();
      }else if(!strcmp(test_case, "DigestCacheable"))
      {
        ns_set_http_hdr("ETag: etg1");
      }
      fill_body(AUTH_OK_RESPONSE);
    }
  }
  else {
    ns_set_http_status_code(401);
    fill_body(AUTH_ERROR_RESPONSE);
      } 
}

/**************************************************************************************/


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



/*-------------------------------------------
  Name: HTTPAuthNTMLService_on_request_callback
  Purpose: This method is called on receiving the service request and after all search and conditional parameters are processed and before applying service delay time.
  Input:   None
  Return:  The function controls service time. Return values can be:
           0 - No service delay time. Override service delay time configure if any
          -1 - Use service delay time as configured
          >0 - Use service delay time in milli-seconds returned by this method
 ------------------------------------------------*/

/*

This uses following query paramters

SvcTime - Service time in milli-seconds. Default is 0

TestCase - 
    OK (Default is OK)
    T0Fail - Send NTLM followed by junk
    T1Fail - Send NTLM without challange in T2 (response of T1)
    T3Fail - Send 401 and WWW-Authenticate header with NTLM without any data
    T3FailNoNTLMHdr - Send 401 and NO WWW-Authenticate header 
    T3Redirect - Send 301 (redirect) and NO WWW-Authenticate header with Location header
    T3Status - Send status as per Status and NO WWW-Authenticate header. Usefule to simulate 404 or 500 on final reponse
    T3Cacheable - Send status 200 and make response cacheable

RespSize - Size of response body
  Or
RespFile - File name which is send in the resp bodyS
  Or
RespSameAsReq - Y/N. If Y, then whatever comes in Req body, it is send back in response

Status - HTTP Status code e.g. 404

Location - Location to be sent in case of redirect test case. Default location is /tours/index.html

Header (Not done)

e.g http://192.168.1.40/url_service/url_test.xml?SvcTime=150&Status=404&RespSize=128
e.g http://192.168.1.40/url_service/url_test.xml?SvcTime=150&Status=404&RespFile=/tmp/a.txt

e.g http://192.168.1.40//http_auth/ntlm.xml?SvcTime=100&TestCase=OK

*/

int HTTPAuthDigestService_on_request_callback() 
{

  int svc_time = get_svc_time();

  set_response();  

  return svc_time;
}
