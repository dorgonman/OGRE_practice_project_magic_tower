#include "Stage.h"
#include "GameEngine.h"


bool Stage::doGameOverScript(){

	bool faderRunning = mEngine->mFaderMap["game_over"]->fade(evt.timeSinceLastFrame);


	if(mPlayerSpr){
		mPlayerSpr->update(evt);
	}
	mParticleMgr->update(evt);
	return true;
}