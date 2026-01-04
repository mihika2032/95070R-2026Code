#pragma once

/* These prevent header files from being included multiple times*/

struct drivePidParams {
  double maxSpeed = 100.0;
};


void drivePID(double targetInches, drivePidParams param = {}, double kP = 0.26, double kI = 0.0, double kD = 0.0);
void turnPID(double targetAngle, double kP, double kI, double kD);


