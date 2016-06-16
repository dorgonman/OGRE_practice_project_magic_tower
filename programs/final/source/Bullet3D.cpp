#include "Bullet3D.h"
#include "Stage.h"
#include "Weapon3D.h"

Bullet3D::Bullet3D(Stage* stage) : Sprite3D(stage){
	
	Bullet3D(stage, NULL);
}

Bullet3D::Bullet3D(Stage* stage, Weapon3D* weapon ) : Sprite3D(stage){
	mWeapon = weapon;
	mLifeTime = 5;
	power = 10;
	setAlive(false);
}

Bullet3D::~Bullet3D(){
}

void Bullet3D::setAlive(bool b){
	mTime = 0;
	this->mAlive = b;
	//mVelocity = Vector3(20, 0, 20);
	if(mSceneNode){
		if(mAlive){
			mSceneNode->setVisible(true);
		}else{
			mSceneNode->setVisible(false);
		}
	}
}

void Bullet3D::update(const Ogre::FrameEvent& evt){

	if(mAlive){
		this->mTime += evt.timeSinceLastFrame;
		if(mTime >= this->mLifeTime){
			setAlive(false);
		}
	

			Real t = evt.timeSinceLastFrame;
			Ogre::Vector3 pos = mSceneNode->getPosition() + (mDirection * (mVelocity * t));
			mSceneNode->setPosition(pos);
			//model it as a projectile
			static Ogre::Vector3 grav;
			if(this->mDirection.y >= 0){//要考慮地心引力的方向
				grav = Ogre::Vector3(0, -100, 0);
			}else{
				grav = Ogre::Vector3(0, 100, 0);
			}
			mVelocity += grav * t; 
			if(mStage->projectScenePointOntoTerrain_PosDirection(pos)){
				this->mDirection.y = -this->mDirection.y;//方向改變
				Ogre::Vector3 offset(0, 10, 0);
				mSceneNode->setPosition(pos+offset);//不要沉入地板
				mVelocity = mInitVelocity;
			}
			//cout << this->mDirection.y << endl;
	}else{
		if(mSceneNode){
			mSceneNode->setVisible(false);
		}
	}
}

void Bullet3D::trigger(Ogre::Vector3 at){
	if(mSceneNode){
		this->mSceneNode->setPosition(at);
	}
	setAlive(true);
}


bool Bullet3D::hit(Sprite3D *sprite, float radius){
	if(mAlive){
		Ogre::Vector3 position = this->getPosition();
		float distnace = position.distance(sprite->getPosition());
		if(distnace <= radius){
			mStage->mParticleMgr->trigger("bulletHit", position);
			sprite->decreaseHealth(power);
			setAlive(false);
			//this->getParticleSceneNode()->setVisible(true);
			return true;
		}
	}

	return false;
}