#include "GameEngine.h"
#include "Stage.h"

using namespace Ogre;

void StageExtra::doLoadingScript(){
	Stage::doLoadingScript();
	cout << "loading StageExtra" << endl;
	chooseScene();
	
	createCamera();

	createViewPort();

	createScene();
	//
	mZoomIn = false;
	mZoomOut = false;
	mZoomTime = 0;

	mGameOver = false;
	//=========over lay=============
	setupFaders();
	mCurFader->startFadeIn(5, 0, 1);
//	this->mEngine->mTrayMgr->hideTrays();
	mScriptMode = SM_STORY;

	//======================
	mCurrentObject->setAlive(true);
	mGameWin = false;

	mDigitDialogue = new DIGIT_STRING_DIALOGUE(mSceneMgr, "Examples/Digits");
	mDigitDialogue->setScore(0, 0.5, 0.5, 0.5, 0.5);
	//mDigitDialogue->

	mBar2D = new BAR_2D(mSceneMgr, "my_game/LifeBar", NULL);
	mBar2D->setDefaultPos(0.05, 0.5);

	//mBar2D_2 = new BAR_2D(mSceneMgr, "wago_game/LifeBar", NULL);
	//mBar2D_2->setDefaultPos(0.05, 0.75);
	//this->mEngine->mTrayMgr->hideTrays();
	
	mMonsterArr[0]->setInitVelocity(Vector3(0, 0, 80));
	mCurrentObject->setVelocity(Vector3(200, 200, 200));
	
}




void StageExtra::doBattleScript(){
	Stage::doBattleScript();

	//this->printAllAnimationName((Entity*)mCurrentObject->getSceneNode()->getAttachedObject(0));

	//更新player
	if(mCurrentObject){
		mCurrentObject->update(evt);
		//mCurrentObject->updateViewDirection();
	}


	if(!mGameOver){
		if(mCurrentObject->getHealth() <= 0){
			mCurrentObject->setAnimation("Die", false);
			mCurrentObject->setAlive(false);
			mCurFader = mFaderMap["game_over"];
			mCurFader->startFadeOut(10, 1, 0);
			mScriptMode = SM_STORY;
			mGameOver = true;
		}
	}


	//更新系統
	if(!mGameWin){
		updateLight();
		updateViewPort1Camera();
		updateZoomAffect();
		updateBattleSystem();
	}
	mParticleManager->update(evt);
	//win condition
	if(mCurrentObject->mLevel >= mParameter->mWinCount){
		mCurFader = mFaderMap["game_win"];
		//mCurFader = mFaderMap["game_over"];
		mCurFader->startFadeOut(10, 1, 0);
		mGameWin = true;
		mScriptMode = SM_STORY;
	
	}

	/*Vector3 monsterPos = mMonsterArr[0]->getPosition();
	Vector3 targetPos = mCurrentObject->getPosition();
	Vector3 direction = targetPos - monsterPos;
	Real m = 1.0;
	direction.normalise();
	Vector3 force = 30 * direction;


	mMonsterArr[0]->setVelocity(mMonsterArr[0]->getVelocity() + force / m * evt.timeSinceLastFrame);

	monsterPos = monsterPos + mMonsterArr[0]->getVelocity()* evt.timeSinceLastFrame;
	mMonsterArr[0]->setPosition(monsterPos);*/
	/*charPos  = mChar[i]->getPosition();
	Vector3 targetPos = mTarget->getPosition();
	Vector3 direction = targetPos - charPos;
	Real m = 1.0;
	direction.normalise(); //unit vector
	Vector3 force = 30*direction; // constant force magnitude = 30

	mCharVelocity[i] = mCharVelocity[i] + force/m*t;
	charPos = charPos + mCharVelocity[i]*t;
	mChar[i]->setPosition(charPos);*/
}


void StageExtra::doStoryScript(){
	Stage::doStoryScript();
	std::cout << "StageExtra Story" << std::endl;

	//mCurMode_Duration+= evt.timeSinceLastFrame;
	//做fade
	bool faderRunning = mCurFader->fade(evt.timeSinceLastFrame);
	//如果遊戲還沒結束的話，就要換回battle
	if (!faderRunning && !mGameWin) {
		mScriptMode = SM_BATTLE;
	}

	//更新player
	if(mCurrentObject){
		mCurrentObject->update(evt);
		//mCurrentObject->updateViewDirection();
	}
	if(!mGameWin){
		//更新系統
		updateLight();
		//updateSphere();
		updateViewPort1Camera();
		updateZoomAffect();
		updateBattleSystem();
	}
	mParticleManager->update(evt);

}

void StageExtra::doFinishScript(){
	Stage::doFinishScript();
	mEngine->currentStage = mEngine->stages[0];
	cout << "StageExtra Finish" <<endl;
	for(int i = 0; i < this->mMonsterArr.size(); i++){
		delete mMonsterArr[i];
	}
	mMonsterArr.clear();
}


void StageExtra::updateZoomAffect(){
	Ogre::Camera* cam = mSceneMgr->getCamera("playerCam1");

	static float maxZomeTime = 1.0;
	if(mZoomIn){
		if(mZoomTime <= maxZomeTime){
			if(cam->getPosition().y <= 1300){
				cam->setPosition(cam->getPosition() + Ogre::Vector3(0, 3, 0));
			}
			mZoomTime += evt.timeSinceLastFrame;
		}else{
			mZoomIn = false;
		}
		
	}

	if(mZoomOut){
		if(mZoomTime <= maxZomeTime){
			if(cam->getPosition().y >= 400){
				cam->setPosition(cam->getPosition() - Ogre::Vector3(0, 3, 0));
			}
		}else{
			mZoomOut = false;
		}
		mZoomTime += evt.timeSinceLastFrame;
	}

}

void StageExtra::updateLight(){
	Ogre::Vector3 offset(50, 100, 50);
	Ogre::Light* light = mSceneMgr->getLight("SpotLight0");
	light->setPosition(mCurrentObject->getSceneNode()->getPosition() + offset);

}


void StageExtra::updateSphere(){
	Ogre::Vector3 pos(750, 330, 750);
	Real a = evt.timeSinceLastFrame;
	static Real b = 0;
	b += a*0.8;
	Real y = 90 * sin(b);
	pos.y += y;
	static Real c = 0.0;
	c+=a;
	mSceneMgr->getSceneNode("mySphereNode")->setPosition(pos);
	mSceneMgr->getSceneNode("particleNode")->setPosition(pos);


}

void StageExtra::updateViewPort1Camera(){
	Ogre::Camera* camera = mSceneMgr->getCamera("playerCam1");
	Ogre::Vector3 playerPos = this->mCurrentObject->getSceneNode()->getPosition();
	Ogre::Vector3 cameraPos = camera->getPosition();
	camera->setPosition(playerPos.x, cameraPos.y, playerPos.z);
}


void StageExtra::updateBattleSystem(){

	//要先回血才能扣血，不然會無法觸方死亡事件
	if(!mGameOver){
		mCurrentObject->increaseHealth((mCurrentObject->mLevel+ 1) * 2 * evt.timeSinceLastFrame);

	}
	//=============
	for(int i = 0; i < mMonsterArr.size(); i++){
		mMonsterArr[i]->update(evt);
		//mMonsterArr[i]->updateViewDirection();
		//如果monster跟player都是活的才會射擊
		if(mMonsterArr[i]->isAlive() && mCurrentObject->isAlive()){
			float distance = mMonsterArr[i]->getPosition().distance(mCurrentObject->getPosition());
			//在射程範圍內的話就對玩家射擊
			if(distance < mMonsterArr[i]->getVision()){
				Vector3 trigger = mCurrentObject->getPosition();
				trigger.y += 40;
				//mMonsterArr[i]->fireWeapon(trigger);
			}
			//擊倒一個monster，增加等級
			if(mMonsterArr[i]->getHealth() <= 0){
				mMonsterArr[i]->setAlive(false);
				mCurrentObject->mLevel++;

			}
		}

	
		//擊中判定：範圍是Entity的半徑
		float radius = mCurrentObject->getSceneNode()->getAttachedObject(0)->getBoundingRadius() / 2;
	//	mMonsterArr[i]->getWeapon()->hit(mCurrentObject, radius);
		radius = mMonsterArr[i]->getSceneNode()->getAttachedObject(0)->getBoundingRadius() / 2;
	//	mCurrentObject->getWeapon()->hit(mMonsterArr[i], radius);
	}




	cout << "health:" << mCurrentObject->getHealth() << endl;
	cout << "level:" << mCurrentObject->mLevel << endl;

	mDigitDialogue->setScore(mCurrentObject->mLevel, 0.05, 0.05);

	//mDigitDialogue->setScore(mCurrentObject->mLevel, 0.1, 0.1, 0.5, 0.5);
	
	mBar2D->setSplit2Parts(true);
	mBar2D->setInfo(mCurrentObject->mHealth, mCurrentObject->mInitHealth);
	mBar2D->update(0, 0);
	//

	
	
}