#pragma once

#include "LogSQLiteRobGrovesTry.h"

#include "..\PubClass\EnumStructureUnion.h"

class CLogSQLiteRobGrovesTryShell
{
public:
	CLogSQLiteRobGrovesTryShell(void);
	~CLogSQLiteRobGrovesTryShell(void);
	
	//--------------------------------------------------------------------------
	static bool CreateTable(CString & strMsg, int iSQLiteTimeOut = MACRO_INT_SQLite_TimeOut_Thread_Worker);
	static bool CreateTable_t_Log(CString & strMsg, int iSQLiteTimeOut = MACRO_INT_SQLite_TimeOut_Thread_Worker);
	//--------------------------------------------------------------------------
	static bool WriteLog(CString strLogFileFullPathName,
						 CString strLog, 
						 int iSQLiteTimeOut = MACRO_INT_SQLite_TimeOut_Thread_Worker);
	
};
