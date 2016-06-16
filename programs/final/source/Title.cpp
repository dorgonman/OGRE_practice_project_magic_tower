#include "GameEngine.h"
#include "Stage.h"

using namespace Ogre;


void Title::chooseScene(){

	if(mSceneMgr == NULL){
		mSceneMgr = mEngine->mRoot->createSceneManager(Ogre::ST_EXTERIOR_CLOSE, "primary");
	}
}


void Title::createScene(){
	Stage::createScene();

	mPicture = OverlayManager::getSingleton().createOverlayElement("Panel","OverlayElement/title");
	mPicture->setParameter("metrics_mode","pixels");
	mPicture->setParameter("left","0");
	mPicture->setParameter("top","0");
	mPicture->setParameter("width","1024");
	mPicture->setParameter("height","800");
	mPicture->setMaterialName("my_game/title");
	mOverlay = OverlayManager::getSingleton().create("Overlay/title");
	mOverlay->add2D((OverlayContainer*)mPicture);
	mOverlay->setZOrder(1);
	mOverlay->show();
	mEngine->mButtonMgr->showCursor();
	mEngine->mButtonMgr->showAllButton();

	
}


bool Title::doLoadingScript(){
	Stage::doLoadingScript();
	cout << "loading story" << endl;
	mEngine->enableDefaultInput(true);
	mScriptMode = SM_STORY;
	return true;
}


bool Title::doBattleScript(){
	Stage::doBattleScript();


	return true;
}


bool Title::doStoryScript(){
	Stage::doStoryScript();

	buttonGUI::buttonEvent * e = mEngine->mButtonMgr->getEvent();		
	//THE FOLLOWING LOOP IS HOW TO GET EVENTS FROM buttonGUI,  simply continue calling getEvent until it returns NULL
	while(e){
		int pressButton = mEngine->handleButtonEvent(e);
		if(pressButton == GameEngine::START){
			mScriptMode = SM_FINISH;
		}

		if(pressButton == GameEngine::EXIT){
			return false;//µ²§ô¹CÀ¸
		}
		e = mEngine->mButtonMgr->getEvent();		
	}	
	mEngine->mButtonMgr->update();
	return true;
}


bool Title::doFinishScript(){
	Stage::doFinishScript();
	mEngine->currentStage = mEngine->mStages[0];
	OverlayManager::getSingleton().destroyOverlayElement(mPicture);
	OverlayManager::getSingleton().destroy(mOverlay);
	mPicture = NULL;
	mOverlay = NULL;
	mEngine->mButtonMgr->hideCursor();
	mEngine->mButtonMgr->hideAllButton();

	return true;
}