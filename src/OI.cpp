#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"

OI::OI()
{
	// Process operator interface input here.
	lStick = new Joystick(L_Stick);
	rStick = new Joystick(R_Stick);
}
Joystick* OI::GetLStick(){
	return lStick;

}

Joystick* OI::GetRStick(){
	return rStick;
}

