#include "robot-config.h"
#include "vex.h"
#include "PID.h"
#include "arm.h"
#include "functions.h"
#include "autons.h"
 //    0
 //270   90
 //   180
using namespace vex;

void sevenblock(){
drivePidParams setting = {};
Arm1.spin(forward,200,percent);
drivePID(19);
setting.maxSpeed = 30.0;
drivePID(5,setting);
turnPID(120.5,0.26,0,0);
drivePID(-9);
Arm2.spin(forward,100,percent);

//😳


}

void fern (){
//🦊
}

void Skills(){
drivePidParams setting = {};
descorer.set(true);
Arm1.spin(forward,100,percent);
drivePID(40);
matchloader.set(true);
turnPID(-88,0.30,0,0);
spinDT(20);
wait(0.8, sec);
drivePID(-0.5);
drivePID(1);
drivePID(-0.5);
drivePID(1);
// drivePID(-0.5);
// drivePID(1);

// //go to other side
setting.maxSpeed = 60.0;
spinDT(-60);
wait(1, sec);
stopDT();
Arm2.spin(forward, 100, percent);
wait(2.2, sec);
drivePID(11);
Arm2.stop();
turnPID(91,0.3,0,0);
setting.maxSpeed = 90.0;
drivePID(-75.5, setting);
turnPID(-81,0.3,0,0);

spinDT(20);
wait(2, sec);
stopDT();
drivePID(-0.5);
drivePID(1);
drivePID(-0.5);
drivePID(1);
drivePID(-0.5);
drivePID(1);
spinDT(-65);
wait(1, sec);
stopDT();
Arm2.spin(forward, 100, percent);
wait(2, sec);
drivePID(20);
matchloader.set(false);
turnPID(-115,0.3,0,0);
drivePID(-65);
}


void SkillsParking(){
  drivePidParams setting = {};
  setting.maxSpeed = 30.0;
  Arm1.spin(forward, 100, percent);
  Arm2.spin(forward, 100, percent);
  spinDT(20);
  wait(1.2, sec);
  stopDT();
  drivePID(1);

  /*drivePID(-10);
  drivePID(5);
  drivePID(-15);
  drivePID(10);
  drivePID(-14);
  drivePID(5);
  drivePID(-17);
  drivePID(3);
  drivePID(-5);
  drivePID(3);*/
  
 


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

                                                                                    
void HighGoalRAuton(){
    drivePidParams setting = {};
    matchloader.set(false);
    Arm1.spin(forward,100,percent);
    drivePID(19);
    setting.maxSpeed = 30.0;
    drivePID(5, setting);
    turnPID(-90,0.26,0,0);
    drivePID(22.5);
    turnPID(-67,0.26,0,0);
    drivePID(-8);
    Arm2.spin(forward,100,percent);
  
    //wait(3, sec);
    //Arm2.stop(hold);
    matchloader.set(true);
    
}
   
   
void HighGoalLAuton(){
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
    matchloader.set(true);
    descorer.set(true);
   /* wait(2.5, sec);
    matchloader.set(true);
    Arm2.stop(hold);
    drivePID(23);
    drivePID(-2);
    Arm1.spin(forward,100,percent);
    drivePID(4);
    wait(2.5,sec);
    Arm1.stop(hold);
    drivePID(-25);*/


    
}
   


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

void LeftAuton(){
//nom nom  
drivePidParams setting = {};
Arm1.spin(forward,100,percent);
setting.maxSpeed = 70.0;
drivePID(25, setting);
turnPID(90,0.30,0,0);
drivePID(22);
turnPID(67,0.3,0,0);
drivePID(-7.2);
Arm2.spin(forward, 100, percent);
wait(1.5, sec);
descorer.set(true);
drivePID(4.7);
turnPID(90,0.30,0,0);
drivePID(-8.5, setting);
setting.maxSpeed = 70.0;
turnPID(-88,0.30,0,0);
descorer.set(false);
drivePID(-22);
}

void RightAuton(){
drivePidParams setting = {};
Arm1.spin(forward,100,percent);
setting.maxSpeed = 70.0;
drivePID(25, setting);
turnPID(-90,0.30,0,0);
drivePID(22);
turnPID(-67,0.3,0,0);
drivePID(-7);
Arm2.spin(forward, 100, percent);
wait(1.5, sec);
descorer.set(true);
drivePID(4.5);
turnPID(90,0.30,0,0);
drivePID(-9, setting);
setting.maxSpeed = 70.0;
turnPID(-89,0.30,0,0);
descorer.set(false);
drivePID(-21);
//i dont no if it commited */
}


//nom nom