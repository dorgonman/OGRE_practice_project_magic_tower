#include "Stage.h"
#include "GameEngine.h"



void StageExtra::setupFaders(){


	{	
		String overlayName;
		int index = 0;
		genNameUsingIndex("overlay", index, overlayName);
		FADER *fader = new FADER(overlayName, "Overlay/GameIntro", "my_game/intro");
		mFaderMap["intro"] = fader;
		mCurFader = mFaderMap["intro"];
	}

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
		FADER *fader = new FADER(overlayName, "Overlay/GameWin", "my_game/game_win");
		mFaderMap["game_win"] = fader;
	}

}