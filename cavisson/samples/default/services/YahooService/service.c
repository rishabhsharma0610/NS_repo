#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hpd_log.h"
#include "hpd_string_api.h"
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>

/*

We can simulate Yahoo HTTP service in NetOcean using correlation service.

Let us add a new correlation  
                YahooService

URL = /config/pwtoken_get

Extract URL query parameter and log in Debug log

src=ymsgr&ts=&login=neeraj&passwd=abc123&chal=MyChallangeString

Send response with following Set-Cookies

Set-Cookie: Y=YahooCookieY
Set-Cookie: T=YahooCookieT
Set-Cookie: B=YahooCookieB

*/

static void log_query_param(char *query_param_name, char *http_name, int decode_option) 
{
char query_val[4096], http_hdr[4096];
int ret;

  ret = ns_get_url_query_param_val(query_param_name, query_val, decode_option);
  if(ret >= 0) // query parameter found, So send in the response
  {
    HPDDL2_CR(NULL, "Parameter name = %s, Parameter value = %s", query_param_name, query_val);
  }
}


static void set_cookie(char *cookie_name, char *cookie_value, char *http_name)
{
char http_hdr[4096];

  sprintf(http_hdr, "Set-Cookie: %s=%s", cookie_name, cookie_value);
  ns_set_http_hdr(http_hdr);

}


int YahooService_on_request_callback() 
{

char query_val[4096], http_hdr[4096];
char hdr_val[4096];

  log_query_param("src", "SRC: ", HPD_CODE_DECODE);
  log_query_param("ts", "TS: ", HPD_CODE_DECODE);
  log_query_param("login", "LOGIN: ", HPD_CODE_DECODE);
  log_query_param("passwd", "PASSWORD: ", HPD_CODE_DECODE);
  log_query_param("chal", "CHAL: ", HPD_CODE_DECODE);
  
  set_cookie("Y", "YahooCookieY", "Set-Cookie:"); 
  set_cookie("T", "YahooCookieT", "Set-Cookie:"); 
  set_cookie("B", "YahooCookieB", "Set-Cookie:"); 

  return -1;

}
