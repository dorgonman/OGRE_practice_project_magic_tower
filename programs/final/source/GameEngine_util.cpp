#include "GameEngine.h"
#include "Stage.h"

GameEngine::~GameEngine(){
	//if(mAudioMgr){
	//	delete mAudioMgr;
		//mAudioMgr = NULL;
	//}

}



void GameEngine::loadSound(){
	mAudioMgr = new AudioManager();
	mAudioMgr->addSound("monster_tama1", ".\\sounds\\tama1.wav");
	mAudioMgr->addSound("monster_tama2", ".\\sounds\\tama2.wav");
	mAudioMgr->addSound("piko", ".\\sounds\\piko1.wav");
	mAudioMgr->addSound("monster_hitted", ".\\sounds\\reflect.wav");
	mAudioMgr->addSound("trace", ".\\sounds\\se_sub03.wav");
	mAudioMgr->addSound("nway", ".\\sounds\\tama2.wav");
	mAudioMgr->addSound("monster_die", ".\\sounds\\se_mod05.wav");
	mAudioMgr->addSound("player_hitted", ".\\sounds\\pattern04.wav");
	mAudioMgr->addSound("recover", ".\\sounds\\status1.wav");
	mAudioMgr->addSound("tower_attacked", ".\\sounds\\se02.wav");

}


void GameEngine::loadOverlay(){
	{
		String overlayName;
		int index = 1;
		genNameUsingIndex("overlay", index, overlayName); ++index;
		FADER *fader = new FADER(overlayName, "Overlay/GameOver", "my_game/game_over");
		mFaderMap["game_over"] = fader;
	}


	{
		String overlayName;
		int index = 2;
		genNameUsingIndex("overlay", index, overlayName); ++index;
		FADER *fader = new FADER(overlayName, "Overlay/Stage1Win", "my_game/stage1_win");
		mFaderMap["stage1_win"] = fader;
	}


	{
		String overlayName;
		int index = 3;
		genNameUsingIndex("overlay", index, overlayName); ++index;
		FADER *fader = new FADER(overlayName, "Overlay/Stage2Win", "my_game/stage2_win");
		mFaderMap["stage2_win"] = fader;
	}

	
	{
		String overlayName;
		int index = 4;
		genNameUsingIndex("overlay", index, overlayName); ++index;
		FADER *fader = new FADER(overlayName, "Overlay/Stage3Win", "my_game/stage3_win");
		mFaderMap["stage3_win"] = fader;
	}
}
//default initialize
void GameEngine::createScene(void) {
	//mWindow->resize(500, 500);
	//mWindow->getViewport(0)->setOverlaysEnabled(false);
//	gScreenText.init("StarWars");
	//gScreenText.init("SimHei");

	gScreenText.init("SimHei");
	loadSound();
	loadOverlay();
	srand(time(0));
	//GUI
	setupButtons();
}

bool GameEngine::frameStarted(const Ogre::FrameEvent &evt){
	gScreenText.frameStarted();
	return currentStage->doScript(evt);
}




//input相關全depatch給stage去做
bool GameEngine::keyPressed( const OIS::KeyEvent &arg ){
	if(mDefaultInputEnable){
		BaseApplication::keyPressed(arg);
	}
	mButtonMgr->injectKeyPressed(arg);
	return currentStage->keyPressed(arg);
}


bool GameEngine::keyReleased( const OIS::KeyEvent &arg ){
	if(mDefaultInputEnable){
		BaseApplication::keyReleased(arg);
	}

	mButtonMgr->injectKeyReleased(arg);
	return currentStage->keyReleased(arg);
}
bool GameEngine::mouseMoved( const OIS::MouseEvent &arg ){
	if(mDefaultInputEnable){
		BaseApplication::mouseMoved(arg);
	}

	mButtonMgr->injectMouseMove(arg.state.X.abs, arg.state.Y.abs);
	return currentStage->mouseMoved(arg);
}


bool GameEngine::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){
	if(mDefaultInputEnable){
		BaseApplication::mousePressed(arg, id);
	}
	mButtonMgr->injectMouseDown(id);
	return currentStage->mousePressed(arg, id);
}

bool GameEngine::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){
	if(mDefaultInputEnable){
		BaseApplication::mouseReleased(arg, id);
	}
	mButtonMgr->injectMouseUp(id);
	return currentStage->mouseReleased(arg, id);
}




