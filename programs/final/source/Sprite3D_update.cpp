#include "Sprite3D.h"
#include "Stage.h"

void Sprite3D::update(const Ogre::FrameEvent& evt){

	if(mAnimationState){
		mAnimationState->addTime(evt.timeSinceLastFrame);
	}

	if(ATTime >= 0){
		ATTime -= evt.timeSinceLastFrame;
	}


	if(!mIsFly){
		Ogre::Vector3 pos = this->mSceneNode->getPosition();
		if(mJumpForce <= 0){
			//如果player是在空中，就往下降落
			bool flgNeg = mStage->projectScenePointOntoTerrain_NegDirection(pos);
			if(flgNeg){
				mJumpTimePassed += evt.timeSinceLastFrame;
				Real t = evt.timeSinceLastFrame;
				Ogre::Vector3 pos = mSceneNode->getPosition() +  (mStage->mGravity * mJumpTimePassed);
				bool flagPos =mStage->projectScenePointOntoTerrain_PosDirection(pos);
				mSceneNode->setPosition(pos);
			}
			if(mJumpTimePassed >= INF){
				mJumpTimePassed = 0;//避免crash
			}
		}else{
			Ogre::Vector3 direction = -mStage->mGravity.normalisedCopy();
			Ogre::Vector3 pos = mSceneNode->getPosition() + mInitJumpForce * direction * evt.timeSinceLastFrame;
			mJumpForce -= mInitJumpForce * evt.timeSinceLastFrame;
			mSceneNode->setPosition(pos);
		}
	}
}




	/*if(dynamic_cast<Penguin*>(this)){
			cout << "penguin jumpForce" << mJumpForce << endl;
			cout << evt.timeSinceLastFrame << endl;
		}*/
		//if(dynamic_cast<Player3D*>(this)){
			//cout << "player jumpForce" << mJumpForce << endl;
			//	cout << evt.timeSinceLastFrame << endl;
		//}