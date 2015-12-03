#ifndef HELPER_H
#define HELPER_H 1

#include "config.h"

void driveTime(int speed, int millis);
void driveDistance(int speed, float distance);
void leftMotor(int speed);
void rightMotor(int speed);
void moveMotor(tMotor mot, int speed);
void pivot(int speed, int millis);
void servoAngle(TServoIndex srv, int angle, int max);

#endif
