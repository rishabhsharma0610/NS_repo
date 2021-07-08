static char *algorithm = "AWS4-HMAC-SHA256";

static int buildStringToSign(char *amzDate, char *credentialScope, char *canonicalRequest, char *stringToSign)
{
  unsigned char canonicalRequest_hash256[64+1] = {0};
  my_hash256(canonicalRequest, strlen(canonicalRequest), canonicalRequest_hash256);
  sprintf(stringToSign, "%s\n%s\n%s\n%s", "AWS4-HMAC-SHA256", amzDate, credentialScope, canonicalRequest_hash256);
  return 0;
}


static int buildCredentialScope(char *dateStamp, char *region, char *service, char *requestType, char *credentialScope)
{
  sprintf(credentialScope, "%s/%s/%s/%s", dateStamp, region, service, requestType);
  return 0;
}


static int buildCanonicalRequest(char *method, char *canonicalUri, char *canonicalQueryString, char *canonicalHeaders, char *signedHeaders, 
                          unsigned char *payloadHash, char *canonicalRequest)
{
  sprintf(canonicalRequest, "%s\n%c%s\n%s\n%s\n%s\n%s", method, '/', canonicalUri, canonicalQueryString,
          canonicalHeaders, signedHeaders, payloadHash);
  return 0;
}

static int get_path_service_query(char *url, char *canonicalUri, char *uri_service, char *canonicalQueryString)
{
  char *service = NULL;
  char *host = "";
  char *path = "";
  char *query = "";

  if(!url)
    return 1;

  if((service = strstr(url, "//")) != NULL)
    service += 2;
  else
    service = url;

  if ((host = strchr(service, '.')) != NULL)
  {
    *host = '\0';
    host ++;
  }
  else
  {
    return 1;
  }

  if ((path = strchr(host, '/')) != NULL){
      *path = '\0';
      path ++;
  }
  else
  {
    return 1;
  }


  if((query = strchr(path, '?')) != NULL)
  {
    *query = '\0';
     query++;
  }
  else
  {
    query = "";
  }
  strcpy(canonicalUri, path);
  strcpy(canonicalQueryString, query);
  strcpy(uri_service, service);
  NSDL2_API(NULL, NULL, "path =[%s] query =[%s] service = [%s] host = [%s]", path, query, service, host);

  return 0;
}


int ns_get_hmac_signature_ex(char *method, char *uri, char *body, char *region, char *key, char *ksecret, char *signature,char *amzDate, char *dateStamp)
{
  unsigned char *kDate;
  unsigned char *kRegion; 
  unsigned char *kService;
  unsigned char *kSigning; //stores final output
  char canonicalUri[256 + 1] = {0};
  char service[256 + 1] = {0};
  char canonicalQueryString[256 + 1] = "";
  char canonicalHeaders[256 + 1] = {0};
  char signedHeaders[256 + 1] = {0};
  char canonicalRequest[256 + 1] = {0};
  char credentialScope[256 + 1] = {0};
  unsigned char payloadHash[64 + 1] = {0};
  char stringToSign[1024 + 1] = {0};
  unsigned char *signature_hmac = {0};
  struct tm *tmp;
  time_t t;
  int i;
   
  
  NSDL2_API(NULL, NULL, "Method Called");
  if(body == NULL){
    printf("Give error\n");
    return 1;
  }

  //STEP 1:  Define all of your request requirements - HTTP method, URL/URI, request body, etc.

  //STEP 2: Create a date for headers and the credential string.
  

  //Step 3: based on request requirement construct a canonical URI based on the URI path.

  //Step 4: based on the request requirement construct the canonical query string.  This is derived from the URI object provided  



  get_path_service_query(uri, canonicalUri, service, canonicalQueryString);

  //Step 5: Create the canonical headers and signed headers. Header names and value must be trimmed and lowercase, and sorted in ASCII order.
  //Note that there is a trailing \n.
  // processHeaders(headers, canonicalHeaders);
  sprintf(canonicalHeaders, "%s:%s\n", "x-amz-date", amzDate);

  /**
   * Step 6: Create the list of signed headers. This lists the headers in the canonical_headers list, delimited with ";" and in alpha order.
   * Note: The request can include any headers; canonical_headers and signed_headers lists those that you want to be included in the hash
           of the request. 
   * x-amz-date" is always required.
   */
  // processSignedHeaders(headers, signedHeaders);
  sprintf(signedHeaders, "%s", "x-amz-date");

  //Step 7: If the request contains a body - you need to sha-256 hash the payload.  For GET request it should be an empty string
  my_hash256(body, strlen(body), payloadHash);

  //Step 8: Combine elements to create create canonical request
  buildCanonicalRequest(method, canonicalUri, canonicalQueryString, canonicalHeaders, signedHeaders, payloadHash, canonicalRequest);
 
  //Step 9: Construct the credential scope and string to sign.
  buildCredentialScope(dateStamp, region, service, "aws4_request", credentialScope);
  buildStringToSign_ex(amzDate, credentialScope, canonicalRequest, stringToSign);

  //Step 10: Produce the signing key

  kDate = ns_hmac((unsigned char*)dateStamp, strlen(dateStamp), (unsigned char*)ksecret, strlen(ksecret), MD_TYPE_SHA256 , 0); //returns hac in kdate
  kRegion =  ns_hmac((unsigned char *)region, strlen(region), (unsigned char *)kDate, 32, MD_TYPE_SHA256, 0); //returns hmac in kRegion
  kService = ns_hmac((unsigned char *)service, strlen(service), (unsigned char *)kRegion, 32, MD_TYPE_SHA256, 0); // returns hmac in kService
  kSigning =  ns_hmac((unsigned char *)"aws4_request", 12, (unsigned char *)kService, 32, MD_TYPE_SHA256, 0);//returns hmac in kSigning
  signature_hmac =  ns_hmac((unsigned char *)stringToSign, strlen(stringToSign), 
                              (unsigned char *)kSigning, 32, MD_TYPE_SHA256, 0);//returns hmac in kSigning
  for(i = 0; i < 32; i++)
    sprintf(signature + (i * 2), "%02x", signature_hmac[i]);

  NSDL2_API(NULL, NULL, "signature_hmac [%s]", signature); 
return 0;
}