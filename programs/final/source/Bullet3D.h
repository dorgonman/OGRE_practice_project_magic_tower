

#ifndef __Bullet3D_H__
#define __Bullet3D_H__
#include "Sprite3D.h"

class Weapon3D;

/**
 * @brief 3D Game Programming<br>
 * My Name: 켲뉴롭 Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class will compute update path and some function for bullet
 * 
 *
*/
class Bullet3D : public Sprite3D{
public:
	/*!
	\brief constructor
	*/
	Bullet3D(Stage* stage);
	/*!
	\brief constructor
	*/
	Bullet3D(Stage* stage, Weapon3D* weapon);
	/*!
	\brief deconstructor
	*/
	~Bullet3D();
public:
	/*!
	\brief update for bullet path
	*/
	virtual void update(const Ogre::FrameEvent& evt);
	/*!
	\brief fire the bullet
	*/
	virtual void trigger(Ogre::Vector3 at);
	/*!
	\brief set if this bullet is alive
	*/
	virtual void setAlive(bool alive);

	/*!
	\brief check if bullet hit a sprite within a radius
	*/
	virtual bool hit(Sprite3D* sprite, float radius);
public:
	Weapon3D* mWeapon;
	float power;//쨖펥ずヂ짵

};


#endif