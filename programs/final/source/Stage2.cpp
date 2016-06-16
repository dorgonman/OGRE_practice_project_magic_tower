#include "GameEngine.h"
#include "Stage.h"

using namespace Ogre;


void Stage2::chooseScene(){

	if(mSceneMgr == NULL){
		mSceneMgr = mEngine->mRoot->createSceneManager(Ogre::ST_EXTERIOR_CLOSE, "primary");
	}
}


bool Stage2::doLoadingScript(){
	Stage::doLoadingScript();
	cout << "loading Stage2" << endl;
	this->mScriptMode = SM_BATTLE;
	this->mEngine->enableDefaultInput(true);
	mTime = 0;
	return true;
}


bool Stage2::doBattleScript(){
	Stage::doBattleScript();
	if(mTime < 4){
		static float alpha = 1;
		gScreenText.setColour(ColourValue(1, 1, 1, alpha));
		gScreenText.print(0.4, 0.3, 2, L"Stage2: 魔塔守護者");
		alpha -= evt.timeSinceLastFrame * 0.1;
	}

	if((int)mTime == 3){
		setEvent1();
	
	}

	if((int)mTime == 5){
		setEvent2();
	
	}


	if((int)mTime == 10){
		setEvent3();
	}

	if((int)mTime == 15){
		setEvent4();
	
	}

	if((int)mTime == 20){
		setEvent5();
	
	}


	
	if((int)mTime == 25){
		setEvent6();
	
	}

	if((int)mTime == 30){
		setEvent7();
	
	}

	if((int)mTime == 35){
		setEvent1();
	
	}

	if((int)mTime == 40){
		setEvent5();
	
	}

	if((int)mTime == 45){
		setEvent4();
		setEvent2();
	}
	
	
	if(mTime > 45 && mTime < 50){
		static float alpha = 1;
		gScreenText.setColour(ColourValue(1, 0, 0, alpha));
		gScreenText.print(0.4, 0.1, 2, L"警告!警告! 敵人主力即將出現!");
		alpha -= evt.timeSinceLastFrame;
	}


	doEvent1(); //robot
	doEvent2(); //fish
	doEvent3(); //penguin
	doEvent4(); //ogrehead
	doEvent5(); //penguin2
	doEvent6(); //ogrehead2
	doEvent7(); //fish 2


	if((int)mTime == 50){
		setEvent8();
	
	}



	if(mTime > 50){
		Sprite3D* p = mMonsterMgr->getSprite("boss2");
		if(p){
			if(!p->isAlive()){
				mEngine->mFaderMap["stage2_win"]->startFadeOut(10, 1, 0);
				mScriptMode = SM_GAME_WIN;
			}
		}
	
	}
	doEvent8();
	return true;
}


bool Stage2::doStoryScript(){
	Stage::doStoryScript();

	return true;
	

}


bool Stage2::doFinishScript(){
	Stage::doFinishScript();
	mEngine->mFaderMap["stage2_win"]->hide();
	mEngine->currentStage = mEngine->mStages[3];
	return true;
}



bool Stage2::doGameWinScript(){
	bool faderRunning = mEngine->mFaderMap["stage2_win"]->fade(evt.timeSinceLastFrame);


	if(mPlayerSpr){
		mPlayerSpr->update(evt);
	}
	mParticleMgr->update(evt);

	return true;

}