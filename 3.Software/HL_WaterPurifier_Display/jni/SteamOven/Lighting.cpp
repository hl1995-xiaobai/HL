#include "../include.h"
#include "utils/TimeHelper.h"
#include "Alarm.h"


CLighiting::CLighiting()
	: m_LightingCnt(0)
{



}

CLighiting::~CLighiting(){

	
}

CLighiting * CLighiting::getInstance(){

	static CLighiting Lighiting;

	return & Lighiting;
}


void CLighiting::SetLighting(){

	Mutex::Autolock _l(m_Lock);

	if(m_LightingCnt == 0){
		m_LightingCnt = AUTO_OFF_LIGHTING_TIME;
		SteamOvenView::getInstance()->SetBright(OPEN);
	}
	else{
		m_LightingCnt = 0;
		SteamOvenView::getInstance()->SetBright(CLOSE);
	}
	
}

uint8 CLighiting::GetLighting(){

	Mutex::Autolock _l(m_Lock);
	
	return m_LightingCnt;
}

void CLighiting::Lighting1SLoop(){

	Mutex::Autolock _l(m_Lock);
	
	/*自动关照明*/
	if(m_LightingCnt){
		m_LightingCnt--;
		if(m_LightingCnt == 0){
			SteamOvenView::getInstance()->SetBright(CLOSE);
		}
	}
}

