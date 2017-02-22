#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
//#include "ADXRS450_Gyro.h"

#include <Commands/PIDSubsystem.h>

class DriveTrain: public PIDSubsystem{
private:
	// It's desirable that everything possible under private except
	constexpr static const float kP = 0.03;
	// for methods that implement subsystem capabilities

	Encoder* encoder;
	//ADXRS450_Gyro* gyro;
//	double p;
//	double i;
//	double d;

public:
	RobotDrive* robotDrive;
	DriveTrain();

	void InitDefaultCommand() override;
	void DriveWithJoystick (Joystick* Stick);
	void AutoDrive(double distance, float speed);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void Stop();
};

#endif
