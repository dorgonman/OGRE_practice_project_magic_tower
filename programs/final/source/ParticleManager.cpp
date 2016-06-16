#include "ParticleManager.h"
#include "Stage.h"


ParticleManager::ParticleManager(){
	//mStage = stage;
}


ParticleManager::~ParticleManager(){
	for(std::map<string, ParticleEffect*>::iterator i =
		mParticleMap.begin(); 
		i!= mParticleMap.end(); i++) {   
              ParticleEffect* p = (*i).second;
			  delete p;
			  p = NULL;
      }
	mParticleMap.clear();


}

void ParticleManager::addParticleEffect(string name, ParticleEffect *effect){
	mParticleMap.insert(make_pair(name, effect));

	//mParticleMap[name] = effect;
	//mParticleMap.push_back(effect);
}




void ParticleManager::update(Ogre::FrameEvent &evt){

	for(std::map<string, ParticleEffect*>::iterator it =
		mParticleMap.begin(); 
		it != mParticleMap.end(); it++) {

		ParticleEffect* p = it->second;
		p->update(evt);

	}
}


void ParticleManager::trigger(Ogre::Vector3 at){

	for(std::map<string, ParticleEffect*>::iterator it =
		mParticleMap.begin(); 
		it!= mParticleMap.end(); it++) {

		ParticleEffect* p = it->second;
		if(p->isAlive()) continue;
		p->setAlive(true);
		p->setInitPosition(at);

	}

}




void ParticleManager::trigger(string name, Ogre::Vector3 at){


	std::map<string, ParticleEffect*>::iterator it = mParticleMap.find(name);
	if(it != mParticleMap.end()){

		//cout << "particle trigger" << endl;
		ParticleEffect* p = it->second;
		p->trigger(at);
	}
}



bool ParticleManager::isAlive(string name){

	std::map<string, ParticleEffect*>::iterator it = mParticleMap.find(name);
	if(it != mParticleMap.end()){
		ParticleEffect* p = it->second;
		return p->isAlive();
	}
	return false;
}