#include "Monster3D.h"
#include "GameEngine.h"



OgreHead::OgreHead(Stage* stage) : Sprite3D(stage){
	mRandSpeed = ((rand()%1000)/1000.0);
	mAmplitude = 1;

	mEntity = mStage->mSceneMgr->createEntity("ogrehead.mesh" ); 
	mSceneNode= mStage->mSceneMgr->getRootSceneNode()->createChildSceneNode();
	mSceneNode->attachObject(mEntity);
}

void OgreHead::update(const Ogre::FrameEvent& evt){

	Sprite3D::update(evt);
	if(isAlive()){
		//�W�U����
		mTime += evt.timeSinceLastFrame + evt.timeSinceLastFrame*(5*mRandSpeed);
		mOffset.y += mAmplitude * sin(mTime);
		Ogre::Vector3 position = this->mSceneNode->getPosition();

		position.y = 0;
		Ogre::Vector3 ip = position + mOffset;

		bool flag = mStage->projectScenePointOntoTerrain_PosDirection(ip);
		ip.y += 20;
		//if(!flag){
		if(mSceneNode){
			mSceneNode->setPosition(ip);
		}
	}

	//cout << "update monster" << endl;
}




void OgreHead::updateViewDirection(Ogre::Vector3 targetPosition, Ogre::Radian yawRadian){
	if(isAlive()){
		if(mSceneNode){
			targetPosition.y = mSceneNode->getPosition().y;
			//�Ǫ���model�ݪ���V�O�G�Ӥ��P����V
			mSceneNode->lookAt(targetPosition, Node::TS_WORLD);//�Ǫ��ݦV���a
			mSceneNode->yaw(yawRadian);//model����V��
		}
	}

}



void OgreHead::setAlive(bool b){
	Sprite3D::setAlive(b);


	if(!b){

		if(mStage->mScriptMode == Stage::SM_BATTLE){
			mStage->mEngine->mAudioMgr->play("monster_die");
		}
	}
	//system("pause");
}