#pragma once

//#include <wininet.h>

//窗口显示状态
enum enumShowStatus
{
	eiShowStatusNew,
	eiShowStatusModify
};

enum enumLanguage
{
	eiLanguageChinese,
	eiLanguageChineseTraditional,
	eiLanguageEnglish
};


enum enumDayOfWeek
{
	eiDayOfWeekSunday,

	eiDayOfWeekMonday,
	eiDayOfWeekTuesday,
	eiDayOfWeekWednesday,
	eiDayOfWeekThurseday,
	eiDayOfWeekFriday,
	eiDayOfWeekSaturday,
	

};


enum enumTimeType
{
	eiTimeTypeAll,
	eiTimeTypeDateTime,

	eiTimeTypeDateTimeMillisecond,

	eiTimeTypeDateTimeOnlyDigit,

	eiTimeTypeDateHour,

	eiTimeTypeDate,
	eiTimeTypeTime,
	eiTimeTypeTimeMillisecond,
	
	eiTimeTypeYear,
	eiTimeTypeMonth,
	eiTimeTypeDay,

	eiTimeTypeWeek
	
};

//窗口显示形式
enum enumWindowShowModality
{
	eiWindowShowModal,
	eiWindowShowModeless
};

enum enumPartitionType
{
	eiPartitionTypeUnknown = DRIVE_UNKNOWN,
	eiPartitionTypeNoRootDir = DRIVE_NO_ROOT_DIR,
	eiPartitionTypeRemovable = DRIVE_REMOVABLE,
	eiPartitionTypeFixed = DRIVE_FIXED,
	eiPartitionTypeCDRom = DRIVE_CDROM,
	eiPartitionTypeRAMDisk = DRIVE_RAMDISK
};



typedef BOOL (* PNOTIFCALLER_FUNC)(void *ptr,void* pPar);



enum enumThreadType
{
	eiThreadType_UI,
	eiThreadType_Worker,
};

class CESUCommon
{
	
};
