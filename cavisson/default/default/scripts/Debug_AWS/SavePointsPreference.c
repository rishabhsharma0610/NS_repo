/*-----------------------------------------------------------------------------
    Name: Loyalty_Comparison_Table
    Generated By: Shashank
    Date of generation: 09/24/2020 09:00:19
    Flow details:
    Build details: 4.3.0 (build# 103)
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"


void SavePointsPreference()
{

    ns_start_transaction("SavePointsPreference");
    ns_web_url ("SavePointsPreference",
          // "URL=https://blue-mobileapi.gamestop.com/v2/loyalty/savePointsPreferences?SelectedOption=3",
          "URL=https://api-test1.gamestop.com/adapter/v2/loyalty/savePointsPreferences?SelectedOption=3",
           "METHOD=POST",
        //   "HEADER=Authorization:JWTToken {AccessTokenSP}",
         "HEADER=Authorization:JWTToken {AccessTokenSPRegAuthOnly}",
           "HEADER=Cache-Control: no-cache",
           "HEADER=User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36",
           "HEADER=Accept: */*",
           "HEADER=Accept-Encoding: gzip, deflate, br",
           "HEADER=Connection: keep-alive",
           "HEADER=x-developer-key: {XDevloperKey_FP}",
           "HEADER=x-device: 51CF1F4D-37F7-4398-9124-0DE3648024B8",
           "HEADER=X-App-Version: 680",
           "HEADER=X-GS-Override: aa9Sul1eiYuPoamu",
         //  "HEADER=x-gs-native-app: android-v4.4.0",
"HEADER=Pragma:akamai-x-get-client-ip, akamai-x-cache-on, akamai-x-cache-remote-on, akamai-x-check-cacheable, akamai-x-get-cache-key, akamai-x-get-extracted-values, akamai-x-get-nonces, akamai-x-get-ssl-client-session-id, akamai-x-get-true-cache-key, akamai-x-serial-no, akamai-x-feo-trace, akamai-x-get-request-id",
           "HEADER=correlation-id: SavePointsPreference_{CorrChar}{CorrID}",
    );
           ns_end_transaction("SavePointsPreference", NS_AUTO_STATUS);
         ns_page_think_time(0);  

}
