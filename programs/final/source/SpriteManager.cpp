#include "SpriteManager.h"

SpriteManager::SpriteManager(){

}




SpriteManager::~SpriteManager(){

	for(std::map<string, Sprite3D*>::iterator it =
		mSpriteMap.begin(); 
		it != mSpriteMap.end(); it++) {

		Sprite3D* p = it->second;
		delete p;
		p = NULL;

	}
	mSpriteMap.clear();

}


void SpriteManager::addSprite(string name, Sprite3D* sprite){
	mSpriteMap.insert(make_pair(name, sprite));
}




void SpriteManager::update(Ogre::FrameEvent &evt){
	for(std::map<string, Sprite3D*>::iterator it =
		mSpriteMap.begin(); 
		it != mSpriteMap.end(); it++) {

		Sprite3D* p = it->second;
		p->update(evt);

	}
}



void SpriteManager::updateViewDirection(Vector3 targetPosition){

	for(std::map<string, Sprite3D*>::iterator it =
		mSpriteMap.begin(); 
		it != mSpriteMap.end(); it++) {

		Sprite3D* p = it->second;
		//�p�G�Oogrehead.mesh���ܡA�ҫ�Y�b���N��3.14
		if(it->first.find("ogrehead") != string::npos  || it->first.find("boss3") != string::npos){ 
			p->updateViewDirection(targetPosition, Ogre::Radian(3.14));
		}

		//�p�G�Ofish.mesh���ܡA�ҫ�Y�b���N��-1.6
		if(it->first.find("fish") != string::npos){
				p->updateViewDirection(targetPosition, Ogre::Radian(-1.6));
		}

		
		//�p�G�Ojaiqua.mesh���ܡA�ҫ�Y�b���N��-1.6
		if(it->first.find("jaiqua") != string::npos){
				p->updateViewDirection(targetPosition, Ogre::Radian(0));
		}
		//�p�G�Ojaiqua.mesh���ܡA�ҫ�Y�b���N��-1.6
		if(it->first.find("penguin") != string::npos  || it->first.find("boss2") != string::npos){
				p->updateViewDirection(targetPosition, Ogre::Radian(3.14));
		}

		if(it->first.find("razor") != string::npos  || it->first.find("boss1") != string::npos){
			p->updateViewDirection(targetPosition, Ogre::Radian(3.14));
		}

		if(it->first.find("robot") != string::npos){
			p->updateViewDirection(targetPosition, Ogre::Radian(1.67));
		}
	}
}


bool SpriteManager::isAlive(string name){
	std::map<string, Sprite3D*>::iterator it = mSpriteMap.find(name);
	if(it != mSpriteMap.end()){
		Sprite3D* p = it->second;
		return p->isAlive();
	}
	return false;

}

Vector3 SpriteManager::getPosition(string name){
	std::map<string, Sprite3D*>::iterator it = mSpriteMap.find(name);
	if(it != mSpriteMap.end()){
		Sprite3D* p = it->second;
		return p->getPosition();
	}

	return Ogre::Vector3();
}



Sprite3D* SpriteManager::getSprite(string name){
	std::map<string, Sprite3D*>::iterator it = mSpriteMap.find(name);
	if(it != mSpriteMap.end()){
		Sprite3D* p = it->second;
		return p;
	}

	return NULL;
}