#include "GameEngine.h"
#include "Stage.h"

void StageExtra::createCamera(){
	Ogre::Camera* camera = mSceneMgr->createCamera("playerCam");
	camera->setPosition(Ogre::Vector3(200, 500,200));
	camera->lookAt(Ogre::Vector3(0,0,0));
	camera->setNearClipDistance(5);
	mEngine->mCameraMan->setCamera(camera);   // assign to default camera controller


	Ogre::Camera* camera1 = mSceneMgr->createCamera("playerCam1");
	camera1->setNearClipDistance(5);
	camera1->setPosition(750, 1300, 751);//設完position之後lookAt跟rotate會設回初始值
	camera1->lookAt(Ogre::Vector3(750,50,750));
	camera1->rotate(Ogre::Quaternion(1, 0, 1, 0));//Y軸轉180度

}