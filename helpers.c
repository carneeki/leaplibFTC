#include "helpers.h"

/**
 * Drive at a speed for a time (specified in milliseconds)
 * int speed from -100 to 100
 * int millis number of milliseconds to drive for
 */
void driveTime(int speed, int millis)
{
  float kLag = 0.9;

  // zero encoder values to ensure driving in a straight line
  nMotorEncoder[motorLeft] = 0;
  nMotorEncoder[motorRight] = 0;

  clearTimer(T1);
  while(time1[T1] < millis)
  {
    if(abs(nMotorEncoder[motorLeft]) < abs(nMotorEncoder[motorRight]))
    {
      // if left motor is too slow
      leftMotor(speed);
      rightMotor(speed * kLag);
    }
    else if(abs(nMotorEncoder[motorRight]) < abs(nMotorEncoder[motorLeft]))
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

    wait1Msec(5);
  }

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
    if(abs(nMotorEncoder[motorLeft]) < abs(nMotorEncoder[motorRight]))
    {
      // if left motor is too slow
      leftMotor(speed);
      rightMotor(speed * kLag);
    }
    else if(abs(nMotorEncoder[motorRight]) < abs(nMotorEncoder[motorLeft]))
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
    currentDistance = (abs(nMotorEncoder[motorLeft]) + abs(nMotorEncoder[motorRight]))/2;
  }

  // stop motors
  leftMotor(0);
  rightMotor(0);
}

/**
 * set left motor(s) to drive at a given speed
 * int speed from -100 to 100
 */
void leftMotor(int speed)
{
  moveMotor(motorLeft, speed);
  // TODO: uncomment the next line for quad motor configuration
  // moveMotor(motorLeft2, speed);
}

/**
 * set right motor(s) to drive at a given speed
 * int speed from -100 to 100
 */
void rightMotor(int speed)
{
  moveMotor(motorRight, speed);
  // TODO: uncomment the next line for quad motor configuration
  // moveMotor(motorRight2, speed);
}

/**
 * set an arbitrary motor to drive at a given speed
 * tMotor mot the motor to set
 * int speed from -100 to 100
 */
void moveMotor(tMotor mot, int speed)
{
  motor[mot] = speed;
}

/**
 * pivot clockwise at a given speed for a given time (millis)
 * float speed from -100 to 100
 * int millis number of milliseconds
 */
void pivot(int speed, int millis)
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
