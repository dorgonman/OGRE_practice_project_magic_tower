#include "Monster3D.h"
#include "GameEngine.h"




Fish::Fish(Stage* stage) : Sprite3D(stage){
	mEntity = mStage->mSceneMgr->createEntity("fish.mesh" ); 
	mSceneNode= mStage->mSceneMgr->getRootSceneNode()->createChildSceneNode();
	mSceneNode->setScale(10, 10, 10);
	mSceneNode->attachObject(mEntity);
	setAnimation("swim");
	mIsFly = true;

}

void Fish::update(const Ogre::FrameEvent& evt){
	Sprite3D::update(evt);
	if(isAlive()){
		if(mSceneNode){
			Ogre::Vector3 position = mSceneNode->getPosition(); 

			//浮在半空中
			if(position.y < 80){
				position.y = 0;
				position = position + Ogre::Vector3(0, 80, 0);
			}
			bool flag = mStage->projectScenePointOntoTerrain_PosDirection(position);
			mSceneNode->setPosition(position);
		}
	}

	
	//cout << "update monster" << endl;
}




void Fish::updateViewDirection(Ogre::Vector3 targetPosition, Ogre::Radian yawRadian){
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



void Fish::setAlive(bool b){
	Sprite3D::setAlive(b);


	if(!b){
		if(mStage->mScriptMode == Stage::SM_BATTLE){
			mStage->mEngine->mAudioMgr->play("monster_die");
		}
	}
	//system("pause");
}