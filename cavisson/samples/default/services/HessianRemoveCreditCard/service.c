#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hpd_log.h"
#include "hpd_string_api.h"
#include <errno.h>
#include <unistd.h>

/*-------------------------------------------
  Name: MacysDemoService_on_request_callback
  Purpose: This method is called on receiving the service request and after all search and conditional parameters are processed and before applying service delay time.
  Input:   None
  Return:  The function controls service time. Return values can be:
           0 - No service delay time. Override service delay time configure if any
          -1 - Use service delay time as configured
          >0 - Use service delay time in milli-seconds returned by this method
 ------------------------------------------------*/
int MacysDemoService_on_request_callback() 
{
char *cp ;
ns_set_content_type_hdr("Content-Type: x-application/hessian");
ns_save_string(ns_eval_string("{cardNo_3}"),"dec");
cp = ns_eval_string("{dec}");
if (cp != "1098342166541333" ||cp != "1098342166541444" ||cp != "1098342166541555")
{ ns_save_string("false","flag");
}
   return -1;
}
