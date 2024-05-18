

/*
 * Facorites.cpp
 *
 *	Created on: 2023年6月16日
 *		Author: lzs2180
 */
#include "../include.h"

CFacorites::CFacorites()
{
	
}


CFacorites::~CFacorites()
{
	
}


CFacorites * CFacorites::getInstance()
{

	static CFacorites CFacorites;

	return & CFacorites;
}


void CFacorites::LoadData()
{

	
	if (JsonHelper::readJsonFile(FACORITES_PAGH, m_Facorites) == FALSE) {

		ILOGD("Read Facorites File Error !!! \n");
	}
}


void CFacorites::SaveData()
{

	
	if (JsonHelper::writeJsonFile(FACORITES_PAGH, m_Facorites) == FALSE) {

		ILOGD("write Facorites File Error !!! \n");
	}
}


int CFacorites::Add(FACORITES_T * in)
{

	
	Json::Value array;

	Json::Value Item;

	if (m_Facorites.isMember("array")) {
		array				= m_Facorites["array"];
	}

	//Item["Name"]			= in->Name;
	Item["MenuHome"]		= in->MenuHome;
	Item["MenuLevel1"]		= in->MenuLevel1;
	Item["MenuLevel2"]		= in->MenuLevel2;
	Item["MenuLevel3"]		= in->MenuLevel3;
	Item["weight"]			= in->weight;
	Item["deal"]			= in->deal;
	Item["cooked"]			= in->cooked;
	Item["Function"]		= in->Function;
	Item["SetTime"] 		= in->SetTime;
	Item["SetTemper"]		= in->SetTemper;
	Item["SetFoodTemper"] 	= in->SetFoodTemper;
	
	Item["Preheat"] 		= in->Preheat;
	Item["KeepWarm"]		= in->KeepWarm;
	
	array.append(Item);

	m_Facorites["array"] = array;


	//ILOGD("生成的json字符串为: ");

	//ILOGD("%s", m_Facorites.toStyledString().c_str());

	return array.size() -1;
}


int CFacorites::Del(uint8 index)
{

	//Mutex::Autolock _l(m_Lock);

	Json::Value array;

	if (m_Facorites.isMember("array")) {
		array				= m_Facorites["array"];
	}
	else {
		return -1;
	}


	if (index >= array.size()) {
		return -1;
	}

	if(array.size() == 1){
		
		Json::Value Item = m_Facorites.removeMember("array");

		Item.clear();
	}
	else{
		Json::Value Item;
		array.removeIndex(index, &Item);
		Item.clear();
		m_Facorites["array"] = array;
	}

	
	return 1;
}

int CFacorites::Identical(FACORITES_T* scr, FACORITES_T* tag){

	return 0;
}

int CFacorites::FindIndex(FACORITES_T* in){

	
	Json::Value array;
	
	if (m_Facorites.isMember("array")) {
		array				= m_Facorites["array"];
	}
	else {
		return -1;
	}

	if(array.size() == 0){
		return -1;
	}

	Json::Value Item;

	//Item["Name"]		= in->Name;
	Item["MenuHome"]		= in->MenuHome;
	Item["MenuLevel1"]		= in->MenuLevel1;
	Item["MenuLevel2"]		= in->MenuLevel2;
	Item["MenuLevel3"]		= in->MenuLevel3;
	Item["weight"]			= in->weight;
	Item["deal"]			= in->deal;
	Item["cooked"]			= in->cooked;
	Item["Function"]		= in->Function;
	Item["SetTime"] 		= in->SetTime;
	Item["SetTemper"]		= in->SetTemper;
	Item["SetFoodTemper"] 	= in->SetFoodTemper;

	Item["Preheat"] 		= in->Preheat;
	Item["KeepWarm"] 		= in->KeepWarm;

	if (array.isArray()) {
		for (Json::ArrayIndex i = 0; i < array.size(); ++i) {
			
			if (array[i] == Item) {
				return i;
			}
		}
	}

	

	return -1;
}

int CFacorites::Del(FACORITES_T* in){

	//Mutex::Autolock _l(m_Lock);

	int index = FindIndex(in);

	if(index < 0)
		return -1;

	return Del(index);
}

int CFacorites::GetCont()
{

	//Mutex::Autolock _l(m_Lock);


	Json::Value array;

	if (m_Facorites.isMember("array")) {
		array				= m_Facorites["array"];
	}
	else {
		return 0;
	}

	return array.size();
}


int CFacorites::GetData(uint8 index, FACORITES_T * out)
{

	//Mutex::Autolock _l(m_Lock);

	Json::Value array;

	if (m_Facorites.isMember("array")) {
		array				= m_Facorites["array"];
	}
	else {
		return 0;
	}

	if (index >= array.size()) {
		return 0;
	}

	Json::Value Item;

	Item				= array[index];

	memset(out, 0, sizeof(FACORITES_T));

	//strncpy(out->Name, Item["Name"].asString().c_str(), Item["Name"].asString().size());

	out->MenuHome		= Item["MenuHome"].asInt();
	out->MenuLevel1 	= Item["MenuLevel1"].asInt();
	out->MenuLevel2 	= Item["MenuLevel2"].asInt();
	out->MenuLevel3 	= Item["MenuLevel3"].asInt();
	out->weight 		= Item["weight"].asFloat();
	out->deal			= Item["deal"].asInt();
	out->cooked 		= Item["cooked"].asInt();
	out->Function		= Item["Function"].asInt();
	out->SetTime		= Item["SetTime"].asInt();
	out->SetTemper		= Item["SetTemper"].asInt();
	out->SetFoodTemper	= Item["SetFoodTemper"].asInt();

	out->Preheat		= Item["Preheat"].asInt();
	out->KeepWarm		= Item["KeepWarm"].asInt();

	return 1;
}



