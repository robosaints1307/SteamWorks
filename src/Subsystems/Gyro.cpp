#include "Gyro.h"
#include "../RobotMap.h"

using namespace frc;


Gyro::Gyro(): Subsystem("Gyro") {


}


}

void Gyro::InitDefaultCommand()
{

	SmartDashboard::PutData("GetAngle", gyro.GetAngle());

	IterativeRobot (1,2),
	gyro(1)
	{
		IterativeRobot.SetExpiration(0.1);
	}


	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
