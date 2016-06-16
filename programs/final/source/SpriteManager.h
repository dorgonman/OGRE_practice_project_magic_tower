


#ifndef __SpriteManager_h_
#define __SpriteManager_h_

#include "Sprite3D.h"
#include "vector"
//class Stage;
/**
 * @brief 3D Game Programming<br>
 * My Name: ±i´º·Ó Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class handle for Sprite manager
 *
*/
class SpriteManager{
public:
	SpriteManager();
	~SpriteManager();
public:
	/*!
	\brief add one sprite
	*/
	virtual void addSprite(string name, Sprite3D* sprite);
	/*!
	\brief update all sprite
	*/
	virtual void update(Ogre::FrameEvent &evt);

	/*!
	\brief update sprite view, for second person view
	*/
	virtual void updateViewDirection(Vector3 targetPosition);

	/*!
	\brief check if the sprite (name) is alive
	*/
	virtual bool isAlive(string name);

	/*!
	\brief get position of the sprite (name)
	*/
	virtual Ogre::Vector3 getPosition(string name);

	/*!
	\brief get sprite
	*/
	virtual Sprite3D* getSprite(string name);

public:
	std::map<string, Sprite3D*> mSpriteMap;

};


#endif