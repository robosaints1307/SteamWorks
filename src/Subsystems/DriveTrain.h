#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ADXRS450_Gyro.h"


class DriveTrain: public Subsystem{
private:
	// It's desirable that everything possible under private except
	constexpr static const float kP = 0.03;
	// for methods that implement subsystem capabilities
	RobotDrive* robotDrive;
	Encoder* encoder;
	ADXRS450_Gyro* gyro;


public:
	DriveTrain();

	void InitDefaultCommand() override;

	void DriveWithJoystick (Joystick* lStick, Joystick* rStick);
	void Stop();
};

#endif
