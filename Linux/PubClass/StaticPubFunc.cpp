//#include "../prjJFLogEx/StdAfx.h"
//#include "StdAfx.h"
#include "StaticPubFunc.h"

#include <iostream>
#include <string.h>
using namespace std;

#include <time.h>
#include <unistd.h>

#include <sys/time.h>
#include <stdio.h>

#include <sys/stat.h>
#include <sys/types.h>

#if 0
string CStaticPubFunc::ChangeBinaryToString(BYTE * pbyteBuffer, DWORD dwBufferLength)
{
	long l;
	string strPrint;
	string strTemp;

	ostringstream ostringstreamThis;

	char szwcharTemp[10];
	//=============================================================================

	if(dwBufferLength <= 0 || !pbyteBuffer)
	{
		return "";
	}
	//--------------------------------------------------------------------------------
#if 1
	for(l = 0;l < dwBufferLength;l++)
	{
		sprintf(szwcharTemp, "%02X", pbyteBuffer[l]);
		ostringstreamThis << szwcharTemp;
		ostringstreamThis << " ";
	}

	strPrint = ostringstreamThis.str();
#else
	//--------------------------------------------------------------------------------
	for(l = 0;l < dwBufferLength;l++)
	{
		strTemp.Format(_T("%02d "),pbyteBuffer[l]);
		strPrint += strTemp;
	}
#endif
	//--------------------------------------------------------------------------------
	//OutputDebugString(strPrint.c_str());
	
	return strPrint;
}
#endif
string CStaticPubFunc::GetCurrentExeFileFullPathName()
{
	char szcharFileName[260];
	int iReturn = 0;
	//================================================================
	//获取当前程序绝对路径
	
	iReturn = readlink("/proc/self/exe", szcharFileName, 260);
	if (iReturn < 0 || iReturn >= 260)
	{
	    //printf("***Error***\n");
	}

	return szcharFileName;
}


string CStaticPubFunc::GetCurrentExeFileFullPath()
{
	string strExeFileFullPathName;
	int iCharPosition;

	strExeFileFullPathName = GetCurrentExeFileFullPathName();

	iCharPosition = strExeFileFullPathName.rfind('/');
	
	return strExeFileFullPathName.substr(0, iCharPosition + 1);	
}

string CStaticPubFunc::GetCurrentExeFileNameWithExtendName()
{
	string strExeFileFullPathName;
	int iCharPosition;
	
	strExeFileFullPathName = GetCurrentExeFileFullPathName();

	iCharPosition = strExeFileFullPathName.rfind('/');

	return strExeFileFullPathName.substr(iCharPosition - 1);

}

string CStaticPubFunc::GetFileExtendName(string strFileName)
{
	int intCharPosition;

	//Find "\\",Get The File's Name
	intCharPosition = strFileName.rfind('/');
	if(-1 != intCharPosition)
	{
		strFileName = strFileName.substr(intCharPosition - 1);
	}
	//AfxMessageBox(strFileName);

	//Find ".",Get the file's extend name
	intCharPosition = strFileName.rfind('.');
	if(-1 != intCharPosition)
	{
		strFileName = strFileName.substr(intCharPosition - 1);
		return strFileName;
	}
	else
	{
		//No extend name
		return "";
	}
}

string CStaticPubFunc::GetStringNoSpecialSymbol(string str)
{
	//str.replace(" ","_");
	//str.replace(".","@");
	//str.replace("\\","_");
	//str.replace(":","_");
	//str.replace("?","_");
	//str.replace("*","_");

	return str;
}

bool CStaticPubFunc::CreateMultiLevelDirectory(char * lpszPath)
{
	int iPos;
	string stringPathTemp;
	string stringPath;
	//===================================================================================
	stringPath = lpszPath;
	
	if(stringPath.empty())
	{
		return false;
	}
	
	//-----------------------------------------------------------------------
	while(1)
	{
		iPos = stringPath.find("/");
		
		if(-1 != iPos)
		{
			stringPathTemp += stringPath.substr(0, iPos + 1);
			stringPath = stringPath.substr(iPos + 1);
			
		}
		else
		{
			stringPathTemp += stringPath;
			stringPath.clear();
		}
		
		mkdir(stringPathTemp.c_str(), 0777);
		
		if(stringPath.empty())
		{
			break;
		}
	}
	
	return true;
}


bool CStaticPubFunc::CreateMultiLevelDirectoryEx(char * lpszFullPathFileName)
{
	int iPos;
	string stringPathTemp;
	string stringTemp;
	string stringPath;
	//===================================================================================
	stringPath = lpszFullPathFileName;
	
	if(stringPath.empty())
	{
		return false;
	}
	//-----------------------------------------------------------------------
	//�� �ļ��� ȥ��#if 0
	iPos = stringPath.rfind ('/');
	if(-1 == iPos)
	{
		return false;
	}
	
	stringPath = stringPath.substr(0, iPos + 1);
	
	//-----------------------------------------------------------------------
	while(1)
	{
		iPos = stringPath.find("/");
		
		if(-1 != iPos)
		{
			stringPathTemp += stringPath.substr(0, iPos + 1);
			stringPath = stringPath.substr(iPos + 1);
		}
		else
		{
			stringPathTemp += stringPath;
			stringPath.clear();
		}
		
		mkdir(stringPathTemp.c_str(), 0777);
		
		if(stringPath.empty())
		{
			break;
		}
	}
	
	return true;
}
#if 0
char * CStaticPubFunc::pwcharTopchar(const wchar_t * pwchar,int iSrcStrCount)
{
	int iCountDesStrRequire;
	char * pchar;
	//=====================================================================
	iCountDesStrRequire = (int)wcstombs(NULL,pwchar,iSrcStrCount);
	
	pchar = new char[iCountDesStrRequire + 1];
	
	memset(pchar,0,iCountDesStrRequire + 1);
	
	wcstombs(pchar,pwchar,iSrcStrCount);
	
	return pchar;
}

bool CStaticPubFunc::pwcharTopchar(char ** ppchar,const wchar_t * pwchar,int iSrcStrCount)
{
	int iCountDesStrRequire;
	char * pchar;
	//=====================================================================
	iCountDesStrRequire = (int)wcstombs(NULL,pwchar,iSrcStrCount);
	
	pchar = new char[iCountDesStrRequire + 1];
	
	memset(pchar,0,iCountDesStrRequire + 1);
	
	wcstombs(pchar,pwchar,iSrcStrCount);
	
	*ppchar = pchar;

	return true;
}

wchar_t * CStaticPubFunc::pcharTopwchar(const char * pchar,int iSrcStrCount)
{
	int iCountDesStrRequire;
	wchar_t * pwchar;
	//=====================================================================
	iCountDesStrRequire = (int)mbstowcs(NULL,pchar,iSrcStrCount);
	
	pwchar = new wchar_t[iCountDesStrRequire + 1];
	
	memset(pwchar,0,iCountDesStrRequire + 1);
	
	mbstowcs(pwchar,pchar,iSrcStrCount);
	
	return pwchar;
}

bool CStaticPubFunc::pcharTopwchar(wchar_t ** ppwchar,const char * pchar,int iSrcStrCount)
{
	int iCountDesStrRequire;
	wchar_t * pwchar = NULL;
	//=====================================================================
	
	iCountDesStrRequire = (int)mbstowcs(NULL,pchar,iSrcStrCount);
	
	pwchar = new wchar_t[iCountDesStrRequire + 1];
	
	memset(pwchar,0,(iCountDesStrRequire + 1) * 2);
	
	mbstowcs(pwchar,pchar,iSrcStrCount);
	
	*ppwchar = pwchar;

	return true;
}

//---------------------------------------------------------------------

char * CStaticPubFunc::pwcharTopcharEx(const wchar_t * pwchar)
{
	int iCountDesStrRequire;
	char * pchar = NULL;
	int iReturn;
	//=====================================================================
	iCountDesStrRequire = WideCharToMultiByte(CP_ACP,NULL,pwchar,-1,NULL,0,NULL,FALSE);
	if(0 == iCountDesStrRequire)
	{
		return NULL;
	}

	pchar = new char[iCountDesStrRequire + 1];
	
	memset(pchar,0,iCountDesStrRequire + 1);
	
	iReturn = WideCharToMultiByte(CP_ACP, NULL, pwchar, -1, pchar,iCountDesStrRequire, NULL, NULL);
	if(0 == iReturn)
	{
		delete [] pchar;
		return NULL;
	}
	
	return pchar;
}

bool CStaticPubFunc::pwcharTopcharEx(char ** ppchar,const wchar_t * pwchar)
{
	int iCountDesStrRequire;
	char * pchar;
	int iReturn;
	//=====================================================================
	iCountDesStrRequire = WideCharToMultiByte(CP_ACP,NULL,pwchar,-1,NULL,0,NULL,FALSE);
	if(0 == iCountDesStrRequire)
	{
		return false;
	}

	pchar = new char[iCountDesStrRequire + 1];
	
	memset(pchar,0,iCountDesStrRequire + 1);
	
	iReturn = WideCharToMultiByte(CP_ACP, NULL, pwchar, -1, pchar,iCountDesStrRequire, NULL, NULL);
	if(0 == iReturn)
	{
		delete [] pchar;
		return false;
	}
	
	*ppchar = pchar;
	
	return true;
}

wchar_t * CStaticPubFunc::pcharTopwcharEx(const char * pchar)
{
	int iCountDesStrRequire;
	wchar_t * pwchar;
	int iReturn;
	//=====================================================================
	iCountDesStrRequire = MultiByteToWideChar(CP_ACP,NULL,pchar,-1,NULL,0);
	if(0 == iCountDesStrRequire)
	{
		return NULL;
	}
	
	pwchar = new wchar_t[iCountDesStrRequire + 1];
	
	memset(pwchar,0,iCountDesStrRequire + 1);
	
	iReturn = MultiByteToWideChar(CP_ACP, NULL, pchar, -1, pwchar,iCountDesStrRequire);
	if(0 == iReturn)
	{
		delete [] pwchar;
		return NULL;
	}
	
	return pwchar;
}

bool CStaticPubFunc::pcharTopwcharEx(wchar_t ** ppwchar,const char * pchar)
{
	int iCountDesStrRequire;
	wchar_t * pwchar = NULL;
	int iReturn;
	//=====================================================================
	
	iCountDesStrRequire = MultiByteToWideChar(CP_ACP,NULL,pchar,-1,NULL,0);
	if(0 == iCountDesStrRequire)
	{
		return false;
	}
	
	pwchar = new wchar_t[iCountDesStrRequire + 1];
	
	memset(pwchar,0,(iCountDesStrRequire + 1) * 2);
	
	iReturn = MultiByteToWideChar(CP_ACP, NULL, pchar, -1, pwchar,iCountDesStrRequire);
	if(0 == iReturn)
	{
		delete [] pwchar;
		return false;
	}
	
	*ppwchar = pwchar;
	
	return true;
}
#endif
//---------------------------------------------------------------------
#if 0
bool CStaticPubFunc::WriteTextToTxtFileOverlay(char * lpszTxtFileFullPathName,
											   const char * pcharContentWritten, 
											   char * pcharMsg)
{
	HANDLE hFile = NULL;
	DWORD dwSize = 0;
	BOOL bSuccessful;
	//=================================================================================
	//Check Data
	if(!lpszTxtFileFullPathName || !pcharContentWritten)
	{
		if(pcharMsg)
		{
			strcpy(pcharMsg, "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : lpszTxtFileFullPathName is NULL or pcharContentWritten is NULL");
		}
		return false;
	}
	
	//---------------------------------------------------------------------------------
	hFile = CreateFile(lpszTxtFileFullPathName,
					   GENERIC_WRITE,
					   FILE_SHARE_WRITE,
					   NULL,
					   CREATE_ALWAYS,
					   FILE_ATTRIBUTE_NORMAL,
					   NULL);

	if(INVALID_HANDLE_VALUE == hFile)
	{
		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : CreateFile failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}
	//---------------------------------------------------------------------------------
	
	bSuccessful = WriteFile(hFile, pcharContentWritten, strlen(pcharContentWritten), &dwSize, NULL);
	
	if(!bSuccessful)
	{
		CloseHandle(hFile);
		hFile = NULL;

		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : WriteFile failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}
	//---------------------------------------------------------------------------------

	CloseHandle(hFile);
	hFile = NULL;
	
	return true;
}

bool CStaticPubFunc::WriteTextToTxtFileOverlay(char * lpszTxtFileFullPathName,
											   char * lpszContentWritten,
											   char * pcharMsg)
{	
	HANDLE hFile = NULL;
	DWORD dwSize = 0;
	BOOL bSuccessful;
	char * pchar = NULL;
	
	//=================================================================================
	//Check Data
	if(!lpszTxtFileFullPathName || !lpszContentWritten)
	{
		if(pcharMsg)
		{
			strcpy(pcharMsg, "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : lpszTxtFileFullPathName is NULL or lpszContentWritten is NULL");
		}
		return false;
	}
	
	//---------------------------------------------------------------------------------
	hFile = CreateFile(lpszTxtFileFullPathName,
					   GENERIC_WRITE,
					   FILE_SHARE_WRITE,
					   NULL,
					   CREATE_ALWAYS,
					   FILE_ATTRIBUTE_NORMAL,
					   NULL);
	
	if(INVALID_HANDLE_VALUE == hFile)
	{
		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : CreateFile failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}

	//---------------------------------------------------------------------------------
	pchar = CStaticPubFunc::pwcharTopcharEx(lpszContentWritten);
	if(!pchar)
	{
		CloseHandle(hFile);
		hFile = NULL;

		if(pcharMsg)
		{
			strcpy(pcharMsg,
				   "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : CStaticPubFunc::pwcharTopcharEx failed!");
		}
		
		return false;
	}
	//---------------------------------------------------------------------------------
	bSuccessful = WriteFile(hFile, 
							pchar, 
							strlen(pchar), 
							&dwSize, 
							NULL);
	if(!bSuccessful)
	{
		CloseHandle(hFile);
		hFile = NULL;

		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : WriteFile failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}

	delete [] pchar;
	pchar = NULL;
	//---------------------------------------------------------------------------------
	CloseHandle(hFile);
	hFile = NULL;
	
	return true;
}
#endif

bool CStaticPubFunc::WriteTextToTxtFileAppend(char * lpszTxtFileFullPathName,
											  char * lpszContentWritten,
											  char * pcharMsg)
{	
#if 0
	HANDLE hFile = NULL;
	DWORD dwSize = 0;
	BOOL bSuccessful;
	char * pchar = NULL;
	DWORD dwReturn;
	//=================================================================================
	//Check Data
	if(!lpszTxtFileFullPathName || !lpszContentWritten)
	{
		if(pcharMsg)
		{
			strcpy(pcharMsg, "CprjWriteFileTestDlg::WriteTextToTxtFileAppend : lpszTxtFileFullPathName is NULL or lpszContentWritten is NULL");
		}
		return false;
	}
	
	//---------------------------------------------------------------------------------
	hFile = CreateFile(lpszTxtFileFullPathName,
					   GENERIC_WRITE,
					   FILE_SHARE_WRITE,
					   NULL,
					   OPEN_ALWAYS,
					   FILE_ATTRIBUTE_NORMAL,
					   NULL);
	
	if(INVALID_HANDLE_VALUE == hFile)
	{
		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileAppend : CreateFile failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}
	//---------------------------------------------------------------------------------
	
	dwReturn = SetFilePointer(hFile,
							  0,
							  NULL,
							  FILE_END);
	if(dwReturn == 0xFFFFFFFF)
	{
		CloseHandle(hFile);
		hFile = NULL;

		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileAppend : SetFilePointer failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}

	//---------------------------------------------------------------------------------
	pchar = CStaticPubFunc::pwcharTopcharEx(lpszContentWritten);
	if(!pchar)
	{
		CloseHandle(hFile);
		hFile = NULL;

		if(pcharMsg)
		{
			strcpy(pcharMsg,
				   "CprjWriteFileTestDlg::WriteTextToTxtFileAppend : CStaticPubFunc::pwcharTopcharEx failed!");
		}
		
		return false;
	}
	//---------------------------------------------------------------------------------
	bSuccessful = WriteFile(hFile, 
							pchar, 
							strlen(pchar), 
							&dwSize, 
							NULL);
	if(!bSuccessful)
	{
		CloseHandle(hFile);
		hFile = NULL;

		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileAppend : WriteFile failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}

	delete [] pchar;
	pchar = NULL;
	//---------------------------------------------------------------------------------
	CloseHandle(hFile);
	hFile = NULL;
#endif
	return true;
}


bool CStaticPubFunc::WriteTextToTxtFileAppendEx(char * lpszTxtFileFullPathName,
												char * lpszContentWritten,
												char * pcharMsg)
{

	FILE * pfile = NULL;
	//char * pchar = NULL;
	long lLength = 0;
	size_t size_t_this = 0;
	//=========================================================================
	//CheckData
	if(!lpszTxtFileFullPathName || !lpszContentWritten)
	{
		return false;
	}
	if(strlen(lpszTxtFileFullPathName) <= 0 || strlen(lpszContentWritten) <= 0)
	{
		return false;
	}
	//-------------------------------------------------------------------------
	pfile = fopen(lpszTxtFileFullPathName,"a");
	
	if(!pfile)
	{
		return false;
	}
	//-------------------------------------------------------------------------

	lLength = strlen(lpszContentWritten);

	size_t_this = fwrite(lpszContentWritten,sizeof(char),lLength, pfile);
	
	//-------------------------------------------------------------------------
	if(pfile)
	{
		fclose(pfile);
	}

	return true;
	//-------------------------------------------------------------------------
}


bool CStaticPubFunc::WriteFileAppend(char * lpszTxtFileFullPathName,
									 char * pbyteBuffer,
									 long dwBufferLength,
									 char * pcharMsg)
{
	FILE * pfile = NULL;
	//char * pchar = NULL;
	//long lLength = 0;
	size_t size_t_this = 0;
	//=========================================================================
	//CheckData
	if(!lpszTxtFileFullPathName || !pbyteBuffer || 0 == dwBufferLength)
	{
		return false;
	}
	if(strlen(lpszTxtFileFullPathName) <= 0)
	{
		return false;
	}
	//-------------------------------------------------------------------------
	pfile = fopen(lpszTxtFileFullPathName,"a");

	if(!pfile)
	{
		return false;
	}
	//-------------------------------------------------------------------------

	size_t_this = fwrite(pbyteBuffer,sizeof(char),dwBufferLength, pfile);

	//-------------------------------------------------------------------------
	if(pfile)
	{
		fclose(pfile);
	}

	return true;
	//-------------------------------------------------------------------------
}


#if 0

bool CStaticPubFunc::ReadFileToCharArray(char * lpszTxtFileFullPathName,
										 char ** ppcharContent,
										 DWORD & dwFileSize,
										 char * pcharMsg)
{
	HANDLE hFile = NULL;
	DWORD dwSize = 0;
	BOOL bSuccessful;
	char * pchar = NULL;
	DWORD dwFileSizeLow;
	DWORD dwFileSizeHigh;
	DWORD dwReturn;
	DWORD dwNumberOfBytesRead;
	//=================================================================================
	//Check Data
	if(!lpszTxtFileFullPathName || !ppcharContent)
	{
		if(pcharMsg)
		{
			strcpy(pcharMsg, "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : lpszTxtFileFullPathName is NULL or ppcharContent is NULL");
		}
		return false;
	}
	
	//---------------------------------------------------------------------------------
	hFile = CreateFile(lpszTxtFileFullPathName,
					   GENERIC_READ,
					   FILE_SHARE_READ,
					   NULL,
					   OPEN_EXISTING,
					   FILE_ATTRIBUTE_NORMAL,
					   NULL);
	
	if(INVALID_HANDLE_VALUE == hFile)
	{
		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : CreateFile failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}

	//---------------------------------------------------------------------------------
	dwFileSizeLow = GetFileSize(hFile, &dwFileSizeHigh);
	
	if(0xFFFFFFFF == dwFileSizeLow)
	{
		dwReturn = GetLastError();
		if(NO_ERROR != dwReturn)
		{
			CloseHandle(hFile);
			hFile = NULL;

			if(pcharMsg)
			{
				sprintf(pcharMsg,
						 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : GetFileSize failed! Error Code = %d",
						 GetLastError());
			}
			
			return false;
		}		
	}
	
	dwFileSize = dwFileSizeHigh;
	dwFileSize = dwFileSize << 8;
	dwFileSize += dwFileSizeLow;
	
	*ppcharContent = new char[dwFileSize + 1];

	if(*ppcharContent == NULL)
	{
		CloseHandle(hFile);
		hFile = NULL;

		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : new failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}

	memset(*ppcharContent, 0, dwFileSize + 1);
	//---------------------------------------------------------------------------------
	
	bSuccessful = ReadFile(hFile, 
						   *ppcharContent, 
						   dwFileSize, 
						   &dwNumberOfBytesRead, 
						   NULL);
	if(!bSuccessful)
	{
		CloseHandle(hFile);
		hFile = NULL;

		delete [] *ppcharContent;
		*ppcharContent = NULL;

		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : WriteFile failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}
	
	//---------------------------------------------------------------------------------
	CloseHandle(hFile);
	hFile = NULL;
	
	return true;
}


bool CStaticPubFunc::ReadFileToWCharArray(char * lpszTxtFileFullPathName,
										 char ** ppwcharContent,
										 DWORD & dwFileSize,
										 char * pcharMsg)
{
	HANDLE hFile = NULL;
	DWORD dwSize = 0;
	BOOL bSuccessful;
	char * pchar = NULL;
	DWORD dwFileSizeLow;
	DWORD dwFileSizeHigh;
	DWORD dwReturn;
	DWORD dwNumberOfBytesRead;
	
	//=================================================================================
	//Check Data
	if(!lpszTxtFileFullPathName || !ppwcharContent)
	{
		if(pcharMsg)
		{
			strcpy(pcharMsg, "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : lpszTxtFileFullPathName is NULL or ppcharContent is NULL");
		}
		return false;
	}
	
	//---------------------------------------------------------------------------------
	hFile = CreateFile(lpszTxtFileFullPathName,
					   GENERIC_READ,
					   FILE_SHARE_READ,
					   NULL,
					   OPEN_EXISTING,
					   FILE_ATTRIBUTE_NORMAL,
					   NULL);
	
	if(INVALID_HANDLE_VALUE == hFile)
	{
		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : CreateFile failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}

	//---------------------------------------------------------------------------------
	dwFileSizeLow = GetFileSize(hFile, &dwFileSizeHigh);
	
	if(0xFFFFFFFF == dwFileSizeLow)
	{
		dwReturn = GetLastError();
		if(NO_ERROR != dwReturn)
		{
			CloseHandle(hFile);
			hFile = NULL;

			if(pcharMsg)
			{
				sprintf(pcharMsg,
						 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : GetFileSize failed! Error Code = %d",
						 GetLastError());
			}
			
			return false;
		}		
	}
	
	dwFileSize = dwFileSizeHigh;
	dwFileSize = dwFileSize << 8;
	dwFileSize += dwFileSizeLow;
	
	pchar = new char[dwFileSize + 1];

	if(pchar == NULL)
	{
		CloseHandle(hFile);
		hFile = NULL;

		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : new failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}

	memset(pchar, 0, dwFileSize + 1);
	//---------------------------------------------------------------------------------
	
	bSuccessful = ReadFile(hFile, 
						   pchar, 
						   dwFileSize, 
						   &dwNumberOfBytesRead, 
						   NULL);
	if(!bSuccessful)
	{
		CloseHandle(hFile);
		hFile = NULL;

		delete [] pchar;
		pchar = NULL;

		if(pcharMsg)
		{
			sprintf(pcharMsg,
					 "CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : WriteFile failed! Error Code = %d",
					 GetLastError());
		}
		
		return false;
	}
	//---------------------------------------------------------------------------------
	*ppwcharContent = CStaticPubFunc::pcharTopwcharEx(pchar);
	if(*ppwcharContent == NULL)
	{
		CloseHandle(hFile);
		hFile = NULL;
		
		delete [] pchar;
		pchar = NULL;
		
		if(pcharMsg)
		{
			strcpy(pcharMsg,
				   "CprjWriteFileTestDlg::WriteTextToTxtFileAppend : CStaticPubFunc::pcharTopwcharEx failed!");
		}
		
		return false;
	}
	
	//---------------------------------------------------------------------------------
	delete [] pchar;
	pchar = NULL;
	
	CloseHandle(hFile);
	hFile = NULL;
		
	return true;
}

#endif

bool CStaticPubFunc::GetCurrentTimeAllDigitEx(char * pcharTime,
													 char * pcharMsg,
													 enumTimeType enumTimeTypeThis,
													 char * lpszTimeSeparator)
{

	//============================================================
	//Check Data
	if(!pcharTime || !lpszTimeSeparator)
	{
		if(pcharMsg)
		{
			strcpy(pcharMsg, "CStaticPubFunc::GetCurrentTimeAllDigitEx : pcharTime is NULL or lpszTimeSeparator is NULL");
		}
		return false;
	}
	//------------------------------------------------------------
	struct timeval tv;
	char szcharTime[60];
	char szcharTimeEx[60];
	string stringTemp;
	//long lTemp = 0;
	int iTemp = 0;

	gettimeofday(&tv, NULL);

	strftime(szcharTime, sizeof(szcharTime), "%Y-%m-%d %T", localtime(&tv.tv_sec));

	//lTemp = tv.tv_usec / 1000;
	iTemp = tv.tv_usec / 1000;

	sprintf(szcharTimeEx, "%s %d", szcharTime, iTemp);

	//------------------------------------------------------------
	
	switch(enumTimeTypeThis)
	{
	case eiTimeTypeAll:
		{
			strftime(szcharTime, sizeof(szcharTime), "%u %Y-%m-%d %T", localtime(&tv.tv_sec));
			iTemp = tv.tv_usec / 1000;
			sprintf(szcharTimeEx, "%s %d", szcharTime, iTemp);
		}
		break;

	case eiTimeTypeDateTime:
		{
			strftime(szcharTimeEx, sizeof(szcharTimeEx), "%Y-%m-%d %T", localtime(&tv.tv_sec));
		}
		break;
	case eiTimeTypeDateTimeMillisecond:
		{
			strftime(szcharTime, sizeof(szcharTime), "%Y-%m-%d %T", localtime(&tv.tv_sec));
			iTemp = tv.tv_usec / 1000;
			sprintf(szcharTimeEx, "%s %d", szcharTime, iTemp);
		}
		break;
	case eiTimeTypeDateTimeOnlyDigit:
		{
			strftime(szcharTimeEx, sizeof(szcharTimeEx), "%Y-%m-%d %T", localtime(&tv.tv_sec));
		}
		break;
	case eiTimeTypeDateHour:
		{
			strftime(szcharTimeEx, sizeof(szcharTimeEx), "%Y-%m-%d_%H", localtime(&tv.tv_sec));
		}
		break;
	case eiTimeTypeDate:
		{
			strftime(szcharTimeEx, sizeof(szcharTimeEx), "%Y-%m-%d", localtime(&tv.tv_sec));
		}
		break;
	case eiTimeTypeTime:
		{
			strftime(szcharTimeEx, sizeof(szcharTimeEx), "%T", localtime(&tv.tv_sec));
		}
		break;
	case eiTimeTypeTimeMillisecond:
		{
			strftime(szcharTime, sizeof(szcharTime), "%T", localtime(&tv.tv_sec));
			iTemp = tv.tv_usec / 1000;
			sprintf(szcharTimeEx, "%s %d", szcharTime, iTemp);
		}
		break;

	case eiTimeTypeYear:
		{
			strftime(szcharTimeEx, sizeof(szcharTimeEx), "%Y", localtime(&tv.tv_sec));
		}
		break;
	case eiTimeTypeMonth:
		{
			strftime(szcharTimeEx, sizeof(szcharTimeEx), "%m", localtime(&tv.tv_sec));
		}
		break;
	case eiTimeTypeDay:
		{
			strftime(szcharTimeEx, sizeof(szcharTimeEx), "%d", localtime(&tv.tv_sec));
		}
		break;
	case eiTimeTypeWeek:
		{
			strftime(szcharTimeEx, sizeof(szcharTimeEx), "%u", localtime(&tv.tv_sec));
		}
		break;
	default:
		{
			return false;
		}
	}

	strcpy(pcharTime, szcharTimeEx);

	return true;
}
