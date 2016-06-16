#include "GameEngine.h"
#include "Stage.h"



void Stage3::createScene(){
	Stage::createScene();
	//cout << "start load parameter" << endl;
	GameParameter mParameter;
	mParameter.readData("Stage3_parameter.txt");
	


	SceneManager* sceneMgr = mSceneMgr;
	{//light
		mSceneMgr->setAmbientLight( ColourValue( 0.5, 0.5, 0.5 ) ); 
		Ogre::Light* light = mSceneMgr->createLight("SpotLight0");
		light->setType(Ogre::Light::LT_SPOTLIGHT);
		light->setPosition(200, 0, 200);
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
		sceneMgr->setWorldGeometry("stage3_terrain.cfg");  
		sceneMgr->setSkyBox(true, "Examples/SceneSkyBox1");
	}

}