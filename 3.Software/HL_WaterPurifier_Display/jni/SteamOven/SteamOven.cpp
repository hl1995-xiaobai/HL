
#include "../include.h"
#include "utils/TimeHelper.h"



SteamOven::~SteamOven()	
{

}


SteamOven::SteamOven()
{

	
}


SteamOven * SteamOven::getInstance()
{
	static SteamOven SteamOven;

	return & SteamOven;
}



void SteamOven::SteamOvenLoop20ms()
{
	//ILOGD("Thread Loop 20MS \n");
}


void SteamOven::SteamOvenLoop100ms()
{
	
	CFlash::getInstance()->Loop100ms();
}


void SteamOven::SteamOvenLoop500ms()
{

	CFlash::getInstance()->Loop500ms();
}




void SteamOven::SteamOvenLoop1S()
{
	CLighiting::getInstance()->Lighting1SLoop();
	CAlarm::getInstance()->AlarmLoop();
}

/*开机*/
void SteamOven::PowerOn(){

	CDisplayView::getInstance()->InitAllParam();

	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);

	SteamOvenView::getInstance()->m_ErrorNumber		= ERROR_CODE_NO_ERROR;
	SteamOvenView::getInstance()->m_PowerOn			= STEAM_OVEN_POWER_ON;
	
	SteamOvenView::getInstance()->m_RotatePump		= 0;
	SteamOvenView::getInstance()->m_Preheat			= 0;
	SteamOvenView::getInstance()->m_KeepWarm		= 0;
	SteamOvenView::getInstance()->m_Function		= STEAM_OVEN_FUNCTION_OFF;
	SteamOvenView::getInstance()->m_SetTime			= 0;
	SteamOvenView::getInstance()->m_SetTemper 		= 0;
	SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;
	SteamOvenView::getInstance()->m_RunState		= 0;
	
	CDisplayView::getInstance()->m_RunStage		= RUN_STAGE_DEFROST;


	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_POWER_ON;

		
}


/*关机*/
void SteamOven::PowerOff()
{
	
	CDisplayView::getInstance()->InitAllParam();
	
	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);

	SteamOvenView::getInstance()->m_ErrorNumber 	= ERROR_CODE_NO_ERROR;
	SteamOvenView::getInstance()->m_PowerOn 		= STEAM_OVEN_POWER_OFF;
	
	SteamOvenView::getInstance()->m_RotatePump		= 0;
	SteamOvenView::getInstance()->m_Preheat 		= 0;
	SteamOvenView::getInstance()->m_KeepWarm		= 0;
	SteamOvenView::getInstance()->m_Function		= STEAM_OVEN_FUNCTION_OFF;
	SteamOvenView::getInstance()->m_SetTime 		= 0;
	SteamOvenView::getInstance()->m_SetTemper		= 0;
	SteamOvenView::getInstance()->m_SetFoodTemper	= 0;
	SteamOvenView::getInstance()->m_RunState		= 0;
	
	CDisplayView::getInstance()->m_RunStage		= RUN_STAGE_DEFROST;
	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_POWER_OFF;
	
}


/*启动*/
void SteamOven::Play()
{
	
	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);

	SteamOvenView::getInstance()->m_Preheat 	= CDisplayView::getInstance()->m_Preheat;
	SteamOvenView::getInstance()->m_KeepWarm 	= CDisplayView::getInstance()->m_KeepWarm;
	SteamOvenView::getInstance()->m_Defrost 	= CDisplayView::getInstance()->m_Defrost;

	if(SteamOvenView::getInstance()->m_Defrost == OPEN){

		SteamOvenView::getInstance()->m_RotatePump		= CLOSE;	
		SteamOvenView::getInstance()->m_Function 		= STEAM_OVEN_FUNCTION_UNFREEZE;	
		SteamOvenView::getInstance()->m_SetTemper 		= 68;	
		SteamOvenView::getInstance()->m_SetTime 		= 50;	
		SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;

		CDisplayView::getInstance()->m_RunStage 		= RUN_STAGE_DEFROST;
	}
	else{

		SteamOvenView::getInstance()->m_RotatePump		= CLOSE;	
		SteamOvenView::getInstance()->m_Function 		= CDisplayView::getInstance()->m_Function;
		SteamOvenView::getInstance()->m_SetTemper 		= CDisplayView::getInstance()->m_SetTemper;
		SteamOvenView::getInstance()->m_SetTime 		= CDisplayView::getInstance()->m_SetTime;
		SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;
		
		CDisplayView::getInstance()->m_RunStage 		= RUN_STAGE_NORMAL;

	}
	
	SteamOvenView::getInstance()->m_RunState 		= STEAM_OVEN_RUN_STATE_PLAY;
	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_KEY_EVENT;


	ILOGD("Play Function:%d, SetTemper:%d, SetTime:%d \n", SteamOvenView::getInstance()->m_Function, SteamOvenView::getInstance()->m_SetTemper, SteamOvenView::getInstance()->m_SetTime);
	
}

void SteamOven::UnfreezePlay(){

	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);
	
	SteamOvenView::getInstance()->m_RotatePump		= CLOSE;	
	SteamOvenView::getInstance()->m_Function 		= CDisplayView::getInstance()->m_Function;
	SteamOvenView::getInstance()->m_SetTemper 		= CDisplayView::getInstance()->m_SetTemper;
	SteamOvenView::getInstance()->m_SetTime 		= CDisplayView::getInstance()->m_SetTime;
	SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;
	
	CDisplayView::getInstance()->m_RunStage 		= RUN_STAGE_NORMAL;

	SteamOvenView::getInstance()->m_RunState 		= STEAM_OVEN_RUN_STATE_PLAY;
	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_KEY_EVENT;

	ILOGD("UnfreezePlay Function:%d, SetTemper:%d, SetTime:%d \n", SteamOvenView::getInstance()->m_Function, SteamOvenView::getInstance()->m_SetTemper, SteamOvenView::getInstance()->m_SetTime);
}


void SteamOven::KeepWarmPlay(){

	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);

	SteamOvenView::getInstance()->m_RotatePump		= CLOSE;	
	SteamOvenView::getInstance()->m_Function 		= STEAM_OVEN_FUNCTION_HEAT_KEEPWARM;	
	SteamOvenView::getInstance()->m_SetTemper 		= 68;	
	SteamOvenView::getInstance()->m_SetTime 		= 50;	
	SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;

	SteamOvenView::getInstance()->m_RunState 		= STEAM_OVEN_RUN_STATE_PLAY;
	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_KEY_EVENT;

	CDisplayView::getInstance()->m_RunStage 		= RUN_STAGE_KEEP_WARM;

	ILOGD("KeepWarmPlay Function:%d, SetTemper:%d, SetTime:%d \n", SteamOvenView::getInstance()->m_Function, SteamOvenView::getInstance()->m_SetTemper, SteamOvenView::getInstance()->m_SetTime);
	
}

void SteamOven::KeepWarmStop(){

	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);

	SteamOvenView::getInstance()->m_RotatePump		= CLOSE;	
	SteamOvenView::getInstance()->m_Function 		= 0;	
	SteamOvenView::getInstance()->m_SetTemper 		= 0;	
	SteamOvenView::getInstance()->m_SetTime 		= 0;	
	SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;

	SteamOvenView::getInstance()->m_RunState 		= STEAM_OVEN_RUN_STATE_STOP;
	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_KEY_EVENT;

	CDisplayView::getInstance()->m_RunStage 		= RUN_STAGE_DEFROST;
}

void SteamOven::PausePlay()
{
	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);

	SteamOvenView::getInstance()->m_RunState 		= STEAM_OVEN_RUN_STATE_PLAY;
	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_KEY_EVENT;
	
}

void SteamOven::Pause()
{
	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);
	
	SteamOvenView::getInstance()->m_RunState 		= STEAM_OVEN_RUN_STATE_PAUSE;
	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_KEY_EVENT;
}

void SteamOven::Stop()
{
	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);

	SteamOvenView::getInstance()->m_RotatePump		= CLOSE;	
	SteamOvenView::getInstance()->m_Function 		= STEAM_OVEN_FUNCTION_OFF;	
	SteamOvenView::getInstance()->m_SetTemper 		= 0;	
	SteamOvenView::getInstance()->m_SetTime 		= 0;	
	SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;

	SteamOvenView::getInstance()->m_RunState 		= STEAM_OVEN_RUN_STATE_STOP;	
	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_KEY_EVENT;

	CDisplayView::getInstance()->m_RunStage 		= RUN_STAGE_DEFROST;
}




/*启动*/
void SteamOven::MultiStepPlay(){

	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);

	SteamOvenView::getInstance()->m_Preheat 	= CLOSE;
	SteamOvenView::getInstance()->m_Defrost 	= CLOSE;
	SteamOvenView::getInstance()->m_KeepWarm	= CLOSE;
	
	if(CDisplayView::getInstance()->m_MultiStepParam.Defrost == OPEN){

		SteamOvenView::getInstance()->m_RotatePump		= CLOSE;	
		SteamOvenView::getInstance()->m_Function 		= CDisplayView::getInstance()->m_MultiStepParam.DefrostFunction;	
		SteamOvenView::getInstance()->m_SetTemper 		= CDisplayView::getInstance()->m_MultiStepParam.DefrostTemper;	
		SteamOvenView::getInstance()->m_SetTime 		= CDisplayView::getInstance()->m_MultiStepParam.DefrostTime;	
		SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;

		CDisplayView::getInstance()->m_MultiStepParam.MultiStep 		= MULTI_STEP_DEFROST;
	}
	else if(CDisplayView::getInstance()->m_MultiStepParam.Preheat == OPEN){

		SteamOvenView::getInstance()->m_RotatePump		= CLOSE;	
		SteamOvenView::getInstance()->m_Function 		= CDisplayView::getInstance()->m_MultiStepParam.PreheatFunction;	
		SteamOvenView::getInstance()->m_SetTemper 		= CDisplayView::getInstance()->m_MultiStepParam.PreheatTemper;	
		SteamOvenView::getInstance()->m_SetTime 		= CDisplayView::getInstance()->m_MultiStepParam.PreheatTime;	
		SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;

		CDisplayView::getInstance()->m_MultiStepParam.MultiStep 		= MULTI_STEP_PREHEAT;
	}
	else{

		SteamOvenView::getInstance()->m_RotatePump		= CLOSE;	
		SteamOvenView::getInstance()->m_Function 		= CDisplayView::getInstance()->m_MultiStepParam.Function[0];
		SteamOvenView::getInstance()->m_SetTemper 		= CDisplayView::getInstance()->m_MultiStepParam.SetTemper[0];
		SteamOvenView::getInstance()->m_SetTime 		= CDisplayView::getInstance()->m_MultiStepParam.SetTime[0];
		SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;
		
		CDisplayView::getInstance()->m_MultiStepParam.MultiStep 		= MULTI_STEP_FUNCTION0;

	}
	
	SteamOvenView::getInstance()->m_RunState 		= STEAM_OVEN_RUN_STATE_PLAY;
	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_KEY_EVENT;


	ILOGD("MultiStep Play MultiStep:%d, Function:%d, SetTemper:%d, SetTime:%d \n", CDisplayView::getInstance()->m_MultiStepParam.MultiStep,SteamOvenView::getInstance()->m_Function, SteamOvenView::getInstance()->m_SetTemper, SteamOvenView::getInstance()->m_SetTime);
}


void SteamOven::MultiStepPreheatPlay(){

	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);
	
	SteamOvenView::getInstance()->m_RotatePump		= CLOSE;	
	SteamOvenView::getInstance()->m_Function 		= CDisplayView::getInstance()->m_MultiStepParam.PreheatFunction;	
	SteamOvenView::getInstance()->m_SetTemper 		= CDisplayView::getInstance()->m_MultiStepParam.PreheatTemper;	
	SteamOvenView::getInstance()->m_SetTime 		= CDisplayView::getInstance()->m_MultiStepParam.PreheatTime;	
	SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;

	CDisplayView::getInstance()->m_MultiStepParam.MultiStep 		= MULTI_STEP_PREHEAT;

	SteamOvenView::getInstance()->m_RunState 		= STEAM_OVEN_RUN_STATE_PLAY;
	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_KEY_EVENT;

	ILOGD("MultiStepPreheatPlay Function:%d, SetTemper:%d, SetTime:%d \n", SteamOvenView::getInstance()->m_Function, SteamOvenView::getInstance()->m_SetTemper, SteamOvenView::getInstance()->m_SetTime);
}

void SteamOven::MultiStepFunctionPlay(uint8 index){

	Mutex::Autolock _l(SteamOvenView::getInstance()->m_Lock);
	
	SteamOvenView::getInstance()->m_RotatePump		= CLOSE;	
	SteamOvenView::getInstance()->m_Function 		= CDisplayView::getInstance()->m_MultiStepParam.Function[index];
	SteamOvenView::getInstance()->m_SetTemper 		= CDisplayView::getInstance()->m_MultiStepParam.SetTemper[index];
	SteamOvenView::getInstance()->m_SetTime 		= CDisplayView::getInstance()->m_MultiStepParam.SetTime[index];
	SteamOvenView::getInstance()->m_SetFoodTemper 	= 0;

	if(index == 0){
		CDisplayView::getInstance()->m_MultiStepParam.MultiStep 		= MULTI_STEP_FUNCTION0;
	}
	else if(index == 1){
		CDisplayView::getInstance()->m_MultiStepParam.MultiStep 		= MULTI_STEP_FUNCTION1;
	}
	else{
		CDisplayView::getInstance()->m_MultiStepParam.MultiStep 		= MULTI_STEP_FUNCTION2;
	}
	

	SteamOvenView::getInstance()->m_RunState 		= STEAM_OVEN_RUN_STATE_PLAY;
	SteamOvenView::getInstance()->m_Buzzer			= BUZZER_KEY_EVENT;

	ILOGD("MultiStepFunctionPlay Function:%d, SetTemper:%d, SetTime:%d \n", SteamOvenView::getInstance()->m_Function, SteamOvenView::getInstance()->m_SetTemper, SteamOvenView::getInstance()->m_SetTime);
}

