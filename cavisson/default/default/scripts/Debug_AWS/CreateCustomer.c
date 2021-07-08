/*-----------------------------------------------------------------------------
    Name: flow
    Generated By: Shashank
    Date of generation: 09/22/2020 04:48:50
    Flow details:
    Build details: 4.3.0 (build# 103)
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void CreateCustomer()

{

	char EmailValue[64];

    ns_start_transaction("CreateCustomer");
    ns_web_url ("CreateCustomer",
//           "URL=https://blue-mobileapi.gstop-preprod.com/v2/customers",
           //"URL=https://blue-mobileapi.gstop-preprod.com/v2/customers/CreateCustomerV2",  
           "URL=https://api-test1.gamestop.com/adapter/v2/customers/CreateCustomerV2",                    
           "METHOD=POST",
        //   "HEADER=Authorization: AWS4-HMAC-SHA256 Credential=AKIAQJYD6VR3J35KXAIM/20200922/us-east-1/execute-api/aws4_request, SignedHeaders=accept;host;x-acf-sensor-data;x-amz-date;x-app-version;x-developer-key;x-device;x-gs-native-app, Signature=b1d14b14e68e47268a720a6442a85c92ded1328b4eed277509fb94dd7fc7e41b",
         //  "HEADER=X-Amz-Content-Sha256: 0ad78986eeec5b351daecc1ce17da3ac6798d1dd7e1d04cafeb73f56393aefd6",
          // "HEADER=X-Amz-Date: 20200922T085405Z",
           "HEADER=Cache-Control: no-cache",
           "HEADER=Content-Type: application/json",
           "HEADER=Authorization: JWTToken {AccessTokenSP}",
           "HEADER=Content-Length: 439", 
            "HEADER=User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36",
           "HEADER=Accept: */*",
           "HEADER=Accept-Encoding: gzip, deflate, br",
           "HEADER=Connection: keep-alive",
           "HEADER=x-developer-key: {XDevloperKey_FP}",
           "HEADER=x-device: 51CF1F4D-37F7-4398-9124-0DE3648024B8",
           "HEADER=X-App-Version: 680",
           "HEADER=X-GS-Override: aa9Sul1eiYuPoamu",
       //    "HEADER=x-gs-native-app: android-v4.4.0",
"HEADER=Pragma:akamai-x-get-client-ip, akamai-x-cache-on, akamai-x-cache-remote-on, akamai-x-check-cacheable, akamai-x-get-cache-key, akamai-x-get-extracted-values, akamai-x-get-nonces, akamai-x-get-ssl-client-session-id, akamai-x-get-true-cache-key, akamai-x-serial-no, akamai-x-feo-trace, akamai-x-get-request-id",
           "HEADER=correlation-id: CreateCustomer_{CorrChar}{CorrID}",
           "BODY=$CAVINCLUDE$=CreateCustomer.json",
    );
           ns_end_transaction("CreateCustomer", NS_AUTO_STATUS);
         ns_page_think_time(0);

snprintf(EmailValue, 64, "%s", ns_eval_string("PlayS{CreateUQ}{CreateEmailRP}@bhexacttarget.com"));
ns_save_string(EmailValue,"DV_EmailValue");

ns_save_data_ex("/home/cavisson/Game_Stop/data/GS/Mobile/Create_Mobile_EmailIds.txt",NS_APPEND_FILE,"%s",ns_eval_string("PlayS{CreateUQ}{CreateEmailRP}@bhexacttarget.com,GameStopPerf#01"));


}