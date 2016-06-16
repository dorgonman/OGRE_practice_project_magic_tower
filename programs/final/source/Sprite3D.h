
#ifndef __Sprite3D_h_
#define __Sprite3D_h_
#include "BasicHeader.h"
#include "Stdlib.h"
#include "vector"
using namespace std;
using namespace Ogre;

class Stage;
class Weapon3D;
/**
 * @brief 3D Game Programming<br>
 * My Name: 張景照 Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class hold some basic function and attribue for a Sprite <br>
 * to move around 3D environment. 
 *
*/
class Sprite3D{
public:

	enum eActionMode{
		AM_JUMP,
		AM_RUN,
		AM_NO
	};
	/*!
	\brief constructor
	*/
	Sprite3D(Stage* stage);
	/*!
	\brief deconstructor
	*/
	~Sprite3D();

public://attach
	/*!
	\brief attach a scene node to Sprite3D
	*/
	virtual void attachSceneNode(SceneNode* snode);


public://walk
	/*!
	\brief walk to a direction
	*/
	virtual void walk(Ogre::Vector3 direction);
	/*!
	\brief walk forward
	*/
	virtual void walkForward(const Ogre::FrameEvent& evt);
	/*!
	\brief walk backward
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

public://update
	/*!
	\brief update sprite
	*/
	virtual void update(const Ogre::FrameEvent& evt);

	/*!
	\brief update view direction with a offset, for FPS or TPS
	*/
	virtual void updateViewDirection(Camera* camera, Vector3 direction, Vector3 offset, Ogre::Radian yawRadian){};


	/*!
	\brief update view direction with a offset, for Second Person view
	*/
	virtual void updateViewDirection(Vector3 targetPosition, Ogre::Radian yawRadian){};

	/*!
	\brief update view direction
	*/
	virtual void updateViewDirection(Ogre::Radian yawRadian){};

public://set
	/*!
	\brief set initial position
	*/
	virtual void setInitPosition(Ogre::Vector3 pos);

	/*!
	\brief set position
	*/
	virtual void setPosition(Ogre::Vector3 pos);


	/*!
	\brief set life time of sprite3D
	*/
	virtual void setLifeTime(float time){mLifeTime = time;};

	/*!
	\brief set current time of sprite3D
	*/
	virtual void setTime(float time){mTime = time;};
	/*!
	\brief set velocity
	*/
	virtual void setInitVelocity(Ogre::Vector3 vel);
	/*!
	\brief set velocity
	*/
	virtual void setVelocity(Ogre::Vector3 vel){mVelocity = vel;};

	/*!
	\brief set initial direction and current Direction
	*/
	virtual void setInitDirection(Ogre::Vector3 direction){
		mInitDirection = direction;
		mDirection = direction;
	};

	
	/*!
	\brief set direction
	*/
	virtual void setDirection(Ogre::Vector3 direction){
		mDirection = direction;
	};


	
	/*!
	\brief set sprite vision region
	*/
	virtual void setVision(float vision){mVision = vision;};

	/*!
	\brief set visibility mask
	*/
	virtual void setVisibilityFlags(uint flags);

	/*!
	\brief set scale of sprite
	*/
	virtual void setScale(Ogre::Vector3 scale);
public://get

	/*!
	\brief get init velocity
	*/
	virtual Vector3 getInitVelocity(){return mInitVelocity;};

	/*!
	\brief get velocity
	*/
	virtual Vector3 getVelocity(){return mVelocity;};


	/*!
	\brief get sprite position
	*/
	virtual Ogre::Vector3 getPosition();


	/*!
	\brief get sprite vision region
	*/
	virtual float getVision(){return mVision;};

		/*!
	\brief get scene node
	*/
	SceneNode* getSceneNode(){return mSceneNode;};

	/*!
	\brief do jump
	*/
	virtual void jump(float force);

	
	
public:


	/*!
	\brief trigger sprite at the postion
	*/
	virtual void trigger(Ogre::Vector3 at){};

	/*!
	\brief when accept a attack power, decrease sprite's health
	*/
	virtual void decreaseHealth(float power);

	/*!
	\brief increase sprite's health
	*/
	virtual void increaseHealth(float power);

	/*!
	\brief set initial health and current health 
	*/
	virtual void setInitHealth(float health){
		mInitHealth = health;
		mHealth = health;
	};
	/*!
	\brief set current health
	*/
	virtual void setHealth(float health){mHealth = health;};
	/*!
	\brief get health 
	*/
	virtual float getHealth(){return mHealth;};

	/*!
	\brief set alive 
	*/
	virtual void setAlive(bool b);
	/*!
	\brief get alive 
	*/
	virtual bool isAlive(){return mAlive;};

public://animation
	/*!
	\brief set animation for sprite
	*/
	virtual void setAnimation(Ogre::String name, bool loop = true);
	/*!
	\brief print all animation name for an entity
	*/
	void printAllAnimationName();
	/*!
	\brief test if the entity has animation
	*/
	bool hasAnimation();

	/*!
	\brief test if the entity has the animation name
	*/
	bool hasAnimationName(Ogre::String name);

	/*!
	\brief disable all animation
	*/
	void disableAllAnimation();

public:
	Stage* mStage;
	SceneNode* mSceneNode;
	AnimationState *mAnimationState;
	Entity* mEntity;
	//Ogre::Camera* mCamera;
	std::vector<Ogre::Vector3> moveList;
	Ogre::Vector3 targetPosition;
public:
	Ogre::Vector3 mInitDirection;
	Ogre::Vector3 mInitVelocity;
	Ogre::Vector3 mInitPosition;

	//jump
	float mInitJumpForce;
	float mJumpTimePassed;
	float mJumpForce;//跳起來的力量

	Ogre::Vector3 mDirection;
	Ogre::Vector3 mQuaternion;
	Ogre::Vector3 mEyePosition;
	Ogre::Vector3 mVelocity;
	float mVision;//sprite的警戒範圍
	Real mTime;
	Real mLifeTime;
	bool mAlive;
	bool mIsFly;//是否會飛，如飛機、鳥
	Vector3 mOffset;
	float mInitHealth;
	float mHealth;
	float mInitLevel;
	float mLevel;
	float mTowerTime;//sprite在塔下幾秒鐘
	float ATTime;//該sprite不會損血的時間
	int mActionMode;
	//Agent* agent; //大腦=>選擇goal，會做goal test=>然後選擇下一個goal，在行動中會檢查是否有突發突況=>priority queue and action queue

};






#endif