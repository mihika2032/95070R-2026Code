/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       katherinezeng                                             */
/*    Created:      5/27/2025, 10:30:19 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/


#include "vex.h"
#include "robot-config.h"
#include "PID.h"
#include "autons.h"
#include "auton-selector.h"
#include "arm.h"
#include "functions.h"

using namespace vex;

// A global instance of competition
competition Competition;


// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...


  vexcodeInit();
  displayAutonSelector();
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  
  switch (getSelectedAuton()) {
    case 0:
      AWP();
      break;
    case 1:
      SkillsAuton();
      break;
    case 2:
      HighGoalRAuton();
      break;
    case 3:
      HighGoalLAuton();
      break;
    case 4:
      SkillsParking();
      break;
    case 5:
      Auton();
      break;

    default:
      Brain.Screen.print("No valid auton selected");
      break;
  }
 


}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

bool inauton = false;

// Drive train functions in functions.cpp


// User control function
void usercontrol(void) {
  bool prevPressed = false;
  bool descorerExtended = false;
  bool matchloaderExtended = false;
 
  while (1){
    double fwd = Controller.Axis3.position();
    double turn = Controller.Axis4.position();


    double left = fwd + turn;
    double right = fwd - turn;
    if(fabs(right) < 5 && fabs(left) > 5){
      RB.stop(coast);
      RF.stop(coast);
      RM.stop(coast);
      LB.stop(coast);
      LF.stop(coast);
      LM.stop(coast);
    }
    else{
      RF.spin(forward, right, percent);
      RB.spin(forward, right, percent);
      RM.spin(forward, right, percent);
      LF.spin(forward, left, percent);
      LB.spin(forward, left, percent);
      LM.spin(forward, left, percent);
    }
    wait(20, msec);
    
    //  //========== DRIVE CONTROL ========== //
    // double fwd = Controller.Axis3.position();
    // double turn = Controller.Axis4.position() * 0.5;
     

    // double leftPower = fwd + turn;
    // double rightPower = fwd - turn;
  
    // spinLeftDT(leftPower*0.7);
    // spinRightDT(rightPower*0.7);
   //========== ARM CONTROL ========== //
   if (Controller.ButtonR1.pressing()) {
     Arm1.spin(forward, 100, percent);
     Arm2.spin(forward, 100, percent);
     } 
     else if (Controller.ButtonR2.pressing()) {
      Arm1.spin(reverse, 100, percent);
      Arm2.spin(reverse, 100, percent);
    } 
    else if (Controller.ButtonL2.pressing()) {
       Arm1.stop(hold);
       Arm2.spin(forward, 100, percent);
    }
    else if (Controller.ButtonL1.pressing()) {
       Arm2.stop(hold);
       Arm1.spin(forward, 100, percent);
    }
    else {
       Arm1.stop(brake);
       Arm2.stop(brake);
     }

    if (Controller.ButtonX.pressing() && !prevPressed){
      descorerExtended = !descorerExtended;
      prevPressed = true;
      descorer.set(descorerExtended);
      wait(0.3, sec);
    }
    
    if (!Controller.ButtonX.pressing() && prevPressed){
      prevPressed = false;
      wait(0.3, sec);
    }

    if (Controller.ButtonB.pressing() && !prevPressed){
      matchloaderExtended = !matchloaderExtended;
      prevPressed = true;
      matchloader.set(matchloaderExtended);
      wait(0.3, sec);
    }
    
    if (!Controller.ButtonB.pressing() && prevPressed){
      prevPressed = false;
      wait(0.3, sec);
    }
    //hw: different variable names to avoid confusion and make logic work

    // if (Controller.ButtonA.pressing() && !prevPressed){
    //   pistonExtended = !pistonExtended;
    //   prevPressed = true;
    //   mlm.set(pistonExtended);
    // }

    // if (!Controller.ButtonA.pressing() && prevPressed){
    //   prevPressed = false;
    // }

    wait(30, msec);
  }
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}