#include "../include.h"
#include "utils/TimeHelper.h"
#include "Alarm.h"


CAlarm::CAlarm()
{
}

CAlarm::~CAlarm(){
}

CAlarm * CAlarm::getInstance(){

	static CAlarm Alarm;

	return & Alarm;
}



void CAlarm::SetAlarm(struct tm* t1){

	Mutex::Autolock _l(m_Lock);

	m_Alarm = 1;

	memcpy(&AlarmTime, t1, sizeof(struct tm));
}

uint8 CAlarm::IsAlarm(){

	Mutex::Autolock _l(m_Lock);

	return m_Alarm;
}

struct tm* CAlarm::GetAlarm(){

	Mutex::Autolock _l(m_Lock);

	return &AlarmTime;
}


void CAlarm::AlarmLoop(){

	Mutex::Autolock _l(m_Lock);

	if(m_Alarm == 0){

		if(m_AlarmCnt){
			m_AlarmCnt--;
			SteamOvenView::getInstance()->SetBuzzer(BUZZER_ERRPR);
		}
	}
	else{


		time_t t1,t2;

		struct tm*  Time;

		Time = TimeHelper::getDateTime();

		t1 = mktime(&AlarmTime);

		t2 = mktime(Time);

		//ILOGD("t1:0x%08X, t2:0x%08X", t1,t2);

		if(t2 >= t1){
			m_Alarm = 0;
			memset(&AlarmTime, 0, sizeof(struct tm ));
			m_AlarmCnt = ALARM_BUZZER_CNT;
		}

	}

}



