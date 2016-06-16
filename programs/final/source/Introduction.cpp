#include "GameEngine.h"
#include "Stage.h"

using namespace Ogre;


void Introduction::chooseScene(){

	if(mSceneMgr == NULL){
		mSceneMgr = mEngine->mRoot->createSceneManager(Ogre::ST_EXTERIOR_CLOSE, "primary");
	}
}




void Introduction::createScene(){
	Stage::createScene();

	mPicture = OverlayManager::getSingleton().createOverlayElement("Panel","OverlayElement/storyBackground");
	mPicture->setParameter("metrics_mode","pixels");
	mPicture->setParameter("left","0");
	mPicture->setParameter("top","0");
	mPicture->setParameter("width","1024");
	mPicture->setParameter("height","800");
	mPicture->setMaterialName("story/magic_field01");
	mOverlay = OverlayManager::getSingleton().create("Overlay/background");
	mOverlay->add2D((OverlayContainer*)mPicture);
	mOverlay->setZOrder(1);
	mOverlay->show();

}


bool Introduction::doLoadingScript(){
	Stage::doLoadingScript();
	cout << "loading story" << endl;
	//mEngine->enableDefaultInput(false);
	mScriptMode = SM_STORY;
	return true;
}


bool Introduction::doBattleScript(){
	Stage::doBattleScript();
	

	return true;
}


bool Introduction::doStoryScript(){
	Stage::doStoryScript();
	if((int)mTime == 0){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.2, 0.3, L"很久很久以前");
	}

	if((int)mTime == 1){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.3, L"很久很久以前");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.22, 0.35, L"世界是由惡魔所統治著");
	}


	if((int)mTime == 2){

		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.3, L"很久很久以前");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.22, 0.35, L"世界是由惡魔所統治著");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.5, 0.6, L"人類在黑暗魔法的威脅下");
	}

	if((int)mTime == 3){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.3, L"很久很久以前");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.22, 0.35, L"世界是由惡魔所統治著");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.5, 0.6, L"人類在黑暗魔法的威脅下");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.55, 0.65, L"長期過著被奴役的生活");
	}

	//=============================================================


	if((int)mTime == 4){
		mPicture->setMaterialName("story/magic_field04");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.3, 0.5, L"直到有一天");
	}

	
	if((int)mTime == 5){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.3, 0.5, L"直到有一天");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.4, 0.6, L"人類發現了世界上存在著足以與惡魔抗衡的光明魔法");
	}


	if((int)mTime == 6){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.3, 0.5, L"直到有一天");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.4, 0.6, L"人類發現了世界上存在著足以與惡魔抗衡的光明魔法");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.4, 0.7, L"於是，終於將惡魔趨逐出人類的世界。");
	}

	//=================================================

	if((int)mTime == 7){
		mPicture->setMaterialName("story/magic_field05");
		mTime++;
	}


	if((int)mTime == 8){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.2, 0.3, L"然而，在百年之後，魔界之門突然大開");
	}


	if((int)mTime == 9){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.3, L"然而，在百年之後，魔界之門突然大開");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.3, 0.4, L"惡魔如水洩一般從中湧現");
	}


	
	if((int)mTime == 10){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.3, L"然而，在百年之後，魔界之門突然大開");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.3, 0.4, L"惡魔如水洩一般從中湧現");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.5, 0.6, L"並攻破人類散佈在世界各地作為魔法陣的魔塔");
	}

	//===============================================

	if((int)mTime == 11){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.2, 0.2, L"人類完全沒有任何抵抗的能力");
	}

	if((int)mTime == 12){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.2, L"人類完全沒有任何抵抗的能力");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.3, 0.3, L"世界頓時陷入混亂與絕望之中");
	}


	//=====================================================

	if((int)mTime == 13){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.4, 0.5, L"最後的主塔，位於人類絕不能被攻陷的聖都");
	}

	
	if((int)mTime == 14){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.5, 0.6, L"此時的情況已經不能再惡化下去...");
	}


	//=================================
	if(mTime >= 15 ){
		mTime += evt.timeSinceLastFrame;
	}

	float fontSize = 2;
	if((int)mTime == 15){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"魔");
	}

	if((int)mTime == 16){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"魔  塔");
	}


	if((int)mTime == 17){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"魔  塔  守");
	}


	if((int)mTime == 18){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"魔  塔  守  護");
	}
 
	if((int)mTime == 19){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"魔  塔  守  護  者");
	}

	if((int)mTime >= 20){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"魔  塔  守  護  者");
		gScreenText.print(0.35, 0.55, fontSize, L"<<Magic Tower>>");
	}

	if((int)mTime >= 22){
		mScriptMode = SM_FINISH;

	}

	return true;

}


bool Introduction::doFinishScript(){
	Stage::doFinishScript();
	mEngine->currentStage = mEngine->mStages[1];
	OverlayManager::getSingleton().destroyOverlayElement(mPicture);
	OverlayManager::getSingleton().destroy(mOverlay);
	mPicture = NULL;
	mOverlay = NULL;
	//mOverlay->clear();
//	mOverlay->clear();
	//OverlayManager::getSingleton().destroyAllOverlayElements();
	//OverlayManager::getSingleton().destroyAll();
	//OverlayManager::getSingleton().destroyAll();
	return true;
}