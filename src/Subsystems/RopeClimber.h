#ifndef RopeClimber_H
#define RopeClimber_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "RobotMap.h"

class RopeClimber : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:

	SpeedController* climbMotor1;
	SpeedController* climbMotor2;

	RopeClimber();
	void InitDefaultCommand();

	void Lift(double power);
};

#endif  // RopeClimber_H
