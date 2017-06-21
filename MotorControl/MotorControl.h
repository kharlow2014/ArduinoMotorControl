// Keaton Harlow
// header file for MotorControl.cpp

#ifndef MotorControl_h
#define MotorControl_h

#include "Arduino.h"

class MotorControl {
  private:
    int extPin;
    int retPin;
  public:
    MotorControl();
    MotorControl(int, int);
    void setExtPin(int);
    void setRetPin(int);
    void kill();
    void actuate(boolean);
    void timedActuate(boolean, int);
};

#endif
