#ifndef HELPER_H
#define HELPER_H 1

#include "config.h"

void driveTime(float speed, int millis);
void driveDistance(float speed, float distance);
void leftMotor(float speed);
void rightMotor(float speed);
void moveMotor(tMotor mot, float speed);
void pivot(float speed, int millis);
void servoAngle(TServoIndex srv, int angle, int max);

#endif
