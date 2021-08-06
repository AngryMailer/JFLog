#pragma once

//#include <wininet.h>

//������ʾ״̬
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

//������ʾ��ʽ
enum enumWindowShowModality
{
	eiWindowShowModal,
	eiWindowShowModeless
};


typedef bool (* PNOTIFCALLER_FUNC)(void *ptr,void* pPar);



enum enumThreadType
{
	eiThreadType_UI,
	eiThreadType_Worker,
};

class CESUCommon
{
	
};
