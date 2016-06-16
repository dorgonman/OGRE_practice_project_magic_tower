#include "Sprite3D.h"
#include "Stage.h"

void Sprite3D::setAnimation(Ogre::String name, bool loop){

	if(mEntity){
		if(hasAnimationName(name)){
			//disableAllAnimation(mEntity);
			mAnimationState = mEntity->getAnimationState(name);
			if(!mAnimationState->getEnabled()){
				mAnimationState->setTimePosition(0);
				mAnimationState->setLoop(loop);
				mAnimationState->setEnabled(true);
			}

		}else{
			mAnimationState = NULL;
		}
	}

}


void Sprite3D::printAllAnimationName(){
	if(mEntity){
		if(hasAnimation()){
			Ogre::AnimationStateSet* animeSet = mEntity->getAllAnimationStates();
			Ogre::AnimationStateIterator it = animeSet->getAnimationStateIterator();
			if(animeSet){
			   Ogre::AnimationStateIterator iter = animeSet->getAnimationStateIterator();
			   while(iter.hasMoreElements()){
					Ogre::AnimationState* anime = iter.getNext();
					cout << anime->getAnimationName()  << endl;
				
			   }
			}
		}
	}
}


bool Sprite3D::hasAnimation(){
	if(mEntity){
		Ogre::AnimationStateSet* animeSet = mEntity->getAllAnimationStates();
		if(animeSet){
			return true;
		}
	}
	return false;
}


bool Sprite3D::hasAnimationName(Ogre::String name){
	if(mEntity){
		Ogre::AnimationStateSet* animeSet = mEntity->getAllAnimationStates();
		Ogre::AnimationStateIterator it = animeSet->getAnimationStateIterator();
		if(animeSet){
		   Ogre::AnimationStateIterator iter = animeSet->getAnimationStateIterator();
		   while(iter.hasMoreElements()){
				Ogre::AnimationState* anime = iter.getNext();
				if(anime->getAnimationName() == name){
					return true;
				}
			
		   }
		}
	}

	return false;
}

void Sprite3D::disableAllAnimation(){

	if(mEntity){
		Ogre::AnimationStateSet* animeSet = mEntity->getAllAnimationStates();
		Ogre::AnimationStateIterator it = animeSet->getAnimationStateIterator();
		if(animeSet){
		   Ogre::AnimationStateIterator iter = animeSet->getAnimationStateIterator();
		   while(iter.hasMoreElements()){
				Ogre::AnimationState* anime = iter.getNext();
				anime->setEnabled(false);
			
		   }
		}
	}


}


