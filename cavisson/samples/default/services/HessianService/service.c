
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hpd_log.h"
#include "hpd_string_api.h"
#include <errno.h>
#include <unistd.h>



static int add(int arg1, int arg2)
{
  int sum;
  sum = arg1 + arg2;
  return sum;
}


int HessianService_on_request_callback() 
{
  //char method[64];
  char *method;
  char *str;
  int arg1, arg2;
  int sum; 

  HPDDL2_CR(NULL, "method called");
  method = ns_eval_string("{method_name}");
  HPDDL2_CR(NULL, "method = %s", method);
  str = ns_eval_string("{args_1}");
  arg1 = atoi(str);
  HPDDL2_CR(NULL, "arg1 = %d", arg1);
  str = NULL;
  str = ns_eval_string("{args_2}");
  arg2 = atoi(str);
  HPDDL2_CR(NULL, "arg2 = %d", arg2);
  HPDDL2_CR(NULL, "method = %s, arg1 = %d, arg2 = %d", method, arg1, arg2);
  
  sum = add(arg1, arg2);
  ns_set_int_val("return_val", sum);
  ns_set_content_type_hdr("Content-Type: application/x-hessian");

  
  return -1; // Return -1 to use service time as per keyword
}
    

