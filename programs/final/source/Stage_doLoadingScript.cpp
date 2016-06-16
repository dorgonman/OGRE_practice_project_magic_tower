#include "Stage.h"
#include "GameEngine.h"


bool Stage::doLoadingScript(){
	cout << "Start stage loading" << endl;
	Stage::doFinishScript();//�b�}�l���d���e�A���T�O�����d�w�M�����b

	chooseScene();
	
	createCamera();

	createViewPort();

	createScene();
	mScriptMode = SM_BATTLE;
	mEngine->mTrayMgr->hideTrays();
	this->mTime = 0;
	//gScreenText.print(L"test print");//�n��print�@���~�|���J
	mTowerSpr->walk(Ogre::Vector3(0,0,0));//���ը��@�U�A����l��l�]�m�n
	mPlayerSpr->walkForward(evt);//���ը��@�U�A����l��l�]�m�n
	mEngine->mFaderMap["game_over"]->hide();
	return true;
}