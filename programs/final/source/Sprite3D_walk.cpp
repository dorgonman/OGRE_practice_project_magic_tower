#include "Sprite3D.h"
#include "Stage.h"

void Sprite3D::walkForward(const Ogre::FrameEvent& evt){
	
	
}



void Sprite3D::walkBackward(const Ogre::FrameEvent& evt){

}

void Sprite3D::walkLeft(const Ogre::FrameEvent& evt){
	
	
}

void Sprite3D::walkRight(const Ogre::FrameEvent& evt){

}


void Sprite3D::walk(Ogre::Vector3 direction){
	direction.normalise();
	float speed = 1;
	this->mSceneNode->translate(direction * speed);
	Ogre::Vector3 pos = mSceneNode->getPosition();

	bool flgPos = mStage->projectScenePointOntoTerrain_PosDirection(pos);
	if(flgPos){
		setInitPosition(pos);
		//mSceneNode->setPosition(pos);
	} 		


}


