#include "Climb.h"
#include "Robot.h"
#include "../CommandBase.h"

using namespace frc;

Climb::Climb()
		//frc::Command("Climb")

{
	Requires(ropeClimber);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Climb::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Climb::Execute() {
	ropeClimber->Lift(Climb_Speed);
}

// Make this return true when this Command no longer needs to run execute()
bool Climb::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Climb::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Climb::Interrupted() {

}
