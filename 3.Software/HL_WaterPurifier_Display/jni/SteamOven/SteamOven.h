

#ifndef _STEAM_OVEN_H_
#define _STEAM_OVEN_H_
#include "system/Thread.h"
#include <signal.h>
#include <time.h>



class SteamOven {


public:
	
	friend class SteamOvenView;
	
	virtual ~SteamOven();
	SteamOven();

	static SteamOven * getInstance();


	void SteamOvenLoop20ms();
	void SteamOvenLoop100ms();
	void SteamOvenLoop500ms();
	void SteamOvenLoop1S();


	void PowerOn();
	void PowerOff();
	void Play();
	void PausePlay();
	void UnfreezePlay();
	void KeepWarmPlay();
	void KeepWarmStop();
	void Pause();
	void Stop();


	void MultiStepPlay();
	void MultiStepPreheatPlay();
	void MultiStepFunctionPlay(uint8 index);
	
protected:


	Mutex		Lock;

};


#define TSteamOven				SteamOven::getInstance()

#endif

