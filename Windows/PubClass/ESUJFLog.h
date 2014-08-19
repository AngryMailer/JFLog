#pragma once

//------------------------------------------------------------------------------------------
//花指令

#if 0

#if 1

//#define MACRO_STR_JunkCode_001

#else

#define MACRO_STR_JunkCode_001\
		__asm\
		{\
		}
#endif

#define MACRO_STR_JunkCode_002\
		__asm\
		{\
		}

#define MACRO_STR_JunkCode_003\
		__asm\
		{\
		}

#define MACRO_STR_JunkCode_004\
		__asm\
		{\
		}

#define MACRO_STR_JunkCode_005\
		__asm\
		{\
		}

#endif

//------------------------------------------------------------------------------------------
//防调试



//------------------------------------------------------------------------------------------

//写文本文件，一次写多少行文本
//每次事务执行的语句数量不能超过 51087

//#define MACRO_INT_The_Count_Of_Line_To_Write_Per_Time		10000 * 100
#define MACRO_INT_The_Count_Of_Line_To_Write_Per_Time		10000
//#define MACRO_INT_The_Count_Of_Line_To_Write_Per_Time		40000


//多少条 SQL 语句执行一次
#define MACRO_INT_The_Count_Of_SQL_To_Execute_Per_Time		500000
//#define MACRO_INT_The_Count_Of_SQL_To_Execute_Per_Time		200000
//#define MACRO_INT_The_Count_Of_SQL_To_Execute_Per_Time		50000
//#define MACRO_INT_The_Count_Of_SQL_To_Execute_Per_Time		10000
//#define MACRO_INT_The_Count_Of_SQL_To_Execute_Per_Time		5000


//---------------------------------------------------------------------------------
//程序语言


#define		MACRO_INT_IDR_INI_Laguage	IDR_INI_Language
#define		MACRO_INT_IDR_TEXT_Protocol	IDR_TEXT_Protocol

#if 0

//中文简体
#define		MACRO_STR_Local_Laguage		"chinese-simplified"
//#define		MACRO_STR_Local_Laguage		"chs"

#elif 0

//中文繁体
#define		MACRO_STR_Local_Laguage		"chinese-traditional"
//#define		MACRO_STR_Local_Laguage		"cht"

#else

//英文
#define		MACRO_STR_Local_Laguage		"english"

#endif



//---------------------------------------------------------------------------------

//程序 分 试用版 和 正式版
enum enumVersion
{
	eiVersionTrial,			//试用版
	eiVersionOfficial,		//正式版
};

//---------------------------------------------------------------------------------

//正式版 分 已授权正式版 和 未授权正式版
enum enumVersionOfficial
{
	eiVersionOfficial_Authorized,		//已授权
	eiVersionOfficial_Unauthorized,		//未授权
};

//---------------------------------------------------------------------------------

//是否试用版
//试用版要把很多代码弄掉，不编译到程序里，用 #if 开关 把代码屏蔽掉

//#define MACRO_BOOL_Is_Trial_Version		TRUE
#define MACRO_BOOL_Is_Trial_Version		FALSE

//---------------------------------------------------------------------------------
//虚拟列表刷新延迟：5 秒
//不能太长，太长的话，正在发送状态就看不到了，要 < 100 毫秒
//#define MACRO_INT_Virtual_List_Refresh_Time_Delay		1 * 10
#define MACRO_INT_Virtual_List_Refresh_Time_Delay		2 * 1000


#define MACRO_INT_SQLite_Time_Out		1000 * 60 * 60
//---------------------------------------------------------------------------------

#define MACRO_INT_Timer_Update_MSN_Information		1000 * 60 * 5

//上传 本地 信息 到 服务器 时间延时
#define MACRO_INT_Timer_UploadLocalInformationToServer		1000 * 60 * 60
//#define MACRO_INT_Timer_UploadLocalInformationToServer		1000 * 60 * 30
//#define MACRO_INT_Timer_UploadLocalInformationToServer		1000 * 60 * 5

//For Example :		http://news.baidu.com/ns?cl=2&rn=20&tn=news&word=HackerJLY

//Server
//#define MACRO_STR_HTTP_Server_URL_Or_IP		L"HackerJLY.vicp.net"
//#define MACRO_STR_HTTP_Server_URL_Or_IP		L"HackerJLYMailer.vicp.cc"
//#define MACRO_STR_HTTP_Server_URL_Or_IP		L"HackerJLY.dns.ipcam.so"
//#define MACRO_STR_HTTP_Server_URL_Or_IP		L"HackerJLY.ym6.cn"
#define MACRO_STR_HTTP_Server_URL_Or_IP		L"HackerJLY.dnsdynamic.com"

#define MACRO_STR_HTTP_Server_Port			L"6688"

#define MACRO_STR_HTTP_UploadLocalInfo_GET_Method_Name_UploadLocalInfo		L"CGI/UploadCustomerPCInfo.exe"
//Local Info
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_OSName			L"OSName"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_OSVersion			L"OSVersion"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_OSLanguage		L"OSLanguage"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_LocalIP			L"LocalIP"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_PublicIP			L"PublicIP"

#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_ComputerName		L"ComputerName"

#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_PEName			L"PEName"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_PEVersion			L"PEVersion"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_PELanguage		L"PELanguage"

//Hardware Info
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_BIOSSN			L"BIOSSN"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_CPUID				L"CPUID"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_HardDiskModel		L"HardDiskModel"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_HardDiskSN		L"HardDiskSN"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_MainboardModel		L"MainboardModel"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_MainboardSN		L"MainboardSN"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_NetworkCardMacAddress		L"NetworkCardMacAddress"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_NetworkCardMacAddressOriginal		L"NetworkCardMacAddressOriginal"
//
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_PEVersionType		L"PEVersionType"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_RegisterCode		L"RegisterCode"

#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_FileMD5			L"FileMD5"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_FileSize			L"FileSize"

#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_VMPUserName		L"vUserName"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_VMPEMail			L"vEMail"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_VMPDateExpire		L"vDateExpire"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_VMPDateMaxBuild	L"vDateMaxBuild"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_VMPRunningTime	L"vRunningTime"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_VMPUserData		L"vUserData"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_VMPState			L"vState"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_VMPHardwareInfo	L"vHarewareInfo"
#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_MachineCode		L"MachineCode"

#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_CompileDateTime	L"CompileDateTime"

#define MACRO_STR_HTTP_UploadLocalInfo_GET_Parameter_Name_			L""


//---------------------------------------------------------------------------------

#define MACRO_INT_SQLite_TimeOut_Thread_UI			1000 * 3

#define MACRO_INT_SQLite_TimeOut_Thread_UI_FillDataToVirtual	1000 * 1

#define MACRO_INT_SQLite_TimeOut_Thread_UI_UpdateSendStatus		1000 * 1

#define MACRO_INT_SQLite_TimeOut_Thread_Worker		1000 * 60 * 10

#define MACRO_INT_SQLite_TimeOut_WriteLog			1000 * 3

//------------------------------------------------------------------------------------

//#define MACRO_STR_BEGIN_TRANSACTION			"BEGIN DEFERRED TRANSACTION"
#define MACRO_STR_BEGIN_TRANSACTION			"BEGIN IMMEDIATE TRANSACTION"
//#define MACRO_STR_BEGIN_TRANSACTION			"BEGIN EXCLUSIVE TRANSACTION"

//------------------------------------------------------------------------------------

#define MACRO_STR_INI_FILE_SectionName_GlobalOption			L"GeneralOption"

#define MACRO_STR_INI_FILE_KeyName_AccountChangeMode		L"AccountChangeMode"

#define MACRO_STR_INI_FILE_KeyName_AccountDomainNameFailedCountMaxByCommon		L"AccountDomainNameFailedCountMaxByCommon"

#define MACRO_STR_INI_FILE_KeyName_IsShutdownPCWhenComplete		L"IsShutdownPCWhenComplete"

#define MACRO_STR_INI_FILE_KeyName_EMailDomainNameFailedCountMaxByEMS		L"EMailDomainNameFailedCountMaxByEMS"
#define MACRO_STR_INI_FILE_KeyName_TopMost			L"TopMost"
#define MACRO_STR_INI_FILE_KeyName_SendIntervalMin		L"SendIntervalMin"
#define MACRO_STR_INI_FILE_KeyName_SendIntervalMax	L"SendIntervalMax"
#define MACRO_STR_INI_FILE_KeyName_ReceiverCountPerTimeMin		L"ReceiverCountPerTime"

#define MACRO_STR_INI_FILE_KeyName_ReceiverCountPerTimeMax		L"ReceiverCountPerTimeMax"

#define MACRO_STR_INI_FILE_KeyName_ReceiverCountPerTimeMax		L"ReceiverCountPerTimeMax"
#define MACRO_STR_INI_FILE_KeyName_FailedCountChangeAccount		L"FailedCountChangeAccount"
#define MACRO_STR_INI_FILE_KeyName_AccountChangeMode		L"AccountChangeMode"
#define MACRO_STR_INI_FILE_KeyName_SendMode		L"SendMode"
#define MACRO_STR_INI_FILE_KeyName_TimeOutOfWaitingForServerAccountDomainNameFailedCountMaxByCommon		L"TimeOutOfWaitingForServerAccountDomainNameFailedCountMaxByCommon"
#define MACRO_STR_INI_FILE_KeyName_TimeOutOfWaitingForServer		L"TimeOutOfWaitingForServer"
#define MACRO_STR_INI_FILE_KeyName_AccountDomainNameFailedCountMaxByCommon		L"AccountDomainNameFailedCountMaxByCommon"
#define MACRO_STR_INI_FILE_KeyName_AccountDomainNameSendCountPerTimeMaxByCommon		L"AccountDomainNameSendCountPerTimeMaxByCommon"

#define MACRO_STR_INI_FILE_KeyName_ColorBackGround		L"ColorBackGround"
#define MACRO_STR_INI_FILE_KeyName_ColorForeGround		L"ColorForeGround"

#define MACRO_STR_INI_FILE_KeyName_SenderCurrent		L"SenderCurrent"
#define MACRO_STR_INI_FILE_KeyName_Language		L"Language"
#define MACRO_STR_INI_FILE_KeyName_IsMailBoxBomb		L"IsMailBoxBomb"
#define MACRO_STR_INI_FILE_KeyName_ThreadCountSendMail		L"ThreadCountSendMail"
#define MACRO_STR_INI_FILE_KeyName_EMailDomainNameSendCountPerTimeMaxByEMS		L"EMailDomainNameSendCountPerTimeMaxByEMS"
#define MACRO_STR_INI_FILE_KeyName_ContinuousSendFailedCountMax		L"ContinuousSendFailedCountMax"

#define MACRO_INT_Default_Value_ContinuousSendFailedCountMax		500

#define MACRO_STR_INI_FILE_KeyName_WriteDebugLog		L"WriteDebugLog"
#define MACRO_STR_INI_FILE_KeyName_		L""
#define MACRO_STR_INI_FILE_KeyName_		L""

//更新列表框数据时间间隔
#define MACRO_INT_UpdateDataVirtualListCtrl_Time_Interval		2 * 1000

//读文件超时
#define MACRO_INT_Time_Out_ReadFile		2 * 60 * 1000

//ListCtrl 查找 Item 等待时间
#define MACRO_INT_FindItem_WaitTime		2 * 1000
//ListCtrl 查找 Item 重新查找次数
#define MACRO_INT_FindItem_Retry_Times	1
//-----------------------------------------------------------------------------
//延时 - 

#define MACRO_INT_Time_Delay_FillDataToVirtualList_SetItemCountEx	5 * 1000

#define MACRO_INT_Time_Delay_UpdateDataListCtrl	1 * 1000

#define MACRO_INT_Time_Delay_CheckListCtrlLinkmanItemRangeChange	2 * 1000

#define MACRO_INT_Time_Delay_UpdateSendStatus	10 * 1000

#define MACRO_INT_Time_Delay_CheckThreadCountSendMail	5 * 1000

//-----------------------------------------------------------------------------

#define MACRO_INT_Time_Out_UpdateDataListCtrl	1000 * 10

//-----------------------------------------------------------------------------

#define MACRO_STR_Event_Name_FillDataToVirtualListAccount		L"FillDataToVirtualListAccount%s"
#define MACRO_STR_Event_Name_UpdateDataListCtrlAccount			L"UpdateDataListCtrlAccount%s"

#define MACRO_STR_Event_Name_FillDataToVirtualListLinkman		L"FillDataToVirtualListLinkman%s"
#define MACRO_STR_Event_Name_UpdateDataListCtrlLinkman			L"UpdateDataListCtrlLinkman%s"

#define MACRO_STR_Event_Name_FillDataToVirtualListReceiver		L"FillDataToVirtualListReceiver%s"
#define MACRO_STR_Event_Name_UpdateDataListCtrlReceiver			L"UpdateDataListCtrlReceiver%s"

#define MACRO_STR_Event_Name_UpdateSendStatus		L"UpdateSendStatus%s"


#define MACRO_INT_Default_Value_Thread_Count_Send_Mail		5


//查询语言字符串超时
#define MACRO_INT_Time_Out_QueryLanguageString		3 * 1000

//Socket 结束线程等待超时
#define MACRO_INT_Time_Out_Terminate_Thread_Socket			6 * 1000

//-----------------------------------------------------------------------------
//程序版本

#define MACRO_STR_Version		L"1.0.0.1"

//-----------------------------------------------------------------------------

//#define MACRO_BOOL_Account_Password_Encrypt	TRUE
#define MACRO_BOOL_Account_Password_Encrypt	FALSE




class CESUJFLog
{
	
};
