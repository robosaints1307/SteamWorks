#include "AutoTurn.h"

AutoTurn::AutoTurn(double angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(driveTrain);
	pid = new PIDController(0.3, 0.025, 0.0, new AutoTurnPIDSource(), new AutoTurnPIDOutput());
	pid->SetPercentTolerance(5);
	pid->SetContinuous(true);
	pid->SetSetpoint(angle);
	pid->SetOutputRange(-0.5, 0.5);
}

// Called just before this Command runs the first time
void AutoTurn::Initialize() {
	driveTrain->Reset();
	pid->Reset();
	pid->Enable();
}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished() {
	return pid->OnTarget();
}

// Called once after isFinished returns true
void AutoTurn::End() {
	driveTrain->Stop();
	SmartDashboard::PutNumber("Turn Ended", 1);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted() {
	End();
}

AutoTurnPIDSource::~AutoTurnPIDSource() {}
double AutoTurnPIDSource::PIDGet() {
    return CommandBase::driveTrain->GetDirection();
}

AutoTurnPIDOutput::~AutoTurnPIDOutput() {}
void AutoTurnPIDOutput::PIDWrite(double a) {
	CommandBase::driveTrain->Turn(a);
}
