#include "GameEngine.h"
#include "Stage.h"

using namespace buttonGUI;



GameEngine::eButton GameEngine::handleButtonEvent(buttonGUI::buttonEvent * e){
	Ogre::UTFString m;
	std::string name; 
	if (e->actionButton)
		name = *(e->actionButton->getName()) ;  //store the name of the main button.
	else
		name = "nothing.";

	if (e->action == KEYACCEPTED)
		m = name + " Accepted key: " + e->additionalData;
	else if (e->action == KEYREJECTED)
		m = name + " Rejected key: " + e->additionalData;	
	else if (e->action == ONCLICK)
		m = "User clicked on: " + name;
	else if (e->action == ONRELEASE)
	{
		if (e->droppedButton)
			m = "User dropped " +*(e->droppedButton->getName()) + " onto " + name;
		else
			m = "User released mouse on: " + name;
	}
	else if (e->action == MOUSEOFF)
		m = "Mouse off: " + name;
	else if (e->action == MOUSEOVER)
		m = "Mouse over: " + name;
	else if (e->action == MOUSEWHEELUP)
		m = "Mouse wheel up on: " + name;
	else if (e->action == MOUSEWHEELDOWN)
		m = "Mouse wheel down on: " + name;
	else if (e->action == ONSUBMIT)
		m = name + " Submitted text: " + e->additionalData;

						//Ogre::LogManager::getSingleton().logMessage(m);				//print out the events to the console.							
						//mButtonMgr->getButton("bg")->editTextArea("eventText", m);	//print out the events in the eventText
		//handle button actions...
		if (e->action == ONCLICK)	//we could just as well have things happen on other events too such as onRelease or mouseOver,  but i will just keep it simple on the demo.
		{
			//redbutton
			if (name == "smoothRed1")
				return eButton::START;
			else if (name == "smoothRed2")
				return eButton::EXIT;
		}

		return eButton::NO_ACTION;
}
