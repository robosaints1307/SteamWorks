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
	Button* climbButton;
	Joystick* GetRStick();

};

#endif
