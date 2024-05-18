

/*
 * CConfig.cpp
 *
 *	Created on: 2023年4月26日
 *		Author: lzs2180
 */
#include "Include.h"
#include "CConfig.h"
#include "SteamOvenView.h"
#include "uart/CommDef.h"


CConfig::CConfig()
{
	// TODO 自动生成的构造函数存根
	LoadConfig();
}


CConfig::~CConfig()
{
	// TODO 自动生成的析构函数存根
}



CConfig * CConfig::getInstance()
{
	static CConfig	CConfig;

	return & CConfig;
}


void CConfig::LoadConfig()
{

	std::string path	= ConfigManager::getInstance()->getResFilePath("SteamOven.json");

	if (JsonHelper::readJsonFile(path.c_str(), m_Config) == FALSE) {
		ILOGD("Read Config File Error !!! \n");
	}

}


Json::Value CConfig::GetHomeKey(const char * key)
{

	Json::Value Item;

	Item				= m_Config[key];

	return Item;
}

const char * CConfig::GetKeyString(const char * key){

	Json::Value vlue	= GetHomeKey(key);

	if (vlue.isNull())
		return "";

	if(vlue.isString()){
		return vlue.asCString();
	}
	else{
		return "";
	}
}

const float CConfig::GetKeyFloat(const char * key){

	Json::Value vlue	= GetHomeKey(key);

	if (vlue.isNull())
		return 0.0;

	if(vlue.isDouble()){
		return vlue.asFloat();
	}
	else{
		return 0.0;
	}
}

const int CConfig::GetKeyInt(const char * key){

	Json::Value vlue	= GetHomeKey(key);

	if (vlue.isNull())
		return 0;

	if(vlue.isInt()){
		return vlue.asInt();
	}
	else{
		return 0;
	}

}

const char * CConfig::GetKeyString(uint8 MenuHome, const char * key){

	Json::Value vlue	= GetLevel1Key(MenuHome,key);

	if (vlue.isNull())
		return "";

	if(vlue.isString()){
		return vlue.asCString();
	}
	else{
		return "";
	}
}

const float CConfig::GetKeyFloat(uint8 MenuHome, const char * key){
	Json::Value vlue	= GetLevel1Key(MenuHome,key);

	if (vlue.isNull())
		return 0.0;

	if(vlue.isDouble()){
		return vlue.asFloat();
	}
	else{
		return 0.0;
	}
}
const int CConfig::GetKeyInt(uint8 MenuHome, const char * key){
	
	Json::Value vlue	= GetLevel1Key(MenuHome,key);
	
	if (vlue.isNull())
		return 0;

	if(vlue.isInt()){
		return vlue.asInt();
	}
	else{
		return 0;
	}
}

Json::Value CConfig::GetLevel1Key(uint8 MenuHome, const char * key)
{

	Json::Value Home	= m_Config["Menu"];

	if (Home.isNull())
		return "";

	if (!Home.isArray())
		return "";

	Json::Value item	= Home[MenuHome];

	return item[key];
}


const char * CConfig::GetKeyString(uint8 MenuHome, uint8 MenuLevel1, const char * key){

	Json::Value vlue	= GetLevel2Key(MenuHome,MenuLevel1,key);

	if (vlue.isNull())
		return "";

	if(vlue.isString()){
		return vlue.asCString();
	}
	else{
		return "";
	}
	
}

const float CConfig::GetKeyFloat(uint8 MenuHome, uint8 MenuLevel1, const char * key){

	Json::Value vlue	= GetLevel2Key(MenuHome,MenuLevel1,key);

	if (vlue.isNull())
		return 0.0;

	if(vlue.isDouble()){
		return vlue.asFloat();
	}
	else{
		return 0.0;
	}
}

const int CConfig::GetKeyInt(uint8 MenuHome, uint8 MenuLevel1,  const char * key){

	Json::Value vlue	= GetLevel2Key(MenuHome,MenuLevel1,key);
	
	if (vlue.isNull())
		return 0;

	if(vlue.isInt()){
		return vlue.asInt();
	}
	else{
		return 0;
	}
}
	

Json::Value CConfig::GetLevel2Key(uint8 MenuHome, uint8 MenuLevel1, const char * key)
{

	Json::Value Home	= m_Config["Menu"];

	if (Home.isNull())
		return "";

	if (!Home.isArray())
		return "";

	Json::Value item	= Home[MenuHome];

	if (item.isNull())
		return "";

	Json::Value item1	= item["Menu"];

	if (item1.isNull())
		return "";

	if (!item1.isArray())
		return "";

	Json::Value item2	= item1[MenuLevel1];

	if (item2.isNull())
		return "";

	return item2[key];

}


const char * CConfig::GetKeyString(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2, const char * key)
{

	Json::Value vlue	= GetLevel3Key(MenuHome,MenuLevel1, MenuLevel2, key);

	if (vlue.isNull())
		return "";

	if(vlue.isString()){
		return vlue.asCString();
	}
	else{
		return "";
	}
}

const float CConfig::GetKeyFloat(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2, const char * key)
{

	Json::Value vlue	= GetLevel3Key(MenuHome,MenuLevel1, MenuLevel2, key);

	if (vlue.isNull())
		return 0.0;

	if(vlue.isDouble()){
		return vlue.asFloat();
	}
	else{
		return 0.0;
	}
}

const int CConfig::GetKeyInt(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2, const char * key)
{

	Json::Value vlue	= GetLevel3Key(MenuHome,MenuLevel1, MenuLevel2, key);

	if (vlue.isNull())
		return 0;

	if(vlue.isInt()){
		return vlue.asInt();
	}
	else{
		return 0;
	}
}

const int CConfig::GetKeyTradittonalMeet(uint8 MenuLevel2, vector <TRADITTIONAL_MEET_DATA_T>* pData)
{

	Json::Value vlue	= GetLevel3Key(MENU_HOME_TRADITIONAL,MENU_TRADITIONAL_MEET, MenuLevel2, "array");

	if (vlue.isNull())
		return 0;

	if(vlue.isArray()){
		
		Json::ArrayIndex size = vlue.size();

		pData->clear();
		
		if(size == 0) return 0;

		Json::Value item;

		for(Json::ArrayIndex i = 0; i < size; i++){
			Json::Value item = vlue[i];

			TRADITTIONAL_MEET_DATA_T it;

			it.Weight 	= item["Weight"].asFloat();
			it.Deal 	= item["Deal"].asInt();
			it.time 	= item["time"].asInt();

			pData->push_back(it);
		}
	}
	else{
		return 0;
	}

	return 1;
}



const int CConfig::GetKeyTradittonalDessert(uint8 MenuLevel2, vector <TRADITTIONAL_DESSERT_DATA_T>* pData){

	
	Json::Value vlue	= GetLevel3Key(MENU_HOME_TRADITIONAL,MENU_TRADITIONAL_DESSERT, MenuLevel2, "array");
	
	if (vlue.isNull())
		return 0;

	if(vlue.isArray()){
		
		Json::ArrayIndex size = vlue.size();

		pData->clear();
		
		if(size == 0) return 0;

		Json::Value item;

		for(Json::ArrayIndex i = 0; i < size; i++){
			Json::Value item = vlue[i];

			TRADITTIONAL_DESSERT_DATA_T it;

			it.Deal 	= item["Deal"].asInt();
			it.time 	= item["time"].asInt();

			pData->push_back(it);
		}
	}
	else{
		return 0;
	}


	return 1;
}

const int CConfig::GetKeyTradittonalBread(uint8 MenuLevel2, vector <TRADITTIONAL_BREAD_DATA_T>* pData)
{

	Json::Value vlue	= GetLevel3Key(MENU_HOME_TRADITIONAL,MENU_TRADITIONAL_BREAD, MenuLevel2, "array");

	if (vlue.isNull())
		return 0;

	if(vlue.isArray()){
		
		Json::ArrayIndex size = vlue.size();

		pData->clear();
		
		if(size == 0) return 0;

		Json::Value item;

		for(Json::ArrayIndex i = 0; i < size; i++){
			Json::Value item = vlue[i];

			TRADITTIONAL_BREAD_DATA_T it;

			it.Deal 	= item["Deal"].asInt();
			it.time 	= item["time"].asInt();

			pData->push_back(it);
		}
	}
	else{
		return 0;
	}

	return 1;
}

const int CConfig::GetKeyTradittonalOther(uint8 MenuLevel2, vector <TRADITTIONAL_OTHER_DATA_T>* pData)
{

	Json::Value vlue	= GetLevel3Key(MENU_HOME_TRADITIONAL,MENU_TRADITIONAL_OTHER, MenuLevel2, "array");

	if (vlue.isNull())
		return 0;

	if(vlue.isArray()){
		
		Json::ArrayIndex size = vlue.size();

		pData->clear();
		
		if(size == 0) return 0;

		Json::Value item;

		for(Json::ArrayIndex i = 0; i < size; i++){
			Json::Value item = vlue[i];

			TRADITTIONAL_OTHER_DATA_T it;

			it.Deal 	= item["Deal"].asInt();
			it.time 	= item["time"].asInt();

			pData->push_back(it);
		}
	}
	else{
		return 0;
	}

	return 1;
}


const int CConfig::GetKeyAutoProgramMeat(uint8 MenuLevel2, vector <AUTO_PROGRAM_MEET_DATA_T>* pData)
{

	Json::Value vlue	= GetLevel3Key(MENU_HOME_AUTO_PROGRAM,MENU_HOME_AUTO_PROGRAM_MEET, MenuLevel2, "array");

	if (vlue.isNull())
		return 0;

	if(vlue.isArray()){
		
		Json::ArrayIndex size = vlue.size();

		pData->clear();
		
		if(size == 0) return 0;

		Json::Value item;

		for(Json::ArrayIndex i = 0; i < size; i++){
			Json::Value item = vlue[i];

			AUTO_PROGRAM_MEET_DATA_T it;

			it.Weight 	= item["Weight"].asFloat();
			it.Deal 	= item["Deal"].asInt();
			it.time 	= item["time"].asInt();

			pData->push_back(it);
		}
	}
	else{
		return 0;
	}

	return 1;
}

const int CConfig::GetKeyAutoProgramDessert(uint8 MenuLevel2, vector <AUTO_PROGRAM_DESSERT_DATA_T>* pData)
{

	Json::Value vlue	= GetLevel3Key(MENU_HOME_AUTO_PROGRAM,MENU_HOME_AUTO_PROGRAM_DESSERT, MenuLevel2, "array");

	if (vlue.isNull())
		return 0;

	if(vlue.isArray()){
		
		Json::ArrayIndex size = vlue.size();

		pData->clear();
		
		if(size == 0) return 0;

		Json::Value item;

		for(Json::ArrayIndex i = 0; i < size; i++){
			Json::Value item = vlue[i];

			AUTO_PROGRAM_DESSERT_DATA_T it;

			it.Deal 	= item["Deal"].asInt();
			it.time 	= item["time"].asInt();

			pData->push_back(it);
		}
	}
	else{
		return 0;
	}

	return 1;
}

const int CConfig::GetKeyAutoProgramBread(uint8 MenuLevel2, vector <AUTO_PROGRAM_BREAD_DATA_T>* pData)
{

	Json::Value vlue	= GetLevel3Key(MENU_HOME_AUTO_PROGRAM,MENU_HOME_AUTO_PROGRAM_BREAD, MenuLevel2, "array");

	if (vlue.isNull())
		return 0;

	if(vlue.isArray()){
		
		Json::ArrayIndex size = vlue.size();

		pData->clear();
		
		if(size == 0) return 0;

		Json::Value item;

		for(Json::ArrayIndex i = 0; i < size; i++){
			Json::Value item = vlue[i];

			AUTO_PROGRAM_BREAD_DATA_T it;

			it.Weight 	= item["Weight"].asFloat();
			it.Deal 	= item["Deal"].asInt();
			it.time 	= item["time"].asInt();

			pData->push_back(it);
		}
	}
	else{
		return 0;
	}

	return 1;
}


const int CConfig::GetKeyAutoProgramFastFood(uint8 MenuLevel2, vector <AUTO_PROGRAM_FASTFOOD_DATA_T>* pData){

	Json::Value vlue	= GetLevel3Key(MENU_HOME_AUTO_PROGRAM,MENU_HOME_AUTO_PROGRAM_FASTFOOD, MenuLevel2, "array");

	if (vlue.isNull())
		return 0;

	if(vlue.isArray()){
		
		Json::ArrayIndex size = vlue.size();

		pData->clear();
		
		if(size == 0) return 0;

		Json::Value item;

		for(Json::ArrayIndex i = 0; i < size; i++){
			Json::Value item = vlue[i];

			AUTO_PROGRAM_FASTFOOD_DATA_T it;

			it.Deal 	= item["Deal"].asInt();
			it.time 	= item["time"].asInt();

			pData->push_back(it);
		}
	}
	else{
		return 0;
	}

	return 1;
}


const int CConfig::GetKeyAutoProgramOther(uint8 MenuLevel2, vector <AUTO_PROGRAM_OTHER_DATA_T>* pData){

	Json::Value vlue	= GetLevel3Key(MENU_HOME_AUTO_PROGRAM,MENU_HOME_AUTO_PROGRAM_OTHER, MenuLevel2, "array");

	if (vlue.isNull())
		return 0;

	if(vlue.isArray()){
		
		Json::ArrayIndex size = vlue.size();

		pData->clear();
		
		if(size == 0) return 0;

		Json::Value item;

		for(Json::ArrayIndex i = 0; i < size; i++){
			Json::Value item = vlue[i];

			AUTO_PROGRAM_OTHER_DATA_T it;

			it.Deal 	= item["Deal"].asInt();
			it.time 	= item["time"].asInt();

			pData->push_back(it);
		}
	}
	else{
		return 0;
	}

	return 1;
}


	

Json::Value CConfig::GetLevel3Key(uint8 MenuHome, uint8 MenuLevel1, uint8 MenuLevel2, const char * key){

	Json::Value Home	= m_Config["Menu"];

	if (Home.isNull())
		return Json::Value(Json::nullValue);

	if (!Home.isArray())
		return Json::Value(Json::nullValue);

	Json::Value item	= Home[MenuHome];

	if (item.isNull())
		return Json::Value(Json::nullValue);

	Json::Value item1	= item["Menu"];

	if (item1.isNull())
		return Json::Value(Json::nullValue);

	if (!item1.isArray())
		return Json::Value(Json::nullValue);

	Json::Value item2	= item1[MenuLevel1];

	if (item2.isNull())
		return Json::Value(Json::nullValue);

	Json::Value item3	= item2["Menu"];

	if (item3.isNull())
		return Json::Value(Json::nullValue);

	if (!item3.isArray())
		return Json::Value(Json::nullValue);
	
	Json::Value item4	= item3[MenuLevel2];

	if (item4.isNull())
		return Json::Value(Json::nullValue);

	return item4[key];
	
}


