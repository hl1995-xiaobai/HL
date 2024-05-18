

#ifndef _ALARM_H_
#define _ALARM_H_

#include "system/Thread.h"
#include <signal.h>
#include <time.h>



class CAlarm {

public:

	CAlarm();
	virtual ~CAlarm();

	static CAlarm * getInstance();


	void SetAlarm(struct tm * t1);
	uint8 IsAlarm();
	struct tm * GetAlarm();

	void AlarmLoop();

protected:

	uint8			m_Alarm;				/*闹钟*/
	struct tm 		AlarmTime; 				/*闹钟时间*/
	uint8			m_AlarmCnt;


	Mutex			m_Lock;

};


#endif

