#include "AutoDrive.h"

AutoDrive::AutoDrive(double distance) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);

	pid = new PIDController(0.8, 0.6, 0.2, new AutoMoveSource(), new AutoMoveOutput());
	pid->SetAbsoluteTolerance(0.3);
	pid->SetOutputRange(-0.725, 0.725);
	pid->SetContinuous(false);
	pid->SetSetpoint(distance*wheel_circum);
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
	driveTrain->encoder->Reset();
	pid->Reset();
	pid->Enable();
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutoDrive::End() {
	pid->Disable();
	AutoDrive(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {

}

AutoMoveSource::~AutoMoveSource(){}
double AutoMoveSource::PIDGet(){
double get = (AutoDrive::driveTrain->encoder->PIDGet());
//printf("Pid:%f\n", get);
return get;//AutoDrive::driveTrain->encoder->PIDGet());
}
AutoMoveOutput::~AutoMoveOutput(){}
void AutoMoveOutput::PIDWrite(float d){
	printf("PidWrite:D:%f", d);
	AutoDrive::driveTrain->AutoDrive(d, 0);
}
