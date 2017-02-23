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
	ADXRS450_Gyro* gyro;
	Spark* f_r_motor;
	Spark* b_r_motor;
	Talon* f_l_motor;
	Talon* b_l_motor;
//	double p;
//	double i;
//	double d;
	double speed;
	double left_speed;
	double right_speed;

public:
	RobotDrive* robotDrive;
	DriveTrain();

	void InitDefaultCommand() override;
	void DriveWithJoystick (Joystick* Stick);
	void AutoDrive(double distance);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void Stop();
	std::tuple<double, double> CorrectSpeed(double angle);
};

#endif
