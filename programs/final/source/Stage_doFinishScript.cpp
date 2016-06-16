#include "Stage.h"
#include "GameEngine.h"


bool Stage::doFinishScript(){

	mEngine->mWindow->removeAllViewports();//�M���Ҧ���viewport
	cout << "do stage finish" << endl;
	//�p�G���e���إ߰_�ӹL����
	if(mSceneMgr != NULL){
		mSceneMgr->clearScene(); //�M����camera�~���Ҧ��F��
		mSceneMgr->destroyAllCameras();
		mEngine->mRoot->destroySceneManager(mSceneMgr);
		mSceneMgr = NULL;
	}
	mEngine->mCameraMan->setCamera(mEngine->mCamera);//�]�^�w�]��camera
	mEngine->enableDefaultInput(true);
	mScriptMode = SM_LOADING;
	mEngine->mTrayMgr->hideCursor();

	if(mPlayerSpr){
		delete mPlayerSpr;
		mPlayerSpr = NULL;
	}

	if(mParticleMgr){
		delete mParticleMgr;
		mParticleMgr = NULL;
	}

	if(mPlayerWeaponMgr){
		delete mPlayerWeaponMgr;
		mPlayerWeaponMgr = NULL;
	}

	if(mMonsterWeaponMgr){
		delete mMonsterWeaponMgr;
		mMonsterWeaponMgr = NULL;
	}

	if(	mMonsterMgr){
		delete 	mMonsterMgr;
		mMonsterMgr = NULL;
	}



	if(mAIEng){
		delete mAIEng;
		mAIEng = NULL;
	}

	if(mWeaponPicture){
		OverlayManager::getSingleton().destroyOverlayElement(mWeaponPicture);
		mWeaponPicture = NULL;
	}
	if(mWeaponOverlay){
		OverlayManager::getSingleton().destroy(mWeaponOverlay);
		mWeaponOverlay = NULL;
	}
	return true;
}

