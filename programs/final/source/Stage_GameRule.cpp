#include "Stage.h"
#include "GameEngine.h"
using namespace Ogre;


void Stage::gameOverRule(){
	//game over
	if(mPlayerSpr){
		if(mPlayerSpr->getHealth() <= 0){
			mScriptMode = SM_GAME_OVER;
			mPlayerSpr->setAnimation("Death1", false);
			//mPlayerSpr->setAlive(false);
			mEngine->mFaderMap["game_over"]->startFadeOut(10, 1, 0);
		}
	}

	if(mTowerSpr){
		if(mTowerSpr->getHealth() <= 0){
			mScriptMode = SM_GAME_OVER;
			mEngine->mFaderMap["game_over"]->startFadeOut(10, 1, 0);
		}
	
	}
}


void Stage::monsterHittedRule(){
	if(mPlayerSpr){
		std::map<string, Sprite3D*> monsters = this->mMonsterMgr->mSpriteMap;
			for(std::map<string, Sprite3D*>::iterator it = monsters.begin(); 
			it!= monsters.end(); it++) {
			Sprite3D* p = it->second;
			//health
			if(p->isAlive()){
				//擊倒一個monster，增加分數
				if(p->getHealth() <= 0){
					p->setAlive(false);
					mEngine->mTotalScore += 40;
				}

				//=====detect and set trace gun's bullet direction============
				Ogre::Vector3 monsterPosition =  p->getPosition();
				Ogre::Vector3 playerPosition = mPlayerSpr->getPosition();
				Ogre::Vector3 toMonsterVector =  monsterPosition - playerPosition;
				toMonsterVector.normalise();
				Ogre::Vector3 playerDirection = mPlayerSpr->mDirection;
				float dotProduct = playerDirection.dotProduct(toMonsterVector);
				//cout << dotProduct << endl;
				//內積大於0，二向量夾角大於90度
				//內積為1則是垂直，大於0.9就代表在玩家視角內
				if(dotProduct > 0.9){
					float distnace = monsterPosition.distance(playerPosition);
					//距離小於1000時才會追蹤
					if(distnace <= 2000){
						Weapon3D* weapon = mPlayerWeaponMgr->getWeapon("trace");
						mPlayerWeaponMgr->setAllBulletDirectPosition(weapon, monsterPosition);
					}
				}
			}



		}
	}

	//是否有打到monster，打到就加分數
	bool isHit = mPlayerWeaponMgr->hit(mMonsterMgr->mSpriteMap);
	if(isHit){
		this->mEngine->mAudioMgr->play("monster_hitted");
		mEngine->mTotalScore += 20;
	}


}

void Stage::towerRelateRule(){

	float towerAT = 2; // AT time
	float RT = 5; //recovery time

	
	//======================塔受攻擊============================
	if(mTowerSpr){
		for(std::map<string, Sprite3D*>::iterator it =
		mMonsterMgr->mSpriteMap.begin(); 
		it != mMonsterMgr->mSpriteMap.end(); it++) {
			Sprite3D* p = it->second;
			if(p->isAlive()){
				Ogre::Vector3 pos1 = p->getPosition();
				pos1.y = 0;
				Ogre::Vector3 pos2 = mTowerSpr->getPosition();
				pos2.y = 0;
				float distance = pos1.distance(pos2);
				//距離小於100則受攻擊
				if(distance < 100){
					gScreenText.setColour(ColourValue(1, 0, 0, 1));
					gScreenText.print(0.5, 0.05, L"魔塔遭受攻擊中");
					p->mTowerTime += evt.timeSinceLastFrame;
				}
				if(p->mTowerTime >= towerAT ){
					//p->setAlive(false);
					p->decreaseHealth(100);
					mEngine->mAudioMgr->play("tower_attacked");
					mTowerSpr->decreaseHealth(10);
					p->mTowerTime = 0;
				}
			}
		}
	
	}

	//============玩家補血=========================

	{
		Ogre::Vector3 playerPosition = mPlayerSpr->getPosition();
		playerPosition.y = 0;
		Ogre::Vector3 towerPosition = mTowerSpr->getPosition();
		towerPosition.y = 0;
		float distance = playerPosition.distance(towerPosition);
		if(distance < 100){
			mPlayerSpr->mTowerTime += evt.timeSinceLastFrame;
			gScreenText.setColour(ColourValue(0, 1, 0, 1));
			gScreenText.print(0.5, 0.1, L"healing");
		}

		if(mPlayerSpr->mTowerTime >= RT){
			mEngine->mAudioMgr->play("recover");
			mPlayerSpr->mTowerTime = 0;
			mPlayerSpr->increaseHealth(10);
			mTowerSpr->increaseHealth(10);
		}
	
	}



}


void Stage::playerHittedRule(){
	float playerAT = 2;
	float radius = mPlayerSpr->getSceneNode()->getAttachedObject(0)->getBoundingRadius() / 2;
	if(mMonsterWeaponMgr->hit(mPlayerSpr, radius)){
		if(mPlayerSpr->ATTime <= 0){
			mPlayerSpr->ATTime = playerAT;
		}
	}
}



void Stage::gameRule(){
	monsterHittedRule();
	playerHittedRule();
	towerRelateRule();
	gameOverRule();
}