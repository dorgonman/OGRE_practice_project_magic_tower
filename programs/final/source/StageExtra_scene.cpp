#include "Stage.h"
#include "GameEngine.h"

using namespace Ogre;
//#define DATA_FILE_NAME	"123456789_game_data.txt"
void StageExtra::chooseScene(){

	if(mSceneMgr == NULL){
		mSceneMgr = mEngine->mRoot->createSceneManager(Ogre::ST_EXTERIOR_CLOSE, "primary");
	}
}




void StageExtra::createScene(){
	//cout << "start load parameter" << endl;
	GameParameter* p = new GameParameter();
	mParameter = p;
	mParameter->readData("9857515_game_data.txt");
	mParameter->printAll();


	SceneManager* sceneMgr = mSceneMgr;
	{//light
		mSceneMgr->setAmbientLight( ColourValue( 0.5, 0.5, 0.5 ) ); 
		Ogre::Light* light = mSceneMgr->createLight("SpotLight0");
		light->setType(Ogre::Light::LT_SPOTLIGHT);
		light->setPosition(200, 0, 200);
	}


	{//fog and shadow
		Ogre::ColourValue fadeColour(0.9, 0.9, 0.9);
		if(mParameter->mExpFogEnabled){
			sceneMgr->setFog(Ogre::FOG_EXP, fadeColour, mParameter->mExpFogDensity); 
		}else{
			sceneMgr->setFog(Ogre::FOG_NONE);
		}

		if(mParameter->mShadowEnabled){
			sceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
		}else{
			sceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_NONE);
		}
	}

	
	{//terrain
		sceneMgr->setWorldGeometry("myterrain.cfg");  
		sceneMgr->setSkyBox(true, "Examples/SpaceSkyBox");
	}

	{// water
		Ogre::Plane plane(Vector3::UNIT_Y, 0);
		Ogre::MeshManager::getSingleton().createPlane(
			"ground", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, 
			plane, 
			1500,1500, 	// width, height
			20,20, 		// x- and y-segments
			true, 		// normal
			1, 		    // num texture sets
			5,5, 		// x- and y-tiles
			Vector3::UNIT_Z	// upward vector
			); 


		Entity* ent = sceneMgr->createEntity("WaterGroundEntity", "ground"); 
		ent->setMaterialName(mParameter->mWaterMaterialsName);
		SceneNode* snode = sceneMgr->getRootSceneNode()->createChildSceneNode();
		snode->attachObject(ent); 
		snode->setPosition(Ogre::Vector3(750, mParameter->mWaterCoord_Y, 750));//x跟z設750是為了讓plane去fit整個terrain
	}


	{//player
		Entity* ent = sceneMgr->createEntity("robot", "robot.mesh");
		SceneNode* snode = sceneMgr->getRootSceneNode()->createChildSceneNode("robotNode");
		snode->attachObject(ent);
		snode->setPosition(200, 0, 200);
		this->mCurrentObject = new Player3D(this);
		mCurrentObject->attachSceneNode(snode);
		mCurrentObject->walkForward(evt);//測試走一下，讓初始位子設置好
		mSceneMgr->getCamera("playerCam")->setPosition(Ogre::Vector3(200, 0, 200));//camera設置初始
		//mCurrentObject->updateViewDirection();
		mCurrentObject->setInitHealth(200);
		Ogre::Viewport* vp0 = mEngine->mWindow->getViewport(0);
		vp0->setVisibilityMask(0x1);
		Ogre::Viewport* vp1 = mEngine->mWindow->getViewport(1);
		vp1->setVisibilityMask(0x2);//注意
		//讓他不在view port 0出現
		//ent->setVisibilityFlags(!(vp0->getVisibilityMask()));
		ent->setVisibilityFlags((!vp0->getVisibilityMask()) | (vp1->getVisibilityMask()));

	}



	{//monster position
		srand ( time(NULL) );
		  /* generate secret number: */
		for(int i = 0; i < mParameter->mMaxMonstersNum; i++){
			Sprite3D* spr = new OgreHead(this);
			mMonsterArr.push_back(spr);
			Entity* ent = mSceneMgr->createEntity("ogrehead.mesh" ); 
			SceneNode* snode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
			snode->attachObject(ent);
			spr->attachSceneNode(snode);

			Vector3 org(750, 40, 750);
			Vector3 pos;
			float x = (rand()%100)/100.0;
			float z = (rand()%100)/100.0;
			//cout << x << z << endl;
			//system("pause");
			pos.x = 700 * x;
			pos.z = 700 * z;
			pos.y = 50;
			snode->setPosition(pos+org);
			spr->setInitPosition(pos+org);

		}

	}

	{//bullet
		Weapon3D* weapon = new Weapon3D(this);
		weapon->createBullet(mParameter->mMaxBulletsNum, "sphere.mesh");
		weapon->setBulletSize(Ogre::Vector3(0.1, 0.1, 0.1));
		weapon->setInitVelocity(Ogre::Vector3(500, 500, 500));
		weapon->setBulletLifeTime(5);
	//	mCurrentObject->attachWeapon(weapon);
	}
	//mEngine->enableDefaultInput(false);//不使用tutorial framework預設的input

	{//讀入及設定player& monster的位子資訊
		mMapReader = new MAP_READER();
		mMapReader->read(mParameter->mMapName);

		mMapReader->scanMapForLocatingObjects();
		//玩家初始資訊
		Ogre::Vector3 vec = mMapReader->getStartingPosition();
		mCurrentObject->setInitPosition(vec);


		std::vector<Vector3> positionArr = mMapReader->getLocationOfMonsters();
		std::vector<Vector3> filterOutPositionArr;//濾掉x, z距離在100以內的
		for (int i = 0; i < positionArr.size(); ++i) {
			Vector3 p = positionArr[i] / 100;//為了去掉距離在100以內的
			//再乘100拿回原本的
			p.x = (int) p.x * 100;
			p.y = 50;
			p.z = (int) p.z  * 100;
			if(!exist(p, filterOutPositionArr)){
				filterOutPositionArr.push_back(p);
				//logMessage(p);
				//system("pause");
			}	
		
		}
		cout <<  filterOutPositionArr.size() << endl;

		for(int i = 0; i < mMonsterArr.size(); i++){
			Sprite3D* spr = mMonsterArr[i];
			float n = (rand() % filterOutPositionArr.size());
			spr->setInitPosition(filterOutPositionArr[n]);
		//	logMessage(filterOutPositionArr[n]);
			filterOutPositionArr.erase(filterOutPositionArr.begin() + n);//remove from list
	
			//cout << n << endl;
		}
		
	}

	//===============attatch武器跟particle node給monster================

	for(int i = 0; i < mMonsterArr.size(); i++){
		Sprite3D* monster = mMonsterArr[i];
		Weapon3D* weapon = new Weapon3D(this);
		weapon->createBullet(mParameter->mMaxBulletsNum, "sphere.mesh");
		weapon->setBulletSize(Ogre::Vector3(0.1, 0.1, 0.1));
		weapon->setInitVelocity(Ogre::Vector3(500, 500, 500));
		weapon->setBulletLifeTime(5);
		weapon->setCoolDown(1);
		//monster->attachWeapon(weapon);
		monster->setVision(600);
		monster->setInitHealth(10);
		monster->setAlive(true);

		

	}
	mEngine->mTrayMgr->hideCursor();
	cout << "finish scene loading" << endl;


	//=============create particle manager=================



	
	{
		String name;
		int index = 1;
		genNameUsingIndex("particle", index, name);
		ParticleEffect* effect = new ParticleEffect(this);
		effect->setAlive(false);
		effect->setLifeTime(1);
		SceneNode* fNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		ParticleSystem* par = mSceneMgr->createParticleSystem(name, "Examples/Smoke");
		ParticleEmitter *e = par->getEmitter(0);
		e->setEnabled(true);
		fNode->attachObject(par);
		fNode->setPosition(Vector3(0, 0, 0));
		fNode->setVisible(false);
		effect->attachSceneNode(fNode);	
	//	mParticleManager->addParticleEffect(effect);
	}


	{
		String name;
		int index = 2;
		genNameUsingIndex("particle", index, name);
		ParticleEffect* effect = new ParticleEffect(this);
		effect->setAlive(false);
		effect->setLifeTime(1);
		SceneNode* fNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		ParticleSystem* par = mSceneMgr->createParticleSystem(name, "Examples/PurpleFountain");
		ParticleEmitter *e = par->getEmitter(0);
		e->setEnabled(true);
		fNode->attachObject(par);
		fNode->setPosition(Vector3(0, 0, 0));
		fNode->setVisible(false);
		effect->attachSceneNode(fNode);	
		//mParticleManager->addParticleEffect(effect);
	}

	{
		String name;
		int index = 0;
		genNameUsingIndex("particle", index, name);
		ParticleEffect* effect = new ParticleEffect(this);
		effect->setAlive(false);
		effect->setLifeTime(1);
		SceneNode* fNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		ParticleSystem* par = mSceneMgr->createParticleSystem(name, "Examples/Rain");
		ParticleEmitter *e = par->getEmitter(0);
		e->setEnabled(true);
		fNode->attachObject(par);
		fNode->setPosition(Vector3(0, 0, 0));
		fNode->setVisible(false);
		effect->attachSceneNode(fNode);	
		//mParticleManager->addParticleEffect(effect);
	}



	


}
