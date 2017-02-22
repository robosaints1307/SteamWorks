#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

using namespace frc;


DriveTrain::DriveTrain() : PIDSubsystem("PIDTrain", 0.4, 0.0, 0.0)
{
	robotDrive = new RobotDrive(F_R_Motor, B_R_Motor, F_L_Motor, B_L_Motor);
//	p = SmartDashboard::GetNumber("p", 0);
//	i = SmartDashboard::GetNumber("i", 0);
//	d = SmartDashboard::GetNumber("d", 0);
//	robotDrive -> SetSensitivity(0.75);
//	robotDrive -> SetMaxOutput(double(Stick->GetZ()));
//	robotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
//	robotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, false);
//	robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
//	robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);

	encoder = new Encoder(Encoder_Pos, Encoder_Neg, true, Encoder::EncodingType::k4X);
//	encoder->SetMaxPeriod(0.1);
//	encoder->SetMinRate(10);
	encoder->SetDistancePerPulse(pulse);
//	encoder->SetSamplesToAverage(7);

	//gyro = new ADXRS450_Gyro();
}

double DriveTrain::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	SmartDashboard::PutNumber("Encoder", encoder->GetDistance());
	return encoder->GetDistance();
}

void DriveTrain::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	SmartDashboard::PutNumber("PIDOutput", output);
	robotDrive->TankDrive(output, output);
}

void DriveTrain::InitDefaultCommand(){
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
	//gyro->Calibrate();
	encoder->Reset();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::DriveWithJoystick(Joystick* Stick){
	//robotDrive -> SetSensitivity((Stick->GetZ()*50+50)*0.01);
	Disable();
	double max_speed = 1.0 - (Stick->GetZ()*50+50)*(0.01);
	//double reading = 0.0;
	//reading = reading + encoder->GetDistance();
	robotDrive -> SetMaxOutput(max_speed);

	robotDrive->ArcadeDrive(Stick->GetY(), Stick->GetX()*(-1));
	SmartDashboard::PutNumber("MaxOutput", max_speed);
	SmartDashboard::PutNumber("Encoder", encoder->GetDistance());
	//SmartDashboard::PutNumber("Encoder Scale", encoder->GetEncodingScale());
	//SmartDashboard::PutNumber("Get Angle", gyro->GetAngle());
}

void DriveTrain::AutoDrive(double distance, float speed){
	encoder->Reset();
	robotDrive->SetMaxOutput(speed);
	SetSetpoint(distance);
	SetPercentTolerance(10);
	Enable();
}

void DriveTrain::Stop() {
	robotDrive->StopMotor();
}
