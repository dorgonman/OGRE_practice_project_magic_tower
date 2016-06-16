/*
This is a game demo written by Wingo Sai-Keung Wong.
OGRE is employed for graphics rendering.
CEGUI is employed for GUI.
Date: Dec 2006 - 2009
Email: wingo.wong@gmail.com

All rights reserved. 2009
*/
#include "fader.h"

using namespace Ogre;
FADER::FADER(const String &a_OverlayName, const String &a_InstanceName, const String &a_MaterialName)
{
	mFadeop = FADE_NONE;
	mAlpha = 0.0;
	mOverlay = OverlayManager::getSingleton().create(a_OverlayName);
	mOverlay->setZOrder(10);
	OverlayElement *e = OverlayManager::getSingleton().createOverlayElement("Panel", a_InstanceName);
	OverlayContainer *c = dynamic_cast<OverlayContainer*>(e);
	e->setMaterialName(a_MaterialName);
	e->setDimensions(1, 1);
	e->setPosition(0, 0.0);
	e->setEnabled(true);
	e->setMetricsMode(GMM_RELATIVE);
	mOverlay->add2D(c);
	mTargetAlpha = 1.0;
}

FADER::~FADER(void)
{
}

void FADER::startFadeIn(double duration, double targetAlpha, double startAlpha)
{
	if( duration < 0 )
		duration = -duration;
	if( duration < 0.000001 )//frame rate沒那麼低
		duration = 1.0;
	mTargetAlpha = targetAlpha;
	mAlpha = startAlpha;
	mTotal_duration = duration;
	mCurrent_duration = duration;
	mFadeop = FADE_IN;

}

void FADER::startFadeOut(double duration, double targetAlpha, double startAlpha)
{
	if( duration < 0 )
		duration = -duration;
	if( duration < 0.000001 )
		duration = 1.0;
	mTargetAlpha = targetAlpha;
	mAlpha = startAlpha;
	mTotal_duration = duration;
	mCurrent_duration = 0.0;
	mFadeop = FADE_OUT;

}

bool FADER::fade(double time_step)
{
	bool result = true;


	
	if( mFadeop != FADE_NONE )
	{
		using namespace std;

		mOverlay->show();

		Overlay::Overlay2DElementsIterator it = mOverlay->get2DElementsIterator();

		while (it.hasMoreElements()) {


			OverlayContainer* cont = it.getNext();
			if (cont == NULL) break;

			String mname;
			mname = cont->getMaterialName();

			ResourcePtr resptr = Ogre::MaterialManager::getSingleton().getByName(mname);
			Material * mat = dynamic_cast<Ogre::Material*>(resptr.getPointer());

			Technique *tech = mat->getTechnique(0);
			Pass *pass = tech->getPass(0);			
			TextureUnitState *tex_unit = pass->getTextureUnitState(0);
			tex_unit->setAlphaOperation(LBX_MODULATE, LBS_MANUAL, LBS_TEXTURE, mAlpha);
		}

		if( mFadeop == FADE_IN )
		{
			mCurrent_duration -= time_step;
			mAlpha = mCurrent_duration / mTotal_duration;
			if( mAlpha < mTargetAlpha )
			{
				mOverlay->hide();
				mFadeop = FADE_NONE;

			}
			if(mCurrent_duration >= 0){
				//std::cout << mCurrent_duration << std::endl;
				result = true;
			}else{
				result = false;//結束
			}
		}


		else if( mFadeop == FADE_OUT )
		{
			mCurrent_duration += time_step;
			mAlpha = mCurrent_duration / mTotal_duration;
			if( mAlpha > mTargetAlpha )
			{
				mFadeop = FADE_NONE;

			}
		}
	}
	return result;
}



void FADER::hide(){
	mOverlay->hide();
}