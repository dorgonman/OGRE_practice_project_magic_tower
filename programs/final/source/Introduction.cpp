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
		gScreenText.print(0.2, 0.3, L"�ܤ[�ܤ[�H�e");
	}

	if((int)mTime == 1){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.3, L"�ܤ[�ܤ[�H�e");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.22, 0.35, L"�@�ɬO�Ѵc�]�ҲΪv��");
	}


	if((int)mTime == 2){

		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.3, L"�ܤ[�ܤ[�H�e");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.22, 0.35, L"�@�ɬO�Ѵc�]�ҲΪv��");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.5, 0.6, L"�H���b�·t�]�k���¯٤U");
	}

	if((int)mTime == 3){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.3, L"�ܤ[�ܤ[�H�e");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.22, 0.35, L"�@�ɬO�Ѵc�]�ҲΪv��");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.5, 0.6, L"�H���b�·t�]�k���¯٤U");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.55, 0.65, L"�����L�۳Q���Ъ��ͬ�");
	}

	//=============================================================


	if((int)mTime == 4){
		mPicture->setMaterialName("story/magic_field04");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.3, 0.5, L"���즳�@��");
	}

	
	if((int)mTime == 5){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.3, 0.5, L"���즳�@��");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.4, 0.6, L"�H���o�{�F�@�ɤW�s�b�ۨ��H�P�c�]�ܿŪ������]�k");
	}


	if((int)mTime == 6){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.3, 0.5, L"���즳�@��");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.4, 0.6, L"�H���o�{�F�@�ɤW�s�b�ۨ��H�P�c�]�ܿŪ������]�k");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.4, 0.7, L"��O�A�ש�N�c�]�ͳv�X�H�����@�ɡC");
	}

	//=================================================

	if((int)mTime == 7){
		mPicture->setMaterialName("story/magic_field05");
		mTime++;
	}


	if((int)mTime == 8){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.2, 0.3, L"�M�ӡA�b�ʦ~����A�]�ɤ�����M�j�}");
	}


	if((int)mTime == 9){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.3, L"�M�ӡA�b�ʦ~����A�]�ɤ�����M�j�}");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.3, 0.4, L"�c�]�p�����@��q����{");
	}


	
	if((int)mTime == 10){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.3, L"�M�ӡA�b�ʦ~����A�]�ɤ�����M�j�}");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.3, 0.4, L"�c�]�p�����@��q����{");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.5, 0.6, L"�ç�}�H�����G�b�@�ɦU�a�@���]�k�}���]��");
	}

	//===============================================

	if((int)mTime == 11){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.2, 0.2, L"�H�������S�������ܪ���O");
	}

	if((int)mTime == 12){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 0.5));
		gScreenText.print(0.2, 0.2, L"�H�������S�������ܪ���O");
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.3, 0.3, L"�@�ɹy�ɳ��J�V�ûP���椧��");
	}


	//=====================================================

	if((int)mTime == 13){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.4, 0.5, L"�̫᪺�D��A���H��������Q�𳴪��t��");
	}

	
	if((int)mTime == 14){
		gScreenText.setColour(Ogre::ColourValue(1, 1, 1, 1));
		gScreenText.print(0.5, 0.6, L"���ɪ����p�w�g����A�c�ƤU�h...");
	}


	//=================================
	if(mTime >= 15 ){
		mTime += evt.timeSinceLastFrame;
	}

	float fontSize = 2;
	if((int)mTime == 15){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"�]");
	}

	if((int)mTime == 16){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"�]  ��");
	}


	if((int)mTime == 17){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"�]  ��  �u");
	}


	if((int)mTime == 18){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"�]  ��  �u  �@");
	}
 
	if((int)mTime == 19){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"�]  ��  �u  �@  ��");
	}

	if((int)mTime >= 20){
		gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
		gScreenText.print(0.3, 0.5, fontSize, L"�]  ��  �u  �@  ��");
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