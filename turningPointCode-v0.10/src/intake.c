#include "main.h" // includes API.h and other headers
#include "intake.h"
#include "ports.h" // All port definitions on the cortex

void intakeSet(int inSpeed) {
  motorSet(INTAKE, inSpeed);
}
