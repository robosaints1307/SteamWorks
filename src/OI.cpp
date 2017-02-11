#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "Commands/Climb.h"

OI::OI()
{
	// Process operator interface input here.
	lStick = new frc::Joystick(L_Stick);
	rStick = new frc::Joystick(R_Stick);
	climbButton = new JoystickButton(lStick, Button1);

	climbButton -> WhileHeld(new Climb());



}
frc::Joystick* OI::GetLStick(){
	return lStick;

}

frc::Joystick* OI::GetRStick(){
	return rStick;
}

