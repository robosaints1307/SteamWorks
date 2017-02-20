#include "Drive.h"
#include "RobotMap.h"
#include "Robot.h"
#include "OI.h"


Drive::Drive(): CommandBase("Drive"){

	Requires(driveTrain);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void Drive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute()
{
	driveTrain->DriveWithJoystick(Robot::oi->GetStick());
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Drive::End()
{
	driveTrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted()
{

}
