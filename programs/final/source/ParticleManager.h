

#ifndef __ParticleManager_h_
#define __ParticleManager_h_

#include "ParticleEffect.h"
#include "map"
/**
 * @brief 3D Game Programming<br>
 * My Name: ±i´º·Ó Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class handle for multiple particle management
 *
*/
class ParticleManager{
public:
	ParticleManager();
	~ParticleManager();
public:
	/*!
	\brief add one particle effect
	*/
	virtual void addParticleEffect(string name, ParticleEffect* effect);
	/*!
	\brief update all particle effect
	*/
	virtual void update(Ogre::FrameEvent &evt);



	/*!
	\brief fire a particle effect in particle manager that it's alive is false
	*/
	virtual void trigger(Ogre::Vector3 at);

	/*!
	\brief fire a particle effect at the index in particle manager
	*/
	virtual void trigger(string name, Ogre::Vector3 at);


	/*!
	\brief check if the particle (index) is already alive
	*/
	virtual bool isAlive(string name);
protected:
	std::map<string, ParticleEffect*> mParticleMap;
};


#endif