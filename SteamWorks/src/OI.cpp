#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "Commands/Climb.h"
//#include "Commands/Direction.h"

using namespace frc;
OI::OI()
{
	// Process operator interface input here.
	Stick = new Joystick(stick);

	//reverseButton = new JoystickButton(Stick, Reverse_Button);

	climbButton = new JoystickButton(Stick, Button1);
//	climbButton->WhenPressed(new Climb());
	climbButton->WhileHeld(new Climb());

	//reverseButton->WhileHeld(new Direction());



}
frc::Joystick* OI::GetStick(){
	return Stick;

}




