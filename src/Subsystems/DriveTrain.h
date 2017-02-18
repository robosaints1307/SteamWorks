#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive* robotDrive;
	Encoder* encoder;

public:
	DriveTrain();
	void InitDefaultCommand() override;
	void DriveWithJoystick (Joystick* lStick, Joystick* rStick);
	void AutoDrive(double left, double right);
	void Stop();
};

#endif
