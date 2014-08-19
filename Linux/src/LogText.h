#pragma once


#include "../PubClass/EnumStructureUnion.h"

#include <string>
using namespace std;

class CLogText
{
public:
	CLogText(void);
	~CLogText(void);
	
	//--------------------------------------------------------------------------
	static bool WriteLog(string stringLogFileFullPathName,
						 string stringLog,
						 int iTimeOutToWrite = MACRO_INT_SQLite_TimeOut_WriteLog);
	
	static bool WriteLog(string stringLogFileFullPathName,
						 char * pbyteBuffer,
						 long dwBufferLength,
						 int iTimeOutToWrite = MACRO_INT_SQLite_TimeOut_WriteLog);

};
