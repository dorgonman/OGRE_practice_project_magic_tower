#include <tchar.h>
   #include <assert.h>
   #include <stdlib.h>
   #include <iostream>
   #include <vector>
   #include <string>
   #include "Ogre.h"
   using namespace Ogre;
   #define WIN32_LEAN_AND_MEAN   
   #define _WIN32_WINNT 0x0501
   #include <windows.h> 
   #include "ScreenText.h"
   #include "OgreTextAreaOverlayElement.h"
   static float DEFAULT_SIZE = 0.03f;
   ScreenText gScreenText;
   //------------------------------------------------------------------------------
   ScreenText::ScreenText()
   //------------------------------------------------------------------------------
   {
      mPanel = 0;
      mOverlay = 0;
      memset(mTextAreas, 0, MAX_TEXT_AREAS*sizeof(TextAreaOverlayElement*));
   }
   //------------------------------------------------------------------------------
   void ScreenText::init(char* fontName)
   //------------------------------------------------------------------------------
   {
      // Create a panel
      mPanel = static_cast<OverlayContainer*>(
         OverlayManager::getSingleton().createOverlayElement("Panel", "PanelName"));
      mPanel->setMetricsMode(Ogre::GMM_RELATIVE);
      mPanel->setPosition(0, 0);
      mPanel->setDimensions(1.0f, 1.0f);
      //panel->setMaterialName("MaterialName"); // Optional background material
      for (int i = 0; i<MAX_TEXT_AREAS; ++i)
      {
         mTextAreas[i] = static_cast<TextAreaOverlayElement*>(
            OverlayManager::getSingleton().createOverlayElement("TextArea",           StringConverter::toString(i) + "TextAreaName"));
         mTextAreas[i]->setMetricsMode(Ogre::GMM_RELATIVE);
         mTextAreas[i]->setFontName(fontName);

         mTextAreas[i]->setColourBottom(ColourValue(1,1,1));
         mTextAreas[i]->setColourTop(ColourValue(1,1,1));
         mTextAreas[i]->setDimensions(1.0f, 1.0f);
         mPanel->addChild(mTextAreas[i]);
      }
      mOverlay = OverlayManager::getSingleton().create("ScreenText");
      mOverlay->add2D(mPanel);
     // Show the overlay
      mOverlay->show();
   }
   //------------------------------------------------------------------------------
   void ScreenText::frameStarted()
   //------------------------------------------------------------------------------
   {
      mStrings.clear();
      for (int i = 0; i<MAX_TEXT_AREAS; ++i)
      {
         mTextAreas[i]->hide();
      }
   }
   //------------------------------------------------------------------------------
   void ScreenText::update()
   //------------------------------------------------------------------------------
   {
      int count = 0;
      for (Strings::iterator i = mStrings.begin(); i!=mStrings.end() && count < MAX_TEXT_AREAS; ++i)
      {
         Entry& entry = *i;
         mTextAreas[count]->setPosition(entry.mX, entry.mY);
         mTextAreas[count]->setCaption(entry.mString.c_str());
         mTextAreas[count]->setCharHeight(DEFAULT_SIZE*entry.mSize);
		 mTextAreas[count]->setColour(entry.mColour);
         mTextAreas[count]->show();
         ++count;
         assert(count < MAX_TEXT_AREAS);
      }   
   }
   namespace
   {
      //------------------------------------------------------------------------------
      const wchar_t* vprint(const wchar_t* format, va_list args)
      //------------------------------------------------------------------------------
      {
         static const int BUFFER_SIZE = 200;
         static wchar_t buffer[BUFFER_SIZE];
         int size = _vscwprintf(format, args);

         assert(size < BUFFER_SIZE);
         vswprintf(buffer, BUFFER_SIZE, format, args);
		
		// ::vswprintf
         return buffer;
      }
   }
   //------------------------------------------------------------------------------
   void ScreenText::print(float x, float y, const wchar_t* format, ...)
   //------------------------------------------------------------------------------
   {
      Entry entry;
      entry.mX = x;
      entry.mY = y;
	  entry.mColour = mColour;
      va_list args;
      va_start( args, format );   
      entry.mString = vprint(format, args);
      va_end( args );   
      mStrings.push_back(entry);
	  update();
   }
   //------------------------------------------------------------------------------
   void ScreenText::print(float x, float y, float size, const wchar_t* format, ...)
   //------------------------------------------------------------------------------
   {
      Entry entry;
      entry.mX = x;
      entry.mY = y;
      entry.mSize = size;
	  entry.mColour = mColour;
      va_list args;
      va_start( args, format );   
      entry.mString = vprint(format, args);
      va_end( args );   
      mStrings.push_back(entry);
	   update();
   }
   //------------------------------------------------------------------------------
   ScreenText::Context::Context()
   //------------------------------------------------------------------------------
   {
      mX = 0.0f;
      mY = 0.0f;
      mSize = 1.0f;
   }
   //------------------------------------------------------------------------------
   void ScreenText::beginPrint(float x, float y, float size)
   //------------------------------------------------------------------------------
   {
      mContext.mX = x;
      mContext.mY = y;
      mContext.mSize = size;
   }
   //------------------------------------------------------------------------------
   void ScreenText::print(const wchar_t* format, ...)
   //------------------------------------------------------------------------------
   {
      Entry entry;
      entry.mX = mContext.mX;
      entry.mY = mContext.mY;
      entry.mSize = mContext.mSize;
	  entry.mColour = mColour;
      mContext.mY += mContext.mSize*DEFAULT_SIZE;
      va_list args;
      va_start( args, format );   
      entry.mString = vprint(format, args);
      va_end( args );   
      mStrings.push_back(entry);
	   update();
   }