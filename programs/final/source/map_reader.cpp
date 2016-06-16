#include "map_reader.h"
#include "BasicTools.h"
#include "stdlib.h"
using namespace std;
MAP_READER::MAP_READER()
{
	mImage = 0;
	mDX = 10;
	mDZ = 10;
	mOriginX = 0;
	mOriginZ = 0;
	mDestination = Vector3::ZERO;
	mStartingPosition = Vector3::ZERO;


}
void MAP_READER::read(const String &a_MapName)
{
	if (mImage !=0) return;
	logMessage("BGN MAP_READER::read");
	logMessage(a_MapName);
	mImage = new Image;
	mImage->load(a_MapName, "General");
	logMessage("END MAP_READER::read");
}

Vector3 &MAP_READER::getDestination()
{
	return mDestination;
}

Vector3 &MAP_READER::getStartingPosition()
{
	return mStartingPosition;
}

void MAP_READER::getDestination(Vector3 &d)
{
	d = mDestination;
}

void MAP_READER::getStartingPosition(Vector3 &d)
{
	d = mStartingPosition;
}

void MAP_READER::scanMapForLocatingObjects()
{
	int nx = mImage->getWidth();
	int nz = mImage->getHeight();
	int bpp = int(mImage->getSize() / (nx*nz)); 
	if (bpp < 3) return;
	int offset = 0;
	if (bpp == 4) offset = 1;
	const uchar* imageData = mImage->getData();
	
	uint t = 100; //threshold
	for (int j = 0; j < nz; ++j)
	{
		for (int i = 0; i < nx; ++i) {
			uint index = (i + j*nx)*bpp;
			
			uint b = imageData[index+0+offset]; //blue color
			uint g = imageData[index+1+offset]; //green color
			uint r = imageData[index+2+offset]; //red color
			if (r > t && g > t && b > t) continue;
			if (r < t && g < t && b < t) continue;
			float x, z;
			x = i*mDX+mOriginX;
			z = j*mDZ+mOriginZ;
			//DEBUG_LOG_MSG_3INT("color R", i, j, r);
			//DEBUG_LOG_MSG_3INT("color G", i, j, g);
			//DEBUG_LOG_MSG_3INT("color B", i, j, b);
			if (b > t) {
				//blue
				mStartingPosition = Vector3(x, 1000, z);
			}

			if (r > t) {
				//red
				mMonsterLocation.push_back(Vector3(x, 1000, z));
			}
			
			if (g > t) { 
				//green
				mDestination = Vector3(x, 0, z);
			}
		}
	}
}

const std::vector<Vector3> &MAP_READER::getLocationOfMonsters() const
{
	return mMonsterLocation;
}