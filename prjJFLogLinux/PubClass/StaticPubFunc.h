#pragma once

#include "EnumStructureUnion.h"

//#include <vector>
#include <string>
using namespace std;

//#include <Windows.h>

class CStaticPubFunc
{
public:
	
	//static string ChangeBinaryToString(BYTE * pbyteBuffer, DWORD dwBufferLength);

	static string GetCurrentExeFileNameWithExtendName();
	static string GetCurrentExeFileFullPath();
	static string GetCurrentExeFileFullPathName();
	
	static string GetFileExtendName(string strFileName);

	static string GetStringNoSpecialSymbol(string str);

	//---------------------------------------------------------------------

	static bool CreateMultiLevelDirectory(char * lpszPath);

	static bool CreateMultiLevelDirectoryEx(char * lpszFullPathFileName);

	//---------------------------------------------------------------------

	
	//---------------------------------------------------------------------
#if 0
	static bool pwcharTopchar(char ** ppchar,const wchar_t * pwchar,int iSrcStrCount);
	
	static char * pwcharTopchar(const wchar_t * pwchar,int iSrcStrCount);
	
	static bool pcharTopwchar(wchar_t ** ppwchar,const char * pchar,int iSrcStrCount);
	
	static wchar_t * pcharTopwchar(const char * pchar,int iSrcStrCount);

	//--------------------------------------------
	
	static bool pwcharTopcharEx(char ** ppchar,const wchar_t * pwchar);
	
	static char * pwcharTopcharEx(const wchar_t * pwchar);
	
	static bool pcharTopwcharEx(wchar_t ** ppwchar,const char * pchar);
	
	static wchar_t * pcharTopwcharEx(const char * pchar);
#endif
	//---------------------------------------------------------------------
#if 0
	static bool WriteTextToTxtFileOverlay(char * lpszTxtFileFullPathName,
										  const char * pcharContentWritten,
										  char * pcharMsg = NULL);

	static bool WriteTextToTxtFileOverlay(char * lpszTxtFileFullPathName,
										  char * lpszContentWritten,
										  char * pcharMsg = NULL);
#endif

	static bool WriteTextToTxtFileAppend(char * lpszTxtFileFullPathName,
										 char * lpszContentWritten,
										 char * pcharMsg = NULL);

	static bool WriteTextToTxtFileAppendEx(char * lpszTxtFileFullPathName,
										   char * lpszContentWritten,
										   char * pcharMsg = NULL);

	static bool WriteFileAppend(char * lpszTxtFileFullPathName,
									char * pbyteBuffer,
									long dwBufferLength,
									char * pcharMsg = NULL);

#if 0
	static bool ReadFileToCharArray(char * lpszTxtFileFullPathName,
									char ** ppcharContent,
									DWORD & dwFileSize,
									char * pcharMsg = NULL);

	static bool ReadFileToWCharArray(char * lpszTxtFileFullPathName,
									 char ** ppwcharContent,
									 DWORD & dwFileSize,
									 char * pcharMsg = NULL);
#endif

	

	static bool GetCurrentTimeAllDigitEx(char * pcharTime,
										 char * pcharMsg = NULL,
										 enumTimeType enumTimeTypeThis = eiTimeTypeDateTime,
										 char * lpszTimeSeparator = (char*)":");

#if 0
	static bool DeleteDirAsRecursionEx(char * lpszFindPath,
									   char * lpszFileName,
									   char * pcharMsg = NULL);
	
	static bool ExecuteFile(char * lpszExecuteFilePathName,char * lpszExecuteFileParameter = NULL);
#endif

	
};
