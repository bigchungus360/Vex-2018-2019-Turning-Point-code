#include "main.h" // includes API.h and other headers
#include "chassis.h"
#include "ports.h" // All port definitions on the cortex

void chassisSet(int left, int right) {
  motorSet(L_DRIVE, left);
  motorSet(R_DRIVE, right);
}

void drivePID() {
  // USE PID to drive straight forever
  int masterPower = 30;
  int slavePower = 30;
  int error = 0;
  int kp = 5;
  //Reset the encoders.
  encoderReset(encoderLD);
  encoderReset(encoderRD);
  //Repeat ten times a second.
  while(true) {
    //Set the motor powers to their respective variables.
    motorSet(L_DRIVE, masterPower);
    motorSet(R_DRIVE, -slavePower);
    error = encoderGet(encoderLD) - encoderGet(encoderRD);
    slavePower += error / kp;
    //Reset the encoders every loop.
    encoderReset(encoderLD);
    encoderReset(encoderRD);
    wait(100);
  }
}
