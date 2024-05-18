#include "../include.h"
#include "utils/TimeHelper.h"
#include "SysTime.h"

static uint8	m_SysTime100msCnt = 0;
static uint8	m_SysTime500msCnt = 0;
static uint8	m_SysTime1SCnt = 0;


CSysTime::CSysTime()
	: m_timerid(NULL)
{



}

CSysTime::~CSysTime(){

	if(m_timerid != NULL){
		timer_delete(m_timerid);
		m_timerid = NULL;
	}
	
}

CSysTime * CSysTime::getInstance(){

	static CSysTime SysTime;

	return & SysTime;
}

void CSysTime::Start(){

	
	struct sigevent evp;
	
	memset((void *) &evp, 0, sizeof(struct sigevent));

	evp.sigev_value.sival_int = 111;
	evp.sigev_notify	= SIGEV_THREAD;

	evp.sigev_notify_function = CSysTime::OnTime;

	timer_create(CLOCK_REALTIME, &evp, &m_timerid);

	struct itimerspec it;
	it.it_interval.tv_sec = 0;
	it.it_interval.tv_nsec = 1000000 * 20;

	it.it_value.tv_sec	= 3;
	it.it_value.tv_nsec = 0;

	timer_settime(m_timerid, 0, &it, NULL);

}


void CSysTime::OnTime(union sigval v)
{

	m_SysTime100msCnt++;
	m_SysTime500msCnt++;
	m_SysTime1SCnt++;

	CSysTime::getInstance()->SetSysTimeTlag(STEAMOVEN_SYSTIMETLAG_20MS);

	if (m_SysTime100msCnt >= 5) {
		m_SysTime100msCnt	= 0;
		CSysTime::getInstance()->SetSysTimeTlag(STEAMOVEN_SYSTIMETLAG_100MS);
	}

	if (m_SysTime500msCnt >= 25) {
		m_SysTime500msCnt	= 0;
		CSysTime::getInstance()->SetSysTimeTlag(STEAMOVEN_SYSTIMETLAG_500MS);
	}

	if (m_SysTime1SCnt >= 50) {
		m_SysTime1SCnt		= 0;
		CSysTime::getInstance()->SetSysTimeTlag(STEAMOVEN_SYSTIMETLAG_1S);
	}

}



void CSysTime::SetSysTimeTlag(uint8 tlag)
{
	Mutex::Autolock _l(m_Lock);

	if (tlag == STEAMOVEN_SYSTIMETLAG_20MS) {
		m_SysTime20ms = 1;
	}
	else if (tlag == STEAMOVEN_SYSTIMETLAG_100MS) {
		m_SysTime100ms = 1;
	}
	else if (tlag == STEAMOVEN_SYSTIMETLAG_500MS) {
		m_SysTime500ms = 1;
	}
	else if (tlag == STEAMOVEN_SYSTIMETLAG_1S) {
		m_SysTime1S = 1;
	}

}


uint8 CSysTime::GetSysTimeTlag(uint8 tlag)
{

	Mutex::Autolock _l(m_Lock);

	if (tlag == STEAMOVEN_SYSTIMETLAG_20MS) {
		if (m_SysTime20ms) {
			m_SysTime20ms = 0;
			return 1;
		}
	}
	else if (tlag == STEAMOVEN_SYSTIMETLAG_100MS) {
		if (m_SysTime100ms) {
			m_SysTime100ms = 0;
			return 1;
		}
	}
	else if (tlag == STEAMOVEN_SYSTIMETLAG_500MS) {
		if (m_SysTime500ms) {
			m_SysTime500ms = 0;
			return 1;
		}
	}
	else if (tlag == STEAMOVEN_SYSTIMETLAG_1S) {
		if (m_SysTime1S) {
			m_SysTime1S = 0;
			return 1;
		}
	}

	return 0;
}


