#include "Stage.h"
#include "GameEngine.h"


bool Stage::doLoadingScript(){
	cout << "Start stage loading" << endl;
	Stage::doFinishScript();//在開始關卡之前，先確保該關卡已清除乾淨

	chooseScene();
	
	createCamera();

	createViewPort();

	createScene();
	mScriptMode = SM_BATTLE;
	mEngine->mTrayMgr->hideTrays();
	this->mTime = 0;
	//gScreenText.print(L"test print");//要先print一次才會載入
	mTowerSpr->walk(Ogre::Vector3(0,0,0));//測試走一下，讓初始位子設置好
	mPlayerSpr->walkForward(evt);//測試走一下，讓初始位子設置好
	mEngine->mFaderMap["game_over"]->hide();
	return true;
}