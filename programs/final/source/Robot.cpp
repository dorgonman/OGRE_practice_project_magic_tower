#include "Monster3D.h"
#include "GameEngine.h"

Robot::Robot(Stage* stage) : Sprite3D(stage){
	mEntity = mStage->mSceneMgr->createEntity("robot.mesh" ); 
	mSceneNode= mStage->mSceneMgr->getRootSceneNode()->createChildSceneNode();
	mSceneNode->attachObject(mEntity);
	printAllAnimationName();
	mEntity->setCastShadows(false);
	mSceneNode->setScale(0.9, 0.9, 0.9);
	setAnimation("Walk");

}

void Robot::update(const Ogre::FrameEvent& evt){
	Sprite3D::update(evt);


	if(isAlive()){
		if(mSceneNode){
			Ogre::Vector3 position = mSceneNode->getPosition(); 
			bool negflg = mStage->projectScenePointOntoTerrain_NegDirection(position);
	
			if(mSceneNode->getPosition().y < position.y){
				mSceneNode->setPosition(position);
			}

		}
	}
	//cout << "update monster" << endl;
}




void Robot::updateViewDirection(Ogre::Vector3 targetPosition, Ogre::Radian yawRadian){
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



void Robot::setAlive(bool b){
	Sprite3D::setAlive(b);


	if(!b){
		if(mStage->mScriptMode == Stage::SM_BATTLE){
			mStage->mEngine->mAudioMgr->play("monster_die");
		}
	}
	//system("pause");
}