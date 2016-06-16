/**
 * @brief 3D Game Programming<br>
 * My Name: ±i´º·Ó Chang, Ching-Chao<br>
 * My ID: 9857515<br>
 * My Email: dorgonman@hotmail.com
 *
 * Modified by Chang, Ching-Chao to support chinese and color appearance
 * original: http://www.ogre3d.org/tikiwiki/Printf+with+ogre&structure=Cookbook
 *
*/


#ifndef SCREEN_TEXT_H
   #define SCREEN_TEXT_H
   namespace Ogre
   {
      class TextAreaOverlayElement;
   }
   class ScreenText
   {
   public:
       ScreenText();
       void init(char* fontName);
       // Print at <x/y>
       void print(float x, float y, const wchar_t*, ...);
       void print(float x, float y, float size, const wchar_t*, ...);
       // Begin printing at a certain coordinate
       void beginPrint(float x, float y, float size);
       // Continue printing (started with beginPrint). Each print will start in a new line.
       void print(const wchar_t*, ...);
       // Call this at the start of each frame
       void frameStarted();
       // Call this at the end of each frame before it is rendered!
       void update();

	   void setColour(Ogre::ColourValue col){mColour = col;};
   private:
       struct Entry
       {
          Entry()
          {
             mX = 0;
             mY = 0;
             mSize = 1.0f;
          }
          float mX;
          float mY;
          float mSize;
          std::wstring mString;
		  Ogre::ColourValue mColour;
       };
       typedef std::vector<Entry> Strings;
       Strings mStrings;
       Overlay* mOverlay;
       OverlayContainer* mPanel;
	   Ogre::ColourValue mColour;
       enum { MAX_TEXT_AREAS = 50 };
       TextAreaOverlayElement* mTextAreas[MAX_TEXT_AREAS];
       struct Context
       {
          Context();
          float mX;
          float mY;
          float mSize;
       } mContext;
   };
   extern ScreenText gScreenText;
#endif // !SCREEN_TEXT_H