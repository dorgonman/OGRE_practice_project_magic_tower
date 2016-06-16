#include "Weapon3D.h"
#include "Stage.h"
Weapon3D::Weapon3D(Stage* stage) : Sprite3D(stage){
	mCoolDown = 0.1;
	mCurrentBulletIndex = 0;
	mTime = mCoolDown;
	this->mLifeTime = 5;

}


Weapon3D::~Weapon3D(){
	for(int i = 0; i < this->mBulletArr.size(); i++){
		delete mBulletArr[i];
	}
	mBulletArr.clear();


}

void Weapon3D::createBullet(int num, string meshName){
	for(int i = 0; i < num; i++){
		Bullet3D* spr = new Bullet3D(mStage, this);
		mBulletArr.push_back(spr);
		Entity* ent = mStage->mSceneMgr->createEntity(meshName);
		ent->setCastShadows(false);
		SceneNode* snode = mStage->mSceneMgr->getRootSceneNode()->createChildSceneNode();
		snode->attachObject(ent);
		snode->scale(0.3, 0.3, 0.3);
		spr->attachSceneNode(snode);
		//this->mEntity
	}
}


void Weapon3D::trigger(Ogre::Vector3 at){

	//cout << "update:" << mTime << ":" << mCoolDown << endl;

	//大於cool down的時間之後才能射擊
	//if(this->mTime >= this->mCoolDown){
		//cout << "trigger weapon at:" << mCurrentBulletIndex << endl;
		//子彈不是活著的才能觸發
		if(!mBulletArr[mCurrentBulletIndex]->isAlive()){
			mBulletArr[mCurrentBulletIndex]->setInitDirection(mInitDirection);
			mBulletArr[mCurrentBulletIndex]->setDirection(mDirection);
			mBulletArr[mCurrentBulletIndex]->setInitVelocity(mInitVelocity);
			mBulletArr[mCurrentBulletIndex]->trigger(at);
			mCurrentBulletIndex++;
			if(mCurrentBulletIndex >= mBulletArr.size()){
				mCurrentBulletIndex = 0;
			}
			mTime = 0;
		}
	//}
}


void Weapon3D::update(const Ogre::FrameEvent &evt){
	for(int i = 0; i < mBulletArr.size(); i++){
		mBulletArr[i]->update(evt);
		mBulletArr[i]->updateViewDirection(Ogre::Radian(0));
	}
	mTime += evt.timeSinceLastFrame;

}


void Weapon3D::setBulletSize(Ogre::Vector3& scale){
	for(int i = 0; i < mBulletArr.size(); i++){
		mBulletArr[i]->getSceneNode()->scale(scale);
	}
}

void Weapon3D::setBulletLifeTime(float lifeTime){
	for(int i = 0; i < mBulletArr.size(); i++){
		mBulletArr[i]->setLifeTime(lifeTime);
	}
}


bool Weapon3D::hit(Sprite3D* sprite, float radius){
	for(int i = 0; i < mBulletArr.size(); i++){
		bool isHit = mBulletArr[i]->hit(sprite, radius);
		if(isHit){
			return true;
		}
	}
	return false;
}


void Weapon3D::setBulletMaterialName(std::string name){
	for(int i = 0; i < mBulletArr.size(); i++){
		mBulletArr[i]->mEntity->setMaterialName(name);
	}


}