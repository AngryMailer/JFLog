#include "StdAfx.h"
#include "LogSQLiteRobGrovesTryShell.h"

//数据库全路径文件名 - 收件人
extern CString g_strDBFileFullPathNameLog;

#include <afxmt.h>

extern CSemaphore g_CSemaphore_g_CLogSQLiteEx;

CLogSQLiteRobGrovesTryShell::CLogSQLiteRobGrovesTryShell(void)
{
}

CLogSQLiteRobGrovesTryShell::~CLogSQLiteRobGrovesTryShell(void)
{
}

//--------------------------------------------------------------------------
bool CLogSQLiteRobGrovesTryShell::CreateTable(CString & strMsg, int iSQLiteTimeOut)
{
	CLogSQLiteRobGrovesTry CLogSQLiteRobGrovesTryThis;
	bool bReturn;
	//===================================================================================
	CLogSQLiteRobGrovesTryThis.m_strDBFileFullPathName = g_strDBFileFullPathNameLog;
	CLogSQLiteRobGrovesTryThis.m_iSQLiteTimeOut = iSQLiteTimeOut;
	bReturn = CLogSQLiteRobGrovesTryThis.InitData(strMsg);
	if(!bReturn)
	{
		strMsg += L"\r\nCLogSQLiteRobGrovesTryShell::CreateTable";
		return false;
	}

	bReturn = CLogSQLiteRobGrovesTryThis.CreateTable(strMsg);
	if(!bReturn)
	{
		strMsg += L"\r\nCLogSQLiteRobGrovesTryShell::CreateTable";
		return false;
	}
	
	return true;
}


bool CLogSQLiteRobGrovesTryShell::CreateTable_t_Log(CString & strMsg, int iSQLiteTimeOut)
{	
	CLogSQLiteRobGrovesTry CLogSQLiteRobGrovesTryThis;
	bool bReturn;
	//===================================================================================
	CLogSQLiteRobGrovesTryThis.m_strDBFileFullPathName = g_strDBFileFullPathNameLog;
	CLogSQLiteRobGrovesTryThis.m_iSQLiteTimeOut = iSQLiteTimeOut;
	bReturn = CLogSQLiteRobGrovesTryThis.InitData(strMsg);
	if(!bReturn)
	{
		strMsg += L"\r\nCLogSQLiteRobGrovesTryShell::CreateTable_t_Log";
		return false;
	}

	bReturn = CLogSQLiteRobGrovesTryThis.CreateTable_t_Log(strMsg);
	if(!bReturn)
	{
		strMsg += L"\r\nCLogSQLiteRobGrovesTryShell::CreateTable_t_Log";
		return false;
	}
	
	return true;
}

//--------------------------------------------------------------------------
bool CLogSQLiteRobGrovesTryShell::WriteLog(CString strLogFileFullPathName, 
										   CString strLog, 
										   int iSQLiteTimeOut)
{
	CLogSQLiteRobGrovesTry CLogSQLiteRobGrovesTryThis;
	bool bReturn;
	CString strMsg;
	//===================================================================================
	
	if(strLogFileFullPathName.IsEmpty())
	{
		return false;
	}
	//-----------------------------------------------------------------------------------
	//g_CSemaphore_g_CLogSQLiteEx.Lock();
		
	CLogSQLiteRobGrovesTryThis.m_strDBFileFullPathName = strLogFileFullPathName;
	CLogSQLiteRobGrovesTryThis.m_iSQLiteTimeOut = iSQLiteTimeOut;
	bReturn = CLogSQLiteRobGrovesTryThis.InitData(strMsg);
	if(!bReturn)
	{
		//g_CSemaphore_g_CLogSQLiteEx.Unlock();
		strMsg += L"\r\nCLogSQLiteRobGrovesTryShell::WriteLog";
		return false;
	}

	bReturn = CLogSQLiteRobGrovesTryThis.WriteLog(strLog);

	//g_CSemaphore_g_CLogSQLiteEx.Unlock();

	if(!bReturn)
	{
		strMsg += L"\r\nCLogSQLiteRobGrovesTryShell::WriteLog";
		return false;
	}
	
	return true;
}
