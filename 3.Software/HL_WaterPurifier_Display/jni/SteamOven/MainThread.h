

#ifndef _CMAIN_THREAD_H_
#define _CMAIN_THREAD_H_
#include "system/Thread.h"
#include <signal.h>
#include <time.h>



class CMainThread: public Thread {


public:

	virtual ~CMainThread();
	CMainThread();

	static CMainThread * getInstance();

protected:

	virtual bool threadLoop();

	void ThreadLoop20ms();
	void ThreadLoop100ms();
	void ThreadLoop500ms();
	void ThreadLoop1S();

	
};


#define TMainThread				CMainThread::getInstance()

#endif

