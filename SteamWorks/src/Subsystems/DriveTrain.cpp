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

//	robotDrive->SetMaxOutput(0.5);
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
	printf("%f\n", angle);
	robotDrive->TankDrive(angle, -angle);
//	if(0 < angle){
//		SmartDashboard::PutNumber("Running", 2);
//		robotDrive->TankDrive(0.25, -0.25);
//	}
//	else if(0 > angle){
//		SmartDashboard::PutNumber("Running", 3);
//		robotDrive->TankDrive(-0.25, 0.25);
//	}
//	else{
//		SmartDashboard::PutNumber("Running", 5);
//	}
}
void DriveTrain::DriveStraight(double speed) {

	SmartDashboard::PutNumber("DriveStraight:speed", speed);

	double angle = GetDirection();
	SmartDashboard::PutNumber("DriveStraight:angle", angle);

	double left_speed = speed;
	SmartDashboard::PutNumber("DriveStraight:leftSpeed", left_speed);

	double right_speed = speed + (angle * kP);
	SmartDashboard::PutNumber("DriveStraight:rightSpeed", right_speed);

	robotDrive->TankDrive(-speed, -speed);//-left_speed, -right_speed);
}

void DriveTrain::InitDefaultCommand(){
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::DriveWithJoystick(Joystick* L_Stick, Joystick* R_Stick){

	double max_speed = 1.0 - (L_Stick->GetZ()*50+50)*(0.01); //remove l when going back to arcade
	robotDrive -> SetMaxOutput(max_speed);

	//robotDrive->ArcadeDrive(Stick->GetY(), Stick->GetX()*(-0.75));
	robotDrive->TankDrive(L_Stick, R_Stick);
	SmartDashboard::PutNumber("MaxOutput", max_speed);
	SmartDashboard::PutNumber("Encoder", encoder->GetDistance());
}

void DriveTrain::Stop() {
	robotDrive->StopMotor();
}
