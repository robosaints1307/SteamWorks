#include "CameraServer.h"
#include "../RobotMap.h"

Camera::Camera() : Subsystem("Cam") {

}

void Camera::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	CameraServer::GetInstance()->StartAutomaticCapture();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
