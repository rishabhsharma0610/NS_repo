/*-----------------------------------------------------------------------------
    Name: flow
    Generated By: jyoti
    Date of generation: 09/24/2020 09:00:19
    Flow details:
    Build details: 4.3.0 (build# 103)
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"


void SDD()
{

    ns_start_transaction("SDD");
    ns_web_url ("SDD",
           "URL=https://blue-mobileapi.gamestop.com/v2/delivery/sameDayDelivery",
          //  "URL=https://blue-mobileapi.gamestop.com/adapter/v2/delivery/sameDayDelivery",
           "METHOD=POST",
           "HEADER=Authorization:JWTToken {AccessTokenSP}",
           "HEADER=Cache-Control: no-cache",
           "HEADER=Content-Type: application/json",
           "HEADER=Content-Length: 250",
           "HEADER=User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36",
           "HEADER=Accept: */*",
           "HEADER=Accept-Encoding: gzip, deflate, br",
           "HEADER=Connection: keep-alive",
           "HEADER=X-acf-sensor-data: 1,a,cxXYI3fjRoEIIwH6L4LJ9nwIx5L1+HwOitMOTd0F1Edwat5NDtRW9xk0QXThdHbnWlEspJXCbAY5qLSTz3Nmqql2zIUgiHVCYbbveIcVAG1MYT/MwLzA2/FZaJHNbbiel3/gJPgWqfUXLea5V8UwTVXA9j3gVVVyOSDj2UREhPI=,pUa1VKLFPoAlUgas9hQ3ubVnMODLD4zNLo7I+yg0SfDD2HSCUqQ+ZGd6hF84Z+wlC+LyIH8047pAGKEwQ8LbMSvILzl7QbdS8GbcT4+FMm2QX+NjGilDVKw6LkZJywIpAEZUb1IZ2YzRJh2aGkJcWQO7PH+md12CqsdqSyN09zM=$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$2000,1000,0",
           "HEADER=x-developer-key: e61dc486679fb28793db0ee7ffdd7f8f",
         //  "HEADER=x-gs-native-app: android-v4.4.0",
           "HEADER=x-device: 51CF1F4D-37F7-4398-9124-0DE3648024B8",
           "HEADER=X-App-Version: 680",
          // "HEADER=X-GS-Override: aa9Sul1eiYuPoamu",
"HEADER=Pragma:akamai-x-get-client-ip, akamai-x-cache-on, akamai-x-cache-remote-on, akamai-x-check-cacheable, akamai-x-get-cache-key, akamai-x-get-extracted-values, akamai-x-get-nonces, akamai-x-get-ssl-client-session-id, akamai-x-get-true-cache-key, akamai-x-serial-no, akamai-x-feo-trace, akamai-x-get-request-id",
           "HEADER=correlation-id: SDD_{CorrChar}{CorrID}",
           "BODY=$CAVINCLUDE$=SDD.json",
     
    );
           ns_end_transaction("SDD", NS_AUTO_STATUS);
         ns_page_think_time(0);

}
