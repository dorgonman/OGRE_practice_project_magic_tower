/*
This is an assignment for 3D Game Programming.
Author: Sai-Keung Wong
NCTU, Taiwan, ROC
Date: March 2011

The code is not well-aligned and it is buggy.
The students must modify the code in order to finish the assignment.

Almost all functions are buggy!
*/


#ifndef __BASIC_TOOLS_H__
#define __BASIC_TOOLS_H__
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include <SdkTrays.h>
#include <SdkCameraMan.h>
#include <string>
#include <sstream>
#include <iostream>

extern void genNameUsingIndex(const Ogre::String & prefix, int index, Ogre::String &out_name);
extern void logMessage(const  Ogre::String &msg);
extern void logMessage(const Ogre::Vector3 &v);
extern void bt_Init(OgreBites::SdkTrayManager* a_TrayMgr, Ogre::SceneManager *a_SceneMgr, Ogre::Camera *a_Camera);
extern bool projectScenePointOntoTerrain_PosDirection(Ogre::Vector3 &p);
extern bool projectScenePointOntoTerrain_NegDirection(Ogre::Vector3 &p);


/*!
\brief rotate a vector according to x axis
*/
extern Vector3 rotateX(Vector3 direction, float degree);
/*!
\brief rotate a vector according to Y axis
*/
extern Vector3 rotateY(Vector3 direction, float degree);

/*!
\brief rotate a vector according to z axis
*/
extern Vector3 rotateZ(Vector3 direction, float degree);
/*!
\brief translate int to string
*/
extern std::string int2str(int &i);

#endif