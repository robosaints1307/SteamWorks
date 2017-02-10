/*
 * Robot.h
 *
 *  Created on: Jan 30, 2017
 *      Author: Robotics
 */
#include "WPILib.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/RopeClimbing.h"
#include "OI.h"


#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_


class Robot: public IterativeRobot{

public:
	static DriveTrain* drivetrain;
	static OI* oi;

private:
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	Command* autonomousCommand;
	SendableChooser<Command*>* chooser;

	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
};





#endif /* SRC_ROBOT_H_ */
