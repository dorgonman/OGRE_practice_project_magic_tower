#include "Stage.h"
#include "GameEngine.h"

void Stage::showInformation(){

	gScreenText.setColour(Ogre::ColourValue(1, 0, 0, 1));
	gScreenText.print(0.8, 0, L"score:%.0f", mEngine->mTotalScore);
	gScreenText.print(0.8, 0.05, L"time:%.2f", mTime);
	
	switch(mWeaponMode){
		case NWAY3:
			//gScreenText.print(0, 0, L"current weapon mode:nway3");
		break;
		case TRACE:
			//gScreenText.print(0, 0, L"current weapon mode:trace");
		break;
	}

	gScreenText.print(0, 0, L"玩家:");
	mPlayerHPBar2D->setDefaultPos(0.05, 0);
	mPlayerHPBar2D->setSplit2Parts(true);
	mPlayerHPBar2D->setInfo(mPlayerSpr->mHealth, mPlayerSpr->mInitHealth);
	mPlayerHPBar2D->update(0, 0);
	gScreenText.setColour(ColourValue(1, 0, 0, 1));
	gScreenText.print(0.07, 0, L"%d/%d", (int)mPlayerSpr->mHealth, (int)mPlayerSpr->mInitHealth);

	gScreenText.print(0, 0.05, L"塔:");
	mTowerHPBar2D->setDefaultPos(0.05, 0.05);
	mTowerHPBar2D->setSplit2Parts(true);
	mTowerHPBar2D->setInfo(mTowerSpr->mHealth, mTowerSpr->mInitHealth);
	mTowerHPBar2D->update(0, 0);
	gScreenText.print(0.07, 0.05, L"%d/%d", (int)mTowerSpr->mHealth, (int)mTowerSpr->mInitHealth);
	


}

bool Stage::doBattleScript(){
	mTime += 0.01;//不能用evt來累加，因為這樣做的話，一開始就會是7秒多(因為讀取資源的時間，讓frame之間有很大的gap)
	//更新player
	if(mPlayerSpr){
		mPlayerSpr->update(evt);
		Ogre::Vector3 direction = mSceneMgr->getCamera("playerCam")->getRealDirection();
		direction.y = 0;
		switch(mViewMode){
			case VM_TPS:
				{
				Ogre::Viewport* vp = mEngine->mWindow->getViewport(0);
				mPlayerSpr->setVisibilityFlags(vp->getVisibilityMask());
		
				mPlayerSpr->updateViewDirection(mSceneMgr->getCamera("playerCam"), direction, mViewOffset, Radian(3.14159 * -1));
				}
			break;
			case VM_FPS:
				{
				Ogre::Viewport* vp = mEngine->mWindow->getViewport(0);
				mPlayerSpr->setVisibilityFlags(!vp->getVisibilityMask());
				mPlayerSpr->updateViewDirection(mSceneMgr->getCamera("playerCam"), direction, Ogre::Vector3(0, 0, 0), Radian(3.14159 * -0.5));
				}
			break;
			default:
				mPlayerSpr->updateViewDirection(mSceneMgr->getCamera("playerCam"), direction, Ogre::Vector3(0, 0, 0), Radian(3.14159 * -0.5));
				break;

		}



		switch(mWeaponMode){
			case NWAY3:
				mWeaponPicture->setMaterialName("mat/nway_icon");
			break;
			case TRACE:
				mWeaponPicture->setMaterialName("mat/trace_icon");
			break;
		}

		mPlayerWeaponMgr->update(evt);
		mMonsterMgr->update(evt);
		Ogre::Vector3 targetPosition = mPlayerSpr->getPosition();//mPlayerSpr->getPosition();
		mMonsterMgr->updateViewDirection(targetPosition);
		mMonsterWeaponMgr->update(evt);
		mParticleMgr->update(evt);
		
	

		gameRule();
		showInformation();
		
		
	
	}


	return true;
}
