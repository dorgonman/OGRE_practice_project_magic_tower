#include "GameEngine.h"
#include "Stage.h"



void Stage1::createScene(){
	Stage::createScene();


	//cout << "start load parameter" << endl;
	GameParameter mParameter;

	mParameter.readData("stage1_parameter.txt");
//	mParameter->printAll();


	SceneManager* sceneMgr = mSceneMgr;
	{//light
		mSceneMgr->setAmbientLight(ColourValue(0.8, 0.8, 0.8) ); 
		Ogre::Light* light = mSceneMgr->createLight("Light0");
		light->setType(Ogre::Light::LT_DIRECTIONAL);
		light->setPosition(2500, 2500, 2500);
	}


	{//fog and shadow
		Ogre::ColourValue fadeColour(0.9, 0.9, 0.9);
		if(mParameter.mExpFogEnabled){
			sceneMgr->setFog(Ogre::FOG_EXP, fadeColour, mParameter.mExpFogDensity); 
		}else{
			sceneMgr->setFog(Ogre::FOG_NONE);
		}

		if(mParameter.mShadowEnabled){
			sceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
		}else{
			sceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_NONE);
		}
	}

	{//terrain
		sceneMgr->setWorldGeometry("stage1_terrain.cfg");  
		sceneMgr->setSkyBox(true, "Examples/SpaceSkyBox");
	}

	//OverlayManager::getSingleton().geto


	//this->mEngine->mTrayMgr->

  /*SOUND *mSound;
  mSound = new SOUND;
  mSound->init();
  mSound->play();	*/
}