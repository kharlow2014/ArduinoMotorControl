// Keaton Harlow
// This program is a work in progress and will be used to control
// an electric actuator through an h-bridge. The arduino used for this
// project was a Feather 32u4. The h-bridge that I used to test this
// code was a homemade h-bridge using a few MOSFETs I had lying
// around.

#include "Arduino.h"
#include "MotorControl.h"

// MotorControl.cpp

// Default constructor
// Pins set to 13 becasue this is typically the onboard LED pin.
// Also instructs the Arduino that the pins will be used for digital 
// output and sets them LOW to ensure the pins are not activated.
MotorControl::MotorControl() {
  extPin = 13;
  retPin = 13;
  pinMode(extPin, OUTPUT);
  digitalWrite(extPin, LOW);
  pinMode(retPin, OUTPUT);
  digitalWrite(retPin, LOW);
}

// Constructor to set values of extPin and retPin.
// Also instructs the Arduino that the pins will be used for digital 
// output and sets them LOW to ensure the pins are not activated.
MotorControl::MotorControl(int ext, int ret) {
  extPin = ext;
  retPin = ret;
  pinMode(extPin, OUTPUT);
  digitalWrite(extPin, LOW);
  pinMode(retPin, OUTPUT);
  digitalWrite(retPin, LOW);
}

// Set the extend pin
// Writes the existing pin to LOW to prevent unwanted actions, sets
// the new pin, instructs the Arduino that it is for digital output,
// then sets the pin LOW to ensure the pin is not active
void MotorControl::setExtPin(int ext) {
  digitalWrite(extPin, LOW);
  extPin = ext;
  pinMode(extPin, OUTPUT);
  digitalWrite(extPin, LOW);
}

// Set the retract pin
// Writes the existing pin to LOW to prevent unwanted actions, sets
// the new pin, instructs the Arduino that it is for digital output,
// then sets the pin LOW to ensure the pin is not active
void MotorControl::setRetPin(int ret) {
  digitalWrite(retPin, LOW);
  retPin = ret;
  pinMode(retPin, OUTPUT);
  digitalWrite(retPin, LOW);
}

// Writes both pin outputs to low to stop the actuator
void MotorControl::kill() {
  digitalWrite(extPin, LOW);
  digitalWrite(retPin, LOW);
}

// Accepts a boolean to determine whether to extend or retract the actuator
// false to retract
// true to extend
void MotorControl::actuate(boolean extRet) {
  MotorControl::kill();
  // If extRet is false, set extPin -> LOW, retPin -> HIGH
  if(!extRet) {
    digitalWrite(extPin, LOW);
    digitalWrite(retPin, HIGH);
  }

  // Else, set retPin -> LOW, extPin -> HIGH
  else {
    digitalWrite(retPin, LOW);
    digitalWrite(extPin, HIGH);
  }
}

