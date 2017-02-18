#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"
#include "ADXRS450_Gyro.h"


using namespace frc;

DriveTrain::DriveTrain()
:	Subsystem("DriveTrain")
{
	robotDrive = new RobotDrive(F_R_Motor, B_R_Motor, F_L_Motor, B_L_Motor);
	robotDrive -> SetSensitivity(0.75);
	robotDrive -> SetMaxOutput(1.0);

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
void DriveTrain::DriveWithJoystick(Joystick* lStick, Joystick* rstick){

	robotDrive->ArcadeDrive(lStick->GetZ(), lStick->GetX());
	SmartDashboard::PutNumber("Encoder", encoder->GetDistance());
	SmartDashboard::PutNumber("Get Angle", gyro->GetAngle());


}

void DriveTrain::Stop() {
	robotDrive->StopMotor();
}
