#include <sys/types.h>
#include <unistd.h>

#include <sstream>
using namespace std;

#include "Log.h"

#include "LogText.h"
//#include "LogSQLiteRobGrovesTryShell.h"

#include "../PubClass/StaticPubFunc.h"

//volatile extern wstring g_strDBFileDirectoryLog;
volatile extern bool g_bWrite_Debug_Log;

#include <sys/syscall.h>

#define gettid()   syscall(__NR_gettid)

#include <pthread.h>

CLog::CLog(void)
{
}

CLog::~CLog(void)
{
}

bool CLog::WriteLog(string stringLogFileFullPathName,
					string stringLog,
					int iTimeOutToWrite)
{
	if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	string stringLogFileFullPathNameEx;
	string stringLogFile_ExtendName;
	bool bReturn;

	string stringCurrentDate;

	char szcharCurrentTime[50];

	char szcharMsg[260];

	ostringstream ostringstreamThis;

	//pid_t pid_t_this = 0;
	//=============================================================================

	bReturn = CStaticPubFunc::GetCurrentTimeAllDigitEx((char*)szcharCurrentTime, (char*)szcharMsg, eiTimeTypeDateHour);

	stringCurrentDate = szcharCurrentTime;

	//pthread_t pthread_self(void);

#if 1

	stringLogFile_ExtendName = "data";
	//stringLogFile_ExtendName = "log";

	ostringstreamThis<<stringLogFileFullPathName;
	ostringstreamThis<<".";
	ostringstreamThis<<stringCurrentDate;
	ostringstreamThis<<".";
	ostringstreamThis<<getpid();
	ostringstreamThis<<".";
	ostringstreamThis<<gettid();
	//ostringstreamThis<<pthread_self();
	ostringstreamThis<<".";
	ostringstreamThis<<stringLogFile_ExtendName;

	stringLogFileFullPathNameEx = ostringstreamThis.str();
			
	bReturn = CStaticPubFunc::CreateMultiLevelDirectoryEx((char*)stringLogFileFullPathNameEx.c_str());
	if(!bReturn)
	{
		
	}

	bReturn = CLogText::WriteLog(stringLogFileFullPathNameEx,
								 stringLog,
								 iTimeOutToWrite);
	if(!bReturn)
	{
		
	}

#else
	//SQLite ��־

	stringLogFile_ExtendName = L"db";

	stringLogFileFullPathNameEx.Format(L"%s.%s.%d.%d.%s",
								  stringLogFileFullPathName,
								  stringCurrentDate,
								  GetCurrentProcessId(),
								  GetCurrentThreadId(),
								  stringLogFile_ExtendName);
		
	bReturn = CStaticPubFunc::CreateMultiLevelDirectoryEx(stringLogFileFullPathNameEx);
	if(!bReturn)
	{
		
	}

	bReturn = CLogSQLiteRobGrovesTryShell::WriteLog(stringLogFileFullPathNameEx,
												    stringLog,
													iTimeOutToWrite);
	if(!bReturn)
	{
		
	}
	
#endif

	return true;
}


bool CLog::WriteLog(string stringLogFileFullPathName,
					char * pbyteBuffer,
					long dwBufferLength,
					int iTimeOutToWrite)
{
	if(!g_bWrite_Debug_Log)
	{
		return true;
	}

	string stringLogFileFullPathNameEx;
	string stringLogFile_ExtendName;
	bool bReturn;

	string stringCurrentDate;

	char szcharCurrentTime[50];

	char szcharMsg[260];

	ostringstream ostringstreamThis;
	//=============================================================================

	bReturn = CStaticPubFunc::GetCurrentTimeAllDigitEx((char*)szcharCurrentTime, (char*)szcharMsg, eiTimeTypeDateHour);

	stringCurrentDate = szcharCurrentTime;

#if 1
	//文本日志

	stringLogFile_ExtendName = "data";
	//stringLogFile_ExtendName = "log";

	ostringstreamThis<<stringLogFileFullPathName;
	ostringstreamThis<<".";
	ostringstreamThis<<stringCurrentDate;
	ostringstreamThis<<".";
	ostringstreamThis<<getpid();
	ostringstreamThis<<".";
	ostringstreamThis<<gettid();
	//ostringstreamThis<<pthread_self();
	ostringstreamThis<<".";
	ostringstreamThis<<stringLogFile_ExtendName;

	stringLogFileFullPathNameEx = ostringstreamThis.str();

	bReturn = CStaticPubFunc::CreateMultiLevelDirectoryEx((char*)stringLogFileFullPathNameEx.c_str());
	if(!bReturn)
	{

	}

	bReturn = CLogText::WriteLog(stringLogFileFullPathNameEx,
								 pbyteBuffer,
								 dwBufferLength,
								 iTimeOutToWrite);
	if(!bReturn)
	{

	}

#else
	//SQLite 日志

	stringLogFile_ExtendName = L"db";

	stringLogFileFullPathNameEx.Format(L"%s.%s.%d.%d.%s",
								  stringLogFileFullPathName,
								  stringCurrentDate,
								  GetCurrentProcessId(),
								  GetCurrentThreadId(),
								  stringLogFile_ExtendName);

	bReturn = CStaticPubFunc::CreateMultiLevelDirectoryEx(stringLogFileFullPathNameEx);
	if(!bReturn)
	{

	}

	bReturn = CLogSQLiteRobGrovesTryShell::WriteLog(stringLogFileFullPathNameEx,
												    stringLog,
													iTimeOutToWrite);
	if(!bReturn)
	{

	}

#endif

	return true;
}



