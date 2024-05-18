/*
 * CConfig.h
 *
 *  Created on: 2023年4月26日
 *      Author: lzs2180
 */

#ifndef OBJ_STEAMOVEN_CCONFIG_H_
#define OBJ_STEAMOVEN_CCONFIG_H_

#include "json/json.h"
#include "utils/JsonHelper.h"
#include <vector>

typedef struct{
	float Weight;
	uint8 Deal;
	uint8 time;
}TRADITTIONAL_MEET_DATA_T;

typedef struct{
	uint8 Deal;
	uint8 time;
}TRADITTIONAL_DESSERT_DATA_T;

typedef struct{
	uint8 Deal;
	uint8 time;
}TRADITTIONAL_BREAD_DATA_T;

typedef struct{
	uint8 Deal;
	uint8 time;
}TRADITTIONAL_OTHER_DATA_T;

typedef struct{
	float Weight;
	uint8 Deal;
	uint8 time;
}AUTO_PROGRAM_MEET_DATA_T;

typedef struct{
	uint8 Deal;
	uint8 time;
}AUTO_PROGRAM_DESSERT_DATA_T;

typedef struct{
	float Weight;
	uint8 Deal;
	uint8 time;
}AUTO_PROGRAM_BREAD_DATA_T;


typedef struct{
	uint8 Deal;
	uint8 time;
}AUTO_PROGRAM_FASTFOOD_DATA_T;

typedef struct{
	uint8 Deal;
	uint8 time;
}AUTO_PROGRAM_OTHER_DATA_T;


class CConfig {


public:
	
	CConfig();
	virtual ~CConfig();
	static CConfig * getInstance();

	void LoadConfig();

	
	const char * GetKeyString(const char * key);
	const float GetKeyFloat(const char * key);
	const int GetKeyInt(const char * key);

	const char * GetKeyString(uint8 MenuHome, const char * key);
	const float GetKeyFloat(uint8 MenuHome, const char * key);
	const int GetKeyInt(uint8 MenuHome, const char * key);

	const char * GetKeyString(uint8 MenuHome, uint8 MenuLevel1, const char * key);
	const float GetKeyFloat(uint8 MenuHome, uint8 MenuLevel1, const char * key);
	const int GetKeyInt(uint8 MenuHome, uint8 MenuLevel1,  const char * key);
	
	
	
	const char * GetKeyString(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2, const char * key);
	const float GetKeyFloat(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2, const char * key);
	const int GetKeyInt(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2, const char * key);


	const int GetKeyTradittonalMeet(uint8 MenuLevel2,vector <TRADITTIONAL_MEET_DATA_T>* pData);
	const int GetKeyTradittonalDessert(uint8 MenuLevel2,vector <TRADITTIONAL_DESSERT_DATA_T>* pData);
	const int GetKeyTradittonalBread(uint8 MenuLevel2, vector <TRADITTIONAL_BREAD_DATA_T>* pData);
	const int GetKeyTradittonalOther(uint8 MenuLevel2, vector <TRADITTIONAL_OTHER_DATA_T>* pData);
	const int GetKeyAutoProgramMeat(uint8 MenuLevel2, vector <AUTO_PROGRAM_MEET_DATA_T>* pData);
	const int GetKeyAutoProgramDessert(uint8 MenuLevel2, vector <AUTO_PROGRAM_DESSERT_DATA_T>* pData);
	const int GetKeyAutoProgramBread(uint8 MenuLevel2, vector <AUTO_PROGRAM_BREAD_DATA_T>* pData);
	const int GetKeyAutoProgramFastFood(uint8 MenuLevel2, vector <AUTO_PROGRAM_FASTFOOD_DATA_T>* pData);
	const int GetKeyAutoProgramOther(uint8 MenuLevel2, vector <AUTO_PROGRAM_OTHER_DATA_T>* pData);
	
protected:

	Json::Value GetHomeKey(const char * key);
	
	Json::Value GetLevel1Key(uint8 MenuHome, const char * key);
	
	Json::Value GetLevel2Key(uint8 MenuHome, uint8 MenuLevel1, const char * key);
	
	Json::Value GetLevel3Key(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2, const char * key);
	
	Json::Value 	m_Config;
};

#define TConfig			CConfig::getInstance()

#endif /* OBJ_STEAMOVEN_CCONFIG_H_ */
