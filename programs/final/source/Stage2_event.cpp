
#include "Stage.h"
#include "GameEngine.h"


void Stage2::environment(){

	{
		Ogre::Vector3 position = mTowerSpr->getPosition();
		mParticleMgr->trigger("magic", position);
		//snow
		position =  mPlayerSpr->getPosition();
		mParticleMgr->trigger("snow", position);

		///flame + smoke
		position =  Ogre::Vector3(1500, 0, 1500); 
		mParticleMgr->trigger("flame", position);
		mParticleMgr->trigger("smoke", position);

		//space
		position =  mPlayerSpr->getPosition(); 
		mParticleMgr->trigger("space", position);
	}

}





//===================robot==========================


void Stage2::setEvent1(){

	for(int i = 0; i < 10; i++){
		String name;
		genNameUsingIndex("robot", i, name);
		Sprite3D* p = mMonsterMgr->getSprite(name);
		if(p){
			Ogre::Vector3 org(1750 + (float)i * 50, 40, 1750 + (float)i * 50);
			p->setInitPosition(org);
			p->setInitVelocity(Ogre::Vector3(100, 100, 100));
			p->setInitHealth(20);
			p->walk(Ogre::Vector3(0, 0, 0));
			p->setAlive(true);
			cout << "set Event 1" << endl;
		}
	}


	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun1");
	if(weapon){
		weapon->setInitVelocity(Ogre::Vector3(500, 500, 500));
		weapon->setBulletLifeTime(5);
		weapon->setCoolDown(1);
	}
	//weapon->setBulletMaterialName("my_game/bullet1");

}


void Stage2::doEvent1(){
	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun1");

	if(weapon){
		if(weapon->mTime >= weapon->mCoolDown){
			for(int i = 0; i < 10; i++){
				String name;
				//genNameUsingIndex("ogrehead", i, name);
				genNameUsingIndex("robot", i, name);
				Sprite3D* p = mMonsterMgr->getSprite(name);
				if(p->isAlive()){
					Ogre::Vector3 monsterPosition =  mMonsterMgr->getPosition(name);
					Ogre::Vector3 playerPosition = mPlayerSpr->getPosition();
					playerPosition.y = 0;
					monsterPosition.y = 0;
					float length = playerPosition.distance(monsterPosition);
					Ogre::Vector3 direction =  mPlayerSpr->getPosition() - mMonsterMgr->getPosition(name);
					direction.normalise();
					if(length < 700){
							weapon->setInitDirection(direction);
							weapon->trigger(mMonsterMgr->getPosition(name));
							mEngine->mAudioMgr->play("monster_tama2");
							p->setAnimation("Idle");
							
					}else{
						mAIEng->runTo(p, mPlayerSpr->getPosition());
			
						p->setAnimation("Walk");

					}
				}
			}
		}
	}
	
}




//=============================fish===========================================



void Stage2::setEvent2(){


	for(int i = 0; i < 3; i++){
		String name;
		genNameUsingIndex("fish", i, name);
		Sprite3D* p = mMonsterMgr->getSprite(name);
		if(p){
			Ogre::Vector3 org(2750 + (float)i * 50, 40, 2750 + (float)i * 50);
			p->setInitPosition(org);
			p->setInitVelocity(Ogre::Vector3(100, 100, 100));
			p->setInitHealth(20);
			p->walk(Ogre::Vector3(0, 0, 0));
			p->setAlive(true);
		}
	}


	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun2");
	if(weapon){
		weapon->setInitVelocity(Ogre::Vector3(500, 500, 500));
		weapon->setBulletLifeTime(5);
		weapon->setCoolDown(1);
	}
}


void Stage2::doEvent2(){

	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun2");
	if(weapon){
		if(weapon->mTime >= weapon->mCoolDown){
			for(int i = 0; i < 3; i++){
				String name;
				//genNameUsingIndex("ogrehead", i, name);
				genNameUsingIndex("fish", i, name);
				Sprite3D* p = mMonsterMgr->getSprite(name);
				if(p->isAlive()){
					Ogre::Vector3 monsterPosition =  mMonsterMgr->getPosition(name);
					Ogre::Vector3 playerPosition = mPlayerSpr->getPosition();
					float length = playerPosition.distance(monsterPosition);
					Ogre::Vector3 direction =  mPlayerSpr->getPosition() - mMonsterMgr->getPosition(name);
					direction.normalise();
					if(length < 1000){
						for(int i = 0; i < 2; i++){
							//int r = rand_number(0, 1000);
							Ogre::Vector3 dir = rotateY(direction, i * 0.01);
							weapon->setInitDirection(dir);
							weapon->trigger(p->getPosition());	
						}
					}else{
						mAIEng->runTo(p, mPlayerSpr->getPosition());

					}

				}
			}
		}

	}
}


//=====================penguin===============================
void Stage2::setEvent3(){

	for(int i = 0; i < 1; i++){
		String name;
		genNameUsingIndex("penguin", i, name);
		Sprite3D* p = mMonsterMgr->getSprite(name);
		if(p){
			Ogre::Vector3 org(3750 + (float)i * 50, 40, 3750 + (float)i * 50);
			p->setInitPosition(org);
			p->setInitVelocity(Ogre::Vector3(600, 600, 600));
			p->setInitHealth(100);
			p->walk(Ogre::Vector3(0, 0, 0));
			p->setAlive(true);
		}
	}


	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun3");
	if(weapon){
		weapon->setInitVelocity(Ogre::Vector3(500, 500, 500));
		weapon->setBulletLifeTime(5);
		weapon->setCoolDown(0.01);
	}

}


void Stage2::doEvent3(){


	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun3");

	if(weapon){
		if(weapon->mTime >= weapon->mCoolDown){
			for(int i = 0; i <1; i++){
				String name;
				genNameUsingIndex("penguin", i, name);
				Sprite3D* p = mMonsterMgr->getSprite(name);
				if(p->isAlive()){
					Ogre::Vector3 monsterPosition =  mMonsterMgr->getPosition(name);
					Ogre::Vector3 playerPosition = mPlayerSpr->getPosition();
					float length = playerPosition.distance(monsterPosition);
					Ogre::Vector3 direction =  mPlayerSpr->getPosition() - mMonsterMgr->getPosition(name);
					direction.normalise();
					if(length < 1000){
						weapon->setInitDirection(direction);
						weapon->trigger(p->getPosition());	
					}else{
						mAIEng->runTo(p, mPlayerSpr->getPosition());

					}
					//跳躍
					if(mPlayerSpr->getPosition().y > 50){
						if(p->mJumpForce <= 0 && p->mJumpTimePassed > 2){
							p->jump(1500);
						}
					}

				}
			}
		}

	}

	
}


//===================ogrehead attack tower=====================
void Stage2::setEvent4(){

	for(int i = 0; i < 5; i++){
		String name;
		genNameUsingIndex("ogrehead", i, name);
		Sprite3D* p = mMonsterMgr->getSprite(name);
		if(p){
			Ogre::Vector3 org(3750 + (float)i * 50, 100, 3750 + (float)i * 50);
			p->setInitPosition(org);
			p->setInitVelocity(Ogre::Vector3(200, 200, 200));
			p->setInitHealth(20);
			p->walk(Ogre::Vector3(0, 0, 0));
			p->setAlive(true);
		}
	}


	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun4");
	if(weapon){
		weapon->setInitVelocity(Ogre::Vector3(500, 500, 500));
		weapon->setBulletLifeTime(5);
		weapon->setCoolDown(0.5);
	}

}


void Stage2::doEvent4(){

	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun4");

	if(weapon){
	//	if(weapon->mTime >= weapon->mCoolDown){
			for(int i = 0; i < 5; i++){
				String name;
				genNameUsingIndex("ogrehead", i, name);
				Sprite3D* p = mMonsterMgr->getSprite(name);
				if(p->isAlive()){
					Ogre::Vector3 monsterPosition =  mMonsterMgr->getPosition(name);
					Ogre::Vector3 playerPosition = mPlayerSpr->getPosition();
					float length = playerPosition.distance(monsterPosition);
					Ogre::Vector3 direction =  mPlayerSpr->getPosition() - mMonsterMgr->getPosition(name);
					direction.normalise();
					if(length < 2000){
						weapon->setInitDirection(direction);
						weapon->trigger(p->getPosition());	
					}
					mAIEng->runTo(p, mTowerSpr->getPosition());
				}
			}
		//}

	}

	
}

//====================penguin2====================
void Stage2::setEvent5(){

	
	for(int i = 1; i < 2; i++){
		String name;
		genNameUsingIndex("penguin", i, name);
		Sprite3D* p = mMonsterMgr->getSprite(name);
		if(p){
			Ogre::Vector3 org(1750 + (float)i * 50, 40, 1750 + (float)i * 50);
			p->setInitPosition(org);
			p->setInitVelocity(Ogre::Vector3(600, 600, 600));
			p->setInitHealth(1000);
			p->walk(Ogre::Vector3(0, 0, 0));
			p->setAlive(true);
		}
	}


	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun5");
	if(weapon){
		weapon->setInitVelocity(Ogre::Vector3(500, 500, 500));
		weapon->setBulletLifeTime(5);
		weapon->setCoolDown(0.01);
	}

}


void Stage2::doEvent5(){

	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun5");

	if(weapon){
		if(weapon->mTime >= weapon->mCoolDown){
			for(int i = 1; i < 2; i++){
				String name;
				genNameUsingIndex("penguin", i, name);
				Sprite3D* p = mMonsterMgr->getSprite(name);
				if(p->isAlive()){
					Ogre::Vector3 monsterPosition =  mMonsterMgr->getPosition(name);
					Ogre::Vector3 playerPosition = mPlayerSpr->getPosition();
					float length = playerPosition.distance(monsterPosition);
					Ogre::Vector3 direction =  mPlayerSpr->getPosition() - mMonsterMgr->getPosition(name);
					direction.normalise();
					if(length < 1000){
						weapon->setInitDirection(direction);
						weapon->trigger(p->getPosition());	
					}else{
						mAIEng->runTo(p, mPlayerSpr->getPosition());

					}
					//跳躍
					if(mPlayerSpr->getPosition().y > 50){
						if(p->mJumpForce <= 0 && p->mJumpTimePassed > 2){
							p->jump(1500);
						}
					}

				}
			}
		}

	}



	
}



//====================ogrehead2 attack tower=========================


void Stage2::setEvent6(){

	for(int i = 5; i < 10; i++){
		String name;
		genNameUsingIndex("ogrehead", i, name);
		Sprite3D* p = mMonsterMgr->getSprite(name);
		if(p){
			Ogre::Vector3 org(3750 + (float)i * 50, 100, 3750 + (float)i * 50);
			p->setInitPosition(org);
			p->setInitVelocity(Ogre::Vector3(200, 200, 200));
			p->setInitHealth(20);
			p->walk(Ogre::Vector3(0, 0, 0));
			p->setAlive(true);
		}
	}


	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun3");
	if(weapon){
		weapon->setInitVelocity(Ogre::Vector3(500, 500, 500));
		weapon->setBulletLifeTime(5);
		weapon->setCoolDown(0.5);
	}

}




void Stage2::doEvent6(){
	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun3");

	if(weapon){
		//if(weapon->mTime >= weapon->mCoolDown){
			for(int i = 5; i < 10; i++){
				String name;
				genNameUsingIndex("ogrehead", i, name);
				Sprite3D* p = mMonsterMgr->getSprite(name);
				if(p->isAlive()){
					Ogre::Vector3 monsterPosition =  mMonsterMgr->getPosition(name);
					Ogre::Vector3 playerPosition = mPlayerSpr->getPosition();
					float length = playerPosition.distance(monsterPosition);
					Ogre::Vector3 direction =  mPlayerSpr->getPosition() - mMonsterMgr->getPosition(name);
					direction.normalise();
					if(length < 2000){
						weapon->setInitDirection(direction);
						weapon->trigger(p->getPosition());	
					}
					mAIEng->runTo(p, mTowerSpr->getPosition());
				}
			}
		//}

	}

}



//======================================



//=============================fish===========================================



void Stage2::setEvent7(){


	for(int i = 3; i < 8; i++){
		String name;
		genNameUsingIndex("fish", i, name);
		Sprite3D* p = mMonsterMgr->getSprite(name);
		if(p){
			Ogre::Vector3 org(2750 + (float)i * 50, 40, 2750 + (float)i * 50);
			p->setInitPosition(org);
			p->setInitVelocity(Ogre::Vector3(100, 100, 100));
			p->setInitHealth(20);
			p->walk(Ogre::Vector3(0, 0, 0));
			p->setAlive(true);
		}
	}


	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun7");
	if(weapon){
		weapon->setInitVelocity(Ogre::Vector3(500, 500, 500));
		weapon->setBulletLifeTime(5);
		weapon->setCoolDown(1);
	}
}


void Stage2::doEvent7(){

	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun7");
	if(weapon){
		if(weapon->mTime >= weapon->mCoolDown){
			for(int i = 3; i < 8; i++){
				String name;
				//genNameUsingIndex("ogrehead", i, name);
				genNameUsingIndex("fish", i, name);
				Sprite3D* p = mMonsterMgr->getSprite(name);
				if(p->isAlive()){
					Ogre::Vector3 monsterPosition =  mMonsterMgr->getPosition(name);
					Ogre::Vector3 playerPosition = mPlayerSpr->getPosition();
					float length = playerPosition.distance(monsterPosition);
					Ogre::Vector3 direction =  mPlayerSpr->getPosition() - mMonsterMgr->getPosition(name);
					direction.normalise();
					if(length < 1000){
						for(int i = 0; i < 5; i++){
							//int r = rand_number(0, 1000);
							Ogre::Vector3 dir = rotateY(direction, i * 0.01);
							weapon->setInitDirection(dir);
							weapon->trigger(p->getPosition());	
						}
					}else{
						mAIEng->runTo(p, mPlayerSpr->getPosition());

					}

				}
			}
		}

	}
}



//================boss======================

void Stage2::setEvent8(){	
	Sprite3D* p = mMonsterMgr->getSprite("boss2");
	if(p){
		Ogre::Vector3 org(1750, 1400, 1750);
		p->setInitPosition(org);
		p->setInitVelocity(Ogre::Vector3(400, 400, 400));
		p->setInitHealth(100);
		p->setScale(Ogre::Vector3(10, 10, 10));
		p->walk(Ogre::Vector3(0, 0, 0));
		p->setAlive(true);
	}


	for(int i = 0; i < 5; i++){
		String guns;
		genNameUsingIndex("gun", i, guns);
		Weapon3D* weapon = mMonsterWeaponMgr->getWeapon(guns);
		if(weapon){
			weapon->setInitVelocity(Ogre::Vector3(200, 200, 200));
			weapon->setBulletLifeTime(20);
			weapon->setCoolDown(1);
		}
	}
	for(int i = 5; i < 10; i++){
		String guns;
		genNameUsingIndex("gun", i, guns);
		Weapon3D* weapon = mMonsterWeaponMgr->getWeapon(guns);
		if(weapon){
			weapon->setInitVelocity(Ogre::Vector3(500, 500, 500));
			weapon->setBulletLifeTime(5);
			weapon->setCoolDown(0.1);
		}
	}
}


void Stage2::doEvent8(){

	Weapon3D* weapon = mMonsterWeaponMgr->getWeapon("gun6");
	if(weapon){
			Sprite3D* p = mMonsterMgr->getSprite("boss2");
			if(p->isAlive()){
				Ogre::Vector3 monsterPosition =  p->getPosition();
				Ogre::Vector3 playerPosition = mPlayerSpr->getPosition();
				float length = playerPosition.distance(monsterPosition);
				Ogre::Vector3 direction =  mPlayerSpr->getPosition() - p->getPosition();
				direction.normalise();
				if(((int)mTime % 5 == 0)){
					for(int i = 9; i < 10; i++){
						String guns;
						genNameUsingIndex("gun", i, guns);
						Weapon3D* weapon = mMonsterWeaponMgr->getWeapon(guns);
						if(weapon){
							weapon->setInitDirection(direction);
							mMonsterWeaponMgr->setAllBulletDirectPosition(weapon, mPlayerSpr->getPosition());
						}
					}
					
				}else{
					for(int i = 9; i < 10; i++){
						String guns;
						genNameUsingIndex("gun", i, guns);
						Weapon3D* weapon = mMonsterWeaponMgr->getWeapon(guns);
						if(weapon){
							Ogre::Vector3 dir = rotateY(direction, 0);
							weapon->setInitDirection(dir);
							weapon->trigger(p->getPosition());	
							
						}
					}

				}
				static Ogre::Vector3 targetPosition(mPlayerSpr->getPosition().x, 
					                          mPlayerSpr->getPosition().y, 
											  mPlayerSpr->getPosition().z);
				//改變要去的地點
				if((int)mTime % 10 == 0){
					targetPosition.x = rand_number(0, 5000);
					targetPosition.y = rand_number(0, 1000);
					targetPosition.z = rand_number(0, 5000);
				}
				mAIEng->runTo(p, targetPosition);
		
				//跳躍
				if(mPlayerSpr->getPosition().y > 50){
					if(p->mJumpForce <= 0 && p->mJumpTimePassed > 2){
						p->jump(1500);
					}
				}

			}
	}
}