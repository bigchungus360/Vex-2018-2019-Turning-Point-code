#include "main.h" // includes API.h and other headers
#include "lift.h"
#include "ports.h" // All port definitions on the cortex

void liftSet(int liftSpeed) {
  motorSet(LIFT, liftSpeed);
}
