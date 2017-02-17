#include "../RobotMap.h"
#include "Gyro.h"
#include "WPILib.h"
#include "ADXRS450_Gyro.h"

using namespace frc;


Gyro::Gyro()
:	Subsystem("Gyro")
{


}

void Gyro::InitDefaultCommand()
{

	SmartDashboard::PutNumber("GetAngle", Gyro::GetAngle());
	robotDrive (1,2),
	Gyro(1);
	{
		robotDrive::SetExpiration(0.1);
	}


	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
