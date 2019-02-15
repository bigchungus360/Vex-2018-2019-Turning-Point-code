/** @file auto.c
 * @brief File for autonomous code
*/

 #include "main.h" // includes API.h and other headers
 #include "chassis.h" // redundant, but ensures that the corresponding header file (chassis.h) is included
 #include "lift.h" // redundant, but ensures that the corresponding header file (lift.h) is included
 #include "flippy.h" // redundant, but ensures that the corresponding header file (flippy.h) is included
 #include "ports.h" //includes ports.h which lists all motor ports

void autonomous() {

  /*driveForDistancePID(120, -127); //backwards
  driveForDistancePID(120, 127); //forwards
  chassisSet(127, -127);
  delay(100);
  driveForDistancePID(120, -127); //backwards*/

  chassisSet(-127, -127);
  delay(2000);

  //RED PARK
  //chassisSet(-127, 127);
  //delay(100);

  chassisSet(127, 127);
  delay(3000);

  //BLUE PARK
  chassisSet(-127, 127);
  delay(740);

  //RED PARK
  //chassisSet(127, -127);
  //delay(600);

  chassisSet(-127, -127);
  delay(3200);

}
