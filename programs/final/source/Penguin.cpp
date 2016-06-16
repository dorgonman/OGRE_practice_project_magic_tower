#include "Monster3D.h"
#include "GameEngine.h"

Penguin::Penguin(Stage* stage) : Sprite3D(stage){
	mEntity = mStage->mSceneMgr->createEntity("penguin.mesh" ); 
	mSceneNode= mStage->mSceneMgr->getRootSceneNode()->createChildSceneNode();
	mSceneNode->setScale(2, 2, 2);
	mSceneNode->attachObject(mEntity);
	printAllAnimationName();
	mEntity->setCastShadows(false);
	setAnimation("amuse");

}

void Penguin::update(const Ogre::FrameEvent& evt){
	Sprite3D::update(evt);


	if(isAlive()){
		if(mSceneNode){
			Ogre::Vector3 position = mSceneNode->getPosition(); 
			bool negflg = mStage->projectScenePointOntoTerrain_NegDirection(position);
			float offset = mEntity->getBoundingRadius() / 2;
			if(mSceneNode->getPosition().y < position.y + offset){
				mSceneNode->setPosition(position + Ogre::Vector3(0, offset, 0));
			}
			
		}
	}
	
	//cout << "update monster" << endl;
}




void Penguin::updateViewDirection(Ogre::Vector3 targetPosition, Ogre::Radian yawRadian){
	Sprite3D::updateViewDirection(targetPosition, yawRadian);
	if(isAlive()){
		if(mSceneNode){
			targetPosition.y = mSceneNode->getPosition().y;
			//�Ǫ���model�ݪ���V�O�G�Ӥ��P����V
			mSceneNode->lookAt(targetPosition, Node::TS_WORLD);//�Ǫ��ݦV���a
			mSceneNode->yaw(yawRadian);//model����V��
		}
	}

}



void Penguin::setAlive(bool b){
	Sprite3D::setAlive(b);


	if(!b){
		if(mStage->mScriptMode == Stage::SM_BATTLE){
			mStage->mEngine->mAudioMgr->play("monster_die");
		}
	}
	//system("pause");
}