

#ifndef _DISPLAY_VIEW_H_
#define _DISPLAY_VIEW_H_



#include "system/Mutex.h"
#include "SteamOvenCmd.h"
#include "Facorites.h"
#include <map>


#define DISPLAY_UP_TIME_ID 			0


typedef enum {
	MENU_HOME_TRADITIONAL = 0, 
	MENU_HOME_MULTI_STEP, 
	MENU_HOME_MANUAL, 
	MENU_HOME_ASSIST, 
	MENU_HOME_AUTO_PROGRAM, 
	MENU_HOME_SIZE
} MENU_HOME_E;


typedef enum {
	MENU_TRADITIONAL_MEET = 0, 
	MENU_TRADITIONAL_DESSERT, 
	MENU_TRADITIONAL_BREAD, 
	MENU_TRADITIONAL_OTHER, 
	MENU_TRADITIONAL_SIZE
} MENU_TRADITIONAL_E;


typedef enum {
	MENU_TRADITIONAL_MEET_KEBAB = 0, 
	MENU_TRADITIONAL_MEET_STUFFED_FISH, 
	MENU_TRADITIONAL_MEET_CHICKEN_KEBAB, 
	MENU_TRADITIONAL_MEET_STUFFED_CHICKEN, 
	MENU_TRADITIONAL_MEET_SIZE
} MENU_TRADITIONAL_MEET_E;

typedef enum {
	MENU_TRADITIONAL_DESSERT_YAZDI_CAKE = 0,
	MENU_TRADITIONAL_DESSERT_PUFF_PASTRY,
	MENU_TRADITIONAL_DESSERT_CHICKPEA,
	MENU_TRADITIONAL_DESSERT_FUMAN_COOKIES,
	MENU_TRADITIONAL_DESSERT_NAN_BERENJI,
	MENU_TRADITIONAL_DESSERT_SIZE
} MENU_TRADITIONAL_DESSERT_E;

typedef enum {
	MENU_TRADITIONAL_BREAD_TARTOOM = 0,
	MENU_TRADITIONAL_BREAD_BARBARI,
	MENU_TRADITIONAL_BREAD_SIZE
} MENU_TRADITIONAL_BREAD_E;


typedef enum {
	MENU_TRADITIONAL_OTHER_MIRZA_GHASEMI = 0,
	MENU_TRADITIONAL_OTHER_TAHCHIN,
	MENU_TRADITIONAL_OTHER_MEAT_BALL,
	MENU_TRADITIONAL_OTHER_DOIMA,
	MENU_TRADITIONAL_OTHER_SIZE
} MENU_TRADITIONAL_OTHER_E;


typedef enum{
	MENU_HOME_MANUAL_HOTAIR_GRILL = 0,
	MENU_HOME_MANUAL_TOP_HEATING,
	MENU_HOME_MANUAL_BOTTOMM_HEATING,
	MENU_HOME_MANUAL_BOTTOM_TOP_HEATING,
	MENU_HOME_MANUAL_GRILL,
	MENU_HOME_MANUAL_FAST_COOKING,
	MENU_HOME_MANUAL_PIZZA_MODE,
	MENU_HOME_MANUAL_HOTAIR,

	MENU_HOME_MANUAL_SIZE
}MENU_HOME_MANUAL_E;

typedef enum{
	MENU_HOME_AUTO_PROGRAM_MEET = 0,
	MENU_HOME_AUTO_PROGRAM_DESSERT,
	MENU_HOME_AUTO_PROGRAM_BREAD,
	MENU_HOME_AUTO_PROGRAM_FASTFOOD,
	MENU_HOME_AUTO_PROGRAM_OTHER,

	MENU_HOME_AUTO_PROGRAM_SIZE
}MENU_HOME_AUTO_PROGRAM_E;

typedef enum{
	MENU_HOME_AUTO_PROGRAM_MEET_MEAT_LOAF = 0,
	MENU_HOME_AUTO_PROGRAM_MEET_MEAT_STRUDEL,
	MENU_HOME_AUTO_PROGRAM_MEET_MUUSCLE,
	MENU_HOME_AUTO_PROGRAM_MEET_FISH_FILLET,
	MENU_HOME_AUTO_PROGRAM_MEET_GRILLED_FISH,
	MENU_HOME_AUTO_PROGRAM_MEET_PRAWN,
	MENU_HOME_AUTO_PROGRAM_MEET_CHICKEN_STEAK,

	MENU_HOME_AUTO_PROGRAM_MEET_SIZE
}MENU_HOME_AUTO_PROGRAM_MEET_E;


typedef enum{
	MENU_HOME_AUTO_PROGRAM_DESSERT_SPONGE_CAKE = 0,
	MENU_HOME_AUTO_PROGRAM_DESSERT_ENGLISH_CAKE,
	MENU_HOME_AUTO_PROGRAM_DESSERT_BROWNI,
	MENU_HOME_AUTO_PROGRAM_DESSERT_TART,
	MENU_HOME_AUTO_PROGRAM_DESSERT_CREAM_BUFF,
	MENU_HOME_AUTO_PROGRAM_DESSERT_APPLE_PIE,
	MENU_HOME_AUTO_PROGRAM_DESSERT_COOKIE,
	MENU_HOME_AUTO_PROGRAM_DESSERT_BISCUIT,
	MENU_HOME_AUTO_PROGRAM_DESSERT_SWEET_STRUDEL,

	MENU_HOME_AUTO_PROGRAM_DESSERT_SIZE
}MENU_HOME_AUTO_PROGRAM_DESSERT_E;

typedef enum{
	MENU_HOME_AUTO_PROGRAM_BREAD_POPOVER = 0,
	MENU_HOME_AUTO_PROGRAM_BREAD_BAGUETTE,

	MENU_HOME_AUTO_PROGRAM_BREAD_SIZE
}MENU_HOME_AUTO_PROGRAM_BREAD_E;

typedef enum{
	MENU_HOME_AUTO_PROGRAM_FASTFOOD_JUMBO_SCHLES = 0,
	MENU_HOME_AUTO_PROGRAM_FASTFOOD_LASAGNA,

	MENU_HOME_AUTO_PROGRAM_FASTFOOD_SIZE
}MENU_HOME_AUTO_PROGRAM_FASTFOOD_E;


typedef enum{
	MENU_HOME_AUTO_PROGRAM_OTHER_OMEIET = 0,
	MENU_HOME_AUTO_PROGRAM_OTHER_DUMPLINGS,
	MENU_HOME_AUTO_PROGRAM_OTHER_CHICKEN_PIE,
	MENU_HOME_AUTO_PROGRAM_OTHER_GRATIN,
	MENU_HOME_AUTO_PROGRAM_OTHER_ROAST_POTATOES,

	MENU_HOME_AUTO_PROGRAM_OTHER_SIZE
}MENU_HOME_AUTO_PROGRAM_OTHER_E;

typedef enum{
	MENU_HOME_ASSIST_DEFROST = 0,
	MENU_HOME_ASSIST_PREHEAT,
	MENU_HOME_ASSIST_KEEP_WARM,

	MENU_HOME_ASSIST_SIZE
}MENU_HOME_ASSIST_E;



#define MULTI_STEP_TYPE_DEFROST 	0
#define MULTI_STEP_TYPE_PREHEAT 	1
#define MULTI_STEP_TYPE_FUNCTION 	2

typedef enum{
	MENU_HOME_MULTI_STEP_NULL = 0,
	MENU_HOME_MULTI_STEP_HOTAIR_GRILL,
	MENU_HOME_MULTI_STEP_TOP_HEATING,
	MENU_HOME_MULTI_STEP_BOTTOMM_HEATING,
	MENU_HOME_MULTI_STEP_BOTTOM_TOP_HEATING,
	MENU_HOME_MULTI_STEP_GRILL,
	MENU_HOME_MULTI_STEP_FAST_COOKING,
	MENU_HOME_MULTI_STEP_PIZZA_MODE,
	MENU_HOME_MULTI_STEP_HOTAIR,

	MENU_HOME_MULTI_STEP_SIZE
}MENU_MULTI_STEP_E;


#define 	MULTI_STEP_DEFROST 		0 /**/
#define 	MULTI_STEP_PREHEAT 		1
#define 	MULTI_STEP_FUNCTION0 	2
#define 	MULTI_STEP_FUNCTION1 	3
#define 	MULTI_STEP_FUNCTION2 	4
#define 	MULTI_STEP_END		 	5



typedef struct {

	bool			Defrost;
	uint8			DefrostTime;
	uint8			DefrostTemper;
	uint8			DefrostFunction;
	
	bool			Preheat;
	uint8			PreheatTime;
	uint8			PreheatTemper;
	uint8			PreheatFunction;
	
	uint8			MultiStepCnt;
	uint8			MultiStepSel;
	
	uint8			PageId[3];
	uint8			PageIdTemp[3];
	
	uint8			Function[3];
	uint8			SetTime[3];
	uint8			SetTemper[3];

	uint8			CurRunFunction;


	uint8 			MultiStep;

} MULTI_STEP_PARAM_T;


#define DEAL_MIX						0 /*小份*/
#define DEAL_MEDIUM 					1 /*中份*/
#define DEAL_MAX						2 /*大份*/



#define RUN_STAGE_DEFROST	0	/*解冻*/
#define RUN_STAGE_NORMAL	1	/*正常运行模式*/
#define RUN_STAGE_KEEP_WARM	2	/*保温*/
#define RUN_STAGE_END		3	/*结束*/


class CDisplayView {

public:

	virtual ~CDisplayView();
	CDisplayView();

	static CDisplayView * getInstance();

	void InitAllParam();

	
	MULTI_STEP_PARAM_T m_MultiStepParam;


	uint8			m_MenuHome; 					/*主页*/
	uint8			m_MenuLevel1;					/*1级菜单*/
	uint8			m_MenuLevel2;					/*2级菜单*/
	uint8			m_MenuLevel3;					/*3级菜单*/

	float			m_weight; 						/*重量*/
	uint8			m_deal;							/*份量*/
	uint8 			m_cooked;						/*全熟、七成熟、少量熟*/

	uint8 			m_ChidLock;						/*童锁*/


	uint8			m_Defrost;						/*打开解冻功能 */
	uint8			m_Preheat;						/*打开预热功能 */
	uint8			m_KeepWarm;						/*打开保温功能 */
	
	uint8			m_Function; 					/*功能*/
	
	uint8			m_SetTime;						/*设置时间*/
	uint8			m_SetTemper;					/*设置温度*/
	uint8 			m_SetFoodTemper;				/*设置食物探针温度*/


	float			m_MaxWeight;					/*最大重量*/
	float			m_MinWeight;					/*最小重量*/

	uint8 			m_MinTime;
	uint8 			m_MaxTime;

	uint8 			m_MinTemper;
	uint8 			m_MaxTemper;

	uint8 			m_RunStage;						/*运行阶段*/

	/*!
		用于设置默认功能、时间、温度、重量、份量、全熟、少量熟等
	*/
	void SetDefaultParam(uint8 MenuHome, uint8 MenuLevel1 = 0, uint8 MenuLevel2 = 0, uint8 MenuLevel3 = 0);

	uint8 WeightDealToTime(float weight, uint8 deal);
	
	uint8 GetMultiStepDefaultMinTime(uint8 MenuLevel2);
	uint8 GetMultiStepDefaultMaxTime(uint8 MenuLevel2);
	uint8 GetMultiStepDefaultMinTemper(uint8 MenuLevel2);
	uint8 GetMultiStepDefaultMaxTemper(uint8 MenuLevel2);


	void SaveFacorites();
	int GetFacoritesCont();
	int GetFacoritesIndex();
	int DelFacorites(int id);	
	int AddFacorites();
	int GetFacoritesData(int index, FACORITES_T * out);
	void SetFacorites(int index);

	uint8 GetDefaultMinTemper();
	uint8 GetDefaultMaxTemper();

private:

	void SetMenuTradittonalMeetParam(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2);
	void SetMenuTradittonalDessertParam(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2);
	void SetMenuTradittonalBreadParam(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2);
	void SetMenuTradittonalOtherParam(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2);

	void SetMenuHomeAutoProgarmMeetParam(uint8 MenuLevel2);
	void SetMenuHomeAutoProgarmDessertParam(uint8 MenuLevel2);
	void SetMenuHomeAutoProgarmBreadParam(uint8 MenuLevel2);
	void SetMenuHomeAutoProgarmFastFoodParam(uint8 MenuLevel2);
	void SetMenuHomeAutoProgarmOtherParam(uint8 MenuLevel2);

	void SetMenuHomeManualParam(uint8 MenuLevel1);

	void SetMenuHomeAssistParam(uint8 MenuLevel1);


	void SetMultiStepDefrostParam();
	void SetMultiStepPreheatParam();
	void SetMultiStepFunctionParam(uint8 MenuLevel2, uint8 MenuLevel3);
	
	uint8 MenuTradittonalMeetToTime(uint8 MenuLevel2, float weight, uint8 deal);
	uint8 MenuTradittonalDessertToTime(uint8 MenuLevel2, uint8 deal);
	uint8 MenuTradittonalBreadToTime(uint8 MenuLevel2, uint8 deal);
	uint8 MenuTradittonalOtherToTime(uint8 MenuLevel2, uint8 deal);
	
	uint8 MenuAutoProgarmMeetToTime(uint8 MenuLevel2, float weight, uint8 deal);
	uint8 MenuAutoProgarmDessertToTime(uint8 MenuLevel2,uint8 deal);
	uint8 MenuAutoProgarmBreadToTime(uint8 MenuLevel2, float weight, uint8 deal);
	uint8 MenuAutoProgarmFastFoodToTime(uint8 MenuLevel2,uint8 deal);
	uint8 MenuAutoProgarmOtherToTime(uint8 MenuLevel2,uint8 deal);
	
};


#define TDisplayView			CDisplayView::getInstance()

#endif

