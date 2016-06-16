#ifndef __OgreHead_h_
#define __OgreHead_h_
#include "Sprite3D.h"
#include "Weapon3D.h"
using namespace std;
using namespace Ogre;

/**
 * @brief 3D Game Programming<br>
 * My Name: 켲뉴롭 Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class derive from Sprite3D, for create ogrehead.mesh object
 * 
 *
*/
class OgreHead :public Sprite3D{
public:
	/*!
	\brief constructor
	*/
	OgreHead(Stage* stage);
	/*!
	\brief implement for update
	*/
	virtual void update(const Ogre::FrameEvent& evt);

	/*!
	\brief update view direction with a offset, for Second Person view
	*/
	virtual void updateViewDirection(Ogre::Vector3 targetPosition, Ogre::Radian yawRadian);

	/*!
	\brief set alive of monster
	*/
	virtual void setAlive(bool b);
protected:
	float mRandSpeed;
	float mAmplitude;
};




/**
 * @brief 3D Game Programming<br>
 * My Name: 켲뉴롭 Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class derive from Sprite3D, for create fish.mesh object
 * 
 *
*/
class Fish :public Sprite3D{
	//anime state:swim
public:
	/*!
	\brief constructor
	*/
	Fish(Stage* stage);
	/*!
	\brief implement for update
	*/
	virtual void update(const Ogre::FrameEvent& evt);

	/*!
	\brief update view direction with a offset, for Second Person view
	*/
	virtual void updateViewDirection(Ogre::Vector3 targetPosition, Ogre::Radian yawRadian);

	/*!
	\brief set alive of monster
	*/
	virtual void setAlive(bool b);
};





/**
 * @brief 3D Game Programming<br>
 * My Name: 켲뉴롭 Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class derive from Sprite3D, for create jaiqua.mesh object
 * 
 *
*/
// Run Sneak Stagger Turn Walk
class Jaiqua :public Sprite3D{
	//anime state:swim
public:
	/*!
	\brief constructor
	*/
	Jaiqua(Stage* stage);
	/*!
	\brief implement for update
	*/
	virtual void update(const Ogre::FrameEvent& evt);

	/*!
	\brief update view direction with a offset, for Second Person view
	*/
	virtual void updateViewDirection(Ogre::Vector3 targetPosition, Ogre::Radian yawRadian);

	/*!
	\brief set alive of monster
	*/
	virtual void setAlive(bool b);
};





/**
 * @brief 3D Game Programming<br>
 * My Name: 켲뉴롭 Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class derive from Sprite3D, for create penguin.mesh object
 * 
 *
*/
//penguin.mesh
//amuse
class Penguin :public Sprite3D{
	//anime state:swim
public:
	/*!
	\brief constructor
	*/
	Penguin(Stage* stage);
	/*!
	\brief implement for update
	*/
	virtual void update(const Ogre::FrameEvent& evt);

	/*!
	\brief update view direction with a offset, for Second Person view
	*/
	virtual void updateViewDirection(Ogre::Vector3 targetPosition, Ogre::Radian yawRadian);

	/*!
	\brief set alive of monster
	*/
	virtual void setAlive(bool b);
};


/**
 * @brief 3D Game Programming<br>
 * My Name: 켲뉴롭 Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class derive from Sprite3D, for create robot.mesh object
 * 
 *
*/

// Die Idle Shoot Slump Walk
class Robot :public Sprite3D{
	//anime state:swim
public:
	/*!
	\brief constructor
	*/
	Robot(Stage* stage);
	/*!
	\brief implement for update
	*/
	virtual void update(const Ogre::FrameEvent& evt);

	/*!
	\brief update view direction with a offset, for Second Person view
	*/
	virtual void updateViewDirection(Ogre::Vector3 targetPosition, Ogre::Radian yawRadian);

	/*!
	\brief set alive of monster
	*/
	virtual void setAlive(bool b);
};



/**
 * @brief 3D Game Programming<br>
 * My Name: 켲뉴롭 Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class derive from Sprite3D, for create razor.mesh object
 * 
 *
*/

class Razor :public Sprite3D{
	//anime state:swim
public:
	/*!
	\brief constructor
	*/
	Razor(Stage* stage);
	/*!
	\brief implement for update
	*/
	virtual void update(const Ogre::FrameEvent& evt);

	/*!
	\brief update view direction with a offset, for Second Person view
	*/
	virtual void updateViewDirection(Ogre::Vector3 targetPosition, Ogre::Radian yawRadian);

	/*!
	\brief set alive of monster
	*/
	virtual void setAlive(bool b);
};




#endif