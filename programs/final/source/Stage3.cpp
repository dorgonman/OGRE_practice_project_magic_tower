#include "GameEngine.h"
#include "Stage.h"

using namespace Ogre;


void Stage3::chooseScene(){

	if(mSceneMgr == NULL){
		mSceneMgr = mEngine->mRoot->createSceneManager(Ogre::ST_EXTERIOR_CLOSE, "primary");
	}
}


bool Stage3::doLoadingScript(){
	Stage::doLoadingScript();
	cout << "loading Stage3" << endl;
	this->mScriptMode = SM_BATTLE;
	this->mEngine->enableDefaultInput(true);
	mTime = 0;
	return true;
}


bool Stage3::doBattleScript(){
	Stage::doBattleScript();
	if(mTime < 4){
		static float alpha = 1;
		gScreenText.setColour(ColourValue(1, 1, 1, alpha));
		gScreenText.print(0.4, 0.3, 2, L"Stage3: 終幕");
		alpha -= evt.timeSinceLastFrame * 0.1;
	}


	if((int)mTime == 5){
		setEvent2();
	}

	
	if((int)mTime == 5){
		setEvent3();
	}

	if((int)mTime == 15){
		setEvent4();
	}

	if((int)mTime == 20){
		setEvent8();
	}

	if((int)mTime == 25){
		setEvent9();
	}

	if((int)mTime == 30){
		setEvent5();
	}

	
	if((int)mTime == 35){
		setEvent6();
	}



	if((int)mTime == 40){
		setEvent7();
	}


	if((int)mTime == 45){
		setEvent1();
	}



	if((int)mTime == 50){
		setEvent2();
	}

	if((int)mTime == 55){
		setEvent8();
		setEvent9();
	}




	doEvent1(); //robot
	doEvent2(); //fish
	doEvent3(); //penguin
	doEvent4(); //ogrehead
	doEvent5(); //penguin2
	doEvent6(); //ogrehead2
	doEvent7(); //fish2
	doEvent8(); //razor
	doEvent9(); //razor2


	if(mTime > 55 && mTime < 60){
		static float alpha = 1;
		gScreenText.setColour(ColourValue(1, 0, 0, alpha));
		gScreenText.print(0.4, 0.1, 2, L"警告!警告! 敵人主力即將出現!");
		alpha -= evt.timeSinceLastFrame;
	}


	if((int)mTime == 60){
		setEvent10();
	}

	doEvent10();


	if(mTime > 60){
		Sprite3D* p = mMonsterMgr->getSprite("boss3");
		if(p){
			if(!p->isAlive()){
				mEngine->mFaderMap["stage3_win"]->startFadeOut(10, 1, 0);
				mScriptMode = SM_GAME_WIN;
			}
		}
	
	}


	return true;
}


bool Stage3::doStoryScript(){
	Stage::doStoryScript();

	return true;

}


bool Stage3::doFinishScript(){
	Stage::doFinishScript();
	mEngine->mFaderMap["stage3_win"]->hide();
	mEngine->currentStage = mEngine->mStages[4];
	return true;
}



bool Stage3::doGameWinScript(){
	bool faderRunning = mEngine->mFaderMap["stage3_win"]->fade(evt.timeSinceLastFrame);

	if(mPlayerSpr){
		mPlayerSpr->update(evt);
	}
	mParticleMgr->update(evt);
	return true;
}