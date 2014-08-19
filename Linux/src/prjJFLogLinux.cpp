//============================================================================
// Name        : prjJFLogLinux.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
//#include <ostringstream>
#include <sstream>

#include <stdlib.h>
#include <wchar.h>


using namespace std;

// dllmain.cpp : 定义 DLL 应用程序的入口点。
//#include "stdafx.h"

string g_strDBFileDirectoryLog;
//volatile bool g_bWrite_Debug_Log = false;
volatile bool g_bWrite_Debug_Log = false;
string g_strDBFileFullPathNameLog;
string g_strIniConfigFileName;

volatile bool g_bHaveReadIniConfig = false;		//是否读取了 INI 配置文件

string g_strDllCurrentDirectory;		//当前目录

#include "Log.h"

#include "../PubClass/StaticPubFunc.h"

class CStaticPubFunc;

#include "inifile.h"


bool InitData(string & strMsg)
{
	string strIniConfigFileName;
	CIniFileA CIniFileAThis;
	bool bReturn = false;
	string stringTemp;
	long lTemp = 0;
	//============================================================================================================
	//如果读取了，不处理此函数
	if(g_bHaveReadIniConfig)
	{
		return true;
	}

	g_bHaveReadIniConfig = true;
	//------------------------------------------------------------------------------------------------------------

	//strIniConfigFileName = CStaticPubFunc::GetCurrentExeFileFullPathName() + L".ini";
	//strIniConfigFileName = CStaticPubFunc::GetCurrentExeFileFullPath() + L"JFLog.ini";
	strIniConfigFileName = CStaticPubFunc::GetCurrentExeFileFullPath() + "TextLog.ini";
	//strIniConfigFileName = CStaticPubFunc::GetCurrentExeFileFullPathName() + L".ini";

	bReturn = CIniFileAThis.Load(strIniConfigFileName);
	if(!bReturn)
	{
		strMsg = "CIniFileAThis.Load failed";
		return false;
	}
	//--------------------------------------------------------------------------------
	stringTemp = CIniFileAThis.GetKeyValue(MACRO_STR_INI_FILE_SectionName_GlobalOption,
										    MACRO_STR_INI_FILE_KeyName_WriteDebugLog);

	//--------------------------------------------------------------------------------

	lTemp = atol(stringTemp.c_str());

	if(0 != lTemp)
	{
		g_bWrite_Debug_Log = true;
	}

	return true;
}

#if 0
bool WriteLogCString(string strLogFileFullPathName, string strMsg)
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
#endif

#if 0
bool WriteLogLPCTSTR(LPCTSTR lpctstrLogFileFullPathName, LPCTSTR lpctstrMsg)
{
    if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------
	bool bReturn = false;

	string strLogFileFullPathName;
	string strMsg;
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
#endif

__attribute ((visibility("default"))) bool WriteLogLPCSTR(char * lpcstrLogFileFullPathName, char * lpcstrMsg)
{
    if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------
	bool bReturn = false;

	string strLogFileFullPathName;
	string strMsg;
	//============================================================================================================
	//Check Data

	if(!lpcstrLogFileFullPathName || !lpcstrMsg)
	{
		return false;
	}

	//------------------------------------------------------------------------------------------
	strLogFileFullPathName = lpcstrLogFileFullPathName;
	strMsg = lpcstrMsg;
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

bool WriteLogBinary(char * lpcstrLogFileFullPathName, char * pbyteBuffer, long dwBufferLength)
{
    if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------
	bool bReturn = false;

	string strLogFileFullPathName;
	string strMsg;

	//WCHAR * pwchar = NULL;
	//============================================================================================================
	//Check Data

	if(!lpcstrLogFileFullPathName || !pbyteBuffer || dwBufferLength <= 0)
	{
		return false;
	}

	//------------------------------------------------------------------------------------------
	strLogFileFullPathName = lpcstrLogFileFullPathName;
	//------------------------------------------------------------------------------------------------------------
	bReturn = CLog::WriteLog(strLogFileFullPathName, pbyteBuffer, dwBufferLength);
	if(!bReturn)
	{
		return false;
	}

	return true;
}

#if 0

bool WriteLogBinaryLPCTSTR(LPCTSTR lpctstrLogFileFullPathName, BYTE * pbyteBuffer, DWORD dwBufferLength)
{
    if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------
	bool bReturn = false;

	string strLogFileFullPathName;
	string strMsg;
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

bool WriteLogBinaryLPCSTR(char * lpcstrLogFileFullPathName, BYTE * pbyteBuffer, DWORD dwBufferLength)
{
    if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	//------------------------------------------------------------------------------------------------------------
	bool bReturn = false;

	string strLogFileFullPathName;
	string strMsg;

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

#endif

#if 0

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
			string strMsg;
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

#endif

int main()
{
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

#if 0

int TestInt()
{
	return 0;
}

bool TestBool()
{
	return true;
}

#endif


__attribute ((constructor)) void initialize(void)
{
    //printf("%s/n", __func__);

	//==============================================================================

	//------------------------------------------------------------------------------------------------------------
	string strMsg;
	bool bReturn = false;

	bReturn = InitData(strMsg);
	if(!bReturn)
	{

	}

	//------------------------------------------------------------------------------------------------------------

	return;
}

__attribute ((destructor)) void finish(void)
{
    //printf("%s/n", __func__);

	//==============================================================================

	return;
}
