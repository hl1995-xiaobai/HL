

#ifndef _STEAM_OVEN_VIEW_H_
#define _STEAM_OVEN_VIEW_H_



#include "system/Mutex.h"
#include "SteamOvenCmd.h"
#include "Facorites.h"


#define AUTO_OFF_LIGHTING_TIME 		180
#define FINISH_PAGE_SHOW_TIME		15
#define FACORITES_SIZE				32

#define ALARM_BUZZER_CNT 			20


#define OPEN 	1
#define CLOSE 	0


#define STEAM_OVEN_POWER_OFF				0  /**/
#define STEAM_OVEN_POWER_ON 				1  /**/

#define STEAM_OVEN_RUN_STATE_STOP 			0 	/*停止状态*/
#define STEAM_OVEN_RUN_STATE_PLAY 			1	/*运行状态*/
#define STEAM_OVEN_RUN_STATE_PAUSE 			2	/*暂停状态*/


#define STEAM_OVEN_FUNCTION_OFF 					0	/*无功能*/
#define STEAM_OVEN_FUNCTION_FAST					1 	/*快烤 		(背部 + 项外 + 循环风机)*/
#define STEAM_OVEN_FUNCTION_WIND_BAKED				2 	/*风焙烤 		(背部 +      循环风机) 		*/
#define STEAM_OVEN_FUNCTION_BAKED					3 	/*焙烤 		(底部 +      项外)			*/
#define STEAM_OVEN_FUNCTION_BOT						4 	/*底加热 		(底部)					*/
#define STEAM_OVEN_FUNCTION_UNFREEZE				5 	/*解冻 		(底部)					*/
#define STEAM_OVEN_FUNCTION_FAN						6 	/*风扇烤  		(项内 + 项外 + 循环风机)*/
#define STEAM_OVEN_FUNCTION_GRILL					7 	/*烧烤		(项内 + 循环风机)				*/
#define STEAM_OVEN_FUNCTION_STONG_GRILL				8 	/*强烧烤		(项内 + 项外)				*/
#define STEAM_OVEN_FUNCTION_HEAT_KEEPWARM			9	/*保温		(背部 +      循环风机)		*/
#define STEAM_OVEN_FUNCTION_SUBSCRIBE				10 	/*预约*/



#define WORK_STATE_EMPTY					0	/*空状态*/
#define WORK_STATE_WARM_UP					1	/*预热升温*/
#define WORK_STATE_WARMING					2	/*升温加热*/
#define WORK_STATE_CONSTANT 				3	/*恒温加热*/
#define WORK_STATE_WORK_END 				4	/*工作结束*/

#define ERROR_NO_ERROR					0
#define ERROR_INTER_NTC_ERROR			(uint16)(1 << 0)	/*腔体NTC错误*/
#define ERROR_BOT_NTC_ERROR				(uint16)(1 << 1)	/*发热盘底NTC异常*/
#define ERROR_STEAM_NTC_ERROR			(uint16)(1 << 2)    /*蒸发器NTC异常*/
#define ERROR_TEMPER_NO_ARRIVE_ERROR	(uint16)(1 << 3)	/*箱体温度异常*/
#define ERROR_COMMUNICATE_ERROR			(uint16)(1 << 4)	/*通讯故障*/
#define ERROR_DOOR_NTC_ERROR			(uint16)(1 << 5)	/*门锁异常*/
#define ERROR_HEATER_NTC_ERROR			(uint16)(1 << 6)	/*即热器NTC错误*/
#define ERROR_MOTOR_STALL_NTC_ERROR		(uint16)(1 << 7)	/*堵转检测NTC错误*/
#define ERROR_ZERO_SIGNAL_ERROR			(uint16)(1 << 8)	/*过零信号错误*/
#define ERROR_DOOR_OPEN_ERROR			(uint16)(1 << 9)	/*门控故障*/
#define ERROR_WATER_LACK_ERROR			(uint16)(1 << 10)	/*缺水错误*/


#define ERROR_CODE_NO_ERROR				0
#define ERROR_CODE_INTER_NTC			1	/*腔体NTC错误*/
#define ERROR_CODE_BOT_NTC				2	/*发热盘底NTC异常*/
#define ERROR_CODE_NO_ARRIVE			3	/*箱体温度异常*/
#define ERROR_CODE_COMMUNICATE			4	/*通讯故障*/

#define ERROR_CODE_DOOR_OPEN			5	/*门控故障*/
#define ERROR_CODE_WATER_LACK			6	/*缺水错误*/


#define BUZZER_KEY_EVENT		1
#define BUZZER_POWER_ON			2
#define BUZZER_POWER_OFF 		3
#define BUZZER_ERRPR 			4
#define BELL_END				5
#define BELL_TEMPER_ARRIVE 		6

typedef struct{	
	uint8 Max;
	uint8 Min;
	uint8 Def;
}MAX_MIN_T;



class SteamOvenView {

public:
	
	friend class SteamOven;
	
	virtual ~SteamOvenView();
	SteamOvenView();

	static SteamOvenView * getInstance();


	void InitAllParam();
	void MainPageInitParam();


	uint8 GetErrorCode(void);
	
	
	void SetSetTime(uint8 setTime);
	uint8 GetSetTime();

	void SetSetTemper(uint8 SetTemper);
	uint8 GetSetTemper();

	void SetFunction(uint8 Function);
	uint8 GetFunction();

	void SetState(uint8 state);
	uint8 GetState();

	void SetRunState(uint8 RunState);
	uint8 GetRunState();

	void SetVersionYear(uint8 year);
	uint8 GetVersionYear();

	void SetVersionMonth(uint8 Month);
	uint8 GetVersionMonth();

	void SetVersionDay(uint8 Day);
	uint8 GetVersionDay();

	void SetDoor(uint8 Door);
	uint8 GetDoor();

	void SetAddWater(uint8 AddWater);
	uint8 GetAddWater();

	void SetHeat(uint8 Heat);
	uint8 GetHeat();

	void SetBuzzer(uint8 Buzzer);
	uint8 GetBuzzer();

	void SetRunTimeSecond(uint8 RunTimeSecond);
	uint8 GetRunTimeSecond();

	void SetRunTimeMinute(uint8 RunTimeMinute);
	uint8 GetRunTimeMinute();
	
	void SetRunTimeDownMinute(uint8 RunTimeDownMinute);
	uint8 GetRunTimeDownMinute();

	void SetRunTimeDownSecond(uint8 RunTimeDownSecond);
	uint8 GetRunTimeDownSecond();

	void SetInterShowTemper(int16 InterShowTemper);
	int16 GetInterShowTemper();

	void SetInterTemper(int16 InterTemper);
	int16 GetInterTemper();

	void SetInterSrcTemper(int16 InterSrcTemper);
	int16 GetInterSrcTemper();

	void SetBotTemper(int16 BotTemper);
	int16 GetBotTemper();

	void SetHeaterTemper(int16 HeaterTemper);
	int16 GetHeaterTemper();

	void SetErrorNumber(uint16 ErrorNumber);
	uint16 GetErrorNumber();

	void SetPowerOn(uint8 PowerOn);
	uint8 GetPowerOn();

	void SetBright(uint8 Bright);
	uint8 GetBright();

	void SetDoorLock(uint8 DoorLock);
	uint8 GetDoorLock();

	void SetHallDoor(uint8 HallDoor);
	uint8 GetHallDoor();

	void SetupTimer(uint8 upTimer);
	uint8 GetupTimer();

	void SetRotatePump(uint8 RotatePump);
	uint8 GetRotatePump();

	void SetPreheat(uint8 Preheat);
	uint8 GetPreheat();

	void SetKeepWarm(uint8 KeepWarm);
	uint8 GetKeepWarm();


	void SetFoodProbe(uint8 FoodProbe);
	uint8 GetFoodProbe();

	void SetFoodTemper(uint8 FoodTemper);
	uint8 GetFoodTemper();

	void SetProbeTemper(uint8 ProbeTemper);
	uint8 GetProbeTemper();

	void SetCmd(PSTEAM_OVEN_ACK_T pInAck);
	void GetCmd(PSTEAM_OVEN_CMD_T pOutCmd);

	uint8 GetRunStage();
private:

	
	
	uint16			m_ErrorNumber;					/*错误代码*/
	uint8			m_PowerOn;						/*电源*/
	
	uint8			m_AddWater; 					/*加水阀状态*/
	uint8			m_HallDoor; 					/*霍尔门校正*/

	
	uint8			m_Heat; 						/*烤模式加热管状态*/
	uint8			m_Door; 						/*门状态*/
	uint8 			m_FoodProbe;					/*食物探针*/
	
	uint8			m_DoorLock; 					/*门锁*/
	uint8			m_upTimer;						/*更新设置时间*/
	
	uint8			m_RotatePump;					/*转烤电机*/
	

	uint8			m_Bright;						/*照明*/

	uint8			m_Defrost;						/*打开解冻功能 */
	uint8			m_Preheat;						/*打开预热功能 */
	uint8			m_KeepWarm;						/*打开保温功能 */


	uint8			m_Buzzer;						/*蜂鸣器*/
		
	uint8			m_Function; 					/*功能*/
	
	uint8			m_SetTime;						/*设置时间*/
	uint8			m_SetTemper;					/*设置温度*/
	uint8 			m_SetFoodTemper;				/*设置食物探针温度*/
	
	uint8			m_State;						/*工作状态 预热 升温 恒温 工作结束*/
	
	uint8			m_RunState; 					/*运行状态 停止 运行 暂停*/
	
	uint8			m_RunTimeSecond;				/*工作时间*/
	uint8			m_RunTimeMinute;				/*工作时间*/
	uint8			m_RunTimeDownMinute;			/*工作倒计时*/
	uint8			m_RunTimeDownSecond;			/*工作倒计时*/
	int16			m_InterShowTemper;				/*腔体显示温度*/
	int16			m_InterTemper;					/*腔体温度*/
	int16			m_InterSrcTemper;				/*没有通过运算的温度*/
	int16			m_BotTemper;					/*底部温度*/
	int16			m_HeaterTemper; 				/*即热器NTC*/
	int16			m_ProbeTemper;					/*食物探针实际温度*/
	
	uint8			m_VersionYearP;
	uint8			m_VersionMonthP;
	uint8			m_VersionDayP;

	Mutex			m_Lock;

};


#define TView			SteamOvenView::getInstance()

#endif

