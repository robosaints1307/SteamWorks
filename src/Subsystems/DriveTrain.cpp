#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"

using namespace frc;


DriveTrain::DriveTrain() : PIDSubsystem("PIDTrain", 0.4, 0.0, 0.0)
{
	f_r_motor = new Spark(F_R_Motor);
	b_r_motor = new Spark(B_R_Motor);
	f_l_motor = new Talon(F_L_Motor);
	b_l_motor = new Talon(B_L_Motor);
	robotDrive = new RobotDrive(f_r_motor, b_r_motor, f_l_motor, b_l_motor);
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

	gyro = new ADXRS450_Gyro();

	speed = Robot_Speed;
	left_speed = speed;
	right_speed = speed;

	SetAbsoluteTolerance(0.3); //what does this do
	//SetContinuous(false);
}

double DriveTrain::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	SmartDashboard::PutNumber("Encoder", encoder->GetDistance());
	SmartDashboard::PutNumber("Gyro", gyro->GetAngle());
	return encoder->GetDistance();
}

void DriveTrain::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	//SmartDashboard::PutNumber("PIDOutput", output);
	std::tuple<double, double> correction = DriveTrain::CorrectSpeed(gyro->GetAngle());
	SmartDashboard::PutNumber("correct left", std::get<0>(correction));
	robotDrive->TankDrive(std::get<0>(correction),
			std::get<1>(correction));
}

void DriveTrain::InitDefaultCommand(){
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Drive());
	gyro->Calibrate();
	encoder->Reset();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::DriveWithJoystick(Joystick* Stick){
	//robotDrive -> SetSensitivity((Stick->GetZ()*50+50)*0.01);
	Disable();
	double max_speed = 1.0 - (Stick->GetZ()*50+50)*(0.01);
	robotDrive -> SetMaxOutput(max_speed);

	robotDrive->ArcadeDrive(Stick->GetY(), Stick->GetX()*(-1));
	SmartDashboard::PutNumber("MaxOutput", max_speed);
	SmartDashboard::PutNumber("Encoder", encoder->GetDistance());
	SmartDashboard::PutNumber("Get Angle", gyro->GetAngle());
}

void DriveTrain::AutoDrive(double distance){
	encoder->Reset();
	gyro->Reset();
	robotDrive->SetMaxOutput(speed);
	SetSetpoint(distance);
	//SetPercentTolerance(0.10);
	Enable();
}

void DriveTrain::Stop() {
	robotDrive->StopMotor();
}

std::tuple<double, double> DriveTrain::CorrectSpeed(double angle){ //pass this gyro->GetAngle()
	double adjustment = 0.0625;
	if(angle < 0){ //adjusts periodically by .05
		left_speed = speed + adjustment;
		right_speed = speed - adjustment;
		return std::make_tuple(left_speed, right_speed);
	}
	else if(angle > 0){
		left_speed = speed + adjustment;
		right_speed = speed - adjustment;
		return std::make_tuple(left_speed, right_speed);
	}
	else{
		left_speed = speed;
		right_speed = speed;
		return std::make_tuple(left_speed, right_speed);
	}
}
