#include "Stage.h"
#include "GameEngine.h"


bool Stage::doFinishScript(){

	mEngine->mWindow->removeAllViewports();//清掉所有的viewport
	cout << "do stage finish" << endl;
	//如果之前有建立起來過的話
	if(mSceneMgr != NULL){
		mSceneMgr->clearScene(); //清掉資camera外的所有東西
		mSceneMgr->destroyAllCameras();
		mEngine->mRoot->destroySceneManager(mSceneMgr);
		mSceneMgr = NULL;
	}
	mEngine->mCameraMan->setCamera(mEngine->mCamera);//設回預設的camera
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

