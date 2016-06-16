#include "AudioManager.h"




AudioManager::AudioManager(){
	//mStage = stage;
	mSound = new SOUND();
}


AudioManager::~AudioManager(){
	/*for(std::map<std::string, SOUND*>::iterator i =
		mAudioMap.begin(); 
		i!= mAudioMap.end(); i++) {   
              SOUND* p = (*i).second;
			  delete p;
			  p = NULL;
      }*/
	mAudioMap.clear();
	if(mSound){
		delete mSound;
	}


}

void AudioManager::addSound(std::string name, std::string path){
	mAudioMap.insert(make_pair(name, mSound->mBufferIndex));
	mSound->loadSound((char*)path.c_str());
	
}



void AudioManager::play(std::string name){
	std::map<std::string, int>::iterator it = mAudioMap.find(name);
	
	if(it != mAudioMap.end()){
		mSound->addSource(it->second);
	}
}