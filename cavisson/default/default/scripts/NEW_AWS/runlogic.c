#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"
#ifdef ENABLE_RUNLOGIC_PROGRESS
  #define UPDATE_USER_FLOW_COUNT(count) update_user_flow_count(count);
#else
  #define UPDATE_USER_FLOW_COUNT(count)
#endif


extern int init_script();
extern int exit_script();

typedef void FlowReturn;

// Note: Following extern declaration is used to find the list of used flows. Do not delete/edit it
// Start - List of used flows in the runlogic
extern FlowReturn Cert_EnrollTibco();
// End - List of used flows in the runlogic


void runlogic()
{
    NSDL2_RUNLOGIC(NULL, NULL, "Executing init_script()");

    init_script();

    NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - AWS");
    {
        UPDATE_USER_FLOW_COUNT(0)
        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Cert_EnrollTibco");
        UPDATE_USER_FLOW_COUNT(1)
        Cert_EnrollTibco();
    }

    NSDL2_RUNLOGIC(NULL, NULL, "Executing ns_exit_session()");
    ns_exit_session();
}
