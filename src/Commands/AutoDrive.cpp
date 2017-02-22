#include "AutoDrive.h"

AutoDrive::AutoDrive(double distance, float spd) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);
	dist = distance;
	speed = spd;
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
	driveTrain->AutoDrive(dist*one_inch, speed);
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	return driveTrain->OnTarget();
}

// Called once after isFinished returns true
void AutoDrive::End() {
	driveTrain->Stop();
	driveTrain->Disable(); //disables PID loop
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {

}
