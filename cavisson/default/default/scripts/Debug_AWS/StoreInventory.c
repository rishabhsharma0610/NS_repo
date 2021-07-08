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

void StoreInventory()

{

    ns_start_transaction("StoreInventory");
    ns_web_url ("StoreInventory",
           "URL=https://api-test1.gamestop.com/adapter/v2/storesv2/storeInventory?skus={SKUidSP}&latitude=12.75643&longitide=77.4321&zip={PostalCodesFP}&radius=10",
           //"URL=https://blue-mobileapi.gstop-preprod.com/adapter/v2/storesv2/storeInventory?skus={SKUidSP}&latitude=12.75643&longitide=77.4321&zip={PostalCodesFP}&radius=10",
           "METHOD=GET",
//           "HEADER=Authorization: AWS4-HMAC-SHA256 Credential=AKIAQJYD6VR3J35KXAIM/20200922/us-east-1/execute-api/aws4_request, SignedHeaders=accept;host;x-acf-sensor-data;x-amz-date;x-app-version;x-developer-key;x-device;x-gs-native-app, Signature=b1d14b14e68e47268a720a6442a85c92ded1328b4eed277509fb94dd7fc7e41b",
//           "HEADER=X-Amz-Content-Sha256: 0ad78986eeec5b351daecc1ce17da3ac6798d1dd7e1d04cafeb73f56393aefd6",
//           "HEADER=X-Amz-Date: 20200922T085405Z",
           "HEADER=Cache-Control: no-cache",
           "HEADER=User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36",
           "HEADER=Accept: */*",
           "HEADER=Accept-Encoding: gzip, deflate, br",
           "HEADER=Connection: keep-alive",
           "HEADER=x-developer-key: {XDevloperKey_FP}",
           "HEADER=x-device: 51CF1F4D-37F7-4398-9124-0DE3648024B8",
           "HEADER=Authorization:JWTToken {AccessTokenSP}",
           "HEADER=X-App-Version: 680",
          // "HEADER=X-GS-Override: aa9Sul1eiYuPoamu",
           //"HEADER=x-gs-native-app: android-v4.4.0",
"HEADER=Pragma:akamai-x-get-client-ip, akamai-x-cache-on, akamai-x-cache-remote-on, akamai-x-check-cacheable, akamai-x-get-cache-key, akamai-x-get-extracted-values, akamai-x-get-nonces, akamai-x-get-ssl-client-session-id, akamai-x-get-true-cache-key, akamai-x-serial-no, akamai-x-feo-trace, akamai-x-get-request-id",
           "HEADER=correlation-id: StoreInv_{CorrChar}{CorrID}",
           
    );
           ns_end_transaction("StoreInventory", NS_AUTO_STATUS);
         ns_page_think_time(0);

}
