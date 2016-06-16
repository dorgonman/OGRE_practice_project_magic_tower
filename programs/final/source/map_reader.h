#ifndef __MAP_READER_H__
#define __MAP_READER_H__
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <vector>
using namespace Ogre;
class MAP_READER {
protected:
	Image *mImage;
	std::vector<Vector3> mMonsterLocation;
	Vector3 mDestination;
	Vector3 mStartingPosition;
	Real mOriginX;
	Real mOriginZ;
	Real mDX;
	Real mDZ;

public:
	MAP_READER();
	void read(const String &a_MapName);
	void getDestination(Vector3 &d);
	void getStartingPosition(Vector3 &d);
	Vector3 &getDestination();
	Vector3 &getStartingPosition();
	void scanMapForLocatingObjects();
	const std::vector<Vector3> &getLocationOfMonsters() const;
};

#endif