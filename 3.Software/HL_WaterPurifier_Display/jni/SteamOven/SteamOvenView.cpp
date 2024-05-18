
#include "../include.h"
#include <arpa/inet.h>


SteamOvenView::~SteamOvenView()
{



}


SteamOvenView::SteamOvenView(): m_ErrorNumber(0), 
m_PowerOn(0), 
m_AddWater(0), 
m_HallDoor(0), 
m_Heat(0), 
m_Door(0), 
m_FoodProbe(0), 
m_DoorLock(0), 
m_upTimer(0), 
m_RotatePump(0), 
m_Bright(0), 
m_Preheat(0), 
m_KeepWarm(0), 
m_Buzzer(0), 
m_Function(0), 
m_SetTime(0), 
m_SetTemper(0), 
m_SetFoodTemper(0), 
m_State(0), 
m_RunState(0), 
m_RunTimeSecond(0), 
m_RunTimeMinute(0), 
m_RunTimeDownMinute(0), 
m_RunTimeDownSecond(0), 
m_InterShowTemper(0), 
m_InterTemper(0), 
m_InterSrcTemper(0), 
m_BotTemper(0), 
m_HeaterTemper(0), 
m_ProbeTemper(0), 
m_VersionYearP(0), 
m_VersionMonthP(0), 
m_VersionDayP(0)
{

	//memset(&m_MultiStepParam, 0, sizeof(MULTI_STEP_PARAM_T));

}




SteamOvenView * SteamOvenView::getInstance()
{
	static SteamOvenView SteamOvenView;

	return & SteamOvenView;
}






uint8 SteamOvenView::GetErrorCode(void)
{

	Mutex::Autolock _l(m_Lock);

	if (GET_ERR(m_ErrorNumber, ERROR_INTER_NTC_ERROR)) {
		return ERROR_CODE_INTER_NTC;
	}

	if (GET_ERR(m_ErrorNumber, ERROR_TEMPER_NO_ARRIVE_ERROR)) {
		return ERROR_CODE_NO_ARRIVE;
	}

	if (GET_ERR(m_ErrorNumber, ERROR_COMMUNICATE_ERROR)) {
		return ERROR_CODE_COMMUNICATE;
	}

	return ERROR_CODE_NO_ERROR;
}



void SteamOvenView::InitAllParam()
{
	Mutex::Autolock _l(m_Lock);
	
	m_ErrorNumber		= ERROR_CODE_NO_ERROR;
	m_PowerOn			= STEAM_OVEN_POWER_OFF;
	
	m_RotatePump		= 0;
	m_Preheat			= 0;
	m_KeepWarm			= 0;
	m_Function			= STEAM_OVEN_FUNCTION_OFF;
	m_SetTime			= 0;
	m_SetTemper 		= 0;
	m_SetFoodTemper 	= 0;
	m_RunState			= 0;
	
}


void SteamOvenView::MainPageInitParam()
{
	Mutex::Autolock _l(m_Lock);
	
	m_ErrorNumber		= ERROR_CODE_NO_ERROR;
	m_PowerOn			= STEAM_OVEN_POWER_ON;
	
	m_RotatePump		= 0;
	m_Preheat			= 0;
	m_KeepWarm			= 0;
	m_Function			= STEAM_OVEN_FUNCTION_OFF;
	m_SetTime			= 0;
	m_SetTemper 		= 0;
	m_SetFoodTemper 	= 0;
	m_RunState			= 0;
	
}

void SteamOvenView::SetSetTime(uint8 setTime)
{
	Mutex::Autolock _l(m_Lock);
	m_SetTime			= setTime;
}


uint8 SteamOvenView::GetSetTime()
{
	Mutex::Autolock _l(m_Lock);
	return m_SetTime;
}

void SteamOvenView::SetSetTemper(uint8 SetTemper)
{
	Mutex::Autolock _l(m_Lock);
	m_SetTemper 		= SetTemper;
}


uint8 SteamOvenView::GetSetTemper()
{
	Mutex::Autolock _l(m_Lock);
	return m_SetTemper;
}


void SteamOvenView::SetFunction(uint8 Function)
{
	Mutex::Autolock _l(m_Lock);
	m_Function			= Function;
}


uint8 SteamOvenView::GetFunction()
{
	Mutex::Autolock _l(m_Lock);
	return m_Function;
}


void SteamOvenView::SetState(uint8 state)
{
	Mutex::Autolock _l(m_Lock);
	m_State 			= state;
}


uint8 SteamOvenView::GetState()
{
	Mutex::Autolock _l(m_Lock);
	return m_State;
}

void SteamOvenView::SetRunState(uint8 RunState)
{
	Mutex::Autolock _l(m_Lock);
	m_RunState			= RunState;
	
}


uint8 SteamOvenView::GetRunState()
{
	Mutex::Autolock _l(m_Lock);
	return m_RunState;
}


void SteamOvenView::SetVersionYear(uint8 year)
{
	Mutex::Autolock _l(m_Lock);
	m_VersionYearP		= year;
}


uint8 SteamOvenView::GetVersionYear()
{
	Mutex::Autolock _l(m_Lock);
	return m_VersionYearP;
}


void SteamOvenView::SetVersionMonth(uint8 Month)
{
	Mutex::Autolock _l(m_Lock);
	m_VersionMonthP 	= Month;
}


uint8 SteamOvenView::GetVersionMonth()
{
	Mutex::Autolock _l(m_Lock);
	return m_VersionMonthP;
}


void SteamOvenView::SetVersionDay(uint8 Day)
{
	Mutex::Autolock _l(m_Lock);
	m_VersionDayP		= Day;
}


uint8 SteamOvenView::GetVersionDay()
{
	Mutex::Autolock _l(m_Lock);
	return m_VersionDayP;
}


void SteamOvenView::SetDoor(uint8 Door)
{
	Mutex::Autolock _l(m_Lock);
	m_Door				= Door;
}


uint8 SteamOvenView::GetDoor()
{
	Mutex::Autolock _l(m_Lock);
	return m_Door;
}


void SteamOvenView::SetAddWater(uint8 AddWater)
{
	Mutex::Autolock _l(m_Lock);
	m_AddWater			= AddWater;
}


uint8 SteamOvenView::GetAddWater()
{
	Mutex::Autolock _l(m_Lock);
	return m_AddWater;
}


void SteamOvenView::SetHeat(uint8 Heat)
{
	Mutex::Autolock _l(m_Lock);
	m_Heat				= Heat;
}


uint8 SteamOvenView::GetHeat()
{
	Mutex::Autolock _l(m_Lock);
	return m_Heat;
}


void SteamOvenView::SetBuzzer(uint8 Buzzer)
{
	Mutex::Autolock _l(m_Lock);
	m_Buzzer			= Buzzer;
}


uint8 SteamOvenView::GetBuzzer()
{
	Mutex::Autolock _l(m_Lock);
	return m_Buzzer;
}


void SteamOvenView::SetRunTimeSecond(uint8 RunTimeSecond)
{
	Mutex::Autolock _l(m_Lock);
	m_RunTimeSecond 	= RunTimeSecond;
}


uint8 SteamOvenView::GetRunTimeSecond()
{
	Mutex::Autolock _l(m_Lock);
	return m_RunTimeSecond;
}


void SteamOvenView::SetRunTimeMinute(uint8 RunTimeMinute)
{
	Mutex::Autolock _l(m_Lock);
	m_RunTimeMinute 	= RunTimeMinute;
}


uint8 SteamOvenView::GetRunTimeMinute()
{
	Mutex::Autolock _l(m_Lock);
	return m_RunTimeMinute;
}


void SteamOvenView::SetRunTimeDownMinute(uint8 RunTimeDownMinute)
{
	Mutex::Autolock _l(m_Lock);
	m_RunTimeDownMinute = RunTimeDownMinute;
}


uint8 SteamOvenView::GetRunTimeDownMinute()
{
	Mutex::Autolock _l(m_Lock);
	return m_RunTimeDownMinute;
}


void SteamOvenView::SetRunTimeDownSecond(uint8 RunTimeDownSecond)
{
	Mutex::Autolock _l(m_Lock);
	m_RunTimeDownSecond = RunTimeDownSecond;
}


uint8 SteamOvenView::GetRunTimeDownSecond()
{
	Mutex::Autolock _l(m_Lock);
	return m_RunTimeDownSecond;
}


void SteamOvenView::SetInterShowTemper(int16 InterShowTemper)
{
	Mutex::Autolock _l(m_Lock);
	m_InterShowTemper	= InterShowTemper;
}


int16 SteamOvenView::GetInterShowTemper()
{
	Mutex::Autolock _l(m_Lock);
	return m_InterShowTemper;
}


void SteamOvenView::SetInterTemper(int16 InterTemper)
{
	Mutex::Autolock _l(m_Lock);
	m_InterTemper		= InterTemper;
}


int16 SteamOvenView::GetInterTemper()
{
	Mutex::Autolock _l(m_Lock);
	return m_InterTemper;
}


void SteamOvenView::SetInterSrcTemper(int16 InterSrcTemper)
{
	Mutex::Autolock _l(m_Lock);
	m_InterSrcTemper	= InterSrcTemper;
}


int16 SteamOvenView::GetInterSrcTemper()
{
	Mutex::Autolock _l(m_Lock);
	return m_InterSrcTemper;
}


void SteamOvenView::SetBotTemper(int16 BotTemper)
{
	Mutex::Autolock _l(m_Lock);
	m_BotTemper 		= BotTemper;
}


int16 SteamOvenView::GetBotTemper()
{
	Mutex::Autolock _l(m_Lock);
	return m_BotTemper;
}


void SteamOvenView::SetHeaterTemper(int16 HeaterTemper)
{
	Mutex::Autolock _l(m_Lock);
	m_HeaterTemper		= HeaterTemper;
}


int16 SteamOvenView::GetHeaterTemper()
{
	Mutex::Autolock _l(m_Lock);
	return m_HeaterTemper;
}


void SteamOvenView::SetErrorNumber(uint16 ErrorNumber)
{
	Mutex::Autolock _l(m_Lock);
	m_ErrorNumber		= ErrorNumber;
}


uint16 SteamOvenView::GetErrorNumber()
{
	Mutex::Autolock _l(m_Lock);
	return m_ErrorNumber;
}


void SteamOvenView::SetPowerOn(uint8 PowerOn)
{
	Mutex::Autolock _l(m_Lock);
	m_PowerOn			= PowerOn;
}


uint8 SteamOvenView::GetPowerOn()
{
	Mutex::Autolock _l(m_Lock);
	return m_PowerOn;
}


void SteamOvenView::SetBright(uint8 Bright)
{
	Mutex::Autolock _l(m_Lock);
	m_Bright			= Bright;
	m_Buzzer			= BUZZER_KEY_EVENT;
}


uint8 SteamOvenView::GetBright()
{
	Mutex::Autolock _l(m_Lock);
	return m_Bright;
}


void SteamOvenView::SetDoorLock(uint8 DoorLock)
{
	Mutex::Autolock _l(m_Lock);
	m_DoorLock			= DoorLock;
	m_Buzzer			= BUZZER_KEY_EVENT;
}


uint8 SteamOvenView::GetDoorLock()
{
	Mutex::Autolock _l(m_Lock);
	return m_DoorLock;
}


void SteamOvenView::SetHallDoor(uint8 HallDoor)
{
	Mutex::Autolock _l(m_Lock);
	m_HallDoor			= HallDoor;
}


uint8 SteamOvenView::GetHallDoor()
{
	Mutex::Autolock _l(m_Lock);
	return m_HallDoor;
}


void SteamOvenView::SetupTimer(uint8 upTimer)
{
	Mutex::Autolock _l(m_Lock);
	m_upTimer			= upTimer;
}


uint8 SteamOvenView::GetupTimer()
{
	Mutex::Autolock _l(m_Lock);
	return m_upTimer;
}


void SteamOvenView::SetRotatePump(uint8 RotatePump)
{
	Mutex::Autolock _l(m_Lock);
	m_RotatePump		= RotatePump;
	m_Buzzer			= BUZZER_KEY_EVENT;
}


uint8 SteamOvenView::GetRotatePump()
{
	Mutex::Autolock _l(m_Lock);
	return m_RotatePump;
}


void SteamOvenView::SetPreheat(uint8 Preheat)
{
	Mutex::Autolock _l(m_Lock);
	m_Preheat			= Preheat;
	m_Buzzer			= BUZZER_KEY_EVENT;
}


uint8 SteamOvenView::GetPreheat()
{
	Mutex::Autolock _l(m_Lock);
	return m_Preheat;
}


void SteamOvenView::SetKeepWarm(uint8 KeepWarm)
{
	Mutex::Autolock _l(m_Lock);

	CDisplayView::getInstance()->m_KeepWarm = KeepWarm;
	m_KeepWarm			= KeepWarm;
	m_Buzzer			= BUZZER_KEY_EVENT;
}

uint8 SteamOvenView::GetKeepWarm()
{
	Mutex::Autolock _l(m_Lock);
	return m_KeepWarm;
}


void SteamOvenView::SetFoodProbe(uint8 FoodProbe)
{

	Mutex::Autolock _l(m_Lock);
	m_FoodProbe 		= FoodProbe;
}


uint8 SteamOvenView::GetFoodProbe()
{

	Mutex::Autolock _l(m_Lock);
	return m_FoodProbe;
}


void SteamOvenView::SetFoodTemper(uint8 FoodTemper)
{

	Mutex::Autolock _l(m_Lock);

	m_SetFoodTemper 	= FoodTemper;
}


uint8 SteamOvenView::GetFoodTemper()
{
	Mutex::Autolock _l(m_Lock);
	return m_SetFoodTemper;

}


void SteamOvenView::SetProbeTemper(uint8 ProbeTemper)
{
	Mutex::Autolock _l(m_Lock);

	m_ProbeTemper		= ProbeTemper;
}


uint8 SteamOvenView::GetProbeTemper()
{
	Mutex::Autolock _l(m_Lock);

	return m_ProbeTemper;
}




void SteamOvenView::SetCmd(PSTEAM_OVEN_ACK_T pInAck)
{

	Mutex::Autolock _l(m_Lock);


	m_VersionYearP		= pInAck->VersionYear;
	m_VersionMonthP 	= pInAck->VersionMonth;
	m_VersionDayP		= pInAck->VersionDay;
	m_Door				= pInAck->Door;
	m_AddWater			= pInAck->AddWater;
	m_Heat				= pInAck->heat;


	if (m_Buzzer == pInAck->buzzer) {
		m_Buzzer			= 0;
	}

	m_FoodProbe 		= pInAck->FoodProbe;
	m_State 			= pInAck->State;
	m_RunTimeSecond 	= pInAck->RunTimeSecond;
	m_RunTimeMinute 	= pInAck->RunTimeMinute;
	m_RunTimeDownMinute = pInAck->RunTimeDownMinute;
	m_RunTimeDownSecond = pInAck->RunTimeDownSecond;
	m_InterShowTemper	= htons(pInAck->InterShowTemper);
	m_InterTemper		= htons(pInAck->InterTemper);
	m_InterSrcTemper	= htons(pInAck->InterSrcTemper);
	m_BotTemper 		= htons(pInAck->BotTemper);
	m_HeaterTemper		= htons(pInAck->HeaterTemper);
	m_ProbeTemper		= htons(pInAck->ProbeTemper);
	m_ErrorNumber		= htons(pInAck->ErrorNumber);

}


void SteamOvenView::GetCmd(PSTEAM_OVEN_CMD_T pOutCmd)
{

	Mutex::Autolock _l(m_Lock);

	pOutCmd->PowerOn	= m_PowerOn;
	pOutCmd->Bright 	= m_Bright;
	pOutCmd->DoorLock	= m_DoorLock;
	pOutCmd->HallDoor	= m_HallDoor;
	pOutCmd->upTimer	= m_upTimer;
	pOutCmd->RotatePump = m_RotatePump;

	pOutCmd->buzzer 	= m_Buzzer;
	pOutCmd->RunState	= m_RunState;
	pOutCmd->Function	= m_Function;
	pOutCmd->SetTime	= m_SetTime;
	pOutCmd->SetTemper	= m_SetTemper;
	pOutCmd->SetFoodTemper = m_SetFoodTemper;

}


