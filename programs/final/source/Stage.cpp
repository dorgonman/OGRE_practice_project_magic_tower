#include "Stage.h"
#include "GameEngine.h"

Stage::Stage(GameEngine* engine){
	mEngine = engine;
	mSceneMgr = NULL;
	mScriptMode = SM_LOADING;
	mViewMode = VM_FPS;
	mWeaponMode = NWAY3;
	mPlayerSpr = NULL;
	mGameOver = false;
	mGameWin = false;
	mTime = 0;
	mGravity = Ogre::Vector3(0, -9.8, 0);
	mParticleMgr = NULL;
	mViewOffset = Ogre::Vector3(100, 0, 100);
	mPlayerHPBar2D = NULL;
	mTowerHPBar2D = NULL;
	mPlayerWeaponMgr = NULL;
	mMonsterWeaponMgr = NULL;
	mMonsterMgr = NULL;
	mAIEng = NULL;
	mWeaponPicture = NULL;
	this->mWeaponOverlay = NULL;

}


Stage::~Stage(){



}
bool Stage::doScript(const Ogre::FrameEvent &_evt){
	evt = _evt;
	
	if(mScriptMode == SM_INITIALIZE){
		cout << " you must change your mScriptMode to begain your stage script" << endl;
	}

	if(mScriptMode == SM_LOADING){
		return doLoadingScript();
	}

	if(mScriptMode == SM_BATTLE){
		mWeaponOverlay->show();
		this->keyDown();
		return doBattleScript();
	}else{
		mWeaponOverlay->hide();
	}


	if(mScriptMode == SM_GAME_OVER){
		keyDown();
		return doGameOverScript();

	}

	if(mScriptMode == SM_GAME_WIN){
		keyDown();
		return doGameWinScript();
	
	}
	if(mScriptMode == SM_STORY){
		this->keyDown();
		return doStoryScript();
	}

	if(mScriptMode == SM_FINISH){
		return doFinishScript();
	}
}






void Stage::chooseScene(){

}

void Stage::createCamera(){
	//一定要建一個名為playerCam的camera，不然會crash
	Ogre::Camera* camera = mSceneMgr->createCamera("playerCam");
	camera->setPosition(Ogre::Vector3(200, 500,200));
	camera->lookAt(Ogre::Vector3(500,580,500));
	camera->setNearClipDistance(5);
	mEngine->mCameraMan->setCamera(camera);   // assign to default camera controller

}


void Stage::createViewPort(){
	
	{//view1
		Ogre::Viewport* vp = mEngine->mWindow->addViewport(
			mSceneMgr->getCamera("playerCam"),
			0,
			0,
			0,
			1,
			1
			);
		vp->setBackgroundColour(Ogre::ColourValue(0,1,0));
		
		mSceneMgr->getCamera("playerCam")->setAspectRatio(
			Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
		vp->setVisibilityMask(0x01);
		vp->setOverlaysEnabled(true);
	}

}

void Stage::createScene(){
	mViewOffset = Ogre::Vector3(100, 0, 100);
	mTime = 0;
	mGameOver = false;
	mGameWin = false;
	mTime = 0;

	mPlayerHPBar2D = new BAR_2D(mSceneMgr, "my_game/LifeBar", NULL);
	mTowerHPBar2D = new BAR_2D(mSceneMgr, "my_game/LifeBar", NULL);

	mMonsterMgr = new SpriteManager();
	mPlayerWeaponMgr = new WeaponManager();
	mMonsterWeaponMgr = new WeaponManager();
	mParticleMgr = new ParticleManager();
	//mAudioMgr = new AudioManager();
	mAIEng = new AIEngine(this);


	loadResource();


}
