/*-----------------------------------------------------------------------------
    Name: runlogic 
    runlogic details:
    Modification History:
-----------------------------------------------------------------------------*/

package JAVA_HPDS.runlogic;

import JAVA_HPDS.*;

import pacJnvmApi.NSApi;

public class runlogic
{

    // Note: Following extern declaration is used to find the list of used flows. Do not delete/edit it
    //Start - List of used flows in the runlogic
    //Initialise the flow class
    flow flowObj = new flow();
    //End - List of used flows in the runlogic

    public void execute(NSApi nsApi) throws Exception
    {
        //Logging
        int initStatus = init_script.execute(nsApi);

        //Executing sequence block - Start
        //Executing flow - flow
        flowObj.execute(nsApi);

        //logging
        nsApi.ns_end_session();
    }

}