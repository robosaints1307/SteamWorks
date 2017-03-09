/*
 * Robot.h
 *
 *  Created on: Jan 30, 2017
 *      Author: Robotics
 */
#include "WPILib.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/RopeClimber.h"
#include "OI.h"
#include "Commands/Climb.h"
#include "Commands/AutoDrive.h"
#include "Commands/AutoTurn.h"
#include "Commands/CenterAuto.h"
#include "Commands/LeftAuto.h"
#include "Commands/RightAuto.h"
#include "Commands/GO.h"

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_


class Robot: public IterativeRobot{

public:
	static DriveTrain* drivetrain;
	static OI* oi;
//	static Climb* climb;

private:
	frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	Command* autonomousCommand; //it might not be happy because I am telling a command to be a commandgroup
	SendableChooser<Command*>* chooser;
	CameraServer* cam0;
	CameraServer* cam1;

//	CommandGroup *centerStart;
//	CommandGroup *leftStart;
//	CommandGroup *rightStart;
//	CommandGroup *test;

	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
};





#endif /* SRC_ROBOT_H_ */
