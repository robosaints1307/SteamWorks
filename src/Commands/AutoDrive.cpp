#include "AutoDrive.h"

AutoDrive::AutoDrive(double distance) { //1 = 1/2in
	Requires(driveTrain);
	pid = new PIDController(0.5, 0.025, 0.0, new AutoDrivePIDSource(), new AutoDrivePIDOutput());
	pid->SetPercentTolerance(5);
	pid->SetContinuous(false);
	pid->SetSetpoint(distance);
	// Change this to be speed and pass speed in the constructor!
	pid->SetOutputRange(-0.5, 0.5);
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
	driveTrain->Reset();
	pid->Reset();
	pid->Enable();
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	return pid->OnTarget();
}

// Called once after isFinished returns true
void AutoDrive::End() {
	driveTrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {
	End();
}


AutoDrivePIDSource::~AutoDrivePIDSource() {}
double AutoDrivePIDSource::PIDGet() {
    return CommandBase::driveTrain->GetDistance();
}

AutoDrivePIDOutput::~AutoDrivePIDOutput() {}
void AutoDrivePIDOutput::PIDWrite(double d) {
	CommandBase::driveTrain->DriveStraight(d);
}
