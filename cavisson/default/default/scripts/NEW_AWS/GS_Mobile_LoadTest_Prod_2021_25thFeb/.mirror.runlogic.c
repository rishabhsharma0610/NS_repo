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
extern FlowReturn GuestAuth();
extern FlowReturn GetConfig();
extern FlowReturn HomePage();
extern FlowReturn LoyaltyLandingPage();
extern FlowReturn LoyaltyRewards();
extern FlowReturn LoyaltyGameInformer();
extern FlowReturn LoyaltyBenefits();
extern FlowReturn LoyaltyExclusivePro();
extern FlowReturn LoyaltyComparisonTable();
extern FlowReturn LoyaltyMembershipDetails();
extern FlowReturn LoyaltyRenewalDetails();
extern FlowReturn LoyaltyProMembershipDetails();
extern FlowReturn LoyaltyCreateAccountCarousel();
extern FlowReturn Continue();
extern FlowReturn CategoryList();
extern FlowReturn SearchProduct();
extern FlowReturn TypeHeadSearchProduct();
extern FlowReturn GetProductDetails();
extern FlowReturn ProductInventory();
extern FlowReturn Recommendations_ViewProdouct();
extern FlowReturn Deal();
extern FlowReturn GetStore();
extern FlowReturn SearchStore();
extern FlowReturn StoreInventory();
extern FlowReturn CreateCart();
extern FlowReturn AddToCart();
extern FlowReturn Recommendations_AddToCart();
extern FlowReturn RegAuth();
extern FlowReturn CreateCustomer();
extern FlowReturn CreateCustomerAsPlayer();
extern FlowReturn RefreshAuth();
extern FlowReturn GetSession();
extern FlowReturn ProfileDetail();
extern FlowReturn UpdateprofileHomeStore();
extern FlowReturn WalletInfo();
extern FlowReturn UpdateCustomerToAdult();
extern FlowReturn FetchRecommendations();
extern FlowReturn ClickRecommendations();
extern FlowReturn ViewRecommendations();
extern FlowReturn SDD();
extern FlowReturn RewardsPurchase();
extern FlowReturn GetStockpilePointPreferences();
extern FlowReturn RewardsDashboard();
extern FlowReturn ActiveOffers();
extern FlowReturn FetchRewardsByRewardId();
extern FlowReturn SavePointsPreference();
extern FlowReturn OrderHistory();
extern FlowReturn PreOrdersHistory();
extern FlowReturn SetDOB();
extern FlowReturn AccountLinking();
extern FlowReturn AccountLinkingTwoFactorAuth();
extern FlowReturn SubmitAccountLinking();
extern FlowReturn UserLegacyMigration();
extern FlowReturn CustomerOrderDetails();
extern FlowReturn RegGetCart();
extern FlowReturn UpdateCart();
extern FlowReturn DeleteCart();
// End - List of used flows in the runlogic


void runlogic()
{
    NSDL2_RUNLOGIC(NULL, NULL, "Executing init_script()");

    init_script();

    NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Start");
    {
        UPDATE_USER_FLOW_COUNT(0)
        int Startpercent = ns_get_random_number_int(1, 10000);

        NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Start = %d", Startpercent);

        if(Startpercent <= 4000)
        {

            NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - GuestUser (pct value = 40.0%)");
            {
                UPDATE_USER_FLOW_COUNT(1)
                int GuestUserpercent = ns_get_random_number_int(1, 10000);

                NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - GuestUser = %d", GuestUserpercent);

                if(GuestUserpercent <= 10000)
                {

                    NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - Normal (pct value = 100.0%)");
                    {
                        UPDATE_USER_FLOW_COUNT(2)

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - G_Auth_Block (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(3)
                            int G_Auth_Blockpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - G_Auth_Block = %d", G_Auth_Blockpercent);

                            if(G_Auth_Blockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - GuestAuth (pct value = 100.0%)");
                                UPDATE_USER_FLOW_COUNT(4)
                                GuestAuth();
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - HomePage_Block (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(6)
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - GetConfig");
                            UPDATE_USER_FLOW_COUNT(7)
                            GetConfig();
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - HomePage");
                            UPDATE_USER_FLOW_COUNT(9)
                            HomePage();
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyLandingPage");
                            UPDATE_USER_FLOW_COUNT(11)
                            LoyaltyLandingPage();

                            NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - ContentService_Block (pct value = 100.0%)");
                            {
                                UPDATE_USER_FLOW_COUNT(13)
                                int ContentService_Blockpercent = ns_get_random_number_int(1, 10000);

                                NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - ContentService_Block = %d", ContentService_Blockpercent);

                                if(ContentService_Blockpercent <= 1100)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyRewards (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(14)
                                    LoyaltyRewards();
                                }
                                else if(ContentService_Blockpercent <= 2200)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyGameInformer (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(16)
                                    LoyaltyGameInformer();
                                }
                                else if(ContentService_Blockpercent <= 3300)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyBenefits (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(18)
                                    LoyaltyBenefits();
                                }
                                else if(ContentService_Blockpercent <= 4400)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyExclusivePro (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(20)
                                    LoyaltyExclusivePro();
                                }
                                else if(ContentService_Blockpercent <= 5500)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyComparisonTable (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(22)
                                    LoyaltyComparisonTable();
                                }
                                else if(ContentService_Blockpercent <= 6600)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyMembershipDetails (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(24)
                                    LoyaltyMembershipDetails();
                                }
                                else if(ContentService_Blockpercent <= 7700)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyRenewalDetails (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(26)
                                    LoyaltyRenewalDetails();
                                }
                                else if(ContentService_Blockpercent <= 8800)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyProMembershipDetails (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(28)
                                    LoyaltyProMembershipDetails();
                                }
                                else if(ContentService_Blockpercent <= 10000)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyCreateAccountCarousel (pct value = 12.0%)");
                                    UPDATE_USER_FLOW_COUNT(30)
                                    LoyaltyCreateAccountCarousel();
                                }
                                else if(ContentService_Blockpercent <= 10000)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 0.0%)");
                                    UPDATE_USER_FLOW_COUNT(32)
                                    Continue();
                                }
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing count block - SearchNBrowse. Min = 2, Max = 3 (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(33)
                            int SearchNBrowseCount = ns_get_random_number_int(2, 3);
                            int SearchNBrowseLoop;
                             for(SearchNBrowseLoop = 1; SearchNBrowseLoop <= SearchNBrowseCount; SearchNBrowseLoop++)
                            {

                                NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - SearchNBrowseBlock (pct value = 100.0%), SelectedCount = %d, Iteration = %d",SearchNBrowseCount, SearchNBrowseLoop);
                                {
                                    UPDATE_USER_FLOW_COUNT(34)
                                    int SearchNBrowseBlockpercent = ns_get_random_number_int(1, 10000);

                                    NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - SearchNBrowseBlock = %d", SearchNBrowseBlockpercent);

                                    if(SearchNBrowseBlockpercent <= 10000)
                                    {

                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - SearchNBrowseBlock (pct value = 100.0%), SelectedCount = %d, Iteration = %d",SearchNBrowseCount, SearchNBrowseLoop);
                                        {
                                            UPDATE_USER_FLOW_COUNT(35)

                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Category (pct value = 100.0%), SelectedCount = %d, Iteration = %d",SearchNBrowseCount, SearchNBrowseLoop);
                                            {
                                                UPDATE_USER_FLOW_COUNT(36)
                                                int Categorypercent = ns_get_random_number_int(1, 10000);

                                                NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Category = %d", Categorypercent);

                                                if(Categorypercent <= 10000)
                                                {
                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - CategoryList (pct value = 100.0%)");
                                                    UPDATE_USER_FLOW_COUNT(37)
                                                    CategoryList();
                                                }
                                            }

                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Search (pct value = 100.0%)");
                                            {
                                                UPDATE_USER_FLOW_COUNT(39)
                                                int Searchpercent = ns_get_random_number_int(1, 10000);

                                                NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Search = %d", Searchpercent);

                                                if(Searchpercent <= 6000)
                                                {
                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - SearchProduct (pct value = 60.0%)");
                                                    UPDATE_USER_FLOW_COUNT(40)
                                                    SearchProduct();
                                                }
                                                else if(Searchpercent <= 10000)
                                                {
                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - TypeHeadSearchProduct (pct value = 40.0%)");
                                                    UPDATE_USER_FLOW_COUNT(42)
                                                    TypeHeadSearchProduct();
                                                }
                                            }
                                        }
                                    }
                                    else if(SearchNBrowseBlockpercent <= 10000)
                                    {
                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 0.0%)");
                                        UPDATE_USER_FLOW_COUNT(44)
                                        Continue();
                                    }
                                }

                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - PDP_Block (pct value = 100.0%), SelectedCount = %d, Iteration = %d",SearchNBrowseCount, SearchNBrowseLoop);
                                    {
                                        UPDATE_USER_FLOW_COUNT(45)
                                        int PDP_Blockpercent = ns_get_random_number_int(1, 10000);

                                        NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - PDP_Block = %d", PDP_Blockpercent);

                                        if(PDP_Blockpercent <= 10000)
                                        {

                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - PDP (pct value = 100.0%), SelectedCount = %d, Iteration = %d",SearchNBrowseCount, SearchNBrowseLoop);
                                            {
                                                UPDATE_USER_FLOW_COUNT(46)
                                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - GetProductDetails");
                                                UPDATE_USER_FLOW_COUNT(47)
                                                GetProductDetails();
                                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ProductInventory");
                                                UPDATE_USER_FLOW_COUNT(49)
                                                ProductInventory();
                                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Recommendations_ViewProdouct");
                                                UPDATE_USER_FLOW_COUNT(51)
                                                Recommendations_ViewProdouct();
                                            }
                                        }
                                    }
                                }
                            }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Deals_Block (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(53)
                            int Deals_Blockpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Deals_Block = %d", Deals_Blockpercent);

                            if(Deals_Blockpercent <= 0)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Deal (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(54)
                                Deal();
                            }
                            else if(Deals_Blockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 100.0%)");
                                UPDATE_USER_FLOW_COUNT(56)
                                Continue();
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Store_Block (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(57)
                            int Store_Blockpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Store_Block = %d", Store_Blockpercent);

                            if(Store_Blockpercent <= 5000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - GetStore (pct value = 50.0%)");
                                UPDATE_USER_FLOW_COUNT(58)
                                GetStore();
                            }
                            else if(Store_Blockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - SearchStore (pct value = 50.0%)");
                                UPDATE_USER_FLOW_COUNT(60)
                                SearchStore();
                            }
                            else if(Store_Blockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - StoreInventory (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(62)
                                StoreInventory();
                            }
                            else if(Store_Blockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(64)
                                Continue();
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - CartOperationBlock (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(65)
                            int CartOperationBlockpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - CartOperationBlock = %d", CartOperationBlockpercent);

                            if(CartOperationBlockpercent <= 10000)
                            {

                                NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - GuestCartOperations (pct value = 100.0%)");
                                {
                                    UPDATE_USER_FLOW_COUNT(66)
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - CreateCart");
                                    UPDATE_USER_FLOW_COUNT(67)
                                    CreateCart();

                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing condition block - ATC_Block");
                                    {
                                        UPDATE_USER_FLOW_COUNT(69)
                                        if(strcmp(ns_eval_string("{OrderAbleCheckSP}"), "true") ==0)
                                        {

                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - ATC_Block (pct value = 100.0%)");
                                            {
                                                UPDATE_USER_FLOW_COUNT(70)

                                                NSDL2_RUNLOGIC(NULL, NULL, "Executing condition block - ATC_ItemCountCheck");
                                                {
                                                    UPDATE_USER_FLOW_COUNT(71)
                                                    if(ns_get_int_val("LineItemIdCountSP") <= 3)
                                                    {

                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - ATC_Final (pct value = 100.0%)");
                                                        {
                                                            UPDATE_USER_FLOW_COUNT(72)
                                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - AddToCart");
                                                            UPDATE_USER_FLOW_COUNT(73)
                                                            AddToCart();
                                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Recommendations_AddToCart");
                                                            UPDATE_USER_FLOW_COUNT(75)
                                                            Recommendations_AddToCart();
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if(CartOperationBlockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(77)
                                Continue();
                            }
                        }
                    }
                }
            }
        }
        else if(Startpercent <= 10000)
        {

            NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - RegisteredUser (pct value = 60.0%)");
            {
                UPDATE_USER_FLOW_COUNT(78)
                int RegisteredUserpercent = ns_get_random_number_int(1, 10000);

                NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - RegisteredUser = %d", RegisteredUserpercent);

                if(RegisteredUserpercent <= 10000)
                {

                    NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - NormalUser (pct value = 100.0%)");
                    {
                        UPDATE_USER_FLOW_COUNT(79)

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - LoginOrCreateAccount (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(80)
                            int LoginOrCreateAccountpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - LoginOrCreateAccount = %d", LoginOrCreateAccountpercent);

                            if(LoginOrCreateAccountpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - RegAuth (pct value = 100.0%)");
                                UPDATE_USER_FLOW_COUNT(81)
                                RegAuth();
                            }
                            else if(LoginOrCreateAccountpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - CreateCustomer (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(83)
                                CreateCustomer();
                            }
                            else if(LoginOrCreateAccountpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - CreateCustomerAsPlayer (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(85)
                                CreateCustomerAsPlayer();
                            }
                            else if(LoginOrCreateAccountpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(87)
                                Continue();
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - HomePage_Block (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(88)
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - GetConfig");
                            UPDATE_USER_FLOW_COUNT(89)
                            GetConfig();
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - HomePage");
                            UPDATE_USER_FLOW_COUNT(91)
                            HomePage();
                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyLandingPage");
                            UPDATE_USER_FLOW_COUNT(93)
                            LoyaltyLandingPage();

                            NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - ContentService_Block (pct value = 100.0%)");
                            {
                                UPDATE_USER_FLOW_COUNT(95)
                                int ContentService_Blockpercent = ns_get_random_number_int(1, 10000);

                                NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - ContentService_Block = %d", ContentService_Blockpercent);

                                if(ContentService_Blockpercent <= 1100)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyRewards (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(96)
                                    LoyaltyRewards();
                                }
                                else if(ContentService_Blockpercent <= 2200)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyGameInformer (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(98)
                                    LoyaltyGameInformer();
                                }
                                else if(ContentService_Blockpercent <= 3300)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyBenefits (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(100)
                                    LoyaltyBenefits();
                                }
                                else if(ContentService_Blockpercent <= 4400)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyExclusivePro (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(102)
                                    LoyaltyExclusivePro();
                                }
                                else if(ContentService_Blockpercent <= 5500)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyComparisonTable (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(104)
                                    LoyaltyComparisonTable();
                                }
                                else if(ContentService_Blockpercent <= 6600)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyMembershipDetails (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(106)
                                    LoyaltyMembershipDetails();
                                }
                                else if(ContentService_Blockpercent <= 7700)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyRenewalDetails (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(108)
                                    LoyaltyRenewalDetails();
                                }
                                else if(ContentService_Blockpercent <= 8800)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyProMembershipDetails (pct value = 11.0%)");
                                    UPDATE_USER_FLOW_COUNT(110)
                                    LoyaltyProMembershipDetails();
                                }
                                else if(ContentService_Blockpercent <= 10000)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - LoyaltyCreateAccountCarousel (pct value = 12.0%)");
                                    UPDATE_USER_FLOW_COUNT(112)
                                    LoyaltyCreateAccountCarousel();
                                }
                                else if(ContentService_Blockpercent <= 10000)
                                {
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 0.0%)");
                                    UPDATE_USER_FLOW_COUNT(114)
                                    Continue();
                                }
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - RefreshAuth_Block (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(115)
                            int RefreshAuth_Blockpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - RefreshAuth_Block = %d", RefreshAuth_Blockpercent);

                            if(RefreshAuth_Blockpercent <= 3000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - RefreshAuth (pct value = 30.0%)");
                                UPDATE_USER_FLOW_COUNT(116)
                                RefreshAuth();
                            }
                            else if(RefreshAuth_Blockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 70.0%)");
                                UPDATE_USER_FLOW_COUNT(118)
                                Continue();
                            }
                        }
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - GetSession");
                        UPDATE_USER_FLOW_COUNT(119)
                        GetSession();
                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ProfileDetail");
                        UPDATE_USER_FLOW_COUNT(121)
                        ProfileDetail();

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing count block - SearchNBrowse. Min = 2, Max = 3 (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(123)
                            int SearchNBrowseCount = ns_get_random_number_int(2, 3);
                            int SearchNBrowseLoop;
                             for(SearchNBrowseLoop = 1; SearchNBrowseLoop <= SearchNBrowseCount; SearchNBrowseLoop++)
                            {

                                NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - SearchNBrowseBlock (pct value = 100.0%), SelectedCount = %d, Iteration = %d",SearchNBrowseCount, SearchNBrowseLoop);
                                {
                                    UPDATE_USER_FLOW_COUNT(124)
                                    int SearchNBrowseBlockpercent = ns_get_random_number_int(1, 10000);

                                    NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - SearchNBrowseBlock = %d", SearchNBrowseBlockpercent);

                                    if(SearchNBrowseBlockpercent <= 10000)
                                    {

                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - SearchNBrowseBlock (pct value = 100.0%), SelectedCount = %d, Iteration = %d",SearchNBrowseCount, SearchNBrowseLoop);
                                        {
                                            UPDATE_USER_FLOW_COUNT(125)

                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Category (pct value = 100.0%), SelectedCount = %d, Iteration = %d",SearchNBrowseCount, SearchNBrowseLoop);
                                            {
                                                UPDATE_USER_FLOW_COUNT(126)
                                                int Categorypercent = ns_get_random_number_int(1, 10000);

                                                NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Category = %d", Categorypercent);

                                                if(Categorypercent <= 10000)
                                                {
                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - CategoryList (pct value = 100.0%)");
                                                    UPDATE_USER_FLOW_COUNT(127)
                                                    CategoryList();
                                                }
                                                else if(Categorypercent <= 10000)
                                                {
                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 0.0%)");
                                                    UPDATE_USER_FLOW_COUNT(129)
                                                    Continue();
                                                }
                                            }

                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Search (pct value = 100.0%)");
                                            {
                                                UPDATE_USER_FLOW_COUNT(130)
                                                int Searchpercent = ns_get_random_number_int(1, 10000);

                                                NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Search = %d", Searchpercent);

                                                if(Searchpercent <= 5000)
                                                {
                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - SearchProduct (pct value = 50.0%)");
                                                    UPDATE_USER_FLOW_COUNT(131)
                                                    SearchProduct();
                                                }
                                                else if(Searchpercent <= 10000)
                                                {
                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - TypeHeadSearchProduct (pct value = 50.0%)");
                                                    UPDATE_USER_FLOW_COUNT(133)
                                                    TypeHeadSearchProduct();
                                                }
                                            }
                                        }
                                    }
                                    else if(SearchNBrowseBlockpercent <= 10000)
                                    {
                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 0.0%)");
                                        UPDATE_USER_FLOW_COUNT(135)
                                        Continue();
                                    }
                                }

                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - PDP_Block (pct value = 100.0%), SelectedCount = %d, Iteration = %d",SearchNBrowseCount, SearchNBrowseLoop);
                                    {
                                        UPDATE_USER_FLOW_COUNT(136)
                                        int PDP_Blockpercent = ns_get_random_number_int(1, 10000);

                                        NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - PDP_Block = %d", PDP_Blockpercent);

                                        if(PDP_Blockpercent <= 10000)
                                        {

                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - PDP (pct value = 100.0%), SelectedCount = %d, Iteration = %d",SearchNBrowseCount, SearchNBrowseLoop);
                                            {
                                                UPDATE_USER_FLOW_COUNT(137)
                                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - GetProductDetails");
                                                UPDATE_USER_FLOW_COUNT(138)
                                                GetProductDetails();
                                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ProductInventory");
                                                UPDATE_USER_FLOW_COUNT(140)
                                                ProductInventory();
                                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Recommendations_ViewProdouct");
                                                UPDATE_USER_FLOW_COUNT(142)
                                                Recommendations_ViewProdouct();
                                            }
                                        }
                                    }
                                }
                            }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Deals_Block (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(144)
                            int Deals_Blockpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Deals_Block = %d", Deals_Blockpercent);

                            if(Deals_Blockpercent <= 0)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Deal (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(145)
                                Deal();
                            }
                            else if(Deals_Blockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 100.0%)");
                                UPDATE_USER_FLOW_COUNT(147)
                                Continue();
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - ProfileWallet (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(148)
                            int ProfileWalletpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - ProfileWallet = %d", ProfileWalletpercent);

                            if(ProfileWalletpercent <= 6000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - UpdateprofileHomeStore (pct value = 60.0%)");
                                UPDATE_USER_FLOW_COUNT(149)
                                UpdateprofileHomeStore();
                            }
                            else if(ProfileWalletpercent <= 6000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - WalletInfo (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(151)
                                WalletInfo();
                            }
                            else if(ProfileWalletpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 40.0%)");
                                UPDATE_USER_FLOW_COUNT(153)
                                Continue();
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - UpdateToAdult (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(154)
                            int UpdateToAdultpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - UpdateToAdult = %d", UpdateToAdultpercent);

                            if(UpdateToAdultpercent <= 0)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - UpdateCustomerToAdult (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(155)
                                UpdateCustomerToAdult();
                            }
                            else if(UpdateToAdultpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 100.0%)");
                                UPDATE_USER_FLOW_COUNT(157)
                                Continue();
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Recommendations_Block (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(158)
                            int Recommendations_Blockpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Recommendations_Block = %d", Recommendations_Blockpercent);

                            if(Recommendations_Blockpercent <= 0)
                            {

                                NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - Recommendations (pct value = 0.0%)");
                                {
                                    UPDATE_USER_FLOW_COUNT(159)
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - FetchRecommendations");
                                    UPDATE_USER_FLOW_COUNT(160)
                                    FetchRecommendations();
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ClickRecommendations");
                                    UPDATE_USER_FLOW_COUNT(162)
                                    ClickRecommendations();
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ViewRecommendations");
                                    UPDATE_USER_FLOW_COUNT(164)
                                    ViewRecommendations();
                                }
                            }
                            else if(Recommendations_Blockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 100.0%)");
                                UPDATE_USER_FLOW_COUNT(166)
                                Continue();
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - SDD_Block (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(167)
                            int SDD_Blockpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - SDD_Block = %d", SDD_Blockpercent);

                            if(SDD_Blockpercent <= 0)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - SDD (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(168)
                                SDD();
                            }
                            else if(SDD_Blockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 100.0%)");
                                UPDATE_USER_FLOW_COUNT(170)
                                Continue();
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Loyality_Block (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(171)
                            int Loyality_Blockpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Loyality_Block = %d", Loyality_Blockpercent);

                            if(Loyality_Blockpercent <= 0)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - RewardsPurchase (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(172)
                                RewardsPurchase();
                            }
                            else if(Loyality_Blockpercent <= 2000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - GetStockpilePointPreferences (pct value = 20.0%)");
                                UPDATE_USER_FLOW_COUNT(174)
                                GetStockpilePointPreferences();
                            }
                            else if(Loyality_Blockpercent <= 2000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - RewardsDashboard (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(176)
                                RewardsDashboard();
                            }
                            else if(Loyality_Blockpercent <= 4000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - ActiveOffers (pct value = 20.0%)");
                                UPDATE_USER_FLOW_COUNT(178)
                                ActiveOffers();
                            }
                            else if(Loyality_Blockpercent <= 6000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - FetchRewardsByRewardId (pct value = 20.0%)");
                                UPDATE_USER_FLOW_COUNT(180)
                                FetchRewardsByRewardId();
                            }
                            else if(Loyality_Blockpercent <= 8000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - SavePointsPreference (pct value = 20.0%)");
                                UPDATE_USER_FLOW_COUNT(182)
                                SavePointsPreference();
                            }
                            else if(Loyality_Blockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 20.0%)");
                                UPDATE_USER_FLOW_COUNT(184)
                                Continue();
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - Customer_Block (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(185)
                            int Customer_Blockpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - Customer_Block = %d", Customer_Blockpercent);

                            if(Customer_Blockpercent <= 2000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - OrderHistory (pct value = 20.0%)");
                                UPDATE_USER_FLOW_COUNT(186)
                                OrderHistory();
                            }
                            else if(Customer_Blockpercent <= 4000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - PreOrdersHistory (pct value = 20.0%)");
                                UPDATE_USER_FLOW_COUNT(188)
                                PreOrdersHistory();
                            }
                            else if(Customer_Blockpercent <= 4000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - SetDOB (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(190)
                                SetDOB();
                            }
                            else if(Customer_Blockpercent <= 4000)
                            {

                                NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - AccountLinkingBlock (pct value = 0.0%)");
                                {
                                    UPDATE_USER_FLOW_COUNT(192)
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - AccountLinking");
                                    UPDATE_USER_FLOW_COUNT(193)
                                    AccountLinking();
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - AccountLinkingTwoFactorAuth");
                                    UPDATE_USER_FLOW_COUNT(195)
                                    AccountLinkingTwoFactorAuth();
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - SubmitAccountLinking");
                                    UPDATE_USER_FLOW_COUNT(197)
                                    SubmitAccountLinking();
                                }
                            }
                            else if(Customer_Blockpercent <= 4000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - UserLegacyMigration (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(199)
                                UserLegacyMigration();
                            }
                            else if(Customer_Blockpercent <= 4000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - CustomerOrderDetails (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(201)
                                CustomerOrderDetails();
                            }
                            else if(Customer_Blockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 60.0%)");
                                UPDATE_USER_FLOW_COUNT(203)
                                Continue();
                            }
                        }

                        NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - CartOperationBlock (pct value = 100.0%)");
                        {
                            UPDATE_USER_FLOW_COUNT(204)
                            int CartOperationBlockpercent = ns_get_random_number_int(1, 10000);

                            NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - CartOperationBlock = %d", CartOperationBlockpercent);

                            if(CartOperationBlockpercent <= 10000)
                            {

                                NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - RegCartOperations (pct value = 100.0%)");
                                {
                                    UPDATE_USER_FLOW_COUNT(205)
                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - CreateCart");
                                    UPDATE_USER_FLOW_COUNT(206)
                                    CreateCart();

                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing condition block - GetCartRegCheck");
                                    {
                                        UPDATE_USER_FLOW_COUNT(208)
                                        if(strcmp(ns_eval_string("{DV_UserType}"), "Registered") ==0)
                                        {
                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - RegGetCart");
                                            UPDATE_USER_FLOW_COUNT(209)
                                            RegGetCart();
                                        }
                                    }

                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing condition block - ATC_Block");
                                    {
                                        UPDATE_USER_FLOW_COUNT(211)
                                        if(strcmp(ns_eval_string("{OrderAbleCheckSP}"), "true") ==0)
                                        {

                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - ATC_Block (pct value = 100.0%)");
                                            {
                                                UPDATE_USER_FLOW_COUNT(212)

                                                NSDL2_RUNLOGIC(NULL, NULL, "Executing condition block - ATC_ItemCountCheck");
                                                {
                                                    UPDATE_USER_FLOW_COUNT(213)
                                                    if(ns_get_int_val("LineItemIdCountSP") <= 3)
                                                    {

                                                        NSDL2_RUNLOGIC(NULL, NULL, "Executing sequence block - ATC_Final (pct value = 100.0%)");
                                                        {
                                                            UPDATE_USER_FLOW_COUNT(214)
                                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - AddToCart");
                                                            UPDATE_USER_FLOW_COUNT(215)
                                                            AddToCart();
                                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Recommendations_AddToCart");
                                                            UPDATE_USER_FLOW_COUNT(217)
                                                            Recommendations_AddToCart();
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }

                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - UpdateDeleteBlock (pct value = 100.0%)");
                                    {
                                        UPDATE_USER_FLOW_COUNT(219)
                                        int UpdateDeleteBlockpercent = ns_get_random_number_int(1, 10000);

                                        NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - UpdateDeleteBlock = %d", UpdateDeleteBlockpercent);

                                        if(UpdateDeleteBlockpercent <= 0)
                                        {

                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing condition block - UpdateDeleteCartBlock");
                                            {
                                                UPDATE_USER_FLOW_COUNT(220)
                                                if(strcmp(ns_eval_string("{DV_UserType}"), "Registered") ==0)
                                                {

                                                    NSDL2_RUNLOGIC(NULL, NULL, "Executing percent block - UpdateDeleteCartOpt (pct value = 0.0%)");
                                                    {
                                                        UPDATE_USER_FLOW_COUNT(221)
                                                        int UpdateDeleteCartOptpercent = ns_get_random_number_int(1, 10000);

                                                        NSDL2_RUNLOGIC(NULL, NULL, "Percentage random number for block - UpdateDeleteCartOpt = %d", UpdateDeleteCartOptpercent);

                                                        if(UpdateDeleteCartOptpercent <= 3000)
                                                        {
                                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - UpdateCart (pct value = 30.0%)");
                                                            UPDATE_USER_FLOW_COUNT(222)
                                                            UpdateCart();
                                                        }
                                                        else if(UpdateDeleteCartOptpercent <= 6000)
                                                        {
                                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - DeleteCart (pct value = 30.0%)");
                                                            UPDATE_USER_FLOW_COUNT(224)
                                                            DeleteCart();
                                                        }
                                                        else if(UpdateDeleteCartOptpercent <= 10000)
                                                        {
                                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 40.0%)");
                                                            UPDATE_USER_FLOW_COUNT(226)
                                                            Continue();
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        else if(UpdateDeleteBlockpercent <= 10000)
                                        {
                                            NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 100.0%)");
                                            UPDATE_USER_FLOW_COUNT(227)
                                            Continue();
                                        }
                                    }
                                }
                            }
                            else if(CartOperationBlockpercent <= 10000)
                            {
                                NSDL2_RUNLOGIC(NULL, NULL, "Executing flow - Continue (pct value = 0.0%)");
                                UPDATE_USER_FLOW_COUNT(228)
                                Continue();
                            }
                        }
                    }
                }
            }
        }
    }

    NSDL2_RUNLOGIC(NULL, NULL, "Executing ns_exit_session()");
    ns_exit_session();
}
