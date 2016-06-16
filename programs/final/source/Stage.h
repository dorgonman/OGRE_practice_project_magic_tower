

#ifndef __Stage_h_
#define __Stage_h_

#include "BasicHeader.h"
#include "Stdlib.h"
#include "Sprite3D.h"
#include "Monster3D.h"
#include "Player3D.h"
#include "SelectionRectangle.h"
#include "fader.h"
#include "map_reader.h"
#include "ParticleManager.h"
#include "WeaponManager.h"
#include "SpriteManager.h"
#include "GameParameter.h"
#include "digit_string_dialogue.h"
#include "bar2D.h"
#include "ScreenText.h"
#include "sound.h"
#include "AudioManager.h"
#include "AIEngine.h"
#include "BasicTool.h"
#include "iostream"
#include <time.h>  //for time()
#include <stdlib.h>  //for rand()




using namespace std;
using namespace Ogre;
class GameEngine;

#define INF 99999999999999
#define rand_number(low,high) rand()%((high)-(low)+1)+(low);

namespace OIS{
	#define KC_LENTER 28
	#define KC_RENTER 156
}
/**
 * @brief 3D Game Programming<br>
 * My Name: 張景照 Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class handle for different stage resource manage and gameplay script issue
 *
*/
class Stage{
public:
	
	/*!
	\brief constructor of stage
	*/
	Stage(GameEngine* engine);
	~Stage();
public:

	/*!
	\brief entry for Stage
	*/
	bool doScript(const Ogre::FrameEvent &evt);
	

	/*!
	\brief enum script mode, every stage have four script mode:Loading, Battle, Story, and Finish.<br>
	initialize doesn't do any thing.
	*/
	enum eScriptMode{
		SM_INITIALIZE,
		SM_LOADING,
		SM_BATTLE,
		SM_GAME_OVER,
		SM_GAME_WIN,
		SM_STORY,
		SM_FINISH
	};
	/*!
	\brief enum script mode, every stage have four script mode:Loading, Battle, Story, and Finish.<br>
	initialize doesn't do any thing.
	*/
	enum eViewMode{
		VM_FPS,//first person shooting
		VM_TPS,//third person shooting
	};


	enum eWeaponMode{
		NWAY3,//first person shooting
		TRACE,//third person shooting
	};


protected:
	/*!
	\brief do loading script
	ex:create scene, camera...
	*/
	virtual bool doLoadingScript();
	/*!
	\brief do battle script
	ex:execute any game rule or AI
	*/
	virtual bool doBattleScript();
	/*!
	\brief do story script
	ex:full script control, don't enable any game rule or AI
	*/
	virtual bool doStoryScript();
	/*!
	\brief do finish script
	ex:release resource and assign script for next stage
	*/
	virtual bool doFinishScript();

protected:
	/*!
	\brief do game over script
	*/
	virtual bool doGameOverScript();

	/*!
	\brief do game win script
	*/
	virtual bool doGameWinScript();



protected:
	protected:
	/*!
	\brief create scene manager
	*/
	virtual void chooseScene();
	/*!
	\brief create camera
	*/
	virtual void createCamera();
	/*!
	\brief create view port
	*/
	virtual void createViewPort();
	/*!
	\brief create object that will appear in scene
	ex: attach scene node to entity
	*/
	virtual void createScene();

protected:
	/*!
	\brief load resource
	*/
	virtual void loadResource();
	/*!
	\brief load particle effect
	*/
	virtual void loadParticle();
	/*!
	\brief load monsters
	*/
	virtual void loadMonster();

	/*!
	\brief load player
	*/
	virtual void loadPlayer();

	/*!
	\brief load overlay
	*/
	virtual void loadOverlay();

public:
	// OIS::KeyListener
	/*!
	\brief hand on key pressed event
	*/
	virtual bool keyPressed( const OIS::KeyEvent &arg );
	/*!
	\brief hand on key released event
	*/
	virtual bool keyReleased( const OIS::KeyEvent &arg );
	/*!
	\brief hand on key down event(hold on a key not release)
	*/
	virtual bool keyDown();
    // OIS::MouseListener
	/*!
	\brief hand on mouse moved event
	*/
	virtual bool mouseMoved( const OIS::MouseEvent &arg );
	/*!
	\brief hand on mouse pressed event
	*/
	virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
	/*!
	\brief hand on mouse released event
	*/
	virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
public://collision detection
	/*!
	\brief test if a position p hit terrain
	*/
	bool projectScenePointOntoTerrain_PosDirection(Ogre::Vector3 &p);
	/*!
	\brief test if a position p escape from terrain to sky
	*/
	bool projectScenePointOntoTerrain_NegDirection(Ogre::Vector3 &p);
public://util
	virtual bool exist(Ogre::Vector3 v, std::vector<Ogre::Vector3> vecArr);
	/*!
	\brief increase stage mTime with delta time step
	*/
	virtual void addTime(double deltaTimeStep);

private://遊戲規則相關
	virtual void gameRule();
	virtual void gameOverRule();
	virtual void monsterHittedRule();
	virtual void playerHittedRule();
	virtual void towerRelateRule();
	virtual void showInformation();




public://stage stage machine
		int mScriptMode; //!< which script we want to execute
		int mViewMode; //!< which script we want to execute
		int mWeaponMode;
public://manager
	GameEngine *mEngine;  //!< Entry for Game Engine, in order to access attribute of tutorial framework
    Ogre::SceneManager* mSceneMgr; //!< Stage Scene Manager
	Ogre::FrameEvent evt; //!< keep the information of frame event

public:
	Ogre::Vector3 mGravity;
	bool mGameOver;
	bool mGameWin;
	double mTime;

public://各別關卡要自己處理的物件
	Player3D* mPlayerSpr;
	Sprite3D* mTowerSpr;
	BAR_2D *mPlayerHPBar2D;
	BAR_2D *mTowerHPBar2D;
	ParticleManager* mParticleMgr;
	Ogre::Vector3 mViewOffset;
	WeaponManager* mPlayerWeaponMgr;
	WeaponManager* mMonsterWeaponMgr;
	SpriteManager* mMonsterMgr;
	AIEngine* mAIEng;
	//std::vector<Sprite3D*> mMonsterArr;
protected:
	OverlayElement* mWeaponPicture;
	Overlay* mWeaponOverlay;

};








/**
 * @brief 3D Game Programming<br>
 * My Name: Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class is extend from stage that override some function for game title
 *
*/

class Title :public Stage{
public:
	/*!
	\brief constructor of stage
	*/
	Title(GameEngine* engine): Stage(engine){};
	/*!
	\brief deconstructor of stage
	*/
	~Title(){};
protected:
	/*!
	\brief do loading script
	ex:create scene, camera...
	*/
	virtual bool doLoadingScript();
	/*!
	\brief do battle script
	ex:execute any game rule or AI
	*/
	virtual bool doBattleScript();
	/*!
	\brief do story script
	ex:full script control, don't enable any game rule or AI
	*/
	virtual bool doStoryScript();
	/*!
	\brief do finish script
	ex:release resource and assign script for next stage
	*/
	virtual bool doFinishScript();
protected:
	/*!
	\brief create scene manager
	*/
	virtual void chooseScene();
	/*!
	\brief create object that will appear in scene
	ex: attach scene node to entity
	*/
	virtual void createScene();

protected:
	OverlayElement* mPicture;
	Overlay* mOverlay;
};


/**
 * @brief 3D Game Programming<br>
 * My Name: Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class is extend from stage that override some function for introduce game story
 *
*/

class Introduction :public Stage{
public:
	/*!
	\brief constructor of stage
	*/
	Introduction(GameEngine* engine): Stage(engine){};
	/*!
	\brief deconstructor of stage
	*/
	~Introduction(){};
protected:
	/*!
	\brief do loading script
	ex:create scene, camera...
	*/
	virtual bool doLoadingScript();
	/*!
	\brief do battle script
	ex:execute any game rule or AI
	*/
	virtual bool doBattleScript();
	/*!
	\brief do story script
	ex:full script control, don't enable any game rule or AI
	*/
	virtual bool doStoryScript();
	/*!
	\brief do finish script
	ex:release resource and assign script for next stage
	*/
	virtual bool doFinishScript();
protected:
	/*!
	\brief create scene manager
	*/
	virtual void chooseScene();
	/*!
	\brief create object that will appear in scene
	ex: attach scene node to entity
	*/
	virtual void createScene();
protected:
	OverlayElement* mPicture;
	Overlay* mOverlay;

};








/**
 * @brief 3D Game Programming<br>
 * My Name: Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class is extend from stage that override some function for create a specific stage
 *
*/

class Stage1 :public Stage{
public:
	/*!
	\brief constructor of stage
	*/
	Stage1(GameEngine* engine): Stage(engine){};
	/*!
	\brief deconstructor of stage
	*/
	~Stage1(){};
protected:
	/*!
	\brief do loading script
	ex:create scene, camera...
	*/
	virtual bool doLoadingScript();
	/*!
	\brief do battle script
	ex:execute any game rule or AI
	*/
	virtual bool doBattleScript();
	/*!
	\brief do story script
	ex:full script control, don't enable any game rule or AI
	*/
	virtual bool doStoryScript();
	/*!
	\brief do finish script
	ex:release resource and assign script for next stage
	*/
	virtual bool doFinishScript();

	/*!
	\brief do game win script
	*/
	virtual bool doGameWinScript();

protected:
	/*!
	\brief create scene manager
	*/
	virtual void chooseScene();
	/*!
	\brief create camera
	*/
	virtual void createCamera();
	/*!
	\brief create view port
	*/
	virtual void createViewPort();
	/*!
	\brief create object that will appear in scene
	ex: attach scene node to entity
	*/
	virtual void createScene();

	/*!
	\brief hand on key pressed event
	*/
	virtual bool keyPressed( const OIS::KeyEvent &arg );

private:
	void environment();
	void setEvent1();
	void doEvent1();
	void setEvent2();
	void doEvent2();
	void setEvent3();
	void doEvent3();
	void setEvent4();
	void doEvent4();
	void setEvent5();
	void doEvent5();
	void setEvent6();
	void doEvent6();

	//=================boss===============
	void setEvent7();
	void doEvent7();
	void setEvent8();
	void doEvent8();
	void setEvent9();
	void doEvent9();
	void doEvent10();
	void doEvent11();





};



class Stage2 :public Stage{
public:
	/*!
	\brief constructor of stage
	*/
	Stage2(GameEngine* engine): Stage(engine){};
	/*!
	\brief deconstructor of stage
	*/
	~Stage2(){};
protected:
	/*!
	\brief do loading script
	ex:create scene, camera...
	*/
	virtual bool doLoadingScript();
	/*!
	\brief do battle script
	ex:execute any game rule or AI
	*/
	virtual bool doBattleScript();
	/*!
	\brief do story script
	ex:full script control, don't enable any game rule or AI
	*/
	virtual bool doStoryScript();
	/*!
	\brief do finish script
	ex:release resource and assign script for next stage
	*/
	virtual bool doFinishScript();


	/*!
	\brief do game win script
	*/
	virtual bool doGameWinScript();
protected:
	/*!
	\brief create scene manager
	*/
	virtual void chooseScene();
	/*!
	\brief create camera
	*/
	virtual void createCamera();
	/*!
	\brief create view port
	*/
	virtual void createViewPort();
	/*!
	\brief create object that will appear in scene
	ex: attach scene node to entity
	*/
	virtual void createScene();


private:
	void environment();
	void setEvent1();
	void doEvent1();
	void setEvent2();
	void doEvent2();
	void setEvent3();
	void doEvent3();
	void setEvent4();
	void doEvent4();
	void setEvent5();
	void doEvent5();
	void setEvent6();
	void doEvent6();
	void setEvent7();
	void doEvent7();

	//=================boss===============
	void setEvent8();
	void doEvent8();
	void doEvent9();
	void doEvent10();
};


//==================================




class Stage3 :public Stage{
public:
	/*!
	\brief constructor of stage
	*/
	Stage3(GameEngine* engine): Stage(engine){};
	/*!
	\brief deconstructor of stage
	*/
	~Stage3(){};
protected:
	/*!
	\brief do loading script
	ex:create scene, camera...
	*/
	virtual bool doLoadingScript();
	/*!
	\brief do battle script
	ex:execute any game rule or AI
	*/
	virtual bool doBattleScript();
	/*!
	\brief do story script
	ex:full script control, don't enable any game rule or AI
	*/
	virtual bool doStoryScript();
	/*!
	\brief do finish script
	ex:release resource and assign script for next stage
	*/
	virtual bool doFinishScript();


	/*!
	\brief do game win script
	*/
	virtual bool doGameWinScript();
protected:
	/*!
	\brief create scene manager
	*/
	virtual void chooseScene();
	/*!
	\brief create camera
	*/
	virtual void createCamera();
	/*!
	\brief create view port
	*/
	virtual void createViewPort();
	/*!
	\brief create object that will appear in scene
	ex: attach scene node to entity
	*/
	virtual void createScene();


private:
	void environment();
	void setEvent1();
	void doEvent1();
	void setEvent2();
	void doEvent2();
	void setEvent3();
	void doEvent3();
	void setEvent4();
	void doEvent4();
	void setEvent5();
	void doEvent5();
	void setEvent6();
	void doEvent6();
	void setEvent7();
	void doEvent7();
	void setEvent8();
	void doEvent8();
	void setEvent9();
	void doEvent9();
	//=================boss===============
	void setEvent10();
	void doEvent10();
	void doEvent11();




};






#endif