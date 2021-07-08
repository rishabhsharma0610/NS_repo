//nsl_static_var(Channel_FP:1, File=/home/cavisson/Game_Stop/data/GS/Mobile/paltform_Channel.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=All, CopyFileToTR=Yes);
//nsl_static_var(XDevloperKey_FP:1, File=/home/cavisson/Game_Stop/data/GS/Mobile/XDevloperKey.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=All, CopyFileToTR=Yes);
//nsl_static_var(Clientid_FP:1, SecretKeyFP:2, File=/home/cavisson/Game_Stop/data/GS/Mobile/Authentication.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=Yes);
//nsl_static_var(EmailFP:1, PasswordFP:2, File=/home/cavisson/Game_Stop/data/GS/Mobile/RegEmail.txt, Refresh=SESSION, Mode=UNIQUE, EncodeMode=None, CopyFileToTR=Yes);
//nsl_static_var(EmailFP:1, PasswordFP:2, File=/home/cavisson/Game_Stop/data/GS/Mobile/Reg_MB_EmailIds.txt, Refresh=SESSION, Mode=UNIQUE, EncodeMode=None, CopyFileToTR=Yes);
//nsl_static_var(EmailFP:1, PasswordFP:2, File=/home/cavisson/Game_Stop/data/GS/Mobile/Create_Mobile_PlayerEmailIds.txt, Refresh=SESSION, Mode=UNIQUE, EncodeMode=None, CopyFileToTR=Yes);
//nsl_static_var(EmailFP:1, PasswordFP:2, File=/home/cavisson/Game_Stop/data/GS/Prod/Reg_Mobile_EmailIds.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=None, CopyFileToTR=Yes);
//nsl_static_var(EmailFP:1, PasswordFP:2, File=/home/cavisson/Game_Stop/data/GS/Mobile/Reg_MB_EmailIds_New.txt, Refresh=SESSION, Mode=UNIQUE, EncodeMode=None, CopyFileToTR=Yes);
//nsl_static_var(Email_AL_FP:1, Password_AL_FP:2, File=/home/cavisson/Game_Stop/data/GS/Mobile/Reg_MB_EmailIds_New.txt, Refresh=SESSION, Mode=UNIQUE, EncodeMode=None, CopyFileToTR=Yes);
//nsl_static_var(Email_Adapter_FP:1, Password_Adapter_FP:2, File=/home/cavisson/Game_Stop/data/GS/Mobile/Adapter_Create_Mobile_PlayerEmailIds.txt, Refresh=SESSION, Mode=UNIQUE, EncodeMode=None, CopyFileToTR=Yes);
//nsl_static_var(EmailFP_bhavana:1, PasswordFP_bhavana:2, File=/home/cavisson/Game_Stop/data/GS/Mobile/bhavana.txt, Refresh=SESSION, Mode=UNIQUE, EncodeMode=None, CopyFileToTR=Yes);
//nsl_static_var(SearchFP:1, File=/home/cavisson/Game_Stop/data/GS/Mobile/SearchKeywords.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=All, EncodeSpaceBy=%20, CopyFileToTR=Yes);
//nsl_static_var(StoreIdsFP:1, File=/home/cavisson/Game_Stop/data/GS/Mobile/StoreID_100mile.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=All, CopyFileToTR=Yes);
//nsl_static_var(PostalCodesFP:1, File=/home/cavisson/Game_Stop/data/GS/Mobile/PostalCodes.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=All, CopyFileToTR=Yes);
//nsl_static_var(addr1FP:1,addr2FP:2,cityFP:3,stateCodeFP:4,postalCodeFP:5,countryCodeFP:6,phoneFP:7,phone2FP:8, File=/home/cavisson/Game_Stop/data/GS/Mobile/Address.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=All, CopyFileToTR=Yes);

/*
nsl_search_var(AccessTokenSP, PAGE=RegAuth, PAGE=RefreshAuth, PAGE=GuestAuth, PAGE=CreateCustomer, PAGE=CreateCustomerAsPlayer, LB="\"access_token\":\"", RB="\",\"token_type\"", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="NO", EncodeMode=Specified, CharsToEncode="=+/");
nsl_search_var(AccessTokenSPRegAuthOnly, PAGE=RegAuth, LB="\"access_token\":\"", RB="\",\"token_type\"", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="NO", EncodeMode=Specified, CharsToEncode="=+/");
nsl_search_var(AccessTokenSP_old, PAGE=RegAuth_Old, PAGE=GuestAuth_Old, LB="\"access_token\":\"", RB="\",\"token_type\"", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="NO", EncodeMode=Specified, CharsToEncode="=+/");
//nsl_search_var(AccessTokenSP, PAGE=RegAuth, PAGE=RefreshAuth, PAGE=GuestAuth, PAGE=CreateCustomer, PAGE=CreateCustomerAsPlayer, LB="\"access_token\":\"", RB="\",\"token_type", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(SlotIdSP, PAGE=LoyaltyLandingPage, LB="\"slotId\":\"", RB="\"", LBMATCH=FIRST, SaveOffset=0, ORD=ANY, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(LtySlotMainSP, PAGE=GetConfig, LB="\"LoyaltyPageSlotDetails\":{", RB="}", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(LtyPlayerSlotIdSP, PAGE=GetConfig, LB="\"Player\":\"", RB="\"", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=LtySlotMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(LtyGuestSlotIdSP, PAGE=GetConfig, LB="\"Guest\":\"", RB="\"", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=LtySlotMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(LtyProSlotIdSP, PAGE=GetConfig, LB="\"Pro\":\"", RB="\"", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=LtySlotMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(LtyComparisonSlotIdSP, PAGE=GetConfig, LB="\"Comparison\":\"", RB="\"", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=LtySlotMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(LtyMembershipSlotIdSP, PAGE=GetConfig, LB="\"MembershipDetails\":\"", RB="\"", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=LtySlotMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(LtyRenewSlotIdSP, PAGE=GetConfig, LB="\"Renew\":\"", RB="\"", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=LtySlotMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(LtyProMembershipSlotIdSP, PAGE=GetConfig, LB="\"ProMembershipDetails\":\"", RB="\"", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=LtySlotMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(LtyAccountSlotIdSP, PAGE=GetConfig, LB="\"Account\":\"", RB="\"", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=LtySlotMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(CategorySearchSP, PAGE=CategoryList, LB="\",\"id\":\"", RB="\",\"thumbnail\"", LBMATCH=FIRST, SaveOffset=0, ORD=ANY, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(ProductIDMainSP, PAGE=SearchProduct, LB="\"Products\":[", RB="],\"Next\":", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(ProductIDSP, PAGE=SearchProduct, LB="\"ProductId\":\"", RB="\",\"ProductType", LBMATCH=FIRST, SaveOffset=0, ORD=ANY, Search=Variable, Var=ProductIDMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(ProductIDTypeHeadSP, PAGE=TypeHeadSearchProduct, LB="\"ProductId\":\"", RB="\",\"IsWebPunchOut", LBMATCH=FIRST, SaveOffset=0, ORD=ANY, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(SKUidSP, PAGE=GetProductDetails, LB="\"product_id\":\"", RB="\",\"variation_values\"", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(PriceSP, PAGE=GetProductDetails, LB="\"price\":{\"sales\":{\"value\":", RB=",\"currency\"", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(OrderAbleCheckSP, PAGE=GetProductDetails, LB=",\"orderable\":", RB=",\"", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(ProdInvCheckSP, PAGE=ProductInventory, LB="\"inventory\":{\"ats\":", RB=".0,\"backorderable", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(CartIdSP, PAGE=CreateCart, PAGE=RegGetCart, LB="{\"CartId\":\"", RB="\",\"", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
//nsl_search_var(CartIdSP, PAGE=CreateCart, PAGE=RegGetCart, LB="{\"CartId\":\"", RB="\",\"Discounts", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(LineItemIdCountSP, PAGE=RegGetCart, LB="\"LineItemId\":\"", RB="\",\"DisplayName", LBMATCH=FIRST, ORD=ALL, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(LineItemIdSP, PAGE=RegGetCart, LB="\"LineItemId\":\"", RB="\",\"DisplayName", LBMATCH=FIRST, ORD=ANY, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(FetchRecomPIdSP, PAGE=FetchRecommendations, LB="\"product-id\":\"", RB="\",\"title\"", LBMATCH=FIRST, SaveOffset=0, ORD=ANY, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(OpenIdSP, PAGE=AccountLinking, LB="openID\":\"", RB="\"}", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(AdultCheckSP, PAGE=ProfileDetails, LB="\"IsAdult\":", RB=",\"Is", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(DOBCheckSP, PAGE=ProfileDetails, LB="\"IsBirthdate\":", RB="}", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);

nsl_search_var(SessionJWTTokenSP, PAGE=GetSessionBridge, LB="\"jwtToken\":\"Bearer ", RB="\",\"bridgeUrl", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(SessionBridgeUrlSP, PAGE=GetSessionBridge, LB="\"bridgeUrl\":\"https://", RB="\"}", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);

nsl_search_var(SessionCookieMainSP, PAGE=GetSession, LB="\"Set-Cookie\":[", RB="}", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(dwanonymousCookieSP, PAGE=GetSession, LB="\"dwanonymous_420142ceefb9f0c103b3815e84e9fcef=", RB="\",\"dwsid", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=SessionCookieMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(dwsidSP, PAGE=GetSession, LB="\"dwsid=", RB="\",\"__cq", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=SessionCookieMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(cq_dntSP, PAGE=GetSession, LB="__cq_dnt=", RB="\",\"dw_", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=SessionCookieMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(dw_dntSP, PAGE=GetSession, LB="\"dw_dnt=", RB="\"]", LBMATCH=FIRST, SaveOffset=0, Search=Variable, Var=SessionCookieMainSP, RETAINPREVALUE="YES", EncodeMode=None);
nsl_search_var(EmptyCartCheckSP, PAGE=ViewCart_Mobile, LB="<h1>Your Shopping Cart is ", RB="</h1>", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
*/

nsl_random_string_var(CorrChar, Min=4, Max=7, CharSet="a-z", Refresh=SESSION);
nsl_unique_number_var(CorrID, Format=%01lu, Refresh=USE);
nsl_random_string_var(CreateEmailRP, Min=8, Max=11, CharSet="a-z0-9", Refresh=SESSION);
nsl_unique_number_var(CreateUQ, Format=%03lu, Refresh=SESSION);


nsl_decl_var(DV_EmailValue);
nsl_decl_var(DV_ProductID);
nsl_decl_var(DV_Month);
nsl_decl_var(DV_Date);
nsl_decl_var(DV_AccessToken_Encoded);
nsl_decl_var(DV_UserType);

/*
nsl_web_find(TEXT="\"HomePageSlotDetails\"", PAGE=GetConfig, FAIL=NOTFOUND, ID="Search product failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"access_token\"", PAGE=GuestAuth, PAGE=RefreshAuth, PAGE=RegAuth, PAGE=CreateCustomer, PAGE=CreateCustomerAsPlayer, PAGE=SubmitAccountLinking, FAIL=NOTFOUND, ID="Request failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"name\":\"PUR Landing Page - Guest\"", PAGE=LoyaltyLandingPage, FAIL=NOTFOUND, ID="Content service failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\",\"deliveryId\":\"", PAGE=LoyaltyRewards, PAGE=LoyaltyGameInformer, PAGE=LoyaltyBenefits, PAGE=LoyaltyExclusivePro, PAGE=LoyaltyComparisonTable, PAGE=LoyaltyMembershipDetails, PAGE=LoyaltyRenewalDetails, PAGE=LoyaltyProMembershipDetails, PAGE=LoyaltyCreateAccountCarousel, FAIL=NOTFOUND, ID="Content service failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"type\":\"category\"", PAGE=HomePage, FAIL=NOTFOUND, ID="Category List failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"id\":\"", PAGE=CategoryList, PAGE=GetProductDetails, FAIL=NOTFOUND, ID="ID not found", ActionOnFail=STOP);
nsl_web_find(TEXT="\"Title\":\"", PAGE=TypeHeadSearchProduct, FAIL=NOTFOUND, ID="TypeHead Search product failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"ProductId\":\"", PAGE=SearchProduct, FAIL=NOTFOUND, ID="Search product failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"id\":\"inventory\"", PAGE=ProductInventory, FAIL=NOTFOUND, ID="Inventory retrieve failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"CartId\":\"", PAGE=CreateCart, FAIL=NOTFOUND, ID="Cart id not found", ActionOnFail=STOP);
nsl_web_find(TEXT="\"storeDeliveryMessage\":\"", PAGE=GetStore, FAIL=NOTFOUND, ID="Get store retrieve failed", ActionOnFail=STOP);
nsl_web_find(TEXT=",\"Orders\":[", PAGE=OrderHistory, FAIL=NOTFOUND, ID="Get Order History retrieve failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"CustomerId\":\"", PAGE=GetSession, PAGE=ProfileDetails, FAIL=NOTFOUND, ID="Get Profile/session Details retrieve failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"product-id\":\"", PAGE=FetchRecommendations, FAIL=NOTFOUND, ID="Fetch Recommendations failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"uuid\":\"", PAGE=ClickRecommendations, PAGE=ViewRecommendations, PAGE=Recommendations_AddToCart, FAIL=NOTFOUND, ID="Recommendations failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"sameDayDelivery\":{\"available\"", PAGE=SDD, FAIL=NOTFOUND, ID="SDD check failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"label\":\"Stockpile My Points to use in the Rewards Center\"", PAGE=GetStockpilePointPreferences, FAIL=NOTFOUND, ID="Get StockpilePointPreferences check failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"ActiveOffers\":[", PAGE=ActiveOffers, PAGE=WalletInfo, FAIL=NOTFOUND, ID="Get Active Offers check failed", ActionOnFail=STOP);
nsl_web_find(TEXT=",\"points\":\"", PAGE=FetchRewardsByRewardId, FAIL=NOTFOUND, ID="Fetc hRewardsByRewardId check failed", ActionOnFail=STOP);
nsl_web_find(TEXT="HTTP/1.1 200 OK", PAGE=UpdateCart, PAGE=DeleteCart, PAGE=UpdateprofileHomeStore, PAGE=UpdateCustomerToAdult, PAGE=SavePointsPreference, PAGE=PreOrdersHistory, PAGE=SetDOB, FAIL=NOTFOUND, ID="Failed", ActionOnFail=STOP, Search_IN=HEADER);
nsl_web_find(TEXT="\"success\":true", PAGE=AccountLinking, FAIL=NOTFOUND, ID="Account Linking failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"success\":", PAGE=AccountLinkingTwoFactorAuth, FAIL=NOTFOUND, ID="Account Linking TwoFactorAuth failed", ActionOnFail=STOP);
nsl_web_find(TEXT="\"customerOrderNo\":\"", PAGE=CustomerOrderDetails, FAIL=NOTFOUND, ID="Get Customer OrderDetails failed", ActionOnFail=STOP);
nsl_web_find(TEXT="deal_of_the_day", PAGE=Deal, FAIL=NOTFOUND, ID="Deal failed", ActionOnFail=STOP);
nsl_web_find(TEXT="{\"jwtToken\":\"Bearer", PAGE=GetSessionBridge, FAIL=NOTFOUND, ID="GetSession Bridge retrieve failed", ActionOnFail=STOP);

*/

nsl_date_var(DateStamp, Format="%Y%m%d", Unique=YES, Refresh=USE);
nsl_date_var(DateTimeRP, Format="%ms", Unique=YES, Refresh=USE);
nsl_date_var(DateAWS, Format="%Y%m%dT%H%M%SZ", Offset=-0.05:30:00, Refresh=SESSION);


//nsl_date_var(TimeAWS, Format="HMMSS", Refresh=SESSION);

//nsl_static_var(AccessTokenPost:1, File=AuthSSSS.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=All, CopyFileToTR=No);
//nsl_static_var(AccessTokenPost_Guest:1, File=GuestAuthMobileAPI.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=All, CopyFileToTR=No);
//nsl_static_var(AccessTokenPost_Reg:1, File=GuestAuthMobileAPI.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=All, CopyFileToTR=No);
//nsl_static_var(AccessTokenPost_Adapter:1, File=AdapterAPI.txt, Refresh=SESSION, Mode=RANDOM, EncodeMode=All, CopyFileToTR=No);
//nsl_search_var(AddressID, PAGE=CreateAddress, LB="\"address_id\":\"", RB="\",", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
nsl_random_number_var(LoyalityCardNumber, Min=12, Max=13, Format=%01lu, Refresh=SESSION);
nsl_random_string_var(EmailAccountLinking, Min=9, Max=10, CharSet="a-z", Refresh=SESSION);
nsl_decl_var(skey);
nsl_decl_var(Time_DP7);
nsl_decl_var(Time_DP8);
//nsl_search_var(signature, PAGE=Cert_EnrollTibco,LB=";x-amz-date;x-api-key\n", RB="'\n\nThe String-to-Sign", LBMATCH=FIRST, SaveOffset=0, RETAINPREVALUE="YES", EncodeMode=None);
//nsl_static_var(DateAWS:1, File=.seq, Refresh=SESSION, Mode=SEQUENTIAL, FirstDataLine=2, EncodeMode=All, CopyFileToTR=No);
nsl_static_var(xmlbody:1, File=xmlbodyfile.seq, Refresh=SESSION, Mode=SEQUENTIAL, VAR_VALUE=F1=file, EncodeMode=All);
