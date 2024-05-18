
#include "../include.h"
#include <arpa/inet.h>


const MAX_MIN_T m_DefaultTime[] =
{
	{
		0, 0, 0
	},
	{
		180, 5, 25
	},

	/*热风烤*/
	{
		180, 5, 25
	},

	/*顶部烤*/
	{
		180, 5, 25
	},

	/*底部烤*/
	{
		180, 5, 25
	},

	/*底顶烤*/
	{
		180, 5, 25
	},

	/*普通烤*/
	{
		180, 5, 25
	},

	/*快烤*/
	{
		180, 5, 25
	},

	/*披萨*/
	{
		180, 5, 25
	},

	/*空汽烤*/
	{
		180, 5, 25
	},

	/*解冻*/
	{
		180, 5, 25
	},

	/*预热*/
	{
		180, 5, 25
	},

	/*保温*/
};


const MAX_MIN_T m_DefaultTemper[] =
{
	{
		0, 0, 0
	},
	{
		220, 100, 200
	},

	/*热风烤*/
	{
		220, 100, 200
	},

	/*顶部烤*/
	{
		220, 100, 200
	},

	/*底部烤*/
	{
		220, 100, 200
	},

	/*底顶烤*/
	{
		220, 100, 200
	},

	/*普通烤*/
	{
		220, 100, 200
	},

	/*快烤*/
	{
		220, 100, 200
	},

	/*披萨*/
	{
		220, 100, 200
	},

	/*空汽烤*/
	{
		220, 100, 200
	},

	/*解冻*/
	{
		220, 100, 200
	},

	/*预热*/
	{
		220, 100, 200
	},

	/*保温*/
};


CDisplayView::~CDisplayView()
{



}


CDisplayView::CDisplayView()
	: m_MenuHome(0)
	, m_MenuLevel1(0)
	, m_MenuLevel2(0)
	, m_MenuLevel3(0)
	, m_weight(0)
	, m_deal(0)
	, m_cooked(0)
	, m_ChidLock(0)
	, m_Defrost(0)
	, m_Preheat(0)
	, m_KeepWarm(0)
	, m_Function(0)
	, m_SetTime(0)
	, m_SetTemper(0)
	, m_SetFoodTemper(0)
{

	memset(&m_MultiStepParam, 0, sizeof(MULTI_STEP_PARAM_T));

}




CDisplayView * CDisplayView::getInstance()
{
	static CDisplayView DisplayView;

	return & DisplayView;
}


void CDisplayView::InitAllParam()
{

	memset(&m_MultiStepParam, 0, sizeof(MULTI_STEP_PARAM_T));

	m_MenuHome			= 0;						/*主页*/
	m_MenuLevel1		= 0;						/*1级菜单*/
	m_MenuLevel2		= 0;						/*2级菜单*/
	m_MenuLevel3		= 0;						/*3级菜单*/
	m_weight			= 0;						/*重量*/
	m_deal				= 0;						/*份量*/
	m_cooked			= 0;						/*全熟、七成熟、少量熟*/
	m_ChidLock			= 0;						/*童锁*/

	m_Preheat			= 0;						/*打开预热功能 */
	m_KeepWarm			= 0;						/*打开保温功能 */
	m_Function			= 0;						/*功能*/
	m_SetTime			= 0;						/*设置时间*/
	m_SetTemper 		= 0;						/*设置温度*/
	m_SetFoodTemper 	= 0;						/*设置食物探针温度*/
	m_Defrost			= 0;
}


void CDisplayView::SetMenuTradittonalMeetParam(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2)
{



	m_Function			= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "Function");

	m_SetTemper 		= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "temper");

	m_weight			= CConfig::getInstance()->GetKeyFloat(MenuHome, MenuLevel1, MenuLevel2, "Weight");

	m_deal				= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "Deal");

	m_MaxWeight 		= CConfig::getInstance()->GetKeyFloat(MenuHome, MenuLevel1, MenuLevel2, "WeightMax");

	m_MinWeight 		= CConfig::getInstance()->GetKeyFloat(MenuHome, MenuLevel1, MenuLevel2, "WeightMin");

	m_cooked			= 0;
	m_SetTime			= 0;

}


void CDisplayView::SetMenuTradittonalDessertParam(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2)
{



	m_Function			= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "Function");

	m_SetTemper 		= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "temper");

	m_deal				= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "Deal");

	m_cooked			= 0;
	m_SetTime			= 0;
	m_weight			= 0.0;
	m_MaxWeight 		= 0.0;
	m_MinWeight 		= 0.0;
}



void CDisplayView::SetMenuTradittonalBreadParam(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2)
{



	m_Function			= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "Function");

	m_SetTemper 		= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "temper");

	m_deal				= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "Deal");

	m_cooked			= 0;
	m_SetTime			= 0;
	m_weight			= 0.0;
	m_MaxWeight 		= 0.0;
	m_MinWeight 		= 0.0;

}


void CDisplayView::SetMenuTradittonalOtherParam(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2)
{


	m_Function			= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "Function");

	m_SetTemper 		= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "temper");

	m_deal				= CConfig::getInstance()->GetKeyInt(MenuHome, MenuLevel1, MenuLevel2, "Deal");

	m_cooked			= 0;
	m_SetTime			= 0;
	m_weight			= 0.0;
	m_MaxWeight 		= 0.0;
	m_MinWeight 		= 0.0;

}


void CDisplayView::SetMenuHomeManualParam(uint8 MenuLevel1)
{


	m_Function			= CConfig::getInstance()->GetKeyInt(MENU_HOME_MANUAL, MenuLevel1, "Function");
	m_SetTime			= CConfig::getInstance()->GetKeyInt(MENU_HOME_MANUAL, MenuLevel1, "time");
	m_MinTime			= CConfig::getInstance()->GetKeyInt(MENU_HOME_MANUAL, MenuLevel1, "MinTime");
	m_MaxTime			= CConfig::getInstance()->GetKeyInt(MENU_HOME_MANUAL, MenuLevel1, "MaxTime");
	m_SetTemper 		= CConfig::getInstance()->GetKeyInt(MENU_HOME_MANUAL, MenuLevel1, "temper");
	m_MinTemper 		= CConfig::getInstance()->GetKeyInt(MENU_HOME_MANUAL, MenuLevel1, "MinTemper");
	m_MaxTemper 		= CConfig::getInstance()->GetKeyInt(MENU_HOME_MANUAL, MenuLevel1, "MaxTemper");

	m_deal				= 0;
	m_cooked			= 0;
	m_weight			= 0.0;
	m_MaxWeight 		= 0.0;
	m_MinWeight 		= 0.0;

}


void CDisplayView::SetMenuHomeAssistParam(uint8 MenuLevel1)
{


	m_Function			= CConfig::getInstance()->GetKeyInt(MENU_HOME_ASSIST, MenuLevel1, "Function");
	m_SetTime			= CConfig::getInstance()->GetKeyInt(MENU_HOME_ASSIST, MenuLevel1, "time");
	m_MinTime			= CConfig::getInstance()->GetKeyInt(MENU_HOME_ASSIST, MenuLevel1, "MinTime");
	m_MaxTime			= CConfig::getInstance()->GetKeyInt(MENU_HOME_ASSIST, MenuLevel1, "MaxTime");
	m_SetTemper 		= CConfig::getInstance()->GetKeyInt(MENU_HOME_ASSIST, MenuLevel1, "temper");
	m_MinTemper 		= CConfig::getInstance()->GetKeyInt(MENU_HOME_ASSIST, MenuLevel1, "MinTemper");
	m_MaxTemper 		= CConfig::getInstance()->GetKeyInt(MENU_HOME_ASSIST, MenuLevel1, "MaxTemper");

	m_deal				= 0;
	m_cooked			= 0;
	m_weight			= 0.0;
	m_MaxWeight 		= 0.0;
	m_MinWeight 		= 0.0;

}


void CDisplayView::SetMenuHomeAutoProgarmMeetParam(uint8 MenuLevel2)
{


	m_Function			= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_MEET,
		 MenuLevel2, "Function");

	m_SetTemper 		= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_MEET,
		 MenuLevel2, "temper");

	m_weight			= CConfig::getInstance()->GetKeyFloat(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_MEET,
		 MenuLevel2, "Weight");

	m_deal				= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_MEET,
		 MenuLevel2, "Deal");

	m_MaxWeight 		= CConfig::getInstance()->GetKeyFloat(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_MEET,
		 MenuLevel2, "WeightMax");

	m_MinWeight 		= CConfig::getInstance()->GetKeyFloat(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_MEET,
		 MenuLevel2, "WeightMin");

	m_cooked			= 0;
	m_SetTime			= 0;

}


void CDisplayView::SetMenuHomeAutoProgarmDessertParam(uint8 MenuLevel2)
{



	m_Function			= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_DESSERT,
		 MenuLevel2, "Function");

	m_SetTemper 		= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_DESSERT,
		 MenuLevel2, "temper");

	m_deal				= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_DESSERT,
		 MenuLevel2, "Deal");

	m_cooked			= 0;
	m_SetTime			= 0;
	m_weight			= 0.0;
	m_MaxWeight 		= 0.0;
	m_MinWeight 		= 0.0;
}


void CDisplayView::SetMenuHomeAutoProgarmBreadParam(uint8 MenuLevel2)
{


	m_Function			= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_BREAD,
		 MenuLevel2, "Function");

	m_SetTemper 		= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_BREAD,
		 MenuLevel2, "temper");

	m_weight			= CConfig::getInstance()->GetKeyFloat(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_BREAD,
		 MenuLevel2, "Weight");

	m_deal				= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_BREAD,
		 MenuLevel2, "Deal");

	m_MaxWeight 		= CConfig::getInstance()->GetKeyFloat(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_BREAD,
		 MenuLevel2, "WeightMax");

	m_MinWeight 		= CConfig::getInstance()->GetKeyFloat(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_BREAD,
		 MenuLevel2, "WeightMin");

	m_cooked			= 0;
	m_SetTime			= 0;

}


void CDisplayView::SetMenuHomeAutoProgarmFastFoodParam(uint8 MenuLevel2)
{



	m_Function			= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_FASTFOOD,
		 MenuLevel2, "Function");

	m_SetTemper 		= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_FASTFOOD,
		 MenuLevel2, "temper");

	m_deal				= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_FASTFOOD,
		 MenuLevel2, "Deal");

	m_cooked			= 0;
	m_SetTime			= 0;
	m_weight			= 0.0;
	m_MaxWeight 		= 0.0;
	m_MinWeight 		= 0.0;
}


void CDisplayView::SetMenuHomeAutoProgarmOtherParam(uint8 MenuLevel2)
{



	m_Function			= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_OTHER,
		 MenuLevel2, "Function");

	m_SetTemper 		= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_OTHER,
		 MenuLevel2, "temper");

	m_deal				= CConfig::getInstance()->GetKeyInt(MENU_HOME_AUTO_PROGRAM, MENU_HOME_AUTO_PROGRAM_OTHER,
		 MenuLevel2, "Deal");

	m_cooked			= 0;
	m_SetTime			= 0;
	m_weight			= 0.0;
	m_MaxWeight 		= 0.0;
	m_MinWeight 		= 0.0;
}


void CDisplayView::SetMultiStepDefrostParam()
{

	m_MultiStepParam.DefrostFunction = CConfig::getInstance()->GetKeyInt(MENU_HOME_MULTI_STEP,
		 MULTI_STEP_TYPE_DEFROST, "Function");
	m_MultiStepParam.DefrostTemper = CConfig::getInstance()->GetKeyInt(MENU_HOME_MULTI_STEP, MULTI_STEP_TYPE_DEFROST, "temper");
	m_MultiStepParam.DefrostTime = CConfig::getInstance()->GetKeyInt(MENU_HOME_MULTI_STEP, MULTI_STEP_TYPE_DEFROST, "time");



	m_Function			= 0;
	m_SetTime			= 0;
	m_MinTime			= 0;
	m_MaxTime			= 0;
	m_SetTemper 		= 0;
	m_MinTemper 		= 0;
	m_MaxTemper 		= 0;

	m_deal				= 0;
	m_cooked			= 0;
	m_weight			= 0.0;
	m_MaxWeight 		= 0.0;
	m_MinWeight 		= 0.0;

	ILOGD("DefrostFunction:%d, DefrostTemper:%d, DefrostTime:%d \n", m_MultiStepParam.DefrostFunction,
		 m_MultiStepParam.DefrostTemper, m_MultiStepParam.DefrostTime);
}


void CDisplayView::SetMultiStepPreheatParam()
{

	m_MultiStepParam.PreheatFunction = CConfig::getInstance()->GetKeyInt(MENU_HOME_MULTI_STEP,
		 MULTI_STEP_TYPE_PREHEAT, "Function");
	m_MultiStepParam.PreheatTemper = CConfig::getInstance()->GetKeyInt(MENU_HOME_MULTI_STEP, MULTI_STEP_TYPE_PREHEAT, "temper");
	m_MultiStepParam.PreheatTime = CConfig::getInstance()->GetKeyInt(MENU_HOME_MULTI_STEP, MULTI_STEP_TYPE_PREHEAT, "time");


	m_Function			= 0;
	m_SetTime			= 0;
	m_MinTime			= 0;
	m_MaxTime			= 0;
	m_SetTemper 		= 0;
	m_MinTemper 		= 0;
	m_MaxTemper 		= 0;

	m_deal				= 0;
	m_cooked			= 0;
	m_weight			= 0.0;
	m_MaxWeight 		= 0.0;
	m_MinWeight 		= 0.0;

	ILOGD("PreheatFunction:%d, PreheatTemper:%d, PreheatTime:%d \n", m_MultiStepParam.PreheatFunction,
		 m_MultiStepParam.PreheatTemper, m_MultiStepParam.PreheatTime);

}


void CDisplayView::SetMultiStepFunctionParam(uint8 MenuLevel2, uint8 MenuLevel3)
{

	m_MultiStepParam.Function[MenuLevel2] 	= CConfig::getInstance()->GetKeyInt(MENU_HOME_MULTI_STEP,	 	MULTI_STEP_TYPE_FUNCTION, MenuLevel3 -1, "Function");
	m_MultiStepParam.SetTemper[MenuLevel2] 	= CConfig::getInstance()->GetKeyInt(MENU_HOME_MULTI_STEP, 		MULTI_STEP_TYPE_FUNCTION, MenuLevel3 -1, "temper");
	m_MultiStepParam.SetTime[MenuLevel2] 	= CConfig::getInstance()->GetKeyInt(MENU_HOME_MULTI_STEP,	 	MULTI_STEP_TYPE_FUNCTION, MenuLevel3 -1, "time");

	m_Function			= 0;
	m_SetTime			= 0;
	m_MinTime			= 0;
	m_MaxTime			= 0;
	m_SetTemper 		= 0;
	m_MinTemper 		= 0;
	m_MaxTemper 		= 0;

	m_deal				= 0;
	m_cooked			= 0;
	m_weight			= 0.0;
	m_MaxWeight 		= 0.0;
	m_MinWeight 		= 0.0;

	ILOGD("MenuLevel2:%d, MenuLevel3:%d, Function:%d SetTemper:%d, SetTime:%d \n", MenuLevel2, MenuLevel3,
		 m_MultiStepParam.Function[MenuLevel2], 
		 m_MultiStepParam.SetTemper[MenuLevel2],
		 m_MultiStepParam.SetTime[MenuLevel2]);

}


void CDisplayView::SetDefaultParam(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2, uint8 MenuLevel3)
{

	if (MenuHome == MENU_HOME_TRADITIONAL) {
		if (MenuLevel1 == MENU_TRADITIONAL_MEET) {
			SetMenuTradittonalMeetParam(MenuHome, MenuLevel1, MenuLevel2);
		}
		else if (MenuLevel1 == MENU_TRADITIONAL_DESSERT) {
			SetMenuTradittonalDessertParam(MenuHome, MenuLevel1, MenuLevel2);
		}
		else if (MenuLevel1 == MENU_TRADITIONAL_BREAD) {
			SetMenuTradittonalBreadParam(MenuHome, MenuLevel1, MenuLevel2);
		}
		else if (MenuLevel1 == MENU_TRADITIONAL_OTHER) {
			SetMenuTradittonalOtherParam(MenuHome, MenuLevel1, MenuLevel2);
		}

	}
	else if (MenuHome == MENU_HOME_MULTI_STEP) {

		if (MenuLevel1 == MULTI_STEP_TYPE_DEFROST) {
			SetMultiStepDefrostParam();
		}
		else if (MenuLevel1 == MULTI_STEP_TYPE_PREHEAT) {
			SetMultiStepPreheatParam();
		}
		else if (MenuLevel1 == MULTI_STEP_TYPE_FUNCTION) {
			SetMultiStepFunctionParam(MenuLevel2, MenuLevel3);
		}
	}
	else if (MenuHome == MENU_HOME_MANUAL) {
		SetMenuHomeManualParam(MenuLevel1);
	}
	else if (MenuHome == MENU_HOME_ASSIST) {
		SetMenuHomeAssistParam(MenuLevel1);
	}
	else if (MenuHome == MENU_HOME_AUTO_PROGRAM) {

		if (MenuLevel1 == MENU_HOME_AUTO_PROGRAM_MEET) {
			SetMenuHomeAutoProgarmMeetParam(MenuLevel2);
		}
		else if (MenuLevel1 == MENU_HOME_AUTO_PROGRAM_DESSERT) {
			SetMenuHomeAutoProgarmDessertParam(MenuLevel2);
		}
		else if (MenuLevel1 == MENU_HOME_AUTO_PROGRAM_BREAD) {
			SetMenuHomeAutoProgarmBreadParam(MenuLevel2);
		}
		else if (MenuLevel1 == MENU_HOME_AUTO_PROGRAM_FASTFOOD) {
			SetMenuHomeAutoProgarmFastFoodParam(MenuLevel2);
		}
		else if (MenuLevel1 == MENU_HOME_AUTO_PROGRAM_OTHER) {
			SetMenuHomeAutoProgarmOtherParam(MenuLevel2);
		}

	}

	ILOGD("Default Param: fun:%d, weight:%.1f, deal:%d, time:%d, temper:%d \n", m_Function, m_weight, m_deal, 
		m_SetTime, m_SetTemper);

}


uint8 CDisplayView::MenuTradittonalMeetToTime(uint8 MenuLevel2, float weight, uint8 deal)
{

	vector < TRADITTIONAL_MEET_DATA_T > Data;

	uint8			ret = 0;

	CConfig::getInstance()->GetKeyTradittonalMeet(MenuLevel2, &Data);

	vector <TRADITTIONAL_MEET_DATA_T>::iterator it;

	for (it = Data.begin(); it != Data.end(); it++) {

		if ((weight == it->Weight) && (it->Deal == deal)) {
			ret 				= it->time;
			break;
		}

	}

	Data.clear();

	return ret;
}


uint8 CDisplayView::MenuTradittonalDessertToTime(uint8 MenuLevel2, uint8 deal)
{

	vector < TRADITTIONAL_MEET_DATA_T > Data;

	uint8			ret = 0;

	CConfig::getInstance()->GetKeyTradittonalMeet(MenuLevel2, &Data);

	vector <TRADITTIONAL_MEET_DATA_T>::iterator it;

	for (it = Data.begin(); it != Data.end(); it++) {

		if (it->Deal == deal) {
			ret 				= it->time;
			break;
		}

	}

	Data.clear();

	return ret;
}


uint8 CDisplayView::MenuTradittonalBreadToTime(uint8 MenuLevel2, uint8 deal)
{

	vector < TRADITTIONAL_BREAD_DATA_T > Data;

	uint8			ret = 0;

	CConfig::getInstance()->GetKeyTradittonalBread(MenuLevel2, &Data);

	vector <TRADITTIONAL_BREAD_DATA_T>::iterator it;

	for (it = Data.begin(); it != Data.end(); it++) {

		if (it->Deal == deal) {
			ret 				= it->time;
			break;
		}

	}

	Data.clear();

	return ret;
}


uint8 CDisplayView::MenuTradittonalOtherToTime(uint8 MenuLevel2, uint8 deal)
{

	vector < TRADITTIONAL_OTHER_DATA_T > Data;

	uint8			ret = 0;

	CConfig::getInstance()->GetKeyTradittonalOther(MenuLevel2, &Data);

	vector <TRADITTIONAL_OTHER_DATA_T>::iterator it;

	for (it = Data.begin(); it != Data.end(); it++) {

		if (it->Deal == deal) {
			ret 				= it->time;
			break;
		}

	}

	Data.clear();

	return ret;
}


uint8 CDisplayView::MenuAutoProgarmMeetToTime(uint8 MenuLevel2, float weight, uint8 deal)
{

	vector < AUTO_PROGRAM_MEET_DATA_T > Data;

	uint8			ret = 0;

	CConfig::getInstance()->GetKeyAutoProgramMeat(MenuLevel2, &Data);

	vector <AUTO_PROGRAM_MEET_DATA_T>::iterator it;

	for (it = Data.begin(); it != Data.end(); it++) {

		if ((weight == it->Weight) && (it->Deal == deal)) {
			ret 				= it->time;
			break;
		}

	}

	Data.clear();

	return ret;
}


uint8 CDisplayView::MenuAutoProgarmDessertToTime(uint8 MenuLevel2, uint8 deal)
{

	vector < AUTO_PROGRAM_DESSERT_DATA_T > Data;

	uint8			ret = 0;

	CConfig::getInstance()->GetKeyAutoProgramDessert(MenuLevel2, &Data);

	vector <AUTO_PROGRAM_DESSERT_DATA_T>::iterator it;

	for (it = Data.begin(); it != Data.end(); it++) {

		if (it->Deal == deal) {
			ret 				= it->time;
			break;
		}

	}

	Data.clear();

	return ret;
}


uint8 CDisplayView::MenuAutoProgarmBreadToTime(uint8 MenuLevel2, float weight, uint8 deal)
{

	vector < AUTO_PROGRAM_BREAD_DATA_T > Data;

	uint8			ret = 0;

	CConfig::getInstance()->GetKeyAutoProgramBread(MenuLevel2, &Data);

	vector <AUTO_PROGRAM_BREAD_DATA_T>::iterator it;

	for (it = Data.begin(); it != Data.end(); it++) {

		if ((weight == it->Weight) && (it->Deal == deal)) {
			ret 				= it->time;
			break;
		}

	}

	Data.clear();

	return ret;
}


uint8 CDisplayView::MenuAutoProgarmFastFoodToTime(uint8 MenuLevel2, uint8 deal)
{

	vector < AUTO_PROGRAM_FASTFOOD_DATA_T > Data;

	uint8			ret = 0;

	CConfig::getInstance()->GetKeyAutoProgramFastFood(MenuLevel2, &Data);

	vector <AUTO_PROGRAM_FASTFOOD_DATA_T>::iterator it;

	for (it = Data.begin(); it != Data.end(); it++) {

		if (it->Deal == deal) {
			ret 				= it->time;
			break;
		}

	}

	Data.clear();

	return ret;
}


uint8 CDisplayView::MenuAutoProgarmOtherToTime(uint8 MenuLevel2, uint8 deal)
{

	vector < AUTO_PROGRAM_OTHER_DATA_T > Data;

	uint8			ret = 0;

	CConfig::getInstance()->GetKeyAutoProgramOther(MenuLevel2, &Data);

	vector <AUTO_PROGRAM_OTHER_DATA_T>::iterator it;

	for (it = Data.begin(); it != Data.end(); it++) {

		if (it->Deal == deal) {
			ret 				= it->time;
			break;
		}

	}

	Data.clear();

	return ret;
}


uint8 CDisplayView::WeightDealToTime(float weight, uint8 deal)
{

	if (m_MenuHome == MENU_HOME_TRADITIONAL) {
		if (m_MenuLevel1 == MENU_TRADITIONAL_MEET) {
			return MenuTradittonalMeetToTime(m_MenuLevel2, weight, deal);
		}
		else if (m_MenuLevel1 == MENU_TRADITIONAL_DESSERT) {
			return MenuTradittonalDessertToTime(m_MenuLevel2, deal);
		}
		else if (m_MenuLevel1 == MENU_TRADITIONAL_BREAD) {
			return MenuTradittonalBreadToTime(m_MenuLevel2, deal);
		}
		else if (m_MenuLevel1 == MENU_TRADITIONAL_OTHER) {
			return MenuTradittonalOtherToTime(m_MenuLevel2, deal);
		}
	}
	else if (m_MenuHome == MENU_HOME_AUTO_PROGRAM) {

		if (m_MenuLevel1 == MENU_HOME_AUTO_PROGRAM_MEET) {
			return MenuAutoProgarmMeetToTime(m_MenuLevel2, weight, deal);
		}
		else if (m_MenuLevel1 == MENU_HOME_AUTO_PROGRAM_DESSERT) {
			return MenuAutoProgarmDessertToTime(m_MenuLevel2, deal);
		}
		else if (m_MenuLevel1 == MENU_HOME_AUTO_PROGRAM_BREAD) {
			return MenuAutoProgarmBreadToTime(m_MenuLevel2, weight, deal);
		}
		else if (m_MenuLevel1 == MENU_HOME_AUTO_PROGRAM_FASTFOOD) {
			return MenuAutoProgarmFastFoodToTime(m_MenuLevel2, deal);
		}
		else if (m_MenuLevel1 == MENU_HOME_AUTO_PROGRAM_OTHER) {
			return MenuAutoProgarmOtherToTime(m_MenuLevel2, deal);
		}

	}

	return 0;
}



void CDisplayView::SetFacorites(int index)
{

	FACORITES_T 	data;

	if (CFacorites::getInstance()->GetData(index, &data)) {

		m_MenuHome			= data.MenuHome;
		m_MenuLevel1		= data.MenuLevel1;
		m_MenuLevel2		= data.MenuLevel2;
		m_MenuLevel3		= data.MenuLevel3;
		m_weight			= data.weight;
		m_deal				= data.deal;
		m_cooked			= data.cooked;

		m_Function			= data.Function;
		m_SetTime			= data.SetTime;
		m_SetTemper 		= data.SetTemper;
		m_SetFoodTemper 	= data.SetFoodTemper;

		m_Preheat			= data.Preheat;
		m_KeepWarm			= data.KeepWarm;

		
	}

}


int CDisplayView::GetFacoritesCont()
{

	return CFacorites::getInstance()->GetCont();
}


int CDisplayView::GetFacoritesIndex()
{

	FACORITES_T 	Facorites;

	Facorites.MenuHome	= m_MenuHome;
	Facorites.MenuLevel1 = m_MenuLevel1;
	Facorites.MenuLevel2 = m_MenuLevel2;
	Facorites.MenuLevel3 = m_MenuLevel3;
	Facorites.weight	= m_weight;
	Facorites.deal		= m_deal;
	Facorites.cooked	= m_cooked;

	Facorites.Function	= m_Function;
	Facorites.SetTime	= m_SetTime;
	Facorites.SetTemper = m_SetTemper;
	Facorites.SetFoodTemper = m_SetFoodTemper;

	Facorites.Preheat	= m_Preheat;
	Facorites.KeepWarm	= m_KeepWarm;

	return CFacorites::getInstance()->FindIndex(&Facorites);
}


int CDisplayView::AddFacorites()
{


	FACORITES_T 	Facorites;

	Facorites.MenuHome	= m_MenuHome;
	Facorites.MenuLevel1 = m_MenuLevel1;
	Facorites.MenuLevel2 = m_MenuLevel2;
	Facorites.MenuLevel3 = m_MenuLevel3;
	Facorites.weight	= m_weight;
	Facorites.deal		= m_deal;
	Facorites.cooked	= m_cooked;

	Facorites.Function	= m_Function;
	Facorites.SetTime	= m_SetTime;
	Facorites.SetTemper = m_SetTemper;
	Facorites.SetFoodTemper = m_SetFoodTemper;

	Facorites.Preheat	= m_Preheat;
	Facorites.KeepWarm	= m_KeepWarm;

	ILOGD("KeepWarm:%d,%d \n", Facorites.KeepWarm,m_KeepWarm);

	return CFacorites::getInstance()->Add(&Facorites);

}


int CDisplayView::DelFacorites(int id)
{

	return CFacorites::getInstance()->Del(id);

}


void CDisplayView::SaveFacorites()
{

	CFacorites::getInstance()->SaveData();
}


int CDisplayView::GetFacoritesData(int index, FACORITES_T * out)
{
	return CFacorites::getInstance()->GetData(index, out);
}



uint8 CDisplayView::GetMultiStepDefaultMinTime(uint8 MenuLevel2)
{

	uint8			Function = 0;

	Function			= m_MultiStepParam.Function[MenuLevel2];

	return m_DefaultTime[Function].Min;
}


uint8 CDisplayView::GetMultiStepDefaultMaxTime(uint8 MenuLevel2)
{

	uint8			Function = 0;

	Function			= m_MultiStepParam.Function[MenuLevel2];

	return m_DefaultTime[Function].Max;
}


uint8 CDisplayView::GetMultiStepDefaultMinTemper(uint8 MenuLevel2)
{

	uint8			Function = 0;

	Function			= m_MultiStepParam.Function[MenuLevel2];

	return m_DefaultTemper[Function].Min;
}


uint8 CDisplayView::GetMultiStepDefaultMaxTemper(uint8 MenuLevel2)
{

	uint8			Function = 0;

	Function			= m_MultiStepParam.Function[MenuLevel2];

	return m_DefaultTemper[Function].Max;
}


uint8 CDisplayView::GetDefaultMinTemper()
{

	return m_MinTemper;
}


uint8 CDisplayView::GetDefaultMaxTemper()
{

	return m_MaxTemper;
}


