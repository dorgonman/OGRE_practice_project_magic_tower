/*
This is an assignment for 3D Game Programming.
Author: Sai-Keung Wong
NCTU, Taiwan, ROC
Date: March 2011

The code is not well-aligned and it is buggy.
The students must modify the code in order to finish the assignment.

Almost all functions are buggy!
*/

#include "BasicTools.h"

namespace {
	OgreBites::SdkTrayManager* sTrayMgr;
	Ogre::RaySceneQuery *sRaySceneQuery;
	Ogre::SceneManager *sSceneMgr;
	Ogre::Camera *sCamera;
};

	using namespace Ogre;
void bt_Init(OgreBites::SdkTrayManager* a_TrayMgr, Ogre::SceneManager *a_SceneMgr, Ogre::Camera *a_Camera)
{
	sTrayMgr = a_TrayMgr;
	sSceneMgr = a_SceneMgr;
	sCamera = a_Camera;
	sRaySceneQuery = sSceneMgr->createRayQuery ( Ogre::Ray() ); 
}

void genNameUsingIndex(const Ogre::String & prefix, int index, Ogre::String &out_name)
{
	out_name= prefix + Ogre::StringConverter::toString(static_cast<int>(index));
}

void logMessage(const  Ogre::String &msg)
{
	 Ogre::LogManager::getSingletonPtr()->logMessage(msg);
}

void logMessage(const Ogre::Vector3 &v)
{
	Ogre::String msg;
	std::stringstream out0;
	std::stringstream out1;
	std::stringstream out2;
	out0 << v.x;
	out1 << v.y;
	out2 << v.z;

	msg = out0.str() + "\t\t" + out1.str() + "\t\t" + out2.str();
	
Ogre::LogManager::getSingletonPtr()->logMessage(msg);
}

bool projectScenePointOntoTerrain_PosDirection(Ogre::Vector3 &p)
{
	
	sRaySceneQuery->setRay(Ray(p, Vector3(0, 1, 0)));
	
	return false;
}

bool projectScenePointOntoTerrain_NegDirection(Ogre::Vector3 &p)
{
	
	sRaySceneQuery->setRay(Ray(p, Vector3(0, -1, 0)));
	
	bool flg = false;

	
	return flg;

}




Vector3 rotateX(Vector3 direction, float degree){
	Vector3 result;
	result.x = direction.x;
	result.y = direction.y * cos(degree) - direction.z * cos(degree);
	result.z =  direction.y * sin(degree) + direction.z * cos(degree);
	return result;
}

Vector3 rotateY(Vector3 direction, float degree){
	Vector3 result;
	result.x = direction.x * cos(degree) - direction.z * sin(degree);
	result.y = direction.y;
	result.z =  direction.x * sin(degree) + direction.z * cos(degree);
	return result;
}


Vector3 rotateZ(Vector3 direction, float degree){
	Vector3 result;
	result.x = direction.x * cos(degree) - direction.y * sin(degree);
	result.y = direction.x * sin(degree) + direction.y * cos(degree);
	result.z =  direction.z;
	return result;
}


std::string int2str(int &i) {
  std::string s;
  std::stringstream ss(s);
  ss << i;
  return ss.str();
}

