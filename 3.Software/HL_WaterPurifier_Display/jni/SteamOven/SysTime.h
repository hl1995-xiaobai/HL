#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_


#include "system/Thread.h"
#include <signal.h>
#include <time.h>


#define STEAMOVEN_SYSTIMETLAG_20MS	0
#define STEAMOVEN_SYSTIMETLAG_100MS 1
#define STEAMOVEN_SYSTIMETLAG_500MS 2
#define STEAMOVEN_SYSTIMETLAG_1S	3


class CSysTime {


public:

	CSysTime();
	virtual ~CSysTime();

	static CSysTime * getInstance();

	void Start();

	void SetSysTimeTlag(uint8 tlag);	
	uint8 GetSysTimeTlag(uint8 tlag);

protected:

	static void OnTime(union sigval v);

	
	uint8 m_SysTime20ms		: 1;
	uint8 m_SysTime100ms	: 1;
	uint8 m_SysTime500ms	: 1;
	uint8 m_SysTime1S 		: 1;
	

	
	timer_t m_timerid;

	Mutex			m_Lock;
	
};




#endif

