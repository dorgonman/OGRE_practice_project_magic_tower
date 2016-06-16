
#ifndef __GameParameter_H__
#define __GameParameter_H__
#include "string"
/**
 * @brief 3D Game Programming<br>
 * My Name: ±i´º·Ó Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class for read game data and store it value
 *
*/
class GameParameter{
public:
	/*!
	\brief constructor
	*/
	GameParameter();
	/*!
	\brief read data file
	*/
	bool readData(std::string filePath);
	/*!
	\brief print all parameter
	*/
	void printAll();
public:
	int mMaxBulletsNum;
	int mMaxMonstersNum;
	float mWaterCoord_Y;
	std::string mWaterMaterialsName;
	bool mExpFogEnabled;
	float mExpFogDensity;
	bool mShadowEnabled;
	std::string mMapName;
	int mWinCount;
};

#endif