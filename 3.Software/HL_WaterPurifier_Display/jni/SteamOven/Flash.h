

#ifndef _FLASH_H_
#define _FLASH_H_

#include "system/Thread.h"
#include <signal.h>
#include <time.h>



class CFlash {



public:

	CFlash();
	virtual ~CFlash();

	static CFlash * getInstance();


	uint8 GetFlash();
	uint8 GetFastFlash();

	void Loop100ms();
	void Loop500ms();

protected:

	uint8 m_Flash;						/*闪烁*/
	uint8 m_FastFlash;					/*快闪*/
	Mutex			m_Lock;

};


#endif

