#ifndef _CHASSIS_H_
#define _CHASSIS_H_

// Sets the speeds of the left and right wheels of the chassis
void chassisSet(int left, int right);
//Drive forward with PID
void driveForDistancePID(int distance, int speed_PID);

#endif // _CHASSIS_H_
