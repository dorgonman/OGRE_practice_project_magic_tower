#include "GameParameter.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
GameParameter::GameParameter(){
	mMaxBulletsNum = 1;
	mMaxMonstersNum = 1;
	mWaterCoord_Y = 0;
	mWaterMaterialsName = "";
	mExpFogEnabled = false;
	mShadowEnabled = false;
	mMapName = "";
	mWinCount = -1;

}


bool GameParameter::readData(string filePath){

	std::ifstream fin;
	fin.open(filePath.c_str(), ios::in | ios::binary);

	if(!fin){    // 檢查讀檔成功與否 
		cout << "fail to load file" << filePath << endl;
		return false;
	}  
	


		std::string key;
		while(!fin.eof()){
			fin >> key;
			
			if (key.compare("MAX_BULLETS") == 0) {
				fin >> this->mMaxBulletsNum;
			}

			if (key.compare("MAX_MONSTERS") == 0) {
				fin >> this->mMaxMonstersNum;
			}

			if (key.compare("WATER_COORD_Y") == 0) {
				fin >> this->mWaterCoord_Y;
			}

			if (key.compare("WATER_MATERIALS") == 0) {
				fin >> this->mWaterMaterialsName;
			}

			if (key.compare("ENABLE_EXP_FOG") == 0) {
				fin >> this->mExpFogEnabled;
				fin >> this->mExpFogDensity;
			}
			
			if (key.compare("ENABLE_SHADOW") == 0) {
				fin >> this->mShadowEnabled;
			}

			if(key.compare("MAP_NAME") == 0){
				fin >> this->mMapName;

			}
			if(key.compare("WIN_COUNT") == 0){
				fin >> this->mWinCount;

			}
			cout << key << endl;
	}

}



void GameParameter::printAll(){
	cout << "mMaxBulletsNum:" << mMaxBulletsNum << endl;
	cout << "mMaxMonstersNum:" << mMaxMonstersNum << endl;
	cout << "mWaterCoord_Y:" << mWaterCoord_Y << endl;
	cout << "mWaterMaterialsName:" << mWaterMaterialsName << endl;
	cout << "ENABLE_EXP_FOG:" << mExpFogEnabled << "	" << mExpFogDensity << endl;
	cout << "mShadowEnabled:" << mShadowEnabled << endl;
	cout << "mMapName:" << mMapName << endl;
	cout << "mWinCount:" << mWinCount << endl;
}