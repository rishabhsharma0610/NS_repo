#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hpd_log.h"
#include "hpd_string_api.h"
#include <errno.h>
#include <unistd.h>

  
int CookieVar_on_request_callback() 
{
 char *var_val;
 //ns_save_string({"srch","dec"});
  var_val = ns_eval_string_ex ("{encode_all_var}", 1);
  HPDDL2_CR(NULL, " ns_eval_string param value = %s", var_val);

   
  return -1; // Return -1 to use service time as per keyword
}
    

