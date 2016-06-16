#ifndef __AIEngine_h_
#define __AIEngine_h_


#include "Sprite3D.h"
/**
 * @brief 3D Game Programming<br>
 * My Name: ±i´º·Ó Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class handle for path finding and move
 *
*/
class AIEngine{
public:
	AIEngine(Stage* stage);
	~AIEngine();
public:
	/*!
	\brief move sprite toward the position.
	*/
	virtual bool runTo(Sprite3D* sprite, Vector3 position, float radius = 20);
public:
	Stage* mStage;

};
#endif