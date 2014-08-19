#include "StdAfx.h"
#include "LogText.h"

#include "..\PubClass\StaticPubFunc.h"

//#include <afxmt.h>

CLogText::CLogText(void)
{
}

CLogText::~CLogText(void)
{
}


bool CLogText::WriteLog(wstring wstringLogFileFullPathName,
						wstring wstringLog, 
						int iTimeOutToWrite)
{
	wstring wstringMsg;
	
	bool bReturn;

	wstring wstringCurrentTime;

	wstring wstringLogToWrite;
	
	wstring wstringTemp;

	BOOL bSuccessful;

	wostringstream wostringstreamThis;

	WCHAR szwcharCurrentTime[50];

	WCHAR szwcharMsg[MAX_PATH];
	//===========================================================================================
	//Check Data
	
	if(wstringLogFileFullPathName.empty())
	{
		return false;
	}
	
	//wstringLog.replace(L"\r\n", L"\t\t");
	//-------------------------------------------------------------------------------------------
	bReturn = CStaticPubFunc::GetCurrentTimeAllDigitEx(szwcharCurrentTime, szwcharMsg, eiTimeTypeDateTimeMillisecond);
	
	wstringCurrentTime = szwcharCurrentTime;

	wostringstreamThis<<wstringCurrentTime;
	wostringstreamThis<<L"\t:\t";
	wostringstreamThis<<wstringLog;
	wostringstreamThis<<L"\r\n";
	
	wstringLogToWrite=wostringstreamThis.str();
	//-------------------------------------------------------------------------------------------
	wostringstreamThis.clear();
	wostringstreamThis<<L"CLogText::WriteLog";
	wostringstreamThis<<wstringLogFileFullPathName;

	wstringTemp = wostringstreamThis.str();
	
	wstringTemp = CStaticPubFunc::GetStringNoSpecialSymbol(wstringTemp);

#if 0

	CSemaphore CSemaphoreThis(1, 1, wstringTemp);
	
	bSuccessful = CSemaphoreThis.Lock(iTimeOutToWrite);
	if(!bSuccessful)
	{
		return FALSE;
	}

#endif
	//-------------------------------------------------------------------------------------------

	bReturn = CStaticPubFunc::WriteTextToTxtFileAppend(wstringLogFileFullPathName.c_str(), 
													   wstringLogToWrite.c_str(), 
													   szwcharMsg);
	
	//CSemaphoreThis.Unlock();
	
	if(!bReturn)
	{
		return false;
	}	
	
	return true;
}


bool CLogText::WriteLog(wstring wstringLogFileFullPathName,
						BYTE * pbyteBuffer,
						DWORD dwBufferLength,
						int iTimeOutToWrite)
{
	wstring wstringMsg;
	
	bool bReturn;

	wstring wstringCurrentTime;

	wstring wstringLogToWrite;
	
	wstring wstringTemp;

	BOOL bSuccessful;

	wostringstream wostringstreamThis;

	WCHAR szwcharCurrentTime[50];

	WCHAR szwcharMsg[MAX_PATH];
	//===========================================================================================
	//Check Data
	
	if(wstringLogFileFullPathName.empty() || !pbyteBuffer || 0 == dwBufferLength)
	{
		return false;
	}
	
#if 0

	CSemaphore CSemaphoreThis(1, 1, wstringTemp);
	
	bSuccessful = CSemaphoreThis.Lock(iTimeOutToWrite);
	if(!bSuccessful)
	{
		return FALSE;
	}

#endif
	//-------------------------------------------------------------------------------------------

	bReturn = CStaticPubFunc::WriteFileAppend(wstringLogFileFullPathName.c_str(), 
											  pbyteBuffer, 
											  dwBufferLength,
											  szwcharMsg);
	
	//CSemaphoreThis.Unlock();
	
	if(!bReturn)
	{
		return false;
	}	
	
	return true;
}

