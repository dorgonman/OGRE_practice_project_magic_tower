#include "GameEngine.h"
#include "Stage.h"

using namespace Ogre;

bool StageExtra::keyPressed( const OIS::KeyEvent &arg ){


		/*Entity* ent = sceneMgr->getEntity("RobotEntity");
		SceneNode* sNode = sceneMgr->getSceneNode("RobotNode");
		*/
	if (arg.key == OIS::KC_F1){
		mScriptMode = SM_FINISH;
	}

	if (arg.key == OIS::KC_ESCAPE){
		return false;
	}

	if(!mGameWin){
		if(mCurrentObject != NULL){
			if(!mGameOver){
				if(mCurrentObject != NULL){
					if(arg.key == OIS::KC_W || arg.key == OIS::KC_S ||
						arg.key == OIS::KC_A || arg.key == OIS::KC_D){
						mCurrentObject->setAnimation("Walk", true);
					}
				}
				if(arg.key == OIS::KC_SPACE){
					mCurrentObject->jump(100);
				}
			}else{
				if(arg.key == OIS::KC_SPACE){
					//先設die的目的是要讓robot的die動畫frame歸0，然站起來的狀態
					mCurrentObject->setAnimation("Die", false);
					mCurrentObject->setAnimation("Idle", true);
					//把alpha變成0
					mCurFader->startFadeIn(0.1, 0, 1);
					mCurFader->fade(0.1);
					//mCurFader = mFaderMap["intro"];
					mCurrentObject->setAlive(true);
					mGameOver = false;
				}
			}
		}
	}
		
	
	return true;
}

bool StageExtra::keyReleased( const OIS::KeyEvent &arg ){
	if(!mGameOver){
		if( mScriptMode == SM_BATTLE){
			if(mCurrentObject != NULL){
				mCurrentObject->setAnimation("Idle", true);
			}
		}

		if(arg.key == OIS::KC_X){
			mZoomIn = true;
			mZoomOut = false;
			mZoomTime = 0;
		}

		if(arg.key == OIS::KC_Z){
			mZoomIn = false;
			mZoomOut = true;
			mZoomTime = 0;
		}
	}


	return true;
}

//按著不放
bool StageExtra::keyDown(){

	//if( mScriptMode == SM_BATTLE){
	if(!mGameWin){
		if(!mGameOver){
			mEngine->mKeyboard->capture();
			if(mCurrentObject != NULL){
				if(mEngine->mKeyboard->isKeyDown(OIS::KC_W)){
					mCurrentObject->walkForward(evt);
				
				}

				if(mEngine->mKeyboard->isKeyDown(OIS::KC_S)){
					mCurrentObject->walkBackward(evt);
				}

				if(mEngine->mKeyboard->isKeyDown(OIS::KC_A)){
					mCurrentObject->walkLeft(evt);
				}

				if(mEngine->mKeyboard->isKeyDown(OIS::KC_D)){
					mCurrentObject->walkRight(evt);
				}
				
			}
			Ogre::Camera* cam = mSceneMgr->getCamera("playerCam1");
			if(mEngine->mKeyboard->isKeyDown(OIS::KC_X)){
				if(cam->getPosition().y <= 1300){
					cam->setPosition(cam->getPosition() + Ogre::Vector3(0, 5, 0));
				}
			}

			if(mEngine->mKeyboard->isKeyDown(OIS::KC_Z)){
				if(cam->getPosition().y >= 400){
					cam->setPosition(cam->getPosition() - Ogre::Vector3(0, 5, 0));
				}
			}
		}
	}
//	}

	return true;
}
bool StageExtra::mouseMoved( const OIS::MouseEvent &arg ){
	if(!mGameOver){
		if(mCurrentObject){
			//mCurrentObject->updateViewDirection();
		}
	}

	return true;
}


bool StageExtra::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){

	if(mCurrentObject != NULL){
		if(!mGameOver){
			if(id == OIS::MB_Left){
				//mCurrentObject->fireWeapon();
			}
		}
	}

	return true;
}

bool StageExtra::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){
	return true;
}



