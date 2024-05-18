/*
 * Facorites.h
 *
 *  Created on: 2023年6月16日
 *      Author: lzs2180
 */

#ifndef JNI_STEAMOVEN_FACORITES_H_
#define JNI_STEAMOVEN_FACORITES_H_


#include "json/json.h"
#include "utils/JsonHelper.h"


#define FACORITES_PAGH "/data/facorites.json"


#define FACORITES_NAME_LEN 16

typedef struct{

	//char			Name[FACORITES_NAME_LEN]; 	/*名称*/
	
	uint8			MenuHome; 					/*主页*/
	uint8			MenuLevel1;					/*1级菜单*/
	uint8			MenuLevel2;					/*2级菜单*/
	uint8			MenuLevel3;					/*3级菜单*/

	float			weight; 					/*重量*/
	uint8			deal;						/*份量*/
	uint8 			cooked;						/*全熟、七成熟、少量熟*/

	uint8			Function; 					/*功能*/
	uint8			SetTime;					/*设置时间*/
	uint8			SetTemper;					/*设置温度*/
	uint8 			SetFoodTemper;				/*设置食物探针温度*/

	uint8			Preheat;					/*打开预热功能 */
	uint8			KeepWarm;					/*打开保温功能 */

}FACORITES_T;

class CFacorites {


public:

	CFacorites();
	virtual ~CFacorites();
	static CFacorites * getInstance();

	void LoadData();
	void SaveData();

	int Add(FACORITES_T* in);
	int Del(uint8 index);
	int Del(FACORITES_T* in);

	int FindIndex(FACORITES_T* in);

	int GetCont();

	int GetData(uint8 index, FACORITES_T* out);

	int Identical(FACORITES_T* scr, FACORITES_T* tag);

protected:

	
	Json::Value 	m_Facorites;
	Mutex			m_Lock;
};

#define TFacorites			CFacorites::getInstance()


#endif /* JNI_STEAMOVEN_FACORITES_H_ */
