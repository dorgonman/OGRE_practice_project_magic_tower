#ifndef __GameEngine_h_
#define __GameEngine_h_

#include "BaseApplication.h"
#include "vector"
#include "Stage.h"
#include "buttonGUI.h"
/**
 * @brief 3D Game Programming<br>
 * My Name: 張景照 Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * This class extend tutorial framework and handle the entry of our stage script entry
 *
*/
class GameEngine : public BaseApplication{
public:
	enum eButton{
		NO_ACTION,
		START,
		EXIT
	};
public:
	GameEngine(void);
	~GameEngine();

public:
	/*!
	\brief set if we want to use default camera man input
	*/
	void enableDefaultInput(bool b){mDefaultInputEnable = b;};
protected:
	/*!
	\brief create default scene 
	*/
	virtual void createScene(void);
	/*!
	\brief only execute current stage script
	*/
	virtual bool frameStarted(const Ogre::FrameEvent& evt);
public:
	// OIS::KeyListener
	/*!
	\brief key pressed event, dispatch to Stage
	*/
    virtual bool keyPressed( const OIS::KeyEvent &arg );
	/*!
	\brief key released event, dispatch to Stage
	*/
    virtual bool keyReleased( const OIS::KeyEvent &arg );
    // OIS::MouseListener
	/*!
	\brief mouse moved event, dispatch to Stage
	*/
    virtual bool mouseMoved( const OIS::MouseEvent &arg );
	/*!
	\brief mouse pressed event, dispatch to Stage
	*/
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
	/*!
	\brief mouse released event, dispatch to Stage
	*/
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

private:
	/*!
	\brief preload sounds that are needed in game
	*/
	virtual void loadSound();

	/*!
	\brief preload overlay that are needed in game
	*/
	virtual void loadOverlay();
public:
	void setupButtons();
	eButton handleButtonEvent(buttonGUI::buttonEvent * e);

public:
	float mTotalScore;//玩家在遊戲中獲得的分數
	Stage* currentStage; //!< current Stage entry for execute stage script
	std::vector<Stage*> mStages;//!< keep all stage entry
	bool mDefaultInputEnable;
	std::map<String, FADER*> mFaderMap;
	std::map<String, Overlay*> mOverlayMap;
	AudioManager* mAudioMgr;
	buttonGUI::buttonManager* mButtonMgr;
};
 
#endif 