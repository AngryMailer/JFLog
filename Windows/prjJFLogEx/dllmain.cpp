// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"

wstring g_strDBFileDirectoryLog;
volatile BOOL g_bWrite_Debug_Log = FALSE;
wstring g_strDBFileFullPathNameLog;
wstring g_strIniConfigFileName;

volatile BOOL g_bHaveReadIniConfig = FALSE;		//是否读取了 INI 配置文件

wstring g_strDllCurrentDirectory;		//当前目录

#include "Log.h"

#include "..\PubClass\StaticPubFunc.h"


bool InitData(wstring & strMsg)
{

	wstring strIniConfigFileName;

	//============================================================================================================
	//如果读取了，不处理此函数
	if(g_bHaveReadIniConfig)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------

	//strIniConfigFileName = CStaticPubFunc::GetCurrentExeFileFullPathName() + L".ini";
	//strIniConfigFileName = CStaticPubFunc::GetCurrentExeFileFullPath() + L"JFLog.ini";
	strIniConfigFileName = CStaticPubFunc::GetCurrentExeFileFullPath() + L"TextLog.ini";
	//strIniConfigFileName = CStaticPubFunc::GetCurrentExeFileFullPathName() + L".ini";

	g_bWrite_Debug_Log = (long)GetPrivateProfileInt(MACRO_STR_INI_FILE_SectionName_GlobalOption, 
													MACRO_STR_INI_FILE_KeyName_WriteDebugLog,
													FALSE,
													strIniConfigFileName.c_str());

	g_bHaveReadIniConfig = true;

	return true;
}

bool WriteLogCString(wstring strLogFileFullPathName, wstring strMsg)
{
	if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------
	bool bReturn = false;
	//============================================================================================================
	//Check Data
	
	if(strLogFileFullPathName.empty() || strMsg.empty())
	{
		return false;
	}

	//------------------------------------------------------------------------------------------------------------

	bReturn = CLog::WriteLog(strLogFileFullPathName, strMsg);
	if(!bReturn)
	{
		return false;
	}
    
	return true;
}

bool WriteLogLPCTSTR(LPCTSTR lpctstrLogFileFullPathName, LPCTSTR lpctstrMsg)
{
    if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------
	bool bReturn = false;

	wstring strLogFileFullPathName;
	wstring strMsg;
	//============================================================================================================
	//Check Data

	strLogFileFullPathName = lpctstrLogFileFullPathName;
	strMsg = lpctstrMsg;
	
	//strLogFileFullPathName.Trim();
	//strMsg.Trim();

	if(strLogFileFullPathName.empty() || strMsg.empty())
	{
		return false;
	}

	//------------------------------------------------------------------------------------------------------------

	bReturn = CLog::WriteLog(strLogFileFullPathName, strMsg);
	if(!bReturn)
	{
		return false;
	}
    
	return true;
}

bool WriteLogLPCSTR(LPCSTR lpcstrLogFileFullPathName, LPCSTR lpcstrMsg)
{
    if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------
	bool bReturn = false;

	wstring strLogFileFullPathName;
	wstring strMsg;

	WCHAR * pwchar = NULL;
	//============================================================================================================
	//Check Data

	if(!lpcstrLogFileFullPathName || !lpcstrMsg)
	{
		return false;
	}

	//------------------------------------------------------------------------------------------
	pwchar = CStaticPubFunc::pcharTopwcharEx(lpcstrLogFileFullPathName);
	if(!pwchar)
	{
		return false;
	}

	strLogFileFullPathName = pwchar;
	if(pwchar)
	{
		delete [] pwchar;
		pwchar = NULL;
	}
	//------------------------------------------------------------------------------------------
	pwchar = CStaticPubFunc::pcharTopwcharEx(lpcstrMsg);
	if(!pwchar)
	{
		return false;
	}

	strMsg = pwchar;
	if(pwchar)
	{
		delete [] pwchar;
		pwchar = NULL;
	}
	//------------------------------------------------------------------------------------------
	//strLogFileFullPathName.Trim();
	//strMsg.Trim();

	if(strLogFileFullPathName.empty() || strMsg.empty())
	{
		return false;
	}

	//------------------------------------------------------------------------------------------------------------

	bReturn = CLog::WriteLog(strLogFileFullPathName, strMsg);
	if(!bReturn)
	{
		return false;
	}
    
	return true;
}

bool WriteLogBinaryLPCTSTR(LPCTSTR lpctstrLogFileFullPathName, BYTE * pbyteBuffer, DWORD dwBufferLength)
{
    if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------
	bool bReturn = false;

	wstring strLogFileFullPathName;
	wstring strMsg;
	//============================================================================================================
	//Check Data
	
	strLogFileFullPathName = lpctstrLogFileFullPathName;

	if(strLogFileFullPathName.empty())
	{
		return false;
	}

	if(dwBufferLength <= 0 || !pbyteBuffer)
	{
		return false;
	}

	//------------------------------------------------------------------------------------------------------------

	strMsg = CStaticPubFunc::ChangeBinaryToString(pbyteBuffer, dwBufferLength);

	//strMsg.Trim();

	if(strMsg.empty())
	{
		return false;
	}

	//------------------------------------------------------------------------------------------------------------
	bReturn = CLog::WriteLog(strLogFileFullPathName, strMsg);
	if(!bReturn)
	{
		return false;
	}
    
	return true;
}

bool WriteLogBinaryLPCSTR(LPCSTR lpcstrLogFileFullPathName, BYTE * pbyteBuffer, DWORD dwBufferLength)
{
    if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------
	bool bReturn = false;

	wstring strLogFileFullPathName;
	wstring strMsg;

	WCHAR * pwchar = NULL;
	//============================================================================================================
	//Check Data
	
	if(!lpcstrLogFileFullPathName || dwBufferLength <= 0 || !pbyteBuffer)
	{
		return false;
	}

	//------------------------------------------------------------------------------------------
	pwchar = CStaticPubFunc::pcharTopwcharEx(lpcstrLogFileFullPathName);
	if(!pwchar)
	{
		return false;
	}

	strLogFileFullPathName = pwchar;
	if(pwchar)
	{
		delete [] pwchar;
		pwchar = NULL;
	}

	//------------------------------------------------------------------------------------------------------------

	strMsg = CStaticPubFunc::ChangeBinaryToString(pbyteBuffer, dwBufferLength);
	
	if(strMsg.empty())
	{
		return false;
	}

	//------------------------------------------------------------------------------------------------------------
	bReturn = CLog::WriteLog(strLogFileFullPathName, strMsg);
	if(!bReturn)
	{
		return false;
	}
    
	return true;
}

bool WriteLogBinary(LPCSTR lpcstrLogFileFullPathName, BYTE * pbyteBuffer, DWORD dwBufferLength)
{
    if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------
	bool bReturn = false;

	wstring strLogFileFullPathName;
	wstring strMsg;

	WCHAR * pwchar = NULL;
	//============================================================================================================
	//Check Data
	
	if(!lpcstrLogFileFullPathName || !pbyteBuffer || dwBufferLength <= 0)
	{
		return false;
	}

	//------------------------------------------------------------------------------------------
	pwchar = CStaticPubFunc::pcharTopwcharEx(lpcstrLogFileFullPathName);
	if(!pwchar)
	{
		return false;
	}

	strLogFileFullPathName = pwchar;
	if(pwchar)
	{
		delete [] pwchar;
		pwchar = NULL;
	}
	//------------------------------------------------------------------------------------------------------------
	bReturn = CLog::WriteLog(strLogFileFullPathName, pbyteBuffer, dwBufferLength);
	if(!bReturn)
	{
		return false;
	}
    
	return true;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			//------------------------------------------------------------------------------------------------------------
			wstring strMsg;
			bool bReturn = false;
	
			bReturn = InitData(strMsg);
			if(!bReturn)
			{
		
			}

			//------------------------------------------------------------------------------------------------------------
		}
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

