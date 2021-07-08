/*-----------------------------------------------------------------------------
    Name: NsFlow
    Recorded By: cavisson
    Date of recording: 07/07/2021 09:10:35
    Flow details:
    Build details: 4.6.1 (build# 36)
    Modification History:
-----------------------------------------------------------------------------*/

package JAVA_HPDS;
import pacJnvmApi.NSApi;

public interface NsFlow
{
    public final int NS_AUTO_STATUS = -1;
    public final int NS_REQUEST_OK = 0;
    public final int NS_BAD_RESP = 22;
    public final int SUCCESS = 0;
    public final int TxErr64 = 64;
    public final int TxErr65 = 65;
    public final int TxErr66 = 66;
    public final int TxErr67 = 67;
    public final int TxErr68 = 68;
    public final int TxErr69 = 69;
    public final int TxErr70 = 70;
    public final int TxErr71 = 71;
    public final int TxErr72 = 72;
    public final int TxErr73 = 73;
    public final int TxErr74 = 74;
    public final int TxErr75 = 75;
    public final int TxErr76 = 76;
    public final int TxErr77 = 77;
    public final int TxErr78 = 78;
    public final int TxErr79 = 79;
    public final int TxErr80 = 80;
    public final int TxErr81 = 81;
    public final int TxErr82 = 82;
    public final int TxErr83 = 83;
    public final int TxErr84 = 84;
    public final int TxErr85 = 85;
    public final int TxErr86 = 86;
    public final int TxErr87 = 87;
    public final int TxErr88 = 88;
    public final int TxErr89 = 89;
    public final int TxErr90 = 90;
    public final int TxErr91 = 91;
    public final int TxErr92 = 92;
    public final int TxErr93 = 93;
    public final int TxErr94 = 94;
    public final byte NS_TX_CODE_RMI_CALL_EXCEPTION = 95;
    public final String INLINE_URLS = "INLINE_URLS";
    public final String END_INLINE = "END_INLINE";
    public final String BODY_BEGIN = "BODY_BEGIN";
    public final String BODY_END = "BODY_END";
    public final String MULTIPART_BOUNDARY = "MULTIPART_BOUNDARY";
    public final String MULTIPART_BODY_BEGIN = "MULTIPART_BODY_BEGIN";
    public final String MULTIPART_BODY_END = "MULTIPART_BODY_END";
    public int execute(NSApi nsApi) throws Exception;
}