#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"

OI::OI()
{
	// Process operator interface input here.
	lStick = new frc::Joystick(L_Stick);
	rStick = new frc::Joystick(R_Stick);
}
frc::Joystick* OI::GetLStick(){
	return lStick;

}

frc::Joystick* OI::GetRStick(){
	return rStick;
}

