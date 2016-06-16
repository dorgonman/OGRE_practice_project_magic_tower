#include "ParticleEffect.h"



void ParticleEffect::update(Ogre::FrameEvent &evt){
	
	if(isAlive()){
		this->mTime += evt.timeSinceLastFrame;
		if(mTime >= this->mLifeTime){
			this->setAlive(false);
		}
	}

}


void ParticleEffect::setAlive(bool b){
	Sprite3D::setAlive(b);
	if(mSceneNode){
		ParticleSystem* par = (ParticleSystem*)mSceneNode->getAttachedObject(0);
		if(b){
			mSceneNode->setVisible(true);
			par->getEmitter(0)->setEnabled(true);
		}else{
			mSceneNode->setVisible(false);
			par->getEmitter(0)->setEnabled(false);
		
		}
	}
}




void ParticleEffect::trigger(Ogre::Vector3 at){
	setAlive(true);
	setInitPosition(at);
}
