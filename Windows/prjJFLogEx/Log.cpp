#include "StdAfx.h"
#include "Log.h"

#include "LogText.h"
//#include "LogSQLiteRobGrovesTryShell.h"

#include "../PubClass/StaticPubFunc.h"

volatile extern wstring g_strDBFileDirectoryLog;
volatile extern BOOL g_bWrite_Debug_Log;

CLog::CLog(void)
{
}

CLog::~CLog(void)
{
}

bool CLog::WriteLog(wstring wstringLogFileFullPathName,
					wstring wstringLog, 
					int iTimeOutToWrite)
{
	if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	wstring wstringLogFileFullPathNameEx;
	wstring wstringLogFile_ExtendName;
	bool bReturn;

	wstring wstringCurrentDate;

	WCHAR szwcharCurrentTime[50];

	WCHAR szwcharMsg[MAX_PATH];

	wostringstream wostringstreamThis;
	//=============================================================================

	bReturn = CStaticPubFunc::GetCurrentTimeAllDigitEx(szwcharCurrentTime, szwcharMsg, eiTimeTypeDateHour, L"_");

	wstringCurrentDate = szwcharCurrentTime;

#if 1
	//文本日志
	
	wstringLogFile_ExtendName = L"data";
	//wstringLogFile_ExtendName = L"log";

	wostringstreamThis<<wstringLogFileFullPathName;
	wostringstreamThis<<L".";
	wostringstreamThis<<wstringCurrentDate;
	wostringstreamThis<<L".";
	wostringstreamThis<<GetCurrentProcessId();
	wostringstreamThis<<L".";
	wostringstreamThis<<GetCurrentThreadId();
	wostringstreamThis<<L".";
	wostringstreamThis<<wstringLogFile_ExtendName;

	wstringLogFileFullPathNameEx = wostringstreamThis.str();
			
	bReturn = CStaticPubFunc::CreateMultiLevelDirectoryEx(wstringLogFileFullPathNameEx.c_str());
	if(!bReturn)
	{
		
	}

	bReturn = CLogText::WriteLog(wstringLogFileFullPathNameEx,
								 wstringLog,
								 iTimeOutToWrite);
	if(!bReturn)
	{
		
	}

#else
	//SQLite 日志

	wstringLogFile_ExtendName = L"db";

	wstringLogFileFullPathNameEx.Format(L"%s.%s.%d.%d.%s",
								  wstringLogFileFullPathName,
								  wstringCurrentDate,
								  GetCurrentProcessId(),
								  GetCurrentThreadId(),
								  wstringLogFile_ExtendName);
		
	bReturn = CStaticPubFunc::CreateMultiLevelDirectoryEx(wstringLogFileFullPathNameEx);
	if(!bReturn)
	{
		
	}

	bReturn = CLogSQLiteRobGrovesTryShell::WriteLog(wstringLogFileFullPathNameEx,
												    wstringLog,
													iTimeOutToWrite);
	if(!bReturn)
	{
		
	}
	
#endif
	
	return true;
}


bool CLog::WriteLog(wstring wstringLogFileFullPathName,
					BYTE * pbyteBuffer, 
					DWORD dwBufferLength,
					int iTimeOutToWrite)
{
	if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	wstring wstringLogFileFullPathNameEx;
	wstring wstringLogFile_ExtendName;
	bool bReturn;

	wstring wstringCurrentDate;

	WCHAR szwcharCurrentTime[50];

	WCHAR szwcharMsg[MAX_PATH];

	wostringstream wostringstreamThis;
	//=============================================================================

	bReturn = CStaticPubFunc::GetCurrentTimeAllDigitEx(szwcharCurrentTime, szwcharMsg, eiTimeTypeDateHour, L"_");

	wstringCurrentDate = szwcharCurrentTime;

#if 1
	//文本日志
	
	wstringLogFile_ExtendName = L"data";
	//wstringLogFile_ExtendName = L"log";

	wostringstreamThis<<wstringLogFileFullPathName;
	wostringstreamThis<<L".";
	wostringstreamThis<<wstringCurrentDate;
	wostringstreamThis<<L".";
	wostringstreamThis<<GetCurrentProcessId();
	wostringstreamThis<<L".";
	wostringstreamThis<<GetCurrentThreadId();
	wostringstreamThis<<L".";
	wostringstreamThis<<wstringLogFile_ExtendName;

	wstringLogFileFullPathNameEx = wostringstreamThis.str();
			
	bReturn = CStaticPubFunc::CreateMultiLevelDirectoryEx(wstringLogFileFullPathNameEx.c_str());
	if(!bReturn)
	{
		
	}

	bReturn = CLogText::WriteLog(wstringLogFileFullPathNameEx,
								 pbyteBuffer,
								 dwBufferLength,
								 iTimeOutToWrite);
	if(!bReturn)
	{
		
	}

#else
	//SQLite 日志

	wstringLogFile_ExtendName = L"db";

	wstringLogFileFullPathNameEx.Format(L"%s.%s.%d.%d.%s",
								  wstringLogFileFullPathName,
								  wstringCurrentDate,
								  GetCurrentProcessId(),
								  GetCurrentThreadId(),
								  wstringLogFile_ExtendName);
		
	bReturn = CStaticPubFunc::CreateMultiLevelDirectoryEx(wstringLogFileFullPathNameEx);
	if(!bReturn)
	{
		
	}

	bReturn = CLogSQLiteRobGrovesTryShell::WriteLog(wstringLogFileFullPathNameEx,
												    wstringLog,
													iTimeOutToWrite);
	if(!bReturn)
	{
		
	}
	
#endif
	
	return true;
}


