#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"
#include "ADXRS450_Gyro.h"


using namespace frc;

DriveTrain::DriveTrain()
:	Subsystem("DriveTrain")
{
	robotDrive = new RobotDrive(F_R_Motor, B_R_Motor, F_L_Motor, B_L_Motor);
//	robotDrive -> SetSensitivity(0.75);
//	robotDrive -> SetMaxOutput(double(Stick->GetZ()));
//	robotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
//	robotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, false);
//	robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
//	robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);

	encoder = new Encoder(Encoder_Pos, Encoder_Neg, false, Encoder::EncodingType::k4X);
	encoder->SetMaxPeriod(0.1);
	encoder->SetMinRate(10);
	encoder->SetDistancePerPulse(5);
	encoder->SetSamplesToAverage(7);

	gyro = new ADXRS450_Gyro();

}

void DriveTrain::InitDefaultCommand(){
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
	gyro -> Calibrate();

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::DriveWithJoystick(Joystick* Stick){
	//robotDrive -> SetSensitivity((Stick->GetZ()*50+50)*0.01);
	double max_speed = 1.0 - (Stick->GetZ()*50+50)*(0.01);
	robotDrive -> SetMaxOutput(max_speed);

	robotDrive->ArcadeDrive(Stick->GetY(), Stick->GetX()*(-1));
	SmartDashboard::PutNumber("MaxOutput", max_speed);
	SmartDashboard::PutNumber("Encoder", encoder->GetRaw());
	SmartDashboard::PutNumber("Get Angle", gyro->GetAngle());


}

void DriveTrain::Stop() {
	robotDrive->StopMotor();
}
