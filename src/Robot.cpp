#include "Robot.h"
#include "CommandBase.h"

#include <cstddef>

using namespace frc;

// In Robot.h, drivetrain is declared a static. This means that
// will be one instance of drivetrain, and we need to define
// Robot::drivetrain somewhere for the linker to find it.
// This is what we're doing here with drivetrain and oi.
// Notice, though, that they are set to null. We set the pointer
// in RobotInit, but the memory that holds the pointer is
// defined here.
//
// These could be smart pointers, but I think that just adds
// a level of complexity without any benefit to the robot code.
//
//DriveTrain* Robot::drivetrain = 0;
OI* Robot::oi = 0;

void Robot::RobotInit()
{
	oi = new OI();

	CommandBase::init();

	chooser = new SendableChooser<Command*>();
	//It takes cmdgroups but only the first command
	chooser->AddDefault("Center Start", new CenterAuto());
	//chooser->AddObject("Left Start", leftStart);
	//chooser->AddObject("Right Start", rightStart);
	//chooser->AddObject("test", new AutoDrive(10.0));

	SmartDashboard::PutData("Auto Modes", chooser);
	CameraServer::GetInstance()->StartAutomaticCapture(0);
	CameraServer::GetInstance()->StartAutomaticCapture(1);

//	centerStart = new CommandGroup();
//	centerStart->DoesRequire(CommandBase::driveTrain);
//	centerStart->AddSequential(new AutoDrive(188.0));
//
//	leftStart = new CommandGroup();
//	leftStart->DoesRequire(CommandBase::driveTrain);
//	leftStart->AddSequential(new AutoDrive(186.6));
//	leftStart->AddSequential(new AutoTurn(60.0));
//	leftStart->AddSequential(new AutoDrive(50.0));
//
//	rightStart = new CommandGroup();
//	rightStart->DoesRequire(CommandBase::driveTrain);
//	rightStart->AddSequential(new AutoDrive(186.6));
//	rightStart->AddSequential(new AutoTurn(-60.0));
//	rightStart->AddSequential(new AutoDrive(50.0));
//
//	test = new CommandGroup();
//	test->DoesRequire(CommandBase::driveTrain);
//	test->AddSequential(new AutoDrive(120.0));
//	test->AddSequential(new AutoTurn(-90.0));
//	test->AddSequential(new AutoDrive(120.0));
}

//I like Trains
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
	/*
	 * This chunk of code is probably from an old example. With
	 * templates (i.e.  SendableChooser<Command*>) the compiler knows
	 * that chooser->GetSelected() returns an Command* and this kind
	 * of switching isn't needed.
	 *
	 std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand = new MyAutoCommand();
		} else {
			autonomousCommand = new ExampleCommand();
		}
	*/
	/*
	 * if(chooser->GetSelected
	 */

	autonomousCommand = chooser->GetSelected();

	if (autonomousCommand != NULL){
		autonomousCommand->Start();
	}
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

