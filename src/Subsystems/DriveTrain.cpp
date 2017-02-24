#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

using namespace frc;


DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	robotDrive = new RobotDrive(F_R_Motor, B_R_Motor, F_L_Motor, B_L_Motor);

	encoder = new Encoder(Encoder_Pos, Encoder_Neg, true, Encoder::EncodingType::k4X);
	encoder->SetDistancePerPulse(0.131);

	gyro = new ADXRS450_Gyro();

	robotDrive->SetMaxOutput(0.5);
}

void DriveTrain::Reset() {
	gyro->Reset();
	encoder->Reset();
}

double DriveTrain::GetDistance() {
	double distance = encoder->GetDistance();
	SmartDashboard::PutNumber("GetDistance", distance);
	return distance;
}

double DriveTrain::GetDirection() {
	double angle = gyro->GetAngle();
	SmartDashboard::PutNumber("GetDirection", angle);
	return angle;
}

void DriveTrain::Turn(double angle) {
	SmartDashboard::PutNumber("CurAngle", angle);
	if(0 < angle){
		robotDrive->TankDrive(0.25, -0.25);
	}
	else if(0 > angle){
		robotDrive->TankDrive(-0.25, 0.25);
	}
}
void DriveTrain::DriveStraight(double speed) {

	SmartDashboard::PutNumber("DriveStraight:speed", speed);

	double angle = GetDirection();
	SmartDashboard::PutNumber("DriveStraight:angle", angle);

	double leftSpeed = speed;
	SmartDashboard::PutNumber("DriveStraight:leftSpeed", leftSpeed);

	double rightSpeed = speed + (angle * kP);
	SmartDashboard::PutNumber("DriveStraight:rightSpeed", rightSpeed);

	robotDrive->TankDrive(leftSpeed, rightSpeed);
}

void DriveTrain::InitDefaultCommand(){
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::DriveWithJoystick(Joystick* Stick){
	double max_speed = 1.0 - (Stick->GetZ()*50+50)*(0.01);
	robotDrive -> SetMaxOutput(max_speed);

	robotDrive->ArcadeDrive(Stick->GetY(), Stick->GetX()*(-1));
	SmartDashboard::PutNumber("MaxOutput", max_speed);
	SmartDashboard::PutNumber("Encoder", encoder->GetDistance());
}

void DriveTrain::Stop() {
	robotDrive->StopMotor();
}
