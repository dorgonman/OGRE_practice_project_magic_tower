#include "WeaponManager.h"

WeaponManager::WeaponManager(){
	//mStage = stage;
}

WeaponManager::~WeaponManager(){
	for(std::map<string, Weapon3D*>::iterator it =
			mWeaponMap.begin(); 
			it != mWeaponMap.end(); it++) {

			Weapon3D* p = it->second;
			delete p;
			p  = NULL;
	}

	mWeaponMap.clear();


}


void WeaponManager::addWeapon(string name, Weapon3D* weapon){
	//mWeaponArr.push_back(weapon);
	mWeaponMap.insert(make_pair(name, weapon));
}



void WeaponManager::update(Ogre::FrameEvent &evt){
	
	for(std::map<string, Weapon3D*>::iterator it =
		mWeaponMap.begin(); 
		it != mWeaponMap.end(); it++) {

		Weapon3D* p = it->second;
		p->update(evt);

	}
}



bool WeaponManager::hit(std::map<string, Sprite3D*> sprites, float radius){

	for(std::map<string, Sprite3D*>::iterator it =
		sprites.begin(); 
		it!= sprites.end(); it++) {
		Sprite3D* p = it->second;
		bool isHit = hit(p, radius);
		if(isHit){
			return true;
		}
	}





}

bool WeaponManager::hit(Sprite3D *sprite, float radius){
	for(std::map<string, Weapon3D*>::iterator it =
		mWeaponMap.begin(); 
		it!= mWeaponMap.end(); it++) {
		Weapon3D* p = it->second;
		bool isHit = p->hit(sprite, radius);
		if(isHit){
			return true;
		}
	
	}
	return false;

}


bool WeaponManager::hit(std::map<string, Sprite3D*> sprites){

	for(std::map<string, Sprite3D*>::iterator it =
		sprites.begin(); 
		it!= sprites.end(); it++) {
		Sprite3D* p = it->second;
		bool isHit = hit(p);
		if(isHit){
			return true;
		}
	}
	
	return false;

}

bool WeaponManager::hit(Sprite3D *sprite){
	float radius = sprite->getSceneNode()->getAttachedObject(0)->getBoundingRadius() / 2;
	if(sprite->isAlive()){
		return hit(sprite, radius);
	}
	return false;

}


Weapon3D* WeaponManager::getWeapon(string name){
	std::map<string, Weapon3D*>::iterator it = mWeaponMap.find(name);
	if(it != mWeaponMap.end()){
		Weapon3D* p = it->second;
		return p;
	}

	return NULL;
}


void WeaponManager::setAllBulletDirectPosition(Weapon3D *weapon, Ogre::Vector3 position){
	for(int i = 0; i < weapon->mBulletArr.size(); i++){
		Bullet3D* bullet = weapon->mBulletArr[i];
		Vector3 direction = position - bullet->getPosition();
		direction.normalise();
		bullet->setDirection(direction);
	}


}


void WeaponManager::setAllBulletDirection(Weapon3D *weapon, Ogre::Vector3 direction){
	for(int i = 0; i < weapon->mBulletArr.size(); i++){
		Bullet3D* bullet = weapon->mBulletArr[i];
		bullet->setDirection(direction);
	}


}


void WeaponManager::setAllBulletDirection(Weapon3D *weapon, float theta, float alpha){
	for(int i = 0; i < weapon->mBulletArr.size(); i++){
		Bullet3D* bullet = weapon->mBulletArr[i];
		Vector3 direction;
		direction.x = cos(theta) * sin(alpha);
		direction.y = sin(theta);
		direction.z = cos(theta) * cos(alpha);
		direction.normalise();
		bullet->setDirection(direction);
	}
}