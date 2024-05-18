

#ifndef _LIGHTING_H_
#define _LIGHTING_H_

#include "system/Thread.h"
#include <signal.h>
#include <time.h>



class CLighiting {



public:

	CLighiting();
	virtual ~CLighiting();

	static CLighiting * getInstance();


	void SetLighting();
	uint8 GetLighting();

	void Lighting1SLoop();

protected:

	Mutex			m_Lock;

	uint8 			m_LightingCnt;						/*照明计数*/

};


#endif

