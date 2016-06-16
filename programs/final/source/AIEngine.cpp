#include "AIEngine.h"

#include "Stage.h"


AIEngine::AIEngine(Stage* stage){
	mStage = stage;


}


AIEngine::~AIEngine(){


}



bool AIEngine::runTo(Sprite3D *sprite, Ogre::Vector3 position, float radius){
	Real t = mStage->evt.timeSinceLastFrame;
	Ogre::Vector3 direction = position - sprite->getPosition();
	direction.normalise();
	Ogre::Vector3 pos = sprite->getPosition() + (direction * (sprite->mVelocity * t));
	bool flgPos = this->mStage->projectScenePointOntoTerrain_PosDirection(pos);
	sprite->setPosition(pos);

	return true;
}