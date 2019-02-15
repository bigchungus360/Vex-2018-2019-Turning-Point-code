#include "main.h" // includes API.h and other headers
#include "chassis.h"
#include "ports.h" // All port definitions on the cortex

void chassisSet(int left, int right) {
  motorSet(L_DRIVE, left);
  motorSet(R_DRIVE, -right);
}

void driveForDistancePID(int distance, int speed_PID) {
  float wheelCircum = 4 * 3.14;
  int motorDegree = (distance / wheelCircum) * 360;  // cast into full degrees
  int totalTicks = 0;                                // track total traveled
  int slavePower = speed_PID - 5;
  int error = 0;
  int kp = 5;
  encoderReset(encoderLD);
  encoderReset(encoderRD);
  //printf("%d\n", motorDegree);
  while(abs(totalTicks) < motorDegree)  {
    motorSet(L_DRIVE, speed_PID);
    motorSet(R_DRIVE, -slavePower);
    printf("Enc L: %d ", encoderGet(encoderLD));
    printf("Enc R: %d", encoderGet(encoderRD));
    error = encoderGet(encoderLD) - encoderGet(encoderRD);
    slavePower += error / kp;
    wait(100);
    totalTicks+= encoderGet(encoderLD);
    //printf("%d\n", totalTicks);
  }
  motorSet(L_DRIVE, 0);
  motorSet(R_DRIVE, 0);
}
