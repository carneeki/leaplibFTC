#ifndef HELPER_H
#define HELPER_H 1

#include "config.h"

/**
 * Drive at a speed for a time (specified in milliseconds)
 */
void driveTime(float speed, int millis)
{
  leftMotor(speed);
  rightMotor(speed);

  wait1Msec(millis);

  // stop motors
  leftMotor(0);
  rightMotor(0);
}

/**
 * Drive at a speed for a specific distance (specified in metres)
 */
void driveDistance(float speed, float distance)
{
  float kLag = 0.9; // scale back a motor that is running too fast
  float currentDistance = 0.0;

  // zero encoder values
  nMotorEncoder[motorLeft] = 0;
  nMotorEncoder[motorRight] = 0;
  wait1Msec(5);

  // drive while the current distance is less than the target distance
  while(currentDistance <= distance)
  {
    if(nMotorEncoder[motorLeft] < nMotorEncoder[motorRight])
    {
      // if left motor is too slow
      leftMotor(speed);
      rightMotor(speed * kLag);
    }
    else if(nMotorEncoder[motorRight] < nMotorEncoder[motorLeft])
    {
      // if right motor is too slow
      leftMotor(speed * kLag);
      rightMotor(speed);
    }
    else
    {
      leftMotor(speed);
      rightMotor(speed);
    }

    wait1Msec(5); // wait 5 millis to allow encoders to update
    currentDistance = (nMotorEncoder[motorLeft] + nMotorEncoder[motorRight])/2;
  }

  // stop motors
  leftMotor(0);
  rightMotor(0);
}

/**
 * set left motor(s) to drive at a given speed
 * float speed from -1.0 to 1.0
 */
void leftMotor(float speed)
{
  motor[motorLeft] = speed;
  // TODO: uncomment the next line for quad motor configuration
  // motor[motorLeft2] = speed;
}

/**
 * set right motor(s) to drive at a given speed
 * float speed from -1.0 to 1.0
 */
void rightMotor(float speed)
{
  motor[motorLeft] = speed;
  // TODO: uncomment the next line for quad motor configuration
  // motor[motorLeft2] = speed;
}

/**
 * pivot clockwise at a given speed for a given time (millis)
 * float speed from -1.0 to 1.0
 * int millis number of milliseconds
 */
void pivot(float speed, int millis)
{
  leftMotor(speed);
  rightMotor(-speed);

  wait1Msec(millis);

  leftMotor(0);
  rightMotor(0);
}

/**
 * servoAngle moves a servo to a given angle
 * TServoIndex srv a servo to be moved
 * int angle desired angle servo to be moved to
 * int max maximum angle setting
 */
void servoAngle(TServoIndex srv, int angle, int max)
{
  servo[srv] = (int) (angle/max) * 255;
}

#endif
