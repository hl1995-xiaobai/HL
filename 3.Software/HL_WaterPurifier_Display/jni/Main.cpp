#include "entry/EasyUIContext.h"

#include "include.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

void onEasyUIInit(EasyUIContext *pContext) {
	// 初始化时打开串口
	UartContext::getInstance()->openUart(ConfigManager::getInstance()->getUartName().c_str(), ConfigManager::getInstance()->getUartBaudRate());

	CFacorites::getInstance()->LoadData();

	CMainThread::getInstance()->run("Water Thread");

	CSysTime::getInstance()->Start();

	SteamOven::getInstance()->PowerOn();
}

void onEasyUIDeinit(EasyUIContext *pContext)
{
	 UartContext::getInstance()->closeUart();

	 CMainThread::getInstance()->requestExitAndWait();

	 SteamOven::getInstance()->PowerOff();
}

const char* onStartupApp(EasyUIContext *pContext) {
	return "mainActivity";
}


#ifdef __cplusplus

}

#endif  /* __cplusplus */

