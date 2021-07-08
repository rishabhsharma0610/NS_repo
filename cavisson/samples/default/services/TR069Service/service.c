#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hpd_log.h"
#include "hpd_string_api.h"
#include <errno.h>
#include <unistd.h>

#define MAX_TR069_RESP_TYPE_FLOW1 7
#define MAX_TR069_RESP_TYPE_FLOW2 13 

#define INFORM_RESP_FILE_IDX 0
#define TRANS_COMP_RESP_FILE_IDX 1

#define TR069_SPECIFIC_METHOD_SIZE 27 

//These macros are for service mode 
#define TR069_SERVICE_MODE_RANDOM 	0
#define TR069_SERVICE_MODE_SEQUENTIAL	1
#define TR069_SERVICE_MODE_SPECIFIC 	2
#define TR069_SERVICE_MODE_ONLY_ONE 	3

#if 0
/*tr069RespTypes & tr069RespFileName must be in sink*/
char *tr069RespTypes[12]  =   
{ "GetInform",
  "GetParameterAttribute",
  "GetRPCMethodsResponse",
  "SetParameterValueResponse",
  "DeleteObjectResponse",
  "SetParameterAttributeResponse",
  "AddObjectResponse",
  "GetParameterNameResponse",
  "GetParameterAttributeResponse",
  "Download"
  "Reboot"
  "EmptyPost"
};
#endif

char *tr069RespFileNameFlow1[MAX_TR069_RESP_TYPE_FLOW1]  =
{
  "/home/cavisson/work/etc/tr069/samples/tr069_inform_rep.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_transfer_complete_rep.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_values_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_download_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_reboot_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_empty_file.xml"
};


char *tr069RespFileNameFlow2[MAX_TR069_RESP_TYPE_FLOW2]  =   
{ 
  "/home/cavisson/work/etc/tr069/samples/tr069_inform_rep.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_transfer_complete_rep.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_get_rpc_methods_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_values_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_names_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_attributes_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_attributes_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_add_object_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_delete_object_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_download_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_reboot_req.xml",
  "/home/cavisson/work/etc/tr069/samples/tr069_empty_file.xml"
};

typedef struct 
{
  char specific_rpc[256];
  char file_name[1024];
} tr069_specific_methods;

static tr069_specific_methods tr069_specific_methods_list[TR069_SPECIFIC_METHOD_SIZE] = {
  {"SPV_1P",			"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_1param_req.xml"},
  {"SPV_2P",			"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_2param_req.xml"},
  {"SPV_10P",			"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_10param_req.xml"},
  {"SPV_20P",			"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_20param_req.xml"},
  {"SPV_INVALID_1P",		"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_invalid_1param_req.xml"},
  {"SPV_INVALID_2P",		"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_invalid_2param_req.xml"},
  {"GPV_ROOT",			"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_values_root_req.xml"},
  {"GPV_FULL",			"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_values_full_path_req.xml"},
  {"GPV_PART",			"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_values_part_req.xml"},
  {"GPV_FULL_PART",		"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_values_full_part_path_req.xml"},
  {"GPV_MULTIPLE",		"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_values_multiple_param_req.xml"},
  {"GPA_1P",			"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_attributes_1param_req.xml"},
  {"GPA_2P",			"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_attributes_2param_req.xml"},
  {"GPA_10P",			"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_attributes_10param_req.xml"},
  {"GPA_PART",			"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_attributes_part_path_req.xml"},
  {"GPA_INVALID_1P",		"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_attributes_invalid_1param_req.xml"},
  {"GPA_INVALID_2P",		"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_attributes_invalid_2param_req.xml"},
  {"GPA_EMPTY",			"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_attributes_empty_req.xml"},
  {"SPA_1P",			"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_attributes_1param_req.xml"},
  {"SPA_2P",			"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_attributes_2param_req.xml"},
  {"SPA_10P",			"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_attributes_10param_req.xml"},
  {"SPA_PART",			"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_attributes_part_path_req.xml"},
  {"SPA_INVALID_1P",		"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_attributes_invalid_1param_req.xml"},
  {"SPA_INVALID_2P",		"/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_attributes_invalid_2param_req.xml"},
  {"GPN_FULL",			"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_names_full_path_req.xml"},
  {"GPN_PART",			"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_names_part_path_req.xml"},
  {"GPN_INVALID",		"/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_names_invalid_req.xml"}
};

static int get_tr069RespFileName_index(int arr_size) {

  int reply_file_idx;
  //char *rand_num;

  HPDDL2_CR(NULL, "method called");
  reply_file_idx = ns_get_random_num_int(2, arr_size - 1);

  return reply_file_idx;
}

static inline void check_and_set_mode(int *mode, char *rpc_method)
{
int ret;
*mode = TR069_SERVICE_MODE_RANDOM;
char query_val[4096];
  ret = ns_get_url_query_param_val("RPCMode", query_val, HPD_CODE_NONE);
  HPDDL4_CR(NULL, "query_val = %s", query_val);
  if(ret >= 0) {
    HPDDL4_CR(NULL, "ret = %d", ret);
    if(!strcmp("Sequential", query_val)){
      HPDDL4_CR(NULL, "mode is sequential");
      *mode = TR069_SERVICE_MODE_SEQUENTIAL;
    }
    else if(!strcmp("Specific", query_val)){
      HPDDL4_CR(NULL, "mode is specific");
      *mode = TR069_SERVICE_MODE_SPECIFIC;
      ret = ns_get_url_query_param_val("RPCMethod", rpc_method, HPD_CODE_NONE);
      if(ret >= 0){
        HPDDL2_CR(NULL, "rpc_method = [%s]", rpc_method);
        HPDDL2_CR(NULL, "RPCMethod found");
      } 
    }
    else if(!strcmp("OnlyOne", query_val)){
      HPDDL4_CR(NULL, "mode is OnlyOne");
      *mode = TR069_SERVICE_MODE_ONLY_ONE;
    }
  }
}

char *set_resp_for_spv()
{
char inform_var[1024];
int ret;
  HPDDL2_CR(NULL, "method called");
  ret = ns_get_url_query_param_val("INFORM", inform_var, HPD_CODE_NONE);
  if(ret >= 0){
    HPDDL4_CR(NULL, "INFORM found. value = %d", inform_var);
    if(!strcmp(inform_var, "1"))
      return "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req1.xml";
    else if(!strcmp(inform_var, "2"))
      return "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req2.xml";
    else if(!strcmp(inform_var, "3"))
      return "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req3.xml";
    else if(!strcmp(inform_var, "4"))
      return "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req4.xml";
  }
  else
    return "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req.xml";
}

 
static char *get_spec_file(char *rpc_method)
{
int file_index;
  HPDDL2_CR(NULL, "method called");
  if(!strcmp("SPV", rpc_method)){
    return "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req.xml"; 
  }  
  else if(!strcmp("GPV", rpc_method)){
    return "/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_values_req.xml";
  }
  else if(!strcmp("GPN", rpc_method)){
    return "/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_names_req.xml"; 
  }
  else if(!strcmp("SPA", rpc_method)){
    return "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_attributes_req.xml";
  }
  else if(!strcmp("GPA", rpc_method)){
    return "/home/cavisson/work/etc/tr069/samples/tr069_get_parameter_attributes_req.xml"; 
  }
  else if(!strcmp("ADD_OBJ", rpc_method)){
    return "/home/cavisson/work/etc/tr069/samples/tr069_add_object_req.xml";
  }
  else if(!strcmp("DEL_OBJ", rpc_method)){
    return "/home/cavisson/work/etc/tr069/samples/tr069_delete_object_req.xml";
  }
  else if(!strcmp("DOWNLOAD", rpc_method)){
    return "/home/cavisson/work/etc/tr069/samples/tr069_download_req.xml";
  }
  else if(!strcmp("REBOOT", rpc_method)){
    return "/home/cavisson/work/etc/tr069/samples/tr069_reboot_req.xml";
  }
  else {
    HPDDL2_CR(NULL, "Entered in else"); 
    int idx;
    for(idx = 0; idx < TR069_SPECIFIC_METHOD_SIZE; idx++)
    { 
      HPDDL2_CR(NULL, "searching for file");
      if(!strcmp(tr069_specific_methods_list[idx].specific_rpc, rpc_method)){
        HPDDL4_CR(NULL, "file name returned = [%s]", tr069_specific_methods_list[idx].file_name);
        return tr069_specific_methods_list[idx].file_name;
      }
    }
  }
    
}
  
int TR069Service_on_request_callback() 
{
  char rpc_method[4096]; 
  static int FileIndex = 0;
  int req_size;
  char *request_buf;
  char *IsInformVarVal = NULL;
  char *IsTransferComplete = NULL;
  //char *tmp = NULL;
  char *tmp1;
  int mode;
  char *file_name;
  char flow_passed[1024];
  char **flow;
  int ret;
  int arr_size = MAX_TR069_RESP_TYPE_FLOW1; 

  HPDDL2_CR(NULL, "Method called");
  check_and_set_mode(&mode, rpc_method);
  HPDDL2_CR(NULL, "mode = %d", mode);
  flow = tr069RespFileNameFlow1;
  if(mode == TR069_SERVICE_MODE_RANDOM || mode == TR069_SERVICE_MODE_SEQUENTIAL){
    ret = ns_get_url_query_param_val("FLOW", flow_passed, HPD_CODE_NONE);
    if(ret >= 0){
      if(!strcmp(flow_passed, "flow2")){
        flow = tr069RespFileNameFlow2;
        arr_size = MAX_TR069_RESP_TYPE_FLOW2;
      }
    }
  }
  
  FileIndex = ns_get_int_val("file_index_param");
  
  if(FileIndex == TRANS_COMP_RESP_FILE_IDX){
    FileIndex++;
    ns_set_int_val ("file_index_param", FileIndex);
    file_name = "/home/cavisson/work/etc/tr069/samples/tr069_empty_file.xml";
    ns_save_value_from_file(file_name, "tr069RespBodyVar");
    return -1;
  }  
  request_buf = ns_get_request_buf(&req_size);
  HPDDL4_CR(NULL, "Request Size = %d", req_size);
  HPDDL4_CR(NULL, "request_buf = [%s]", request_buf);
  
  IsInformVarVal = strstr(request_buf, "<cwmp:Inform>");
  //tmp = strstr(request_buf, "</cwmp:Inform>"); 

  IsTransferComplete = strstr(request_buf, "<cwmp:TransferComplete>");
  tmp1 = strstr(request_buf, "</cwmp:TransferComplete>");
 
  // If Inform request is coming, then this will not be empty
  //if(IsInformVarVal && tmp) // Not empty
  if(IsInformVarVal) // Not empty
  {
    FileIndex = INFORM_RESP_FILE_IDX;
    file_name = flow[FileIndex];
    HPDDL2_CR(NULL, "FileIndex = %d, Sending Inform Response", FileIndex); 
  }
   else if(IsTransferComplete && tmp1) // Not empty
  {
    FileIndex = TRANS_COMP_RESP_FILE_IDX;
    file_name = flow[FileIndex];
    HPDDL2_CR(NULL, "FileIndex = %d, Sending Transfer Complete Response", FileIndex);  
  }
  else{
    if(mode == TR069_SERVICE_MODE_RANDOM){
      FileIndex = get_tr069RespFileName_index(arr_size);
      HPDDL4_CR(NULL, "Random FileIndex = %d", FileIndex);
      file_name = flow[FileIndex];
      if(!strcmp(file_name, "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req.xml"))
        file_name = set_resp_for_spv();
        
    }
    else if(mode == TR069_SERVICE_MODE_SEQUENTIAL){
      HPDDL4_CR(NULL, "FileIndex = %d", FileIndex);
      if(FileIndex == INFORM_RESP_FILE_IDX){
        FileIndex = FileIndex + 2;
        HPDDL4_CR(NULL, "FileIndex = %d", FileIndex);
      }
      else{
        FileIndex++;
        if(FileIndex == 13) FileIndex = 0;
      }
        file_name = flow[FileIndex];
        if(!strcmp(file_name, "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req.xml"))
          file_name = set_resp_for_spv();
    }
    else if(mode == TR069_SERVICE_MODE_SPECIFIC){
      if(FileIndex == 0){
        FileIndex = FileIndex + 2;
        file_name = get_spec_file(rpc_method);
        if(!strcmp(file_name, "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req.xml"))
          file_name = set_resp_for_spv();
       }
      else
        file_name = "/home/cavisson/work/etc/tr069/samples/tr069_empty_file.xml";
    }
    else if(mode == TR069_SERVICE_MODE_ONLY_ONE){
      if(FileIndex == 0){
        FileIndex = get_tr069RespFileName_index(arr_size - 1);
        HPDDL4_CR(NULL, "Random FileIndex = %d", FileIndex);
        file_name = flow[FileIndex];
        if(!strcmp(file_name, "/home/cavisson/work/etc/tr069/samples/tr069_set_parameter_values_req.xml"))
          file_name = set_resp_for_spv();
      }
      else 
        file_name = "/home/cavisson/work/etc/tr069/samples/tr069_empty_file.xml";
    } 

  }
  HPDDL2_CR(NULL, "FileIndex = %d", FileIndex);
  ns_set_int_val ("file_index_param", FileIndex);

  ns_save_value_from_file(file_name, "tr069RespBodyVar");
   
  return -1; // Return -1 to use service time as per keyword
}
    

