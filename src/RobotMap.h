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
const int F_R_Motor = 0;
const int B_R_Motor = 1;
const int F_L_Motor = 2;
const int B_L_Motor = 3;

//climbmotors
const int CLIMB_MOTOR1 = 4;
const int CLIMB_MOTOR2 = 5;

//Joystick
const int R_Stick = 0;
const int L_Stick = 1;

//buttons
const int Button1 = 0;

//Encoder
const int Encoder_Pos = 8;
const int Encoder_Neg = 9;

const int Climb_Speed = 0.25;

#endif
