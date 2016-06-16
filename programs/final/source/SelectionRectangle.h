#ifndef __SelectionRectangle_h__
#define __SelectionRectangle_h__

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

using namespace Ogre;

/**
 * @brief 3D Game Programming<br>
 * My Name: ±i´º·Ó Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class for volume selection, not relate to assign03
 *
*/
class SelectionRectangle : public ManualObject
{
public:
	/*!
	\brief constructor
	*/
    SelectionRectangle(const String &name)
        : ManualObject(name)
    {
        setUseIdentityProjection(true);
        setUseIdentityView(true);
        setRenderQueueGroup(RENDER_QUEUE_OVERLAY);
        setQueryFlags(0);
		//this->set
    }

	/*!
	\brief draw a 2D rectangle
	*/
	void setCorners(float left, float top, float right, float bottom){
		mLeft = left;
		mTop = top;
		mRight = right;
		mBottom = bottom;
		//Mapping to Ogre3D Projection Plane Space
		//BEGIN Using CEGUI
		//left = left * 2 - 1;
		//right = right * 2 - 1;
		//top = 1 - top * 2;
		//bottom = 1 - bottom * 2;
		//End USING CEGUI

		//BEGIN Using TrayMgr
		left = left * 2 - 1;
		right = right * 2 - 1;
		top = -1 - top * 2;
		bottom = -1 -bottom * 2;
		//End USING TrayMgr
		//////////////////////////
		Real z = -1;
		clear();

		/*begin("Examples/Hilite/Yellow", RenderOperation::OT_LINE_STRIP);
		colour(1, 1, 1, 0.5);
		position(left, top, z);
		position(right, top, z);
		position(right, bottom, z);
		position(left, bottom, z);
		position(left, top, z);*/
		
/////////////////////////////////////////
		//
		//  1----0
		//  | \  | 
		//  |  \ |
		//  3----2 
		begin("Examples/Hilite/Yellow", RenderOperation::OT_TRIANGLE_STRIP);
		colour(0.3, 0.2, 0.3, 0.1);
		position(right, top, z);
		position(left, top, z);
		position(right, bottom, z);
		position(left, bottom, z);
/////////////////////////////////////////
		end();

		AxisAlignedBox box;
		box.setInfinite();
		setBoundingBox(box);

	}
public:
	//screen coordination
	Real mLeft, mTop, mRight, mBottom;
};


#endif