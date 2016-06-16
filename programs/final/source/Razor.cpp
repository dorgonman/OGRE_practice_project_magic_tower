#include "Monster3D.h"
#include "GameEngine.h"

Razor::Razor(Stage* stage) : Sprite3D(stage){
	mEntity = mStage->mSceneMgr->createEntity("razor.mesh"); 
	mSceneNode= mStage->mSceneMgr->getRootSceneNode()->createChildSceneNode();
	mSceneNode->setScale(1, 1, 1);
	mSceneNode->attachObject(mEntity);
	printAllAnimationName();
	mEntity->setCastShadows(false);
	mIsFly = true;
}

void Razor::update(const Ogre::FrameEvent& evt){
	Sprite3D::update(evt);


	if(isAlive()){
		if(mSceneNode){
			Ogre::Vector3 position = mSceneNode->getPosition(); 
			//浮在半空中
			if(position.y < 200){
				position.y = 0;
				position = position + Ogre::Vector3(0, 200, 0);
			}
			bool flag = mStage->projectScenePointOntoTerrain_PosDirection(position);
			mSceneNode->setPosition(position);
		}
	}
	
}




void Razor::updateViewDirection(Ogre::Vector3 targetPosition, Ogre::Radian yawRadian){
	Sprite3D::updateViewDirection(targetPosition, yawRadian);
	if(isAlive()){
		if(mSceneNode){
			targetPosition.y = mSceneNode->getPosition().y;
			//怪物跟model看的方向是二個不同的方向
			mSceneNode->lookAt(targetPosition, Node::TS_WORLD);//怪物看向玩家
			mSceneNode->yaw(yawRadian);//model的方向轉
		}
	}

}



void Razor::setAlive(bool b){
	Sprite3D::setAlive(b);


	if(!b){
		if(mStage->mScriptMode == Stage::SM_BATTLE){
			mStage->mEngine->mAudioMgr->play("monster_die");
		}
	}
	//system("pause");
}