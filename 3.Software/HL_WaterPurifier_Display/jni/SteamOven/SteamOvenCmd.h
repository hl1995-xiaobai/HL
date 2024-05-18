

#ifndef _STEAMOVEN_CMD_H_
#define _STEAMOVEN_CMD_H_

#pragma pack(1) 				

typedef struct {
	uint8			PowerOn 		: 1;			/*电源*/
	uint8			Bright			: 1;			/*照明*/
	uint8			DoorLock		: 1;			/*门锁*/
	uint8			HallDoor		: 1;			/*霍尔门校正*/
	uint8			upTimer 		: 1;			/*更新设置时间*/
	uint8			RotatePump		: 1;			/*转烤电机*/
	uint8			Action			: 1;			/*演示模式*/
	uint8 			Preheat			: 1;			/*预热开关*/	

	uint8			buzzer			: 4;			/*蜂鸣器*/
	uint8			RunState		: 4;			/*运行状态*/
	
	uint8			Function;						/*功能  */
	uint8			SetTemper;						/*设置温度*/
	uint8 			SetFoodTemper;					/*设置食物探针温度*/
	uint8			SetTime;						/*设置时间*/
	uint16			crc16;							/*CRC16*/
} STEAM_OVEN_CMD_T, *PSTEAM_OVEN_CMD_T;


typedef struct {
	uint8			VersionYear;
	uint8			VersionMonth;
	uint8			VersionDay;

	uint8			PowerOn 		: 1;			/*电源*/
	uint8			Door			: 1;			/*门状态*/
	uint8			AddWater		: 1;			/*加水阀状态*/
	uint8			heat			: 1;			/*烤模式加热管状态*/
	uint8 			FoodProbe		: 1;			/*食物探针状态*/
	uint8							: 3;

	uint8			Function;						/*功能  */
	
	uint8			buzzer			: 4;			/*蜂鸣器*/
	uint8			State			: 4;			/*工作状态*/
	
	uint8			RunTimeSecond;					/*工作时间*/
	uint8			RunTimeMinute;					/*工作时间*/
	uint8			RunTimeDownMinute;				/*工作倒计时*/
	uint8			RunTimeDownSecond;				/*工作倒计时*/
	int16			InterShowTemper;				/*腔体显示温度*/
	int16			InterTemper;					/*腔体温度*/
	int16			InterSrcTemper; 				/*没有通过运算的温度*/
	int16			BotTemper;						/*底部温度*/
	int16			SteamTemper;					/*蒸发器NTC*/
	int16			HeaterTemper;					/*即热器NTC*/
	int16 			ProbeTemper;					/*食物探针实际温度*/
	uint16			ErrorNumber;					/*错误代码*/
	
	uint16			crc16;							/*CRC16*/
} STEAM_OVEN_ACK_T, *PSTEAM_OVEN_ACK_T;


#pragma pack()					


class SteamOvenCmd {


public:

	virtual ~SteamOvenCmd();
	SteamOvenCmd();
	static SteamOvenCmd * getInstance();

	void RecvByte(BYTE in);
	void RecvCmd(BYTE * in,uint8 len);

	void SendCmd();


private:

	BYTE *			m_pRecvBuf;
	UINT			m_RecvCont;

	BYTE *			m_pSendBuf;
	Mutex			m_Lock;
};


#define TSteamOvenCmd			SteamOvenCmd::getInstance()

#endif

