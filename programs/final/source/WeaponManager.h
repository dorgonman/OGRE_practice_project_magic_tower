

#ifndef __WeaponManager_h_
#define __WeaponManager_h_

#include "Weapon3D.h"

//class Stage;
/**
 * @brief 3D Game Programming<br>
 * My Name: ±i´º·Ó Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class handle for weapon manager
 *
*/
class WeaponManager{
public:
	WeaponManager();
	~WeaponManager();
public:
	/*!
	\brief add one weapon
	*/
	virtual void addWeapon(string name, Weapon3D* weapon);
	/*!
	\brief update all weapon
	*/
	virtual void update(Ogre::FrameEvent &evt);

	/*!
	\brief get weapon
	*/
	virtual Weapon3D* getWeapon(string name);


	/*!
	\brief set all bulet direction to position
	*/
	virtual void setAllBulletDirectPosition(Weapon3D* weapon, Vector3 position);

	/*!
	\brief set all bulet direction
	*/
	virtual void setAllBulletDirection(Weapon3D* weapon, Vector3 direction);

	/*!
	\brief set all bulet direction
	*/
	virtual void setAllBulletDirection(Weapon3D* weapon, float theta, float alpha);

public://collision detection
	
	/*!
	\brief sprites that hited by sprite in this sprite manager within a radius
	*/
	virtual bool hit(std::map<string, Sprite3D*> sprites,  float radius);

	/*!
	\brief sprite that hited by sprite in this sprite manager within a radius
	*/
	virtual bool hit(Sprite3D* sprite,  float radius);


	/*!
	\brief sprites that hited by sprite in this sprite manager 
	*/
	virtual bool hit(std::map<string, Sprite3D*> sprites);

	/*!
	\brief sprite that hited by sprite in this sprite manager
	*/
	virtual bool hit(Sprite3D* sprite);

protected:
	std::map<string, Weapon3D*> mWeaponMap;
};


#endif