#include "GameEngine.h"
#include "Stage.h"


void StageExtra::createViewPort(){

	{//view1
		Ogre::Viewport* vp = mEngine->mWindow->addViewport(
			mSceneMgr->getCamera("playerCam"),
			0,
			0,
			0,
			1,
			1
			);
		vp->setBackgroundColour(Ogre::ColourValue(0,1,0));
		
		mSceneMgr->getCamera("playerCam")->setAspectRatio(
			Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
		vp->setOverlaysEnabled(true);
	
	}
	{//view2
		Ogre::Viewport* vp = mEngine->mWindow->addViewport(
			mSceneMgr->getCamera("playerCam1"),
			1,
			0.7f,
			0,
			0.3f,
			0.3f
			);
		vp->setBackgroundColour(Ogre::ColourValue(0,1,0));
		mSceneMgr->getCamera("playerCam1")->setAspectRatio(
			Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
		vp->setOverlaysEnabled(false);
	}

}