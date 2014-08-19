#pragma once


#include "..\PubClass\EnumStructureUnion.h"


class CLogText
{
public:
	CLogText(void);
	~CLogText(void);
	
	//--------------------------------------------------------------------------
	static bool WriteLog(wstring wstringLogFileFullPathName,
						 wstring wstringLog, 
						 int iTimeOutToWrite = MACRO_INT_SQLite_TimeOut_WriteLog);

	static bool WriteLog(wstring wstringLogFileFullPathName,
						 BYTE * pbyteBuffer, 
						 DWORD dwBufferLength,
						 int iTimeOutToWrite = MACRO_INT_SQLite_TimeOut_WriteLog);
	
};
