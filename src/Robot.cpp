#include "WPILib.h"
#include "Commands/Command.h"
//#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Subsystems/Drivetrain.h"
#include "Robot.h"

std::shared_ptr<DriveTrain> Robot::(new DriveTrain());
//class only once, in the .h file

	void Robot::RobotInit()
	{
		CommandBase::init();
//		chooser = new SendableChooser();
		//chooser->AddDefault("Default Auto", new ExampleCommand());
		//chooser->AddObject("My Auto", new MyAutoCommand());
		SmartDashboard::PutData("Auto Modes", chooser);
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void Robot::AutonomousInit()
	{
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		autonomousCommand.reset((Command *)chooser->GetSelected());

		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void Robot::AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void Robot::TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void Robot::TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void Robot::TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}


START_ROBOT_CLASS(Robot)

