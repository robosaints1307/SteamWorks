#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

//Driveing vroom vroom
const int F_R_Motor = 0; //spark
const int B_R_Motor = 1; //spark
const int F_L_Motor = 2; //talon
const int B_L_Motor = 3; //talon
const double Robot_Speed = 0.75;

//climbmotors
const int CLIMB_MOTOR1 = 4;
const int CLIMB_MOTOR2 = 5;
const double Climb_Speed = -1.0;

//Joystick
const int stick_port = 0;

//buttons
const int Button1 = 1;
const int Reverse_Button = 2;
const int DIRECTION = 1;

//Encoder
const int Encoder_Pos = 8;
const int Encoder_Neg = 9;
const int pulses_per_rotation = 1440;
const double wheel_circumference = 6*M_PI; //wheel is 6in in diameter

const double pulse = wheel_circumference/pulses_per_rotation;
//const double one_inch = pulse*wheel_circumference;

//camera
const int Cam0 = 0;
const int Cam1 = 1;

#endif
