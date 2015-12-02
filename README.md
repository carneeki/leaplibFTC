# leaplibFTC

A library for LEAP Robotics by Adam Carmichael <carneeki@carneeki.net> authored
in spare time.

## Autonomous Code
Place code in `autonomous.c`, specifically, look for a line to the effect of
```c
// TODO: place autonomous code here
```
in side the `task main()` block.

## Teleop Code
Place code in `teleop.c`, specifically, look for a line to the effect of
```c
// TODO: place teleop code here
```

Teleop code will typically be a short piece of code that is repeated over and
over. It will usually take input from the joystick and tell the robot to do
something with that input. Moving around, and making a manipulator (such as an
arm or plow upon a button being pushed) are common tasks.

## Helpers
`helpers.c` contains helper functions that are useful for both teleop and
autonomous programs. They are:

* `driveTime()` tells the robot to drive for a specific amount of time
* `driveDistance()` tells the robot to drive for a specific distance
* `pivot()` tells the robot to pivot (turn) in a clockwise direction for a
specific amount of time.
* `servoAngle()` tells the robot to move a servo to a specific angle.

In addition are two other functions:
* `leftMotor()`
* `rightMotor()`

These functions take a speed and tell the motor(s) to drive at that speed. If
you have only a single motor assigned to each side, these functions may be left
alone. If you have two motors assigned to each side, then these functions allow
you to tell both motors to drive easily.

Finally, there is one last function that is useful to move a motor that might
not be connected to drive (such as a winch motor):
* `moveMotor()` tells the robot to move a motor to move at a given speed.

### Conventions:
Speeds are a floating point value (a number with a decimal point) from -1.0 to
1.0.

Angles are an integer from 0 to 359 degrees.

Times are measured in milliseconds (or 'millis').

Distances are measured in metres.

### `driveTime()`
This function will tell the robot to drive in a straight line at a given speed
for a set time. It takes the form `driveTime(float speed, int millis)`.

Hint: Useful for autonomous!

Note: This function will not drive in a perfectly straight line, but it will try
it's best. If one side is lagging behind the other, it will slow down the fast
side.

### `driveDistance()`
This function will tell the robot to drive in a straight line at a given speed
for a certain distance. It takes the form
`driveDistance(float speed, float distance)`.

Hint: Useful for autonomous!

Note: This function will not drive in a perfectly straight line, but it will try
it's best. If one side is lagging behind the other, it will slow down the fast
side.

### `pivot()`
This function will tell the robot to pivot (turn on the spot) at a given speed
for a set time. It takes the form `pivot(float speed, int millis)`.

Hint: Use me to steer in autonomous!

Hint: It is probably useful to find out out how long it takes to pivot 90
degrees (eg 200ms) and make a note of that in the `config.h` file as a constant
using the `#define` notation. This is called "dead reckoning" where the robot
doesn't know which way it is facing, but it can take a guess based on how long
it has been turning. If the wheels skid (or is caught on an obstacle temporarily)
the robot will have no way of detecting this, and so it might be facing the
wrong way when it stops. Read the advanced hint for ways to get around this if
you think it is a big problem.

Advanced hint: pro-teams will use a gyro sensor when they want to turn a given
angle. A challenge for you will be to implement this if you get a gyro. A
recommended function prototype: `pivotAngle(float speed, int angle)`.

### `servoAngle()`
This function will tell the robot to move a servo to a given angle. It takes
the form `servoAngle(TServoIndex srv, int angle)`.

`servoAngle()` is useful to move an arm or gripper that is driven by a servo.

Hint: Useful in autonomous AND teleop.

Suppose you want to raise an arm connected to a 270 degree servo, where the
resting position is 0 degrees and the upright position is 90 degrees; the arm
should be held up for 5 seconds (while the robot does something else), and then
lowers back down:

```c
seroAngle(servoArm, 90, 270);
wait1Msec(5000);
servoAngle(servoArm, 0, 270);
```

We must specify the maximum angle of the servo, this is because some servos have
a maximum range of 180 degrees, some are 90, and some are 270 degrees. Servos
usually work with a percentage of their maximum travel, so the function will
calculate what the percentage is every time.

It might be useful to write your own function at the end of `helpers.h` that
might look like:
```c
void armUp()
{
  servoAngle(servoArm, 90, 270);
}

void armDown()
{
  servoAngle(servoArm, 0, 270);
}
```

So the example code might look like this:
```c
armUp();
wait1Msec(5000);
armDown();
```

### `motorLeft()` and `motorRight()`
These functions tell the robot to drive either the left or the right hand side
of the drive train at a specified speed, they take the form
`motorLeft(float speed)`.

A piece of tank drive code can be as simple as:
```c
while(true)
{
  getJoystickSettings(joystick); // get updates from the laptop

  motorLeft(joystick.joy1_y1);   // set  left motor(s) to Joystick Y1
  motorRight(joystick.joy1_y2);  // set right motor(s) to Joystick Y2
}
```

### `moveMotor()`
This function tells the robot to drive a specific motor at a given speed. It
takes the form `moveMotor(tMotor mot, float speed)`.

Say one wanted to drive a winch for 5 seconds, it could be done as follows:
```c
moveMotor(wichMotor, 1.0);
wait1Msec(5000); // wait 5 seconds
moveMotor(winchMotor, 0.0);
```
