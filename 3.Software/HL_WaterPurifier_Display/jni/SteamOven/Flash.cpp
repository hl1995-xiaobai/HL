#include "../include.h"
#include "utils/TimeHelper.h"
#include "Alarm.h"


CFlash::CFlash()
	: m_Flash(0)
	, m_FastFlash(0)
{



}

CFlash::~CFlash(){

	
}

CFlash * CFlash::getInstance(){

	static CFlash Flash;

	return & Flash;
}


uint8 CFlash::GetFlash(){

	Mutex::Autolock _l(m_Lock);

	return m_Flash;
}

uint8 CFlash::GetFastFlash(){

	Mutex::Autolock _l(m_Lock);

	return m_FastFlash;
}


void CFlash::Loop100ms(){

	Mutex::Autolock _l(m_Lock);
	m_FastFlash = !m_FastFlash;
	
}

void CFlash::Loop500ms(){

	Mutex::Autolock _l(m_Lock);
	
	m_Flash = !m_Flash;
}

