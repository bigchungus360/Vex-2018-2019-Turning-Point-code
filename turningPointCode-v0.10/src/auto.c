/** @file auto.c
 * @brief File for autonomous code
*/

 #include "main.h" // includes API.h and other headers
 #include "chassis.h" // redundant, but ensures that the corresponding header file (chassis.h) is included
 #include "lift.h" // redundant, but ensures that the corresponding header file (lift.h) is included
 #include "flippy.h" // redundant, but ensures that the corresponding header file (flippy.h) is included
 #include "ports.h" //includes ports.h which lists all motor ports

void autonomous() {
  chassisSet(-90, 127);
  delay(2000);
  chassisSet(90, -127);
  delay(2000);
  chassisSet(90, 127);
  delay(740);
  chassisSet(90, -127);
  delay(1000);
  chassisSet(90, 127);
  delay(760);
  chassisSet(-90, 127);
  delay(2400);
  //chassisSet(100, -127);
  //delay(1500);
//  print
  //chassisSet(0, 0);
  //delay(1000000000);
  //delay(1000);
  /*driveForDistancePID(5, -127);

  chassisSet(127, -127);
  delay(100);

  driveForDistancePID(5, 127);
  */
}
