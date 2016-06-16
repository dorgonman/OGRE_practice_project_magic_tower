#include "Sprite3D.h"
#include "Stage.h"
#include "Weapon3D.h"


Sprite3D::Sprite3D(Stage* stage){
	mStage = stage;
	mSceneNode = NULL;
	mAnimationState = NULL;
	mEntity = NULL;
	mInitDirection = Ogre::Vector3(1, 0, 0);
	mEyePosition = Ogre::Vector3(0,90, 0);
	mVelocity = Ogre::Vector3(20, 20, 20);
	mTime = 0;
	mLifeTime = 10;
	mVision = 0;
	mInitHealth = 100;
	mHealth = 100;
	mInitLevel = 0;
	mLevel = 0;
	mInitJumpForce = 0;
	mJumpForce = 0;
	mJumpTimePassed = 0;
	mTowerTime = 0;
	mOffset = Ogre::Vector3(0, 0, 0);
	ATTime = 0;
	mActionMode = AM_NO;
	mIsFly = false;
	setAlive(false);


}



Sprite3D::~Sprite3D(){
	mSceneNode = NULL;
	mEntity = NULL;
}


void Sprite3D::attachSceneNode(Ogre::SceneNode *snode){
	mSceneNode = snode;
	Ogre::SceneNode::ObjectIterator it = mSceneNode->getAttachedObjectIterator();
	if(it.hasMoreElements()){
		Ogre::Entity* ent = (Entity*)it.getNext();
		if(ent){
			mEntity = ent;
		}
	}
}



void Sprite3D::setInitPosition(Ogre::Vector3 pos){
	mInitPosition = pos;
	if(mSceneNode){
		mSceneNode->setPosition(pos);
	}
}

void Sprite3D::setPosition(Ogre::Vector3 pos){
	if(mSceneNode){
		mSceneNode->setPosition(pos);
	}
}



Ogre::Vector3 Sprite3D::getPosition(){
	return mSceneNode->getPosition();
}

void Sprite3D::setInitVelocity(Ogre::Vector3 vel){
	mInitVelocity = vel;
	mVelocity = vel;
}


void Sprite3D::decreaseHealth(float power){

	//cout << ATTime << endl;
	if(ATTime <= 0){
		if(mHealth >= 0){	
			mHealth -= power;
			if(mHealth <= 0 ){
				mHealth = 0;
			}
		}
	}
}

void Sprite3D::increaseHealth(float power){
	if(mHealth <= mInitHealth){	
		mHealth += power;
		if(mHealth >= mInitHealth ){
			mHealth = mInitHealth;
		}
	}

}


void Sprite3D::setAlive(bool b){
	mAlive = b;
	mTime = 0;
	mTowerTime = 0;
	ATTime = 0;
	mInitJumpForce = 0;
	mJumpForce = 0;
	mJumpTimePassed = 0;
	mActionMode = AM_NO;
	if(mAlive){
		mHealth = mInitHealth;
		if(mSceneNode){
			this->mSceneNode->setPosition(this->mInitPosition);
		}
		if(mSceneNode){
			this->mSceneNode->setVisible(true);
		}
	}else{
		if(mSceneNode){
			this->mSceneNode->setVisible(false);
		}
	}
	
}


void Sprite3D::setVisibilityFlags(Ogre::uint flags){
	if(mEntity){
		mEntity->setVisibilityFlags(flags);
	}

}


void Sprite3D::jump(float force){
	mInitJumpForce = force;
	mJumpForce = force;
	mJumpTimePassed = 0;
}


void Sprite3D::setScale(Ogre::Vector3 scale){
	mSceneNode->setScale(scale);

}