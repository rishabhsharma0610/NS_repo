/*-----------------------------------------------------------------------------
    Name: HTTPAuthNTLMTestNOService
    Recorded By: Manually by Neeraj Jain
    Date of recording: 
    Flow details:
    Modification History:
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void HTTPAuthNTLMTestNOService()
{

    ns_web_url ("NonNTML", "URL=http://127.0.0.1/tours/index.html");

    // ns_page_think_time(1.0);

    ns_web_url ("NTLMCaseOK", "URL=http://127.0.0.1/http_auth/ntlm.xml?SvcTime=10&TestCase=OK");

    // ns_page_think_time(1.0);

    ns_web_url ("NTLMCaseT0Fail", "URL=http://127.0.0.1/http_auth/ntlm.xml?SvcTime=10&TestCase=T0Fail");

    // ns_page_think_time(1.0);

    ns_web_url ("NTLMCaseT1Fail", "URL=http://127.0.0.1/http_auth/ntlm.xml?SvcTime=10&TestCase=T1Fail");

    // ns_page_think_time(1.0);

    ns_web_url ("NTLMCaseT3Fail", "URL=http://127.0.0.1/http_auth/ntlm.xml?SvcTime=10&TestCase=T3Fail");

    ns_web_url ("NTLMCaseT3FailNoNTLMHdr", "URL=http://127.0.0.1/http_auth/ntlm.xml?SvcTime=10&TestCase=T3FailNoNTLMHdr");

    ns_page_think_time(1.0);

}
