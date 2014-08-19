#include "StdAfx.h"
#include "LogSQLiteRobGrovesTry.h"
#include "Log.h"

#include "..\PubClass\StaticPubFunc.h"

#include <afxmt.h>

extern CSemaphore g_CSemaphore_g_CLogSQLiteEx;

CLogSQLiteRobGrovesTry::CLogSQLiteRobGrovesTry(void)
{
}

CLogSQLiteRobGrovesTry::~CLogSQLiteRobGrovesTry(void)
{
	CString strMsg;
	//=======================================================================================================
	try
	{
		m_CppSQLite3DB.close();
	}
	catch (CppSQLite3Exception& e)
    {
		strMsg = e.errorMessage();
		strMsg += "\r\nCLogSQLiteRobGrovesTry::~CLogSQLiteRobGrovesTry";
		//return false;
    }
}

bool CLogSQLiteRobGrovesTry::CreateTable( CString & strMsg)
{	
	bool bReturn;
	
	//=======================================================================================
	bReturn = CreateTable_t_Log(strMsg);
	if(!bReturn)
	{
		strMsg += L"\r\nCLogSQLiteRobGrovesTry::CreateTable";
		return false;
	}
	
	return true;
}

bool CLogSQLiteRobGrovesTry::CreateTable_t_Log(CString & strMsg)
{
	CString strSql;
	
	bool bReturn;

	int iReturn = 0;

	char * pchar = NULL;
	//=======================================================================================

	//Create Table - 
	
    strSql.Format(
			//-----------------------------------------------------------------------------------
			//t_Log
			L"CREATE TABLE IF NOT EXISTS t_Log(\r\n"
			L"FID INTEGER PRIMARY KEY ASC AUTOINCREMENT,--FID			:ID\r\n"
			L"FTime TEXT COLLATE NOCASE,								--FInformation	:信息\r\n"
			L"FInformation TEXT COLLATE NOCASE,						--FInformation	:信息\r\n"
			L"FRemark TEXT COLLATE NOCASE);							--FRemark		:备注\r\n");
	
	pchar = CStaticPubFunc::pwcharTopcharEx(strSql);
		
	if(!pchar)
	{
		strMsg.Format(L"CStaticPubFunc::pwcharTopcharEx failed\r\n"
					  L"CLogSQLiteRobGrovesTry::CreateTable_t_Log");
		return false;
	}
	
	try
	{
		iReturn = m_CppSQLite3DB.execDML(pchar);
	}
	catch (CppSQLite3Exception& e)
    {
		if(pchar)
		{
			delete [] pchar;
			pchar = NULL;
		}
		strMsg = e.errorMessage();
		strMsg += "\r\nCLogSQLiteRobGrovesTry::CreateTable_t_Log";
		return false;
    }
	
	if(pchar)
	{
		delete [] pchar;
		pchar = NULL;
	}

	//---------------------------------------------------------------------------------------
	
	return true;
}


#if 1

//含有创建表功能

bool CLogSQLiteRobGrovesTry::WriteLog(CString strLog)
{
	CString strSql;
	CString strTemp;

	bool bReturn;

	int iReturn = 0;

	char * pchar = NULL;

	CString strCurrentTime;

	CString strMsg;
	//=======================================================================================
	//Check Data
	
	strLog.Trim();
	
	if(strLog.IsEmpty())
	{
		strMsg.Format(L"strLog Is Empty\r\n"
					  L"CLogSQLiteRobGrovesTry::WriteLog");

		return false;
	}
	//---------------------------------------------------------------------------------------
	//创建表
	bReturn = CreateTable(strMsg);
	if(!bReturn)
	{
		return false;
	}
	//---------------------------------------------------------------------------------------
	//不替换会出现语法错误
	strLog.Replace(L"'", L"''");
	strLog.Replace(L"\r\n", L"\t\t");
	
	strCurrentTime = CStaticPubFunc::GetCurrentTimeAllDigit(eiTimeTypeDateTimeMillisecond);

	//---------------------------------------------------------------------------------------
	//Insert
    strSql.Format(L"INSERT OR IGNORE INTO t_Log"
				  L"(FTime, FInformation)"
				  L"VALUES('%s', '%s');\r\n",
				  strCurrentTime,
				  strLog);

	pchar = CStaticPubFunc::pwcharTopcharEx(strSql);
		
	if(!pchar)
	{
		strMsg.Format(L"CStaticPubFunc::pwcharTopcharEx failed\r\n"
					  L"CLogSQLiteRobGrovesTry::WriteLog");
		return false;
	}

	iReturn = m_CppSQLite3DB.execDML(MACRO_STR_BEGIN_TRANSACTION);

	try
	{
		iReturn = m_CppSQLite3DB.execDML(pchar);
	}
	catch (CppSQLite3Exception& e)
    {
		iReturn = m_CppSQLite3DB.execDML("ROLLBACK TRANSACTION");
		if(pchar)
		{
			delete [] pchar;
			pchar = NULL;
		}
		strMsg = e.errorMessage();
		strMsg += "\r\nCLogSQLiteRobGrovesTry::WriteLog";
		return false;
    }

	iReturn = m_CppSQLite3DB.execDML("COMMIT TRANSACTION");
	
	if(pchar)
	{
		delete [] pchar;
		pchar = NULL;
	}
	
	//---------------------------------------------------------------------------------------
	
	return true;
}

#else

//没有创建表功能

bool CLogSQLiteRobGrovesTry::WriteLog(CString strLog)
{
	CString strSql;
	CString strTemp;

	bool bReturn;

	int iReturn = 0;

	char * pchar = NULL;

	CString strCurrentTime;

	CString strMsg;
	//=======================================================================================
	//Check Data
	
	strLog.Trim();
	
	if(strLog.IsEmpty())
	{
		strMsg.Format(L"strLog Is Empty\r\n"
					  L"CLogSQLiteRobGrovesTry::WriteLog");

		return false;
	}

	//不替换会出现语法错误
	strLog.Replace(L"'", L"''");
	
	strCurrentTime = CStaticPubFunc::GetCurrentTimeAllDigit(eiTimeTypeDateTime);

	//---------------------------------------------------------------------------------------
	//Insert
    strSql.Format(L"INSERT OR IGNORE INTO t_Log"
				  L"(FTime, FInformation)"
				  L"VALUES('%s', '%s');\r\n",
				  strCurrentTime,
				  strLog);

	pchar = CStaticPubFunc::pwcharTopcharEx(strSql);
		
	if(!pchar)
	{
		strMsg.Format(L"CStaticPubFunc::pwcharTopcharEx failed\r\n"
					  L"CLogSQLiteRobGrovesTry::WriteLog");
		return false;
	}

	iReturn = m_CppSQLite3DB.execDML(MACRO_STR_BEGIN_TRANSACTION);

	try
	{
		iReturn = m_CppSQLite3DB.execDML(pchar);
	}
	catch (CppSQLite3Exception& e)
    {
		iReturn = m_CppSQLite3DB.execDML("ROLLBACK TRANSACTION");
		if(pchar)
		{
			delete [] pchar;
			pchar = NULL;
		}
		strMsg = e.errorMessage();
		strMsg += "\r\nCLogSQLiteRobGrovesTry::WriteLog";
		return false;
    }

	iReturn = m_CppSQLite3DB.execDML("COMMIT TRANSACTION");
	
	if(pchar)
	{
		delete [] pchar;
		pchar = NULL;
	}
	
	//---------------------------------------------------------------------------------------
	
	return true;
}

#endif


bool CLogSQLiteRobGrovesTry::InitData(CString & strMsg)
{
	bool bReturn;
	//================================================================================
	
	bReturn = InitDataVariable(strMsg);
	if(!bReturn)
	{
		strMsg += L"\r\nCLogSQLiteRobGrovesTry::InitData";
		return false;
	}
	
	bReturn = InitDataDatabase(strMsg);
	if(!bReturn)
	{
		strMsg += L"\r\nCLogSQLiteRobGrovesTry::InitData";
		return false;
	}
	
	return true;
}


bool CLogSQLiteRobGrovesTry::InitDataVariable(CString & strMsg)
{
	
	//================================================================================
	
	m_iSQLiteTimeOut = MACRO_INT_SQLite_TimeOut_WriteLog;
	
	
	return true;
}


bool CLogSQLiteRobGrovesTry::InitDataDatabase(CString & strMsg)
{
	char * pchar = NULL;
	
	bool bReturn;
	//================================================================================
	
	pchar = CStaticPubFunc::pwcharTopcharEx(m_strDBFileFullPathName, strMsg, CP_UTF8);
	if(!pchar)
	{
		strMsg.Format(L"CStaticPubFunc::pwcharTopcharEx failed\r\n"
					  L"CLogSQLiteRobGrovesTry::InitDataDatabase");
		
		return false;
	}

	try
	{
		m_CppSQLite3DB.open(pchar);
		m_CppSQLite3DB.setBusyTimeout(m_iSQLiteTimeOut);
		m_CppSQLite3DB.execDML("PRAGMA journal_mode=WAL;\r\n"
							   "PRAGMA auto_vacuum = 0;\r\n"
							   "PRAGMA cache_size = 8000;\r\n"
							   "PRAGMA case_sensitive_like = 1;\r\n"
							   "PRAGMA count_changes = 1;\r\n"
							   "PRAGMA page_size = 32768;\r\n"
							   "PRAGMA synchronous = OFF;\r\n"
							   "PRAGMA temp_store = MEMORY;\r\n");
	}
	catch (CppSQLite3Exception& e)
    {
		if(pchar)
		{
			delete [] pchar;
			pchar = NULL;
		}
		strMsg = e.errorMessage();
		strMsg += "\r\nCReceiverSQLiteRobGrovesTry::InitDataDatabase";
		return false;
    }
	
	if(pchar)
	{
		delete [] pchar;
		pchar = NULL;
	}

	return true;
}


