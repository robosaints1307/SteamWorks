#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	Joystick *Stick;
	//JoystickButton *reverseButton;

public:
	OI();

	Joystick* GetStick();
	Button* climbButton;

};

#endif
