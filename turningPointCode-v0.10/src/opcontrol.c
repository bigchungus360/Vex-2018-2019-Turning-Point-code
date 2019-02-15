/* @file opcontrol.c
   @brief File for operator control code
*/
#include "main.h" // includes API.h and other headers
#include "chassis.h" // redundant, but ensures that the corresponding header file (chassis.h) is included
#include "lift.h" // redundant, but ensures that the corresponding header file (lift.h) is included
#include "flippy.h" // redundant, but ensures that the corresponding header file (flippy.h) is included
#include "ports.h" //includes ports.h which lists all motor ports
#include "intake.h"

void operatorControl() {

	//DISABLE IF COMP.
	/*
	bool auto_run = true;
	while(auto_run == true) {
		if(joystickGetDigital(1, 7, JOY_UP)) {
			autonomous();
		}
		if(joystickGetDigital(1, 7, JOY_RIGHT)) {
			auto_run = false;
		}
	}
	*/

	int left, right;
  int deadZone = 10; //amount of excluded deadzone
  int togglespeed = 1;
	while(1) {
		left = joystickGetAnalog(1, 3); // vertical axis on left joystick
		right = joystickGetAnalog(1, 2); // vertical axis on right joystick
		if(abs(left) <= deadZone) {
			left = 0;
		}
		if(abs(right) <= deadZone) {
			right = 0;
		}
    if(togglespeed == -1) {
      chassisSet(left / 2, right / 2);
    }
    else {
      chassisSet(left, right);
    }

    //togglespeed Code
    if(joystickGetDigital(1, 8, JOY_DOWN)) {
    	togglespeed *= -1;
    }

    //lift code
		if(joystickGetDigital(1, 6, JOY_UP)) { //pressing up
		   liftSet(-127);
		}
		else if(joystickGetDigital(1, 6, JOY_DOWN)) { //pressing down
			 liftSet(127);
		}
		else { //nothing, so zero
			 liftSet(0);
		}

    //flippy Code
		if(joystickGetDigital(1, 7, JOY_DOWN)) {
			 flipSet(127);
		}
		else if(joystickGetDigital(1, 7, JOY_RIGHT)) {
			 flipSet(-127);
		}
		else {
			 flipSet(0);
		}

		//intake Code
		if(joystickGetDigital(1, 5, JOY_UP)) {
			intakeSet(127);
		}
		else if(joystickGetDigital(1, 5, JOY_DOWN)) {
			intakeSet(-127);
		}
		else {
			intakeSet(-50);
		}
		//Celebration Code
		/*if(joystickGetDigital(1, 7, JOY_UP)) {
			const char* rtttl[] = {
    	"Super Mario:d=4,o=5,b=100:"
      	"16e6,16e6,32p,8e6,16c6,8e6,8g6,8p,8g,8p,"
      	"8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,16p,"
      	"8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,16p,"
      	"8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,"
      	"8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16c7,16p,16c7,16c7,8p.,"
      	"8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,"
      	"8p,16d#6,8p,16d6,8p,16c6",
    	"Super Mario:d=4,o=4,b=100:"
      	"16d,16d,32p,8d,16d,8d,8g5,8p,8g,8p,"
      	"8g5,16p,8e,16p,8c,16p,8f,8g,16f#,8f,16e.,16c5,16e5,8f5,16d5,8e5,8c5,16a,16b,8g,16p,"
      	"8g5,16p,8e,16p,8c,16p,8f,8g,16f#,8f,16e.,16c5,16e5,8f5,16d5,8e5,8c5,16a,16b,8g,16p,"
      	"8c,16p,16g,8p,8c5,8f,16p,16c5,16c5,16c5,8f,"
      	"8c,16p,16e,8p,16g,16c5,p.,8g,"
      	"8c,16p,16g,8p,8c5,8f,16p,16c5,16c5,16c5,8f,"
      	"8c,16g#,8p,16a#,8p,16c5",
    		NULL
  		};
  		speakerPlayArray(rtttl);
		}*/

    delay(20);
    }
	}
