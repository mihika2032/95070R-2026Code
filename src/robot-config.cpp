// src/robot-config.cpp
//#include "robot-config.h"

//Configuration!

/*Reminders: 
Make sure that all your ports are different and correct! 
Make sure all of your motor + piston names are different and not confusing.
If it seems like some of your motors are running against eachother in the drivetrain, try switching around the true/false

*/

// src/robot-config.cpp
#include "robot-config.h"

//Configuration!

/*Reminders: 
Make sure that all your ports are different and correct! 
Make sure all of your motor + piston names are different and not confusing.
If it seems like some of your motors are running against eachother in the drivetrain, try switching around the true/false

*/

vex::brain Brain;
vex::controller Controller(vex::controllerType::primary);

vex::motor LB(vex::PORT3, vex::gearSetting::ratio6_1, true); //Left Back Motor
vex::motor LM(vex::PORT2, vex::gearSetting::ratio6_1, true); //Left Middle Motor
vex::motor LF(vex::PORT1, vex::gearSetting::ratio6_1, true); //Left Front Motor
vex::motor RB(vex::PORT10, vex::gearSetting::ratio6_1, false); //Right Back Motor
vex::motor RM(vex::PORT9, vex::gearSetting::ratio6_1, false); //Right Middle Motor
vex::motor RF(vex::PORT8, vex::gearSetting::ratio6_1, false); //Right Front Motor

vex::motor_group LeftDrive(LF, LM, LB);
vex::motor_group RightDrive(RF, RM, RB);

// Drivetrain: wheel travel = 320mm, track width = 280mm, wheelbase = 300mm (adjust as needed)
vex::drivetrain Drivetrain(LeftDrive, RightDrive, 320, 280, 300);

vex::motor Arm1(vex::PORT4, vex::gearSetting::ratio18_1,  false); //Arm motor
vex::motor Arm2(vex::PORT5, vex::gearSetting::ratio18_1, false); //Arm motor

vex::digital_out matchloader(Brain.ThreeWirePort.B);
vex::digital_out descorer(Brain.ThreeWirePort.A);

vex::inertial InertialSensor(vex::PORT7);

void vexcodeInit() {
  InertialSensor.calibrate();
  while (InertialSensor.isCalibrating()) {
    vex::task::sleep(100);
  }
}