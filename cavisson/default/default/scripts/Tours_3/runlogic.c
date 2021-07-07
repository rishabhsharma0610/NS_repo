#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"


extern int init_script();
extern int exit_script();

typedef void FlowReturn;

// Note: Following extern declaration is used to find the list of used flows. Do not delete/edit it
// Start - List of used flows in the runlogic
extern FlowReturn flow();
//extern FlowReturn hpd_tours();
// End - List of used flows in the runlogic

void runlogic()
{
  init_script();
  {
      flow();
  }
  ns_exit_session();
}
