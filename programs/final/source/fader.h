/*
This is a game demo written by Wingo Sai-Keung Wong.
OGRE is employed for graphics rendering.
CEGUI is employed for GUI.
Date: Dec 2006 - 2009
Email: wingo.wong@gmail.com

All rights reserved. 2009
*/
#ifndef __FADER_H__
#define __FADER_H__
#include "Ogre.h"
#include "OgreStringConverter.h"
#include "OgreException.h"
#include "OgreMaterialManager.h"
#include "OgreOverlayManager.h"
#include "OgreTechnique.h"
#include "OgreBlendMode.h"
#include "OgreOverlay.h"

using namespace Ogre;

class FADER
{
public:
	FADER(const String &OverlayName, const String &InstanceName, const String &MaterialName);
	~FADER(void);

	void startFadeIn(double duration = 1.0f, double targetAlpha = 0.0f, double startAlpha = 1.0f);
	void startFadeOut(double duration = 1.0f, double targetAlpha = 1.0f, double startAlpha = 0.0f);
	bool fade(double time_step);
	//bool isFadeFinish();
	void hide();

protected:
	double mTargetAlpha;
	double mAlpha;
	double mCurrent_duration;
	double mTotal_duration;
	Overlay *mOverlay;

	enum FADEOP {
		FADE_NONE,
		FADE_IN,
		FADE_OUT,
	} mFadeop;
};

#endif