#ifndef _INCLUDE_H_
#define _INCLUDE_H_

#include <vector>
#include <string.h>
#include <system/Mutex.h>

#include "utils/Log.h"
#include "utils/BitmapHelper.h"


#include "uart/CommDef.h"
#include "uart/ProtocolParser.h"


#include "uart/UartContext.h"
#include "manager/ConfigManager.h"

#include "./SteamOven/ImageCache.h"
#include "./SteamOven/DisplayView.h"

#include "./SteamOven/MainThread.h"
#include "./SteamOven/SysTime.h"
#include "./SteamOven/SteamOvenView.h"
#include "./SteamOven/SteamOven.h"
#include "./SteamOven/SteamOvenCmd.h"
#include "./SteamOven/CConfig.h"
#include "./SteamOven/Facorites.h"
#include "./SteamOven/Alarm.h"
#include "./SteamOven/Lighting.h"
#include "./SteamOven/Flash.h"


#define SET_ERR(x,y) (x) |= (y)
#define GET_ERR(x,y) (x) & (y)
#define CLR_ERR(x,y) (x) &= (~y)


//static ImageCache m_sImageCacheMain;

#endif
