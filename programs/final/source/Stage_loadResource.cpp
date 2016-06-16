#include "Stage.h"





void Stage::loadResource(){
	loadParticle();
	loadMonster();
	loadPlayer();
	loadOverlay();
}


void Stage::loadOverlay(){
	mWeaponPicture = OverlayManager::getSingleton().createOverlayElement("Panel","OverlayElement/weapon");
	mWeaponPicture->setParameter("metrics_mode","pixels");
	mWeaponPicture->setParameter("left","50");
	mWeaponPicture->setParameter("top","80");
	mWeaponPicture->setParameter("width","100");
	mWeaponPicture->setParameter("height","100");
	mWeaponOverlay = OverlayManager::getSingleton().create("Overlay/weapon");
	mWeaponOverlay->add2D((OverlayContainer*)mWeaponPicture);
	mWeaponOverlay->setZOrder(10);
}

void Stage::loadPlayer(){

	{//player
		Entity* ent = mSceneMgr->createEntity("player", "ninja.mesh");
		SceneNode* snode = mSceneMgr->getRootSceneNode()->createChildSceneNode("playerNode");
		snode->attachObject(ent);
		this->mPlayerSpr = new Player3D(this);
		mPlayerSpr->attachSceneNode(snode);
		//mSceneMgr->getCamera("playerCam")->setPosition(Ogre::Vector3(200, 0, 200));//camera設置初始
		//mPlayerSpr->updateViewDirection();
		mPlayerSpr->setInitHealth(200);
		//mPlayerSpr->printAllAnimationName();
		snode->setScale(0.5, 0.5, 0.5);
		snode->yaw(Radian(0.785));//model的方向轉1 pi
		mPlayerSpr->setVelocity(Ogre::Vector3(200, 0, 200));
		mPlayerSpr->walkForward(evt);
		mPlayerSpr->setInitHealth(100);
		mPlayerSpr->setInitPosition(Ogre::Vector3(2500, 0, 2500));
		mPlayerSpr->walkForward(evt);//測試走一下，讓初始位子設置好

		{
			Weapon3D* weapon = new Weapon3D(this);
			weapon->createBullet(100, "sphere.mesh");
			weapon->setBulletSize(Ogre::Vector3(0.1, 0.1, 0.1));
			weapon->setInitVelocity(Ogre::Vector3(700, 700, 700));
			weapon->setBulletLifeTime(5);
			weapon->setBulletMaterialName("mat/green");
			mPlayerWeaponMgr->addWeapon("nway", weapon);
		}

		{
			Weapon3D* weapon = new Weapon3D(this);
			weapon->createBullet(100, "sphere.mesh");
			weapon->setBulletSize(Ogre::Vector3(0.1, 0.1, 0.1));
			weapon->setInitVelocity(Ogre::Vector3(500, 500, 500));
			weapon->setBulletLifeTime(5);
			weapon->setBulletMaterialName("mat/tower");
			weapon->setBulletMaterialName("mat/blue");
			mPlayerWeaponMgr->addWeapon("trace", weapon);

		}
		//mPlayerSpr->attachWeapon(weapon);
	}


	{//tower
		Entity* ent = mSceneMgr->createEntity("towerEntity", "column.mesh");
		ent->setCastShadows(false);
		SceneNode* snode = mSceneMgr->getRootSceneNode()->createChildSceneNode("towerNode");
		snode->attachObject(ent);
		ent->setMaterialName("mat/tower");
		mTowerSpr = new Sprite3D(this);
		mTowerSpr->attachSceneNode(snode);
		//mTowerSpr->printAllAnimationName();
		//mSceneMgr->getCamera("playerCam")->setPosition(Ogre::Vector3(200, 0, 200));//camera設置初始
		//mPlayerSpr->updateViewDirection();
		mTowerSpr->setInitHealth(100);
		mTowerSpr->setInitPosition(Ogre::Vector3(2500, 50, 2500));
		mTowerSpr->walk(Ogre::Vector3(0,0,0));//測試走一下，讓初始位子設置好
	}
}



void Stage::loadMonster(){

	{//====================monster====================
		for(int i = 0; i < 10; i++){
			String name;
			genNameUsingIndex("ogrehead", i, name);
			Sprite3D* spr = new OgreHead(this);
			mMonsterMgr->addSprite(name, spr);
			spr->setAlive(false);
		}


		for(int i = 0; i < 10; i++){
			String name;
			genNameUsingIndex("fish", i, name);
			Sprite3D* spr = new Fish(this);
			mMonsterMgr->addSprite(name, spr);
			spr->setAlive(false);
		}

		
		for(int i = 0; i < 10; i++){
			String name;
			genNameUsingIndex("jaiqua", i, name);
			Sprite3D* spr = new Jaiqua(this);
			mMonsterMgr->addSprite(name, spr);
			spr->setAlive(false);
		}


		for(int i = 0; i < 10; i++){
			String name;
			genNameUsingIndex("penguin", i, name);
			Sprite3D* spr = new Penguin(this);
			mMonsterMgr->addSprite(name, spr);
			spr->setAlive(false);
		}

		

		for(int i = 0; i < 10; i++){
			String name;
			genNameUsingIndex("robot", i, name);
			Sprite3D* spr = new Robot(this);
			mMonsterMgr->addSprite(name, spr);
			spr->setAlive(false);
		}

		for(int i = 0; i < 10; i++){
			String name;
			genNameUsingIndex("razor", i, name);
			Sprite3D* spr = new Razor(this);
			mMonsterMgr->addSprite(name, spr);
			spr->setAlive(false);
		}

		for(int i = 0; i < 10; i ++){
			String name;
			genNameUsingIndex("gun", i, name);
			Weapon3D* weapon = new Weapon3D(this);
			weapon->createBullet(100, "sphere.mesh");
			weapon->setBulletSize(Ogre::Vector3(0.1, 0.1, 0.1));
			weapon->setBulletMaterialName("mat/red");
			mMonsterWeaponMgr->addWeapon(name, weapon);
		}

		{
			Sprite3D* spr = new Razor(this);
			mMonsterMgr->addSprite("boss1", spr);
			spr->setAlive(false);
		}
		{
			Sprite3D* spr = new Penguin(this);
			mMonsterMgr->addSprite("boss2", spr);
			spr->setAlive(false);
		}

		{
			Sprite3D* spr = new OgreHead(this);
			mMonsterMgr->addSprite("boss3", spr);
			spr->setAlive(false);
			spr->mEntity->setCastShadows(false);
		}
	}

}


void Stage::loadParticle(){

	{//particles 0
		ParticleEffect* effect = new ParticleEffect(this);
		effect->setAlive(false);
		effect->setLifeTime(1);
		SceneNode* fNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		ParticleSystem* par = mSceneMgr->createParticleSystem("bulletHit", "Examples/Smoke");
		ParticleEmitter *e = par->getEmitter(0);
		e->setEnabled(true);
		fNode->attachObject(par);
		fNode->setPosition(Ogre::Vector3(0, 0, 0));
		fNode->setVisible(false);
		effect->attachSceneNode(fNode);	
		mParticleMgr->addParticleEffect("bulletHit", effect);
	}

	{//particles 1
		ParticleEffect* effect = new ParticleEffect(this);
		effect->setAlive(false);
		effect->setLifeTime(20);
		SceneNode* fNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		ParticleSystem* par = mSceneMgr->createParticleSystem("towerMagic", "PEExamples/pentagram");
		ParticleEmitter *e = par->getEmitter(0);
		e->setEnabled(true);
		fNode->attachObject(par);
		fNode->setPosition(Ogre::Vector3(0, 0, 0));
		fNode->setVisible(false);
		//fNode->setScale(10,10, 10);
		Ogre::Quaternion q(Degree(90), Ogre::Vector3::UNIT_X);
		fNode->rotate(q);
		effect->attachSceneNode(fNode);	
		mParticleMgr->addParticleEffect("magic", effect);
	}



	//=====================snow=========================
	{//particles 2
		ParticleEffect* effect = new ParticleEffect(this);
		effect->setAlive(false);
		effect->setLifeTime(20);
		SceneNode* fNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		ParticleSystem* par = mSceneMgr->createParticleSystem("snow", "Examples/Snow");
		ParticleEmitter *e = par->getEmitter(0);
		e->setEnabled(true);
		fNode->attachObject(par);
		fNode->setPosition(Ogre::Vector3(0, 0, 0));
		fNode->setVisible(false);
		fNode->setScale(30, 2, 30);
		effect->attachSceneNode(fNode);	
		mParticleMgr->addParticleEffect("snow", effect);
	}


	//=====================flame=========================
	{//particles 3
		ParticleEffect* effect = new ParticleEffect(this);
		effect->setAlive(false);
		effect->setLifeTime(20);
		SceneNode* fNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		ParticleSystem* par = mSceneMgr->createParticleSystem("flame", "PEExamples/flame");
		ParticleEmitter *e = par->getEmitter(0);
		e->setEnabled(true);
		fNode->attachObject(par);
		fNode->setPosition(Ogre::Vector3(0, 0, 0));
		fNode->setVisible(false);
		fNode->setScale(30, 2, 30);
		effect->attachSceneNode(fNode);	
		mParticleMgr->addParticleEffect("flame", effect);
	}

	

	//=====================smoke=========================
	{//particles 4
		ParticleEffect* effect = new ParticleEffect(this);
		effect->setAlive(false);
		effect->setLifeTime(20);
		SceneNode* fNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		ParticleSystem* par = mSceneMgr->createParticleSystem("smoke", "PEExamples/smoke");
		ParticleEmitter *e = par->getEmitter(0);
		e->setEnabled(true);
		fNode->attachObject(par);
		fNode->setPosition(Ogre::Vector3(0, 0, 0));
		fNode->setVisible(false);
		fNode->setScale(30, 2, 30);
		effect->attachSceneNode(fNode);	
		mParticleMgr->addParticleEffect("smoke", effect);
	}

	//===============space==========

	{//particles 5
	
		ParticleEffect* effect = new ParticleEffect(this);
		effect->setAlive(false);
		effect->setLifeTime(20);
		SceneNode* fNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		ParticleSystem* par = mSceneMgr->createParticleSystem("space", "PEExamples/blast2");
		ParticleEmitter *e = par->getEmitter(0);
		e->setEnabled(true);
		fNode->attachObject(par);
		fNode->setPosition(Ogre::Vector3(0, 0, 0));
		fNode->setVisible(false);
		fNode->setScale(30, 2, 30);
		effect->attachSceneNode(fNode);	
		mParticleMgr->addParticleEffect("space", effect);
	}

}