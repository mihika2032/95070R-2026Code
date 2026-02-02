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

void AWP(){
drivePidParams setting = {};
descorer.set(true);
Arm1.spin(forward,100,percent);
drivePID(40);
matchloader.set(true);
turnPID(91,0.26,0,0);
setting.maxSpeed = 35.0;
drivePID(11, setting);
setting.maxSpeed = 30.0;
drivePID(-0.5);
drivePID(1);
drivePID(-0.5);
drivePID(1);
//go to other side
drivePID(-5);
turnPID(88,0.26, 0, 0);
drivePID(-9, setting);
turnPID(-90,0.26, 0, 0);
Arm1.stop();
setting.maxSpeed = 167.0;
drivePID(-75, setting);
// setting.maxSpeed = 5.0;
// drivePID(-5);
// turnPID(45,0.26, 0, 0);
// drivePID(-15);
// turnPID(-42, 0.26, 0, 0);
// setting.maxSpeed = 50.0;
// drivePID(-70);
//deposit blocks
setting.maxSpeed = 30.0;
turnPID(90, 0.26, 0, 0);
drivePID(10, setting);
turnPID(90,0.26,0,0);
drivePID(-14);
Arm2.spin(forward, 100, percent);
Arm1.spin(forward,100,percent);
//next matchload
wait(3, sec);
Arm2.stop();
setting.maxSpeed = 35.0;
drivePID(24, setting);
drivePID(-0.5);
drivePID(1);
drivePID(-0.5);
drivePID(1);
drivePID(-24);
Arm2.spin(forward, 100, percent);
wait(3,sec);
drivePID(12, setting);
turnPID(-90, 0.26, 0, 0);


// // InertialSensor.setRotation(270, degrees);
// drivePidParams setting = {};
// setting.maxSpeed = 10.0;
// Arm1.spin(forward,80,percent);
// drivePID(30);
// matchloader.set(true);
// turnPID(91,0.26,0,0);
// setting.maxSpeed = 2.0;
// drivePID(15);
// drivePID(-0.5);
// drivePID(1);
// // drivePID(-0.5);
// // drivePID(1);
// wait(1, sec);
// // drivePID(4);
// setting.maxSpeed = 10.0;
// drivePID(-1);
// turnPID(-2,0.26,0,0);
// drivePID(-20);
// Arm2.spin(forward,100,percent);
// drivePID(1);
// wait(2,sec);
// Arm2.stop();
// Arm1.stop();
// matchloader.set(false);
// drivePID(10);
// turnPID(145,0.26,0,0);
// Arm1.spin(forward,100,percent);
// drivePID(20);
// drivePID(2);
// turnPID(180,0.26,0,0);
// drivePID(-13);
// Arm2.spin(forward,200,percent);
// wait(2,sec);
// drivePID(13);
// turnPID(-90,0.26,0,0);
// drivePID(-100);
}


void SkillsAuton(){
  drivePidParams setting = {};
  setting.maxSpeed = 30.0;
  drivePID(-10);
  drivePID(5);
  drivePID(-15);
  drivePID(10);
  drivePID(-14);
  drivePID(5);
  drivePID(-17);
  drivePID(3);
  drivePID(-5);
  drivePID(3);
  
 


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

void Auton(){
//nom nom  
}



