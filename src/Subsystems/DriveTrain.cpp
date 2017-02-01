#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

DriveTrain::DriveTrain()
	:	Subsystem("DriveTrain")
{
  robotDrive = new RobotDrive(F_R_Motor, B_R_Motor, F_L_Motor, B_L_Motor);
  robotDrive -> SetSensitivity(0.75);
  robotDrive -> SetMaxOutput(1.0);
}

void DriveTrain::InitDefaultCommand(){
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
	void DriveTrain::Drivewithjoystick(Joystick* lStick, Joystick* rStick){

	robotDrive->TankDrive(lStick, rStick);

}
