


#ifndef __ParticleEffect_h_
#define __ParticleEffect_h_

#include "BasicHeader.h"
#include "Sprite3D.h"
using namespace std;
using namespace Ogre;


//class Stage;
/**
 * @brief 3D Game Programming<br>
 * My Name: ±i´º·Ó Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class is handle for particle sprite and relate method
 *
*/
class ParticleEffect : public Sprite3D{
public:
	ParticleEffect(Stage* stage) : Sprite3D(stage){};
	/*!
	\brief update particle effect
	*/
	virtual void update(Ogre::FrameEvent &evt);
	/*!
	\brief set particle effect alive
	*/
	virtual void setAlive(bool b);

	/*!
	\brief trigger particle effect at a position
	*/

	virtual void trigger(Ogre::Vector3 at);
};



#endif