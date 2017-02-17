#ifndef Gyro_H
#define Gyro_H

#include <Commands/Subsystem.h>
#include "ADXRS450_Gyro.h"

class Gyro : public Subsystem
{
	RobotDrive IterativeRobot;
static const float kP = 0.03;

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Gyro();

	ADXRS450_Gyro gyro;
	void InitDefaultCommand();
};

#endif  // Gyro_H
