//#include "../prjJFLogEx/StdAfx.h"
#include "StdAfx.h"
#include "StaticPubFunc.h"

wstring CStaticPubFunc::ChangeBinaryToString(BYTE * pbyteBuffer, DWORD dwBufferLength)
{
	long l;
	wstring strPrint;
	wstring strTemp;

	wostringstream wostringstreamThis;

	WCHAR szwcharTemp[10];
	//=============================================================================

	if(dwBufferLength <= 0 || !pbyteBuffer)
	{
		return L"";
	}
	//--------------------------------------------------------------------------------
#if 1
	for(l = 0;l < dwBufferLength;l++)
	{
		swprintf(szwcharTemp, L"%02X", pbyteBuffer[l]);
		wostringstreamThis << szwcharTemp;
		wostringstreamThis << L" ";
	}

	strPrint = wostringstreamThis.str();
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

wstring CStaticPubFunc::GetCurrentExeFileFullPathName()
{
	WCHAR szwcharFileName[MAX_PATH];
	
	GetModuleFileName(NULL, szwcharFileName, MAX_PATH);

	//wstring strExeFileFullPathName(szwcharFileName);
	//return strExeFileFullPathName;

	return szwcharFileName;
}

//获取程序目录，带最后“\”
wstring CStaticPubFunc::GetCurrentExeFileFullPath()
{
	wstring strExeFileFullPathName;
	int iCharPosition;

	strExeFileFullPathName = GetCurrentExeFileFullPathName();

	iCharPosition = strExeFileFullPathName.rfind(L'\\');
	
	return strExeFileFullPathName.substr(0, iCharPosition + 1);	
}

wstring CStaticPubFunc::GetCurrentExeFileNameWithExtendName()
{
	wstring strExeFileFullPathName;
	int iCharPosition;
	
	strExeFileFullPathName = GetCurrentExeFileFullPathName();

	iCharPosition = strExeFileFullPathName.rfind(L'\\');

	return strExeFileFullPathName.substr(iCharPosition - 1);

}

wstring CStaticPubFunc::GetFileExtendName(wstring strFileName)
{
	int intCharPosition;

	//Find "\\",Get The File's Name
	intCharPosition = strFileName.rfind(L'\\');
	if(-1 != intCharPosition)
	{
		strFileName = strFileName.substr(intCharPosition - 1);
	}
	//AfxMessageBox(strFileName);

	//Find ".",Get the file's extend name
	intCharPosition = strFileName.rfind(L'.');
	if(-1 != intCharPosition)
	{
		strFileName = strFileName.substr(intCharPosition - 1);
		return strFileName;
	}
	else
	{
		//No extend name
		return L"";
	}
}

wstring CStaticPubFunc::GetStringNoSpecialSymbol(wstring str)
{
	//str.replace(L" ",L"_");
	//str.replace(L".",L"@");
	//str.replace(L"\\",L"_");
	//str.replace(L":",L"_");
	//str.replace(L"?",L"_");
	//str.replace(L"*",L"_");

	return str;
}

bool CStaticPubFunc::CreateMultiLevelDirectory(LPCTSTR lpszPath)
{
	int iPos;
	wstring wstringPathTemp;
	wstring wstringPath;
	//===================================================================================
	wstringPath = lpszPath;
	
	if(wstringPath.empty())
	{
		return false;
	}
	
	//-----------------------------------------------------------------------
	while(TRUE)
	{
		iPos = wstringPath.find(L"\\");
		
		if(-1 != iPos)
		{
			wstringPathTemp += wstringPath.substr(0, iPos + 1);
			wstringPath = wstringPath.substr(iPos + 1);
			
		}
		else
		{
			wstringPathTemp += wstringPath;
			wstringPath.clear();
		}
		
		CreateDirectory(wstringPathTemp.c_str(), NULL);
		
		if(wstringPath.empty())
		{
			break;
		}
	}
	
	return true;
}

//参数：文件名
bool CStaticPubFunc::CreateMultiLevelDirectoryEx(LPCTSTR lpszFullPathFileName)
{
	int iPos;
	wstring wstringPathTemp;
	wstring wstringTemp;
	wstring wstringPath;
	//===================================================================================
	wstringPath = lpszFullPathFileName;
	
	if(wstringPath.empty())
	{
		return false;
	}
	//-----------------------------------------------------------------------
	//把 文件名 去掉
	iPos = wstringPath.rfind (L'\\');
	if(-1 == iPos)
	{
		return false;
	}
	
	wstringPath = wstringPath.substr(0, iPos + 1);
	
	//-----------------------------------------------------------------------
	while(TRUE)
	{
		iPos = wstringPath.find(L"\\");
		
		if(-1 != iPos)
		{
			wstringPathTemp += wstringPath.substr(0, iPos + 1);
			wstringPath = wstringPath.substr(iPos + 1);			
		}
		else
		{
			wstringPathTemp += wstringPath;
			wstringPath.clear();
		}
		
		CreateDirectory(wstringPathTemp.c_str(),NULL);
		
		if(wstringPath.empty())
		{
			break;
		}
	}
	
	return true;
}

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

//---------------------------------------------------------------------

bool CStaticPubFunc::WriteTextToTxtFileOverlay(LPCTSTR lpszTxtFileFullPathName, 
											   const char * pcharContentWritten, 
											   WCHAR * pwcharMsg)
{
	HANDLE hFile = NULL;
	DWORD dwSize = 0;
	BOOL bSuccessful;
	//=================================================================================
	//Check Data
	if(!lpszTxtFileFullPathName || !pcharContentWritten)
	{
		if(pwcharMsg)
		{
			wcscpy(pwcharMsg, L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : lpszTxtFileFullPathName is NULL or pcharContentWritten is NULL");
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
		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : CreateFile failed! Error Code = %d",
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

		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : WriteFile failed! Error Code = %d", 
					 GetLastError());
		}
		
		return false;
	}
	//---------------------------------------------------------------------------------

	CloseHandle(hFile);
	hFile = NULL;
	
	return true;
}

bool CStaticPubFunc::WriteTextToTxtFileOverlay(LPCTSTR lpszTxtFileFullPathName, 
											   LPCTSTR lpszContentWritten,
											   WCHAR * pwcharMsg)
{	
	HANDLE hFile = NULL;
	DWORD dwSize = 0;
	BOOL bSuccessful;
	char * pchar = NULL;
	
	//=================================================================================
	//Check Data
	if(!lpszTxtFileFullPathName || !lpszContentWritten)
	{
		if(pwcharMsg)
		{
			wcscpy(pwcharMsg, L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : lpszTxtFileFullPathName is NULL or lpszContentWritten is NULL");
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
		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : CreateFile failed! Error Code = %d",
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

		if(pwcharMsg)
		{
			wcscpy(pwcharMsg, 
				   L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : CStaticPubFunc::pwcharTopcharEx failed!");
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

		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : WriteFile failed! Error Code = %d", 
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


bool CStaticPubFunc::WriteTextToTxtFileAppend(LPCTSTR lpszTxtFileFullPathName, 
											  LPCTSTR lpszContentWritten,
											  WCHAR * pwcharMsg)
{	
	HANDLE hFile = NULL;
	DWORD dwSize = 0;
	BOOL bSuccessful;
	char * pchar = NULL;
	DWORD dwReturn;
	//=================================================================================
	//Check Data
	if(!lpszTxtFileFullPathName || !lpszContentWritten)
	{
		if(pwcharMsg)
		{
			wcscpy(pwcharMsg, L"CprjWriteFileTestDlg::WriteTextToTxtFileAppend : lpszTxtFileFullPathName is NULL or lpszContentWritten is NULL");
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
		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileAppend : CreateFile failed! Error Code = %d",
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

		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileAppend : SetFilePointer failed! Error Code = %d", 
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

		if(pwcharMsg)
		{
			wcscpy(pwcharMsg, 
				   L"CprjWriteFileTestDlg::WriteTextToTxtFileAppend : CStaticPubFunc::pwcharTopcharEx failed!");
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

		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileAppend : WriteFile failed! Error Code = %d", 
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


bool CStaticPubFunc::WriteFileAppend(LPCTSTR lpszTxtFileFullPathName, 
									 BYTE * pbyteBuffer, 
									 DWORD dwBufferLength,
									 WCHAR * pwcharMsg)
{
	HANDLE hFile = NULL;
	DWORD dwSize = 0;
	BOOL bSuccessful = FALSE;
	char * pchar = NULL;
	DWORD dwReturn = 0;
	//=================================================================================
	//Check Data
	if(!lpszTxtFileFullPathName || !pbyteBuffer || 0 == dwBufferLength)
	{
		if(pwcharMsg)
		{
			wcscpy(pwcharMsg, L"CprjWriteFileTestDlg::WriteTextToTxtFileAppend : lpszTxtFileFullPathName is NULL or pbyteBuffer is NULL");
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
		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileAppend : CreateFile failed! Error Code = %d",
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

		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileAppend : SetFilePointer failed! Error Code = %d", 
					 GetLastError());
		}
		
		return false;
	}

	//---------------------------------------------------------------------------------
	bSuccessful = WriteFile(hFile, 
							pbyteBuffer, 
							dwBufferLength, 
							&dwSize, 
							NULL);
	if(!bSuccessful)
	{
		CloseHandle(hFile);
		hFile = NULL;

		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileAppend : WriteFile failed! Error Code = %d", 
					 GetLastError());
		}
		
		return false;
	}
	//---------------------------------------------------------------------------------
	CloseHandle(hFile);
	hFile = NULL;
		
	return true;
}


bool CStaticPubFunc::WriteTextToTxtFileAppendEx(LPCTSTR lpszTxtFileFullPathName,
												LPCTSTR lpszContentWritten)
{
	FILE * pfile = NULL;
	char * pchar = NULL;
	TCHAR * pwchar = NULL;
	long l;
	//=========================================================================
	//CheckData
	if(!lpszTxtFileFullPathName || !lpszContentWritten)
	{
		return false;
	}
	if(wcslen(lpszTxtFileFullPathName) <= 0 || wcslen(lpszContentWritten) <= 0)
	{
		return false;
	}
	//-------------------------------------------------------------------------
	pchar = CStaticPubFunc::pwcharTopcharEx(lpszContentWritten);
	if(!pchar)
	{
		return false;
	}
	//-------------------------------------------------------------------------
	pfile = _wfopen(lpszTxtFileFullPathName,L"a");
	
	if(!pfile)
	{
		return false;
	}
	//-------------------------------------------------------------------------
	//fwrite(pchar,sizeof(char),MACRO_INT_Max_Number_Written, pfile);
	l = strlen(pchar);

	fwrite(pchar,sizeof(char),l, pfile);
	
	if(pchar)
	{
		delete [] pchar;
		pchar = NULL;
	}
	//-------------------------------------------------------------------------
	fclose(pfile);

	return true;
	//-------------------------------------------------------------------------
}


bool CStaticPubFunc::ReadFileToCharArray(LPCTSTR lpszTxtFileFullPathName, 
										 char ** ppcharContent,
										 DWORD & dwFileSize,
										 WCHAR * pwcharMsg)
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
		if(pwcharMsg)
		{
			wcscpy(pwcharMsg, L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : lpszTxtFileFullPathName is NULL or ppcharContent is NULL");
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
		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : CreateFile failed! Error Code = %d",
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

			if(pwcharMsg)
			{
				swprintf(pwcharMsg, 
						 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : GetFileSize failed! Error Code = %d",
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

		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : new failed! Error Code = %d",
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

		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : WriteFile failed! Error Code = %d", 
					 GetLastError());
		}
		
		return false;
	}
	
	//---------------------------------------------------------------------------------
	CloseHandle(hFile);
	hFile = NULL;
	
	return true;
}


bool CStaticPubFunc::ReadFileToWCharArray(LPCTSTR lpszTxtFileFullPathName, 
										 WCHAR ** ppwcharContent,
										 DWORD & dwFileSize,
										 WCHAR * pwcharMsg)
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
		if(pwcharMsg)
		{
			wcscpy(pwcharMsg, L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : lpszTxtFileFullPathName is NULL or ppcharContent is NULL");
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
		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : CreateFile failed! Error Code = %d",
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

			if(pwcharMsg)
			{
				swprintf(pwcharMsg, 
						 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : GetFileSize failed! Error Code = %d",
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

		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : new failed! Error Code = %d",
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

		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CprjWriteFileTestDlg::WriteTextToTxtFileOverlay : WriteFile failed! Error Code = %d", 
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
		
		if(pwcharMsg)
		{
			wcscpy(pwcharMsg, 
				   L"CprjWriteFileTestDlg::WriteTextToTxtFileAppend : CStaticPubFunc::pcharTopwcharEx failed!");
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


//获取：当前时间（全数字）
bool CStaticPubFunc::GetCurrentTimeAllDigitEx(WCHAR * pwcharTime,
											  WCHAR * pwcharMsg,
											  enumTimeType enumTimeTypeThis,
											  LPCTSTR lpszTimeSeparator)
{
	SYSTEMTIME systime;
	//============================================================
	//Check Data
	if(!pwcharTime || !lpszTimeSeparator)
	{
		if(pwcharMsg)
		{
			wcscpy(pwcharMsg, L"CStaticPubFunc::GetCurrentTimeAllDigitEx : pwcharTime is NULL or lpszTimeSeparator is NULL");
		}
		return false;
	}
	//------------------------------------------------------------
	GetLocalTime(&systime);
	//------------------------------------------------------------
	
	switch(enumTimeTypeThis)
	{
	case eiTimeTypeAll:
		swprintf(pwcharTime,
				L"%d %4d-%02d-%02d %02d%s%02d%s%02d%s%003d",
				systime.wDayOfWeek,
				systime.wYear,
				systime.wMonth,
				systime.wDay,
				systime.wHour,
				lpszTimeSeparator,
				systime.wMinute,
				lpszTimeSeparator,
				systime.wSecond,
				lpszTimeSeparator,
				systime.wMilliseconds);
		break;

	case eiTimeTypeDateTime:
		
		swprintf(pwcharTime,
				L"%4d-%02d-%02d %02d%s%02d%s%02d",
				systime.wYear,
				systime.wMonth,
				systime.wDay,
				systime.wHour,
				lpszTimeSeparator,
				systime.wMinute,
				lpszTimeSeparator,
				systime.wSecond);
		
		break;

	case eiTimeTypeDateTimeMillisecond:
		swprintf(pwcharTime,
				L"%4d-%02d-%02d %02d%s%02d%s%02d%s%03d",
				systime.wYear,
				systime.wMonth,
				systime.wDay,
				systime.wHour,
				lpszTimeSeparator,
				systime.wMinute,
				lpszTimeSeparator,
				systime.wSecond,
				lpszTimeSeparator,
				systime.wMilliseconds);		
		break;

	case eiTimeTypeDateTimeOnlyDigit:
		
		swprintf(pwcharTime,
				L"%4d%02d%02d%02d%02d%02d",
				systime.wYear,
				systime.wMonth,
				systime.wDay,
				systime.wHour,
				systime.wMinute,
				systime.wSecond);
		
		break;

	case eiTimeTypeDateHour:
		
		swprintf(pwcharTime,
				L"%4d-%02d-%02d_%02d",
				systime.wYear,
				systime.wMonth,
				systime.wDay,
				systime.wHour);
		
		break;
	
	case eiTimeTypeDate:
		swprintf(pwcharTime,
				L"%4d-%02d-%02d",
				   systime.wYear,
				   systime.wMonth,
				   systime.wDay);
		break;

	case eiTimeTypeTime:
		swprintf(pwcharTime,
				L"%02d%s%02d%s%02d",
				   systime.wHour,
				   lpszTimeSeparator,
				   systime.wMinute,
				   lpszTimeSeparator,
				   systime.wSecond);
		break;

	case eiTimeTypeTimeMillisecond:
		swprintf(pwcharTime,
				L"%02d%s%02d%s%02d%s%003d",
				   systime.wHour,
				   lpszTimeSeparator,
				   systime.wMinute,
				   lpszTimeSeparator,
				   systime.wSecond,
				   lpszTimeSeparator,
				   systime.wMilliseconds);
		break;

	case eiTimeTypeYear:
		swprintf(pwcharTime,
				L"%4d",
				   systime.wYear);
		break;
	case eiTimeTypeMonth:
		swprintf(pwcharTime,
				L"%02d",
				   systime.wMonth);
		break;
	case eiTimeTypeDay:
		swprintf(pwcharTime,
				L"%02d",
				   systime.wDay);
		break;
	case eiTimeTypeWeek:
		swprintf(pwcharTime,
				L"%d",
				   systime.wDayOfWeek);
		break;
		
	}

	return true;
}


bool CStaticPubFunc::MsgBox(LPCTSTR lpszMsg,
							LPCRITICAL_SECTION lpCritical_Section)
{
	WCHAR szwcharCurrentTime[30];
	WCHAR * pwcharTemp = NULL;
	long lBufferSize;
	bool bReturn;
	//================================================================================================
	//Check Data
	if(!lpszMsg)
	{
		return false;
	}
	//------------------------------------------------------------------------------------------------
	
#if(MACRO_BOOL_Show_Error_MsgBox)
	
	AfxMessageBox(lpszMsg);
	
#endif	
	//------------------------------------------------------------------------------------------------
	bReturn = GetCurrentTimeAllDigitEx(szwcharCurrentTime);
	if(!bReturn)
	{
		return false;
	}
	//------------------------------------------------------------------------------------------------
	lBufferSize = wcslen(lpszMsg) + wcslen(szwcharCurrentTime) + MAX_PATH;
	
	pwcharTemp = new TCHAR[lBufferSize];
	if(!pwcharTemp)
	{
		return false;
	}
	wmemset(pwcharTemp, 0, lBufferSize);
	//------------------------------------------------------------------------------------------------
	swprintf(pwcharTemp,
			 L"--------------------------------------------------------------------\r\n"
			 L"%s\r\n\r\n"
			 L"%s\r\n",
			 szwcharCurrentTime,
			 lpszMsg);
	
	

#if(MACRO_BOOL_Write_Debug_Log)

	//OutputDebugString(lpszMsg);
	OutputDebugString(pwcharTemp);
	
	//写文件 - Lock
	if(lpCritical_Section)
	{
		EnterCriticalSection(lpCritical_Section);
	}

#if 0
	bReturn = WriteTextToTxtFileAppendEx(MACRO_STR_LOG_FILE,
										 pwcharTemp);
#else
	bReturn = WriteTextToTxtFileAppend(MACRO_STR_LOG_FILE,
									   pwcharTemp);
#endif
	
	//写文件 - UnLock
	if(lpCritical_Section)
	{
		LeaveCriticalSection(lpCritical_Section);
	}
	
	if(!bReturn)
	{
		delete [] pwcharTemp;
		pwcharTemp = NULL;
		return false;
	}
#endif
	
	delete [] pwcharTemp;
	pwcharTemp = NULL;
	
	return true;
}




bool CStaticPubFunc::DeleteDirAsRecursionEx(LPCTSTR lpszFindPath,
											LPCTSTR lpszFileName,
											WCHAR * pwcharMsg)
{
	wstring wstringFilePathNameBeFound;
	
	BOOL bSuccessful;
	
	bool bReturn;
	
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = NULL;

	wstring wstringPathCurrent;
	wstring wstringTemp;
	
	wstring wstringFindPath;
	wstring wstringFileName;
	
	WCHAR szwcharTemp[MAX_PATH * 2];

	int iTemp;
	//====================================================================================================
	OutputDebugString(L"▲▲▲Enter DeleteDirAsRecursionEx\r\n");
	
	//Check Data
	if(!lpszFindPath || !lpszFileName)
	{
		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CStaticPubFunc::DeleteDirAsRecursionEx : lpszFindPath is NULL or lpszFileName is NULL");
		}
		return false;
	}
	
	iTemp = wcslen(lpszFindPath);
	if(0 == iTemp)
	{
		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CStaticPubFunc::DeleteDirAsRecursionEx : lpszFindPath's length is 0");
		}
		return false;
	}

	iTemp = wcslen(lpszFileName);
	if(0 == iTemp)
	{
		if(pwcharMsg)
		{
			swprintf(pwcharMsg, 
					 L"CStaticPubFunc::DeleteDirAsRecursionEx : lpszFileName's length is 0");
		}
		return false;
	}
	
	wstringFindPath = lpszFindPath;
	wstringFileName = lpszFileName;
	//-------------------------------------------------------------------------------------------------
	//查找目录
	OutputDebugString(L"●●CStaticPubFunc::DeleteDirAsRecursionEx 查找目录\r\n");
	
	if(wstringFindPath[wstringFindPath.size() - 1] == L'\\')
	{
		wmemset(szwcharTemp, 0, MAX_PATH * 2);
		swprintf(szwcharTemp,
				 L"%s%s",
				 wstringFindPath.c_str(),
				 L"*.*");

		wstringFilePathNameBeFound = szwcharTemp;
		wstringPathCurrent = wstringFindPath;
	}
	else
	{
		wmemset(szwcharTemp, 0, MAX_PATH * 2);
		swprintf(szwcharTemp,
				 L"%s\\%s",
				 wstringFindPath.c_str(),
				 L"*.*");

		wstringFilePathNameBeFound = szwcharTemp;
		wstringPathCurrent = wstringFindPath;
		wstringPathCurrent += L"\\";
	}
	
	//----------------------------------------------------------------------------
	hFind = FindFirstFile(wstringFilePathNameBeFound.c_str(), &FindFileData);

	bSuccessful = TRUE;
	while(hFind != INVALID_HANDLE_VALUE && bSuccessful)
	{
		wstringTemp = wstringPathCurrent;
		wstringTemp += FindFileData.cFileName;

		OutputDebugString(wstringTemp.c_str());
		OutputDebugString(L"\r\n");
		
		//目录
		if(((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) > 0) && (FindFileData.cFileName[0] != L'.'))
		{
			wstringTemp = wstringPathCurrent;
			wstringTemp += FindFileData.cFileName;
			
			bReturn = DeleteDirAsRecursionEx(wstringTemp.c_str(),
											 lpszFileName,
											 pwcharMsg);
			if(!bReturn)
			{
				
			}
		}
		
		bSuccessful = FindNextFile(hFind,&FindFileData);
	}
	
	FindClose(hFind);
	hFind = NULL;
	//-------------------------------------------------------------------------------------------------
	//查找文件
	OutputDebugString(L"●●CStaticPubFunc::DeleteDirAsRecursionEx 查找文件\r\n");
	
	if(wstringFindPath[wstringFindPath.size() - 1] == L'\\')
	{
		wmemset(szwcharTemp, 0, MAX_PATH * 2);
		swprintf(szwcharTemp,
				 L"%s%s",
				 wstringFindPath.c_str(),
				 L"*.*");

		wstringFilePathNameBeFound = szwcharTemp;
		wstringPathCurrent = wstringFindPath;
	}
	else
	{
		wmemset(szwcharTemp, 0, MAX_PATH * 2);
		swprintf(szwcharTemp,
				 L"%s\\%s",
				 wstringFindPath.c_str(),
				 L"*.*");

		wstringFilePathNameBeFound = szwcharTemp;
		wstringPathCurrent = wstringFindPath;
		wstringPathCurrent += L"\\";
	}
	
	//----------------------------------------------------------------------------

	hFind = FindFirstFile(wstringFilePathNameBeFound.c_str(), &FindFileData);
	
	bSuccessful = TRUE;
	while(hFind != INVALID_HANDLE_VALUE && bSuccessful)
	{
		wstringTemp = wstringPathCurrent;
		wstringTemp += FindFileData.cFileName;
		OutputDebugString(wstringTemp.c_str());
		OutputDebugString(L"\r\n");

		//非目录 - 文件
		if((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) <= 0)
		{
			wstringTemp = wstringPathCurrent;
			wstringTemp += FindFileData.cFileName;
			//去掉只读属性
			if(!SetFileAttributes(wstringTemp.c_str(), FILE_ATTRIBUTE_NORMAL))
			{
				
			}
			
			if(!DeleteFile(wstringTemp.c_str()))
			{
				
			}
			OutputDebugString(L"Delete : ");
			OutputDebugString(wstringTemp.c_str());
			OutputDebugString(L"\r\n");
		}
		
		bSuccessful = FindNextFile(hFind,&FindFileData);
	}

	//-------------------------------------------------------------------------------------------------
	
	FindClose(hFind);
	hFind = NULL;

	//把这个目录删掉
	//去掉只读属性
	if(!SetFileAttributes(wstringFindPath.c_str(), FILE_ATTRIBUTE_NORMAL))
	{
		
	}
	
	if(RemoveDirectory(wstringFindPath.c_str()))
	{
		
	}
	
	OutputDebugString(L"Delete : ");
	OutputDebugString(wstringFindPath.c_str());
	OutputDebugString(L"\r\n");
	
	OutputDebugString(L"★★★Exit DeleteDirAsRecursionEx\r\n");
	
	return true;
}


