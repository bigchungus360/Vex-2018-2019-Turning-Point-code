#include "main.h" // includes API.h and other headers
#include "flippy.h"
#include "ports.h" // All port definitions on the cortex

void flipSet(int flipSpeed) {
  motorSet(FLIPPY, flipSpeed);
}
