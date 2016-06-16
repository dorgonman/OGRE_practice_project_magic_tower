#include "Stage.h"
#include "GameEngine.h"


bool Stage::keyPressed( const OIS::KeyEvent &arg ){
	
	if (arg.key == OIS::KC_ESCAPE){
		return false;

	}
	if (arg.key == OIS::KC_F1){
		mScriptMode = SM_FINISH;
	
	}
	if (arg.key == OIS::KC_F2){
		mViewMode = VM_FPS;
	}
	if (arg.key == OIS::KC_F3){
		mViewMode = VM_TPS;
	}

	if (arg.key == OIS::KC_LSHIFT){
		//mViewMode = VM_TPS;
		mWeaponMode = (mWeaponMode + 1) % 2;
	}


	if(arg.key == OIS::KC_1){
		mEngine->mAudioMgr->play("trace");
	}

	if(arg.key == OIS::KC_2){
		mEngine->mAudioMgr->play("nway");
	}

	if(arg.key == OIS::KC_3){
		mEngine->mAudioMgr->play("monster_shoot1");
	}

	if(arg.key == OIS::KC_4){
		mEngine->mAudioMgr->play("piko");
	}

	if(arg.key == OIS::KC_5){
		mEngine->mAudioMgr->play("monster_hitted");
	}


	if(mScriptMode == SM_BATTLE && !mGameOver){
		if(mPlayerSpr != NULL){
			if(arg.key == OIS::KC_W || arg.key == OIS::KC_S ||
				arg.key == OIS::KC_A || arg.key == OIS::KC_D ||
				arg.key == OIS::KC_UP || arg.key == OIS::KC_DOWN || 
				arg.key == OIS::KC_LEFT || arg.key == OIS::KC_RIGHT)
			{
				mPlayerSpr->disableAllAnimation();

			}

			//跳躍
			if(arg.key == OIS::KC_SPACE)
			{
					mPlayerSpr->disableAllAnimation();
					mPlayerSpr->jump(200);
					mPlayerSpr->setAnimation("Jump", false);
			}
		}
	}

	//cout << arg.key << endl;
	if(mScriptMode == SM_STORY){
		if(arg.key == KC_LENTER){
			mTime += 1;
		}
	}



	if(mScriptMode == SM_GAME_OVER){
		if(arg.key == KC_LENTER || arg.key == OIS::KC_F12){
			mScriptMode = SM_LOADING;
			mEngine->mFaderMap["game_over"]->hide();
		}
	}

	if(mScriptMode == SM_GAME_WIN){
		if(arg.key == KC_LENTER){
			mScriptMode = SM_FINISH;
		}

	}

	return true;
}


bool Stage::keyReleased( const OIS::KeyEvent &arg ){

	if( mScriptMode == SM_BATTLE){
		if(mPlayerSpr != NULL){
			if(arg.key == OIS::KC_W || arg.key == OIS::KC_S ||
				arg.key == OIS::KC_A || arg.key == OIS::KC_D)
				{
					mPlayerSpr->disableAllAnimation();
					mPlayerSpr->setAnimation("Idle1", true);
			}
		}
	}
	return true;
}

//按著不放
bool Stage::keyDown(){


	mEngine->mKeyboard->capture();
	if(mScriptMode == SM_BATTLE){
		if(mPlayerSpr != NULL){
			Ogre::Vector3 pos = mPlayerSpr->getPosition();
	   
			//不要走出terrain
			if(pos.x < 50){
				mPlayerSpr->setPosition(Ogre::Vector3(50, pos.y, pos.z));
			}

			 
			if(pos.x > 4950){
				mPlayerSpr->setPosition(Ogre::Vector3(4950, pos.y, pos.z));
			}

			if(pos.z < 50){
				mPlayerSpr->setPosition(Ogre::Vector3(pos.x, pos.y, 50));
			}

			 
			if(pos.z > 4950){
				mPlayerSpr->setPosition(Ogre::Vector3(pos.x, pos.y, 4950));
			}

			if(mEngine->mKeyboard->isKeyDown(OIS::KC_W) || mEngine->mKeyboard->isKeyDown(OIS::KC_UP)){
				mPlayerSpr->walkForward(evt);
				mPlayerSpr->setAnimation("Walk", true);
			}

			if(mEngine->mKeyboard->isKeyDown(OIS::KC_S) || mEngine->mKeyboard->isKeyDown(OIS::KC_DOWN)){
				mPlayerSpr->walkBackward(evt);
				mPlayerSpr->setAnimation("Idle2", true);
				mPlayerSpr->setAnimation("Walk", true);
			}

			if(mEngine->mKeyboard->isKeyDown(OIS::KC_A) || mEngine->mKeyboard->isKeyDown(OIS::KC_LEFT)){
				mPlayerSpr->walkLeft(evt);
				mPlayerSpr->setAnimation("Idle3", true);
				 mPlayerSpr->setAnimation("Walk", true);
			}

			if(mEngine->mKeyboard->isKeyDown(OIS::KC_D) || mEngine->mKeyboard->isKeyDown(OIS::KC_RIGHT)){
				mPlayerSpr->walkRight(evt);
				mPlayerSpr->setAnimation("Idle1", true);
				mPlayerSpr->setAnimation("Walk", true);
			}

			
		}
	}
/*	Ogre::Camera* cam = mSceneMgr->getCamera("playerCam1");
	if(mEngine->mKeyboard->isKeyDown(OIS::KC_X)){
		if(cam->getPosition().y <= 1300){
			cam->setPosition(cam->getPosition() + Ogre::Vector3(0, 5, 0));
		}
	}

	if(mEngine->mKeyboard->isKeyDown(OIS::KC_Z)){
		if(cam->getPosition().y >= 400){
			cam->setPosition(cam->getPosition() - Ogre::Vector3(0, 5, 0));
		}
	}*/
	return true;
}
bool Stage::mouseMoved( const OIS::MouseEvent &arg ){
	return true;
}


bool Stage::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){

	if(mScriptMode == SM_BATTLE){
		if(mPlayerSpr != NULL){
			if(id == OIS::MB_Left){
				Ogre::Vector3 direction = mSceneMgr->getCamera("playerCam")->getRealDirection();
				if(mPlayerWeaponMgr){
					switch(mWeaponMode){
						case NWAY3:
							{

								Weapon3D* weapon = mPlayerWeaponMgr->getWeapon("nway");
								mEngine->mAudioMgr->play("nway");
								if(weapon->mLevel == 0){
									for(int i = -1; i < 2; i++){
										//=============1==================
										Ogre::Vector3 dir = rotateY(direction, i * 0.1);
										weapon->setInitDirection(dir);
										weapon->trigger(mPlayerSpr->getPosition() + Ogre::Vector3(0, 80, 0));	
									}
								}

							}
						break;
						case TRACE:
						{
							mEngine->mAudioMgr->play("trace");
							Weapon3D* weapon = mPlayerWeaponMgr->getWeapon("trace");
							if(weapon->mLevel == 0){
								weapon->setInitDirection(direction);
								weapon->trigger(mPlayerSpr->getPosition() + Ogre::Vector3(0, 80, 0));	
							}
						}
							break;
					}
				}
			}
		}
	}



	if(mScriptMode == SM_STORY){
		if(id == OIS::MB_Left){
			mTime += 1;
		}
	}
	return true;
}

bool Stage::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){
	
	return true;
}



