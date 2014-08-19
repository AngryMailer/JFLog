#pragma once

#include "..\SQLite\CppSQLite3.h"

class CLogSQLiteRobGrovesTry
{
public:
	CLogSQLiteRobGrovesTry(void);
	~CLogSQLiteRobGrovesTry(void);
	
	//--------------------------------------------------------------------------

	bool InitData(CString & strMsg);
	bool InitDataVariable(CString & strMsg);	
	bool InitDataDatabase(CString & strMsg);
	//--------------------------------------------------------------------------
	bool CreateTable(CString & strMsg);
	bool CreateTable_t_Log(CString & strMsg);
	//--------------------------------------------------------------------------
	bool WriteLog(CString strLog);
	//--------------------------------------------------------------------------
	//Variable
	
	CppSQLite3DB m_CppSQLite3DB;

	CString m_strDBFileFullPathName;

	int m_iSQLiteTimeOut;
	
};
