//#include "StdAfx.h"
#include "LogText.h"

#include "../PubClass/StaticPubFunc.h"

//#include <afxmt.h>

#include <sstream>
using namespace std;
#include <memory.h>

CLogText::CLogText(void)
{
}

CLogText::~CLogText(void)
{
}


bool CLogText::WriteLog(string stringLogFileFullPathName,
						string stringLog,
						int iTimeOutToWrite)
{
	string stringMsg;
	
	bool bReturn = false;

	string stringCurrentTime;

	string stringLogToWrite;
	
	string stringTemp;

	//bool bSuccessful = false;

	ostringstream ostringstreamThis;

	char szcharCurrentTime[50];

	char szcharMsg[260];
	//===========================================================================================
	//Check Data
	
	if(stringLogFileFullPathName.empty())
	{
		return false;
	}
	
	//stringLog.replace(L"\r\n", L"\t\t");
	//-------------------------------------------------------------------------------------------
	memset(szcharCurrentTime, 0, 50);
	bReturn = CStaticPubFunc::GetCurrentTimeAllDigitEx(szcharCurrentTime, szcharMsg, eiTimeTypeDateTimeMillisecond);
	
	stringCurrentTime = szcharCurrentTime;

	ostringstreamThis<<stringCurrentTime;
	ostringstreamThis<<"\t:\t";
	ostringstreamThis<<stringLog;
	ostringstreamThis<<"\r\n";
	
	stringLogToWrite=ostringstreamThis.str();
	//-------------------------------------------------------------------------------------------
	ostringstreamThis.clear();
	ostringstreamThis<<"CLogText::WriteLog";
	ostringstreamThis<<stringLogFileFullPathName;

	stringTemp = ostringstreamThis.str();
	
	//////stringTemp = CStaticPubFunc::GetStringNoSpecialSymbol(stringTemp);

#if 0

	CSemaphore CSemaphoreThis(1, 1, stringTemp);
	
	bSuccessful = CSemaphoreThis.Lock(iTimeOutToWrite);
	if(!bSuccessful)
	{
		return FALSE;
	}

#endif
	//-------------------------------------------------------------------------------------------

	bReturn = CStaticPubFunc::WriteTextToTxtFileAppendEx((char*)stringLogFileFullPathName.c_str(),
													   (char*)stringLogToWrite.c_str(),
													   (char*)szcharMsg);
	
	//CSemaphoreThis.Unlock();
	
	if(!bReturn)
	{
		return false;
	}	
	
	return true;
}


bool CLogText::WriteLog(string stringLogFileFullPathName,
						char * pbyteBuffer,
						long dwBufferLength,
						int iTimeOutToWrite)
{
	string stringMsg;

	bool bReturn;

	string stringCurrentTime;

	string stringLogToWrite;

	string stringTemp;

	bool bSuccessful;

	wostringstream wostringstreamThis;

	char szcharCurrentTime[50];

	char szcharMsg[260];
	//===========================================================================================
	//Check Data

	if(stringLogFileFullPathName.empty() || !pbyteBuffer || 0 == dwBufferLength)
	{
		return false;
	}

#if 0

	CSemaphore CSemaphoreThis(1, 1, stringTemp);

	bSuccessful = CSemaphoreThis.Lock(iTimeOutToWrite);
	if(!bSuccessful)
	{
		return FALSE;
	}

#endif
	//-------------------------------------------------------------------------------------------

	bReturn = CStaticPubFunc::WriteFileAppend((char*)stringLogFileFullPathName.c_str(),
											  (char*)pbyteBuffer,
											  dwBufferLength,
											  (char*)szcharMsg);

	//CSemaphoreThis.Unlock();

	if(!bReturn)
	{
		return false;
	}

	return true;
}


