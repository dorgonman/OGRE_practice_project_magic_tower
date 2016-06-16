
#ifndef __AudioManager_h_
#define __AudioManager_h_

#include "Sound.h"
#include "map"
#include "string"
//class Stage;
/**
 * @brief 3D Game Programming<br>
 * My Name: ±i´º·Ó Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class handle for Audio manager
 *
*/
class AudioManager{
public:
	AudioManager();
	~AudioManager();
public:
	virtual void addSound(std::string name, std::string filePath);
	virtual void play(std::string name);


private:
	//std::map<std::string, SOUND*> mAudioMap;
	std::map<std::string, int> mAudioMap;  //name, buffer index
	SOUND* mSound;


};

#endif