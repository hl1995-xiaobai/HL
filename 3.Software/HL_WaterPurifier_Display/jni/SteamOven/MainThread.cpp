
#include "../include.h"
#include "utils/TimeHelper.h"



CMainThread::~CMainThread()
{

}


CMainThread::CMainThread()
{



}


CMainThread * CMainThread::getInstance()
{
	static CMainThread MainThread;

	return & MainThread;
}


bool CMainThread::threadLoop()
{

	if (CSysTime::getInstance()->GetSysTimeTlag(STEAMOVEN_SYSTIMETLAG_20MS)) {
		ThreadLoop20ms();
	}

	if (CSysTime::getInstance()->GetSysTimeTlag(STEAMOVEN_SYSTIMETLAG_100MS)) {
		ThreadLoop100ms();
	}


	if (CSysTime::getInstance()->GetSysTimeTlag(STEAMOVEN_SYSTIMETLAG_500MS)) {
		ThreadLoop500ms();
	}

	if (CSysTime::getInstance()->GetSysTimeTlag(STEAMOVEN_SYSTIMETLAG_1S)) {
		ThreadLoop1S();
	}


	//Thread::sleep(10);
	return true;
}



void CMainThread::ThreadLoop20ms()
{
	SteamOven::getInstance()->SteamOvenLoop20ms();
}


void CMainThread::ThreadLoop100ms()
{

	SteamOven::getInstance()->SteamOvenLoop100ms();
}


void CMainThread::ThreadLoop500ms()
{
	SteamOven::getInstance()->SteamOvenLoop500ms();
}


void CMainThread::ThreadLoop1S()
{
	SteamOven::getInstance()->SteamOvenLoop1S();
}


