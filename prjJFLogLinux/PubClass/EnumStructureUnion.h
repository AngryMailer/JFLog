#pragma once


#include "ESUCommon.h"

#include "ESUJFLog.h"



//#include <vector>
//using namespace std;



enum enumShutdownPCType
{
	eiShutdownPCTypeShutdown,
	eiShutdownPCTypeRestart,
	eiShutdownPCTypeLogoff
};


#define MACRO_STR_LOG_FILE	L"C:\\prjHackerJLYMailer.log"

//#define MACRO_BOOL_Show_Error_MsgBox	TRUE
#define MACRO_BOOL_Show_Error_MsgBox	FALSE

//#define MACRO_BOOL_Write_Debug_Log	TRUE
#define MACRO_BOOL_Write_Debug_Log	FALSE



class CEnumStructureUnion
{

};
