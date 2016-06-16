#include "GameEngine.h"
#include "Stage.h"

using namespace buttonGUI;
void GameEngine::setupButtons(){
	buttonGUI::textScheme vip("vipond",20, 0,1,0,1);  //here, i declare a simple textscheme to start with.  (just make it green all the time)

	buttonGUI::textScheme t("neuropol",22, 1,1,1,1);			//for this textscheme i will be a little more specific and specify different colors for some of the events and gradients for each.
		t.cMouseOver.cTop = Ogre::ColourValue( 1, 1 ,1, 1);
		t.cMouseOver.cBottom = Ogre::ColourValue( .5, 1 ,.5, 1);
		t.cMouseOff.cTop = Ogre::ColourValue( 1, 1 ,1, 1);
		t.cMouseOff.cBottom = Ogre::ColourValue( 0, .2 ,1, 1);
		t.cOnRelease.cTop = Ogre::ColourValue( 0, 1,1, 1);
		t.cOnRelease.cBottom = Ogre::ColourValue( 0, .5 ,.5, 1);

	// Create the buttonManager to make our buttons
	mButtonMgr = new buttonGUI::buttonManager("darkInput",t, mSceneMgr,"MainCam");	//"darkInput" wil be the default textInputArea material... however if you have exceptions you can specify directly in createTextInputArea function override (or change the default with mButtonMgr->setDefaults())

	//setup the cursor
	mButtonMgr->setCursor("cursorMat1", 32, 32, 3,3)->addTextArea("one", "", 15,8, TextAreaOverlayElement::Left);
	
	mButtonMgr->createButton("smoothRed1", "smoothRedMat", buttonPosition(TOP_RIGHT,10,5), 100, 35)->
		setMovable(false)->
		addTextArea("three", "START", 15,8, TextAreaOverlayElement::Left);  
	mButtonMgr->createButton("smoothRed2", "smoothRedMat", buttonPosition(TOP_RIGHT,10,40), 100, 35)->
		setMovable(false)->
		addTextArea("two", "EXIT", 30,8, TextAreaOverlayElement::Left);  
}


