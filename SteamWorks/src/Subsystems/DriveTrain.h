#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
//#include "ADXRS450_Gyro.h"

#include <Commands/PIDSubsystem.h>

class DriveTrain: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	constexpr static const float kP = 0.03;

	RobotDrive* robotDrive;
	//Encoder* encoder;
	ADXRS450_Gyro* gyro;

public:
	DriveTrain();

	Encoder* encoder;

	void InitDefaultCommand() override;
	void DriveWithJoystick (Joystick* L_Stick, Joystick* R_Stick);
	void DriveStraight(double speed);
	void Turn(double angle);
	double GetDistance();
	double GetDirection();
	void SetMaxSpeed(double maxSpeed);
	void Reset();
	void Stop();
};

#endif
