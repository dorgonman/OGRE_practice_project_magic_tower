#ifndef __Weapon3D_H__
#define __Weapon3D_H__
#include "vector"
#include "string"
#include "Sprite3D.h"
#include "Bullet3D.h"
using namespace std;
/**
 * @brief 3D Game Programming<br>
 * My Name: ±i´º·Ó Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class will compute update path and some function for bullet
 * 
 *
*/
class Weapon3D: public Sprite3D{
public:
	/*!
	\brief constructor
	*/
	Weapon3D(Stage* stage);
	/*!
	\brief deconstructor
	*/
	~Weapon3D();

	/*!
	\brief create bullet
	\param num number of bullet
	\param meshName which mesh we used to create bullet
	\param lifeTime bullet's lifeTime that it can fly
	*/
	virtual void createBullet(int num, string meshName);
	/*!
	\brief fire a bullet
	\param at where our bullet initial position will generated
	*/
	virtual void trigger(Ogre::Vector3 at);
	/*!
	\brief update all bullets in this weapon
	*/
	virtual void update(const Ogre::FrameEvent &evt);
	/*!
	\brief size of bullets
	*/
	virtual void setBulletSize(Ogre::Vector3& scale);

	/*!
	\brief set material
	*/
	virtual void setBulletMaterialName(string name);
	/*!
	\brief life time of bullets
	*/
	virtual void setBulletLifeTime(float lifeTime);

	/*!
	\brief check if any bullet in this weapon hit a position area within a radius
	*/
	virtual bool hit(Sprite3D* sprite, float radius);
	/*!
	\brief set cool down time of weapon
	*/
	virtual void setCoolDown(float coolDown){mCoolDown = coolDown;};

public:
	std::vector<Bullet3D*> mBulletArr;
	float mCoolDown;
	float mCurrentBulletIndex;
};

#endif