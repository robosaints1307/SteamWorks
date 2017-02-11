#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	Joystick *lStick;
	Joystick *rStick;

public:
	OI();

	Joystick* GetLStick();
	Joystick* GetRStick();
	Button* climbButton;

};

#endif
