#include "Climb.h"
#include "../Robot.h"
#include "../CommandBase.h"

using namespace frc;

Climb::Climb() : CommandBase("Climb")
{
	Requires(ropeClimber);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	SmartDashboard::PutString("Climber", "Climber");
}

// Called just before this Command runs the first time
void Climb::Initialize() {
	ropeClimber->Lift(Climb_Speed);
}

// Called repeatedly when this Command is scheduled to run
void Climb::Execute() {
	SmartDashboard::PutString("Climber", "Execute");
//	ropeClimber->Lift(Climb_Speed);
}

// Make this return true when this Command no longer needs to run execute()
bool Climb::IsFinished() {
	SmartDashboard::PutString("Climber", "isFinished");
	return false;
}

// Called once after isFinished returns true
void Climb::End() {
	SmartDashboard::PutString("Climber", "End");

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Climb::Interrupted() {
	SmartDashboard::PutString("Climber", "Interrupted");
	ropeClimber->Lift(0.0);

}
