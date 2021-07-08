#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow()
{
  int ret = -1;

  ret = ns_jmeter_start();  

  if(ret < 0)
     ns_jmeter_stop();
}
