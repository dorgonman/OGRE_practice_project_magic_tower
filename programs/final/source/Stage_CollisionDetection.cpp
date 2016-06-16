#include "Stage.h"
#include "GameEngine.h"


bool Stage::projectScenePointOntoTerrain_PosDirection(Ogre::Vector3 &p){
	RaySceneQuery *mRaySceneQuery =  mSceneMgr->createRayQuery ( Ray() ); 
	mRaySceneQuery->setRay(Ray(p, Ogre::Vector3::UNIT_Y));
	mRaySceneQuery->setQueryTypeMask(SceneManager::ENTITY_TYPE_MASK );

	// Perform the scene query
	RaySceneQueryResult &result = mRaySceneQuery->execute();
	RaySceneQueryResult::iterator itr = result.begin();
	//cout << result.size() << endl;
	for (itr = result.begin(); itr != result.end(); itr++){
		if (itr->movable){
			//::gScreenText.print(0.2, 0.2, "koube");
		}else if (itr->worldFragment) {
			p = itr->worldFragment->singleIntersection;
			mSceneMgr->destroyQuery(mRaySceneQuery);
			//::gScreenText.print(0.2, 0.2, "koube2");
			return true;
		}

	}


	mSceneMgr->destroyQuery(mRaySceneQuery);
	return false;
}


bool Stage::projectScenePointOntoTerrain_NegDirection(Ogre::Vector3 &p){
	RaySceneQuery *mRaySceneQuery =  mSceneMgr->createRayQuery ( Ray() ); 
	mRaySceneQuery->setRay(Ray(p, Ogre::Vector3::NEGATIVE_UNIT_Y));
	mRaySceneQuery->setQueryTypeMask(SceneManager::WORLD_GEOMETRY_TYPE_MASK );

	// Perform the scene query
	RaySceneQueryResult &result = mRaySceneQuery->execute();
	RaySceneQueryResult::iterator itr = result.begin();
	for (itr = result.begin(); itr != result.end(); itr++){
		if (itr->movable){
		}else if (itr->worldFragment) {
			p = itr->worldFragment->singleIntersection;
			mSceneMgr->destroyQuery(mRaySceneQuery);
			return true;

		}

	}
	mSceneMgr->destroyQuery(mRaySceneQuery);
	return false;
}