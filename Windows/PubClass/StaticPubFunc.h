#pragma once

#include "EnumStructureUnion.h"

//#include <vector>
#include <string>
using namespace std;

#include <Windows.h>

class CStaticPubFunc
{
public:
	
	static wstring ChangeBinaryToString(BYTE * pbyteBuffer, DWORD dwBufferLength);

	static wstring GetCurrentExeFileNameWithExtendName();
	static wstring GetCurrentExeFileFullPath();
	static wstring GetCurrentExeFileFullPathName();
	
	static wstring GetFileExtendName(wstring strFileName);

	static wstring GetStringNoSpecialSymbol(wstring str);

	//---------------------------------------------------------------------
	//参数：路径
	static bool CreateMultiLevelDirectory(LPCTSTR lpszPath);
	//参数：文件名
	static bool CreateMultiLevelDirectoryEx(LPCTSTR lpszFullPathFileName);

	//---------------------------------------------------------------------

	
	
	static TCHAR * GetLocalIP();
	
	//---------------------------------------------------------------------
	//多字节 宽字节 互转
	static bool pwcharTopchar(char ** ppchar,const wchar_t * pwchar,int iSrcStrCount);
	
	static char * pwcharTopchar(const wchar_t * pwchar,int iSrcStrCount);
	
	static bool pcharTopwchar(wchar_t ** ppwchar,const char * pchar,int iSrcStrCount);
	
	static wchar_t * pcharTopwchar(const char * pchar,int iSrcStrCount);

	//--------------------------------------------
	
	static bool pwcharTopcharEx(char ** ppchar,const wchar_t * pwchar);
	
	static char * pwcharTopcharEx(const wchar_t * pwchar);
	
	static bool pcharTopwcharEx(wchar_t ** ppwchar,const char * pchar);
	
	static wchar_t * pcharTopwcharEx(const char * pchar);

	//---------------------------------------------------------------------
	
	static bool WriteTextToTxtFileOverlay(LPCTSTR lpszTxtFileFullPathName,
										  const char * pcharContentWritten,
										  WCHAR * pwcharMsg = NULL);

	static bool WriteTextToTxtFileOverlay(LPCTSTR lpszTxtFileFullPathName,
										  LPCTSTR lpszContentWritten,
										  WCHAR * pwcharMsg = NULL);
	
	static bool WriteTextToTxtFileAppend(LPCTSTR lpszTxtFileFullPathName, 
										 LPCTSTR lpszContentWritten,
										 WCHAR * pwcharMsg = NULL);

	static bool WriteTextToTxtFileAppendEx(LPCTSTR lpszTxtFileFullPathName,
										   LPCTSTR lpszContentWritten);

	static bool WriteFileAppend(LPCTSTR lpszTxtFileFullPathName, 
								BYTE * pbyteBuffer, 
								DWORD dwBufferLength,
								WCHAR * pwcharMsg = NULL);

	static bool ReadFileToCharArray(LPCTSTR lpszTxtFileFullPathName, 
									char ** ppcharContent,
									DWORD & dwFileSize,
									WCHAR * pwcharMsg = NULL);

	static bool ReadFileToWCharArray(LPCTSTR lpszTxtFileFullPathName, 
									 WCHAR ** ppwcharContent,
									 DWORD & dwFileSize,
									 WCHAR * pwcharMsg = NULL);

	static bool MsgBox(LPCTSTR lpszMsg,
					   LPCRITICAL_SECTION lpCritical_Section = NULL);
	
	//获取：当前时间（全数字）
	static bool GetCurrentTimeAllDigitEx(WCHAR * pwcharTime,
										 WCHAR * pwcharMsg = NULL,
										 enumTimeType enumTimeTypeThis = eiTimeTypeDateTime,
										 LPCTSTR lpszTimeSeparator = L":");

	
	static bool DeleteDirAsRecursionEx(LPCTSTR lpszFindPath,
									   LPCTSTR lpszFileName,
									   WCHAR * pwcharMsg = NULL);
	
	static bool ExecuteFile(LPCTSTR lpszExecuteFilePathName,LPCTSTR lpszExecuteFileParameter = NULL);


	
};
