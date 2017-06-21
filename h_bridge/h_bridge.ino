// Keaton Harlow
// 4/19/2017
// Test for h-bridge using a microcontroller
// One button for forward, one button for reverse

#include <MotorControl.h>

// Defining the pins for forward and reverse output
#define EXTEND       2
#define RETRACT      3
// Defining the pins for forward and reverse input
#define EXT_BUTTON   10
#define RET_BUTTON   11

// Initialize the MotorControl object
MotorControl motor(EXTEND, RETRACT);

// int to keep track of the status of the two buttons
int fbutton = 0;
int rbutton = 0;

void setup() {
  pinMode(EXT_BUTTON, INPUT);
  pinMode(RET_BUTTON, INPUT);
}

void loop() {
  // Read the status of the two buttons
  fbutton = digitalRead(EXT_BUTTON);
  rbutton = digitalRead(RET_BUTTON);
  
  // Execute the motion according to the status of the buttons.
  // If one is LOW and the other is HIGH, it moves in the corresponding direction
  // If both are LOW or both are HIGH, stop motion
  if(fbutton == HIGH && rbutton == LOW) motor.actuate(true);
  else if(rbutton == HIGH && fbutton == LOW) motor.actuate(false);
  else motor.kill();
}
