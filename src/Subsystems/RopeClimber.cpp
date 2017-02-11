#include "RopeClimber.h"
#include "../RobotMap.h"
#include "OI.h"

RopeClimber::RopeClimber() : Subsystem("RopeClimber")
{
	climbMotor1 = new Spark(CLIMB_MOTOR1);
	climbMotor2 = new Spark(CLIMB_MOTOR2);
}

void RopeClimber::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void RopeClimber::Lift(double power)
{
	climbMotor1->Set(power);
	climbMotor2->Set(power);
}
