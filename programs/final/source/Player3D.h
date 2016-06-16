#ifndef __Player3D_h_
#define __Player3D_h_
#include "Sprite3D.h"
#include "Weapon3D.h"
using namespace std;
using namespace Ogre;

/**
 * @brief 3D Game Programming<br>
 * My Name: ±i´º·Ó Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class derive from Sprite3D, for create player object
 * 
 *
*/
class Player3D:public Sprite3D{
public:
	/*!
	\brief constructor
	*/
	Player3D(Stage* stage);
	/*!
	\brief implement for walk forward
	*/
	virtual void walkForward(const Ogre::FrameEvent& evt);
	/*!
	\brief implement for walk backward
	*/
	virtual void walkBackward(const Ogre::FrameEvent& evt);

	/*!
	\brief walk left
	*/
	virtual void walkLeft(const Ogre::FrameEvent& evt);
	/*!
	\brief walk Right
	*/
	virtual void walkRight(const Ogre::FrameEvent& evt);


	/*!
	\brief implement for update
	*/
	virtual void update(const Ogre::FrameEvent& evt);

	
	/*!
	\brief update view direction with a offset
	*/
	virtual void updateViewDirection(Camera* camera, Vector3 direction, Vector3 offset, Ogre::Radian yawRadian);

protected:

};

#endif