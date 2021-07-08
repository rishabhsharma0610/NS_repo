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
  - Support for compresses/chunk repsonse
  - Support for large header value
  - Cookie in the response (Done)
  - Embedded objects in the body for auto fetch testing (Done using RespFile)
*/

static int ns_get_cur_date(char *format, int offset_secs, char *buf, int buf_len) 
{
time_t time_secs;
struct tm *tm_ptr;
char local_format[512];

  char *tzone = "TZ=GMT0";

// Sat Sep 18 15:07:10 IST 2010

  if(format) 
    strcpy(local_format, format);
  else 
    strcpy(local_format, "%a, %d %b %Y %H:%M:%S GMT");

  time_secs = time(NULL) + offset_secs;
  tm_ptr = localtime(&time_secs);
  if (tm_ptr == NULL) 
  {
    perror("localtime");
    strcpy(buf, "Error in localtime");
    return -1;
  }

  putenv(tzone);
  if (strftime(buf, buf_len, local_format, tm_ptr) == 0) 
  {
    tzone = "";
    putenv(tzone);
    fprintf(stderr, "strftime returned 0");
    strcpy(buf, "Error in strftime");
    return -1;
  }

  tzone = "";
  putenv(tzone);
  return 0;
}

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

static int check_and_set_http_hdr(char *query_param_name, char *hdr_name)
{
  return(check_and_set_http_hdr_ex(query_param_name, hdr_name, HPD_CODE_NONE));
}


static int check_and_set_http_hdr_date_offset(char *query_param_name, char *hdr_name)
{
char query_val[4096], hdr_val[4096], http_hdr[4096];
int ret;
int offset;

  ret = ns_get_url_query_param_val(query_param_name, query_val, HPD_CODE_NONE);
  if(ret >= 0) // found query parameter
  {
    offset = atoi(query_val); //getting offset from parameter
    ns_get_cur_date(NULL, offset, hdr_val, sizeof(hdr_val)); //getting current time+offset
    sprintf(http_hdr, "%s%s", hdr_name, hdr_val);
    ns_set_http_hdr(http_hdr);
  }
  return 0;
}

static int check_and_set_http_hdr_date(char *query_param_name, char *hdr_name)
{
char query_val[4096], hdr_val[4096], http_hdr[4096];
int ret;

  ret = ns_get_url_query_param_val(query_param_name, query_val, HPD_CODE_NONE);
  if(ret >=0) // flag found
  {
    if(strcasecmp(query_val, "Y") == 0) // Header to be send in the response
    {
      ns_get_cur_date(NULL, 0, hdr_val, sizeof(hdr_val)); //getting current date
      sprintf(http_hdr, "%s%s", hdr_name, hdr_val);
      ns_set_http_hdr(http_hdr);
    }
  }
  return 0;
}

static int check_and_set_http_hdr_if_yes(char *query_param_name, char *hdr_name_val)
{
char query_val[4096], hdr_val[4096], http_hdr[4096];
int ret;

  ret = ns_get_url_query_param_val(query_param_name, query_val, HPD_CODE_NONE);
  if(ret >=0) // found in query parameter
  {
    if(strcasecmp(query_val, "Y") == 0) // header to be send in the response
    {
      sprintf(http_hdr, "%s", hdr_name_val);
      ns_set_http_hdr(http_hdr);
    }
  }
  return 0;
}

// Return status code filled
static int check_and_set_status_code()
{
char query_val[4096], hdr_val[4096], http_hdr[4096];
int ret;

  if((ns_http_req_has_validator_ims()) || (ns_http_req_has_validator_if_none_match()))
  {

    // Get value of query parameter - NMPct
    // NMPct=10
    int nm_pct = 100;
    ret = ns_get_url_query_param_val("NMPct", query_val, HPD_CODE_NONE);
    if(ret >=0) // NMPct found in query parameter
    {
      nm_pct = atoi(query_val);
    }
    char *nm_rand = ns_get_random_num(1, 100);

    int nm_rand_num = atoi(nm_rand);

    HPDDL2_CR(NULL, "nm_rand_num = %d, nm_pct = %d", nm_rand_num, nm_pct);
    if(nm_rand_num <= nm_pct)
    {
      ns_set_http_status_code(304);
      return 304; // 304 is set
    }
  }

  // Check if any other status code to fill
  // This can be used to simulate redirect (301 and 302)
  int code = 0;
  ret = ns_get_url_query_param_val("Code", query_val, HPD_CODE_NONE);
  if(ret >= 0) // Code found in query parameter
  {
    code = atoi(query_val);
    ns_set_http_status_code(code);
    if((code == 301) || (code == 302))
    {
      check_and_set_http_hdr_ex("Location", "Location: ", HPD_CODE_NONE);
    }
    return code; // code is set, so return it
  }

  return 0; // No status filled, so default 200 OK will be returned
}       

static int fill_body(int code_filled)
{
char query_val[4096];
int ret;

  int resp_size_304 = 0;
  ret = ns_get_url_query_param_val("RespSize304", query_val, HPD_CODE_NONE);
  if(ret >=0) // RespSize304 found in query parameter
  {
    resp_size_304 = atoi(query_val);
  }
  
  int resp_size = 128; // Default reponse size for 200 OK
  if(code_filled == 304) // Means not modified response
  {
    resp_size = resp_size_304;
  }
  else // Means normal response
  {
    // Get value of query parameter - RespSize
    ret = ns_get_url_query_param_val("RespSize", query_val, HPD_CODE_NONE);
    if(ret >=0) // RespSize found in query parameter
    {
      resp_size = atoi(query_val);
    }

  }
  if(resp_size == 0)
  {
    ns_save_string("", "Body"); // make Body variable empty
    return 0;
  }

  // Get value of query parameter - RespFile
  ret = ns_get_url_query_param_val("RespFile", query_val, HPD_CODE_NONE);
  if(ret >=0) // RespFile found in query parameter
  {
    ns_save_value_from_file(query_val, "Body");
    return;
  }

  char *resp_buf = malloc(resp_size + 1);
  int malloc_done = 0;
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


/*-------------------------------------------
  Name: QATCaching_on_request_callback
  Purpose: This method is called on receiving the service request and after all search and conditional parameters are processed and before applying service delay time.
  Input:   None
  Return:  The function controls service time. Return values can be:
           0 - No service delay time. Override service delay time configure if any
          -1 - Use service delay time as configured
          >0 - Use service delay time in milli-seconds returned by this method
 ------------------------------------------------*/

/*

This uses following query paramters

Etag
..
.
.
.
..


*/

int QATCaching_on_request_callback() 
{
char query_val[4096], http_hdr[4096];
char hdr_val[4096];

int offset;

  // Get value of query parameter - etag
  // We get Comma separated list of Etags in the ETag query paramter
  // e.g. ETag="etag1","etag2"
  check_and_set_http_hdr_ex("ETag", "ETag: ", HPD_CODE_DECODE);

  // Get value of query parameter - LastModified offset in seconds
  // LastModified=120 or -120
  check_and_set_http_hdr_date_offset("LastModified", "Last-Modified: ");
 
  // Get value of query parameter - Expires
  check_and_set_http_hdr_date_offset("Expires", "Expires: ");

  // Get value of query parameter - Date to send or not
  // E.g. Date=Y or Date=N
  check_and_set_http_hdr_date("Date", "Date: ");

  // Get value of query parameter - Age
  // e.g. Age=60
  check_and_set_http_hdr("Age", "Age: ");

  // Get value of query parameter - Pragma
  // E.g. Pragma=no-cache
  check_and_set_http_hdr("Pragma", "Pragma: ");

  // Get value of query parameter - CacheControlNoCache
  // CacheControlNoCache=Y or N
  check_and_set_http_hdr_if_yes("CacheControlNoCache", "Cache-Control: no-cache");

  // Get value of query parameter - CacheControlMA
  // NOTE: We are using MA as MaxAge conflicts with Age - NO BUG
  check_and_set_http_hdr("CacheControlMA", "Cache-Control: max-age=");

  // Get value of query parameter - CacheControlNoStore
  check_and_set_http_hdr_if_yes("CacheControlNoStore", "Cache-Control: no-store");

  // Get value of query parameter - CacheControlMustRevalidate
  check_and_set_http_hdr_if_yes("CacheControlMustRevalidate", "Cache-Control: must-revalidate");

  // Get value of query parameter - CacheControlSMA
  check_and_set_http_hdr("CacheControlSMA", "Cache-Control: s-maxage=");

  // Get value of query parameter - CacheControl
  // This is to test many values in one header
  // e.g. Cache-Control: no-store, no-cache, max-age=0
  check_and_set_http_hdr("CacheControl", "Cache-Control: ");

  // Get value of query parameter - Cookie
  // This is to test set cookie
  check_and_set_http_hdr("Cookie", "Set-Cookie: ");

  int code_filled = check_and_set_status_code();

  fill_body(code_filled);

  return -1;
}
