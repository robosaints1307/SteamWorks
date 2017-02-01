/*
 * Robot.h
 *
 *  Created on: Jan 30, 2017
 *      Author: Robotics
 */
#include "WPILib.h"
#include "Commands/Command.h"
#include "Subsystems/DriveTrain.h"
#include "OI.h"

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_


class Robot: public IterativeRobot{

public:
	static std::shared_ptr<DriveTrain> drivetrain;
	static std::unique_ptr<OI> oi;

private:
	LiveWindow *lw = LiveWindow::GetInstance();

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};





#endif /* SRC_ROBOT_H_ */
