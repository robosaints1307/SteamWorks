#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"

OI::OI()
{
	// Process operator interface input here.
	lStick = new frc::Joystick(L_Stick);
	rStick = new frc::Joystick(R_Stick);
	joy = new Joystick(1);

	JoystickButton* button1 = new JoystickButton(joy, 1);
}
frc::Joystick* OI::GetLStick(){
	return lStick;

}

frc::Joystick* OI::GetRStick(){
	return rStick;
}
