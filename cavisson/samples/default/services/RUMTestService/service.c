#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hpd_log.h"
#include "hpd_string_api.h"
#include <errno.h>
#include <unistd.h>
#include <time.h>
#define RUM_EXPIRY_TIMEOUT 1*60

/*-------------------------------------------
Name: RUMTestService_on_request_callback
Purpose: This method is called on receiving the service request and after all search and conditional parameters are processed and before applying service delay time.
Input:   None
Return:  The function controls service time. Return values can be:
0 - No service delay time. Override service delay time configure if any
-1 - Use service delay time as configured
>0 - Use service delay time in milli-seconds returned by this method
------------------------------------------------*/
int RUMTestService_on_request_callback()
{
 
  static unsigned char count = 0;  // Increased while session is changed
  time_t cur_ts,now;
  char *sid;
  char sid_buffer[1024],lts_buf[128];
  unsigned char hpd_id = 0;
  struct tm  s_tm;
  long time_diff;
  unsigned long cookie_time;
  char *time_str;
  
  //Get current time stamp in seconds
  cur_ts = time(NULL);

  // set LTS buffer
  sprintf(lts_buf, "Set-Cookie: CAV_LTS=%lu", cur_ts);

  // set new lts in cookie
  ns_set_http_hdr(lts_buf); 

  // get last access time (LTS)
  time_str = ns_eval_string("{CAV_LTS}");

  cookie_time = atol(time_str);

  time_diff = cur_ts - cookie_time; 
 
  hpd_id = atoi(getenv("CHILD_INDEX"));
  sid = ns_eval_string("{CAV_SID}");

  if(*sid == '\0' || time_diff > RUM_EXPIRY_TIMEOUT )
  {
    sprintf(sid_buffer, "Set-Cookie: CAV_SID=%d%d%8d", hpd_id, count, cur_ts);
   //sprintf(sid_buffer, "Cookie: CVA_SID=%d",tsi1);
    ns_set_http_hdr(sid_buffer);
    HPDDL2_CR(NULL, "setting CAV_SID CAV_SID = %s", sid);
    count ++;
  }
  else
  {
    HPDDL2_CR(NULL, "Got CAV_SID CAV_SID = %s", sid);
  }

// HPDDL2_CR(NULL, "CAV_LTS = %a %Y-%m-%d %H:%M:%S %Z", ns_eval_string("{CAV_LTS}"));
  
  return -1;
}
