#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "arm.h"
#include "functions.h"
#include "autons.h"

using namespace vex;


void SkillsAuton(){
  drivePidParams setting = {};
  setting.maxSpeed = 30.0;
  drivePID(10);

//   drivePidParams setting = {};
//   Arm1.spin(forward,100,percent);
//   drivePID(19);
//   setting.maxSpeed = 30.0;
//   drivePID(5, setting);
//   turnPID(-90,0.26,0,0);
//   drivePID(24);
//   turnPID(-56,0.26,0,0);
//   drivePID(-12);
//   Arm2.spin(forward,100,percent); 
//   wait(3, sec);
//   Arm2.stop(hold);
//   turnPID(1,0.26,0,0);
//   matchloader.set(true);
//   setting.maxSpeed = 70.0;
//   drivePID(25.5);
//   drivePID(-0.5);
//   drivePID(1);
//   drivePID(-1);
//   drivePID(1);
//   drivePID(-0.8);
//   drivePID(0.8);
//   drivePID(-0.9);
//   drivePID(0.9);
//   drivePID(-1);
//   drivePID(1);
//   Arm1.spin(forward,100,percent);
//   Arm2.spin(forward,100,percent);
//   drivePID(-10);
//   turnPID(120 ,0.26,0,0);
//   drivePID(-50);
}
void SkillsParking(){
  Arm1.spin(forward,100,percent);
  /*drivePidParams setting = {};
  setting.maxSpeed = 40.0;
  drivePID(10);
  drivePID(-10);
  drivePID(10);
  drivePID(-5);
  drivePID(5);*/
}
                                                                                    
void HighGoalRAuton(){
    drivePidParams setting = {};
    matchloader.set(false);
    Arm1.spin(forward,100,percent);
    drivePID(19);
    setting.maxSpeed = 30.0;
    drivePID(5, setting);
    turnPID(-90,0.26,0,0);
    drivePID(22.5);
    turnPID(-60,0.26,0,0);
    drivePID(-9);
    Arm2.spin(forward,100,percent);
  
    //wait(3, sec);
    //Arm2.stop(hold);
    matchloader.set(true);
    
}
   
   
void HighGoalLAuton(){
   Controller.Screen.print("Hello hooman MWHHAHAHA!");
    drivePidParams setting = {};
    Arm1.spin(forward,100,percent);
    drivePID(19);
    setting.maxSpeed = 30.0;
    drivePID(5, setting);
    turnPID(90,0.26,0,0);
    drivePID(22.5);
    turnPID(67,0.26,0,0);
    drivePID(-8);
    Arm2.spin(forward, 100, percent);
    wait(2.5, sec);
    matchloader.set(true);
    Arm2.stop(hold);
    drivePID(23);
    drivePID(-2);
    Arm1.spin(forward,100,percent);
    drivePID(4);
    wait(2.5,sec);
    Arm1.stop(hold);
    drivePID(-25);


    
}
   
    /*void VIOLA IS BETTER IYKYK(){
      while(true){
        if(OpticalSensor.brightness()<50){
          bottomIntakeMotor.spin(forward,100,percent);
          middleIntakeMotor.spin(reverse,100,percent);
          topIntakeMotor.spin(forward,100,percent); 
        }
        else{
          bottomIntakeMotor.stop();
          middleIntakeMotor.stop();
          topIntakeMotor.stop();
        }
        wait(20,msec);
      }
    }
    vex::thread intakejamprevention(VIOLA IS BETTER IYKYK); */



// void MiddleGoalRAuton(){
//         drivePidParams setting = {};
//     Arm1.spin(forward,100,percent);
//     drivePID(19);
//     setting.maxSpeed = 30.0;
//     drivePID(5, setting);
//     turnPID(90,0.26,0,0);
//     drivePID(22);
//     turnPID(70,0.26,0,0);
//     drivePID(-10);
//     Arm2.spin(forward,100,percent);

// }



