#include "config.h"                   // Motor and servo configuration
#include "helpers.c"                  // Helper functions

#include "JoystickDriver.c"           // Include file to "handle" the Bluetooth
                                      // messages.

/**
 * initializeRobot zero out sensors, and set servos to starting positions.
 */
void initializeRobot()
{
  return;
}

/**
 * The following is the main code for the tele-op robot operation. Customize as
 * appropriate for your specific robot.
 *
 * Game controller / joystick information is sent periodically (about every 50
 * milliseconds) from the FMS (Field Management System) to the robot. Most
 * tele-op programs will follow the following logic:
 *   1. Loop forever repeating the following actions:
 *   2. Get the latest game controller / joystick settings that have been
 *      received from the PC.
 *   3. Perform appropriate actions based on the joystick + buttons settings.
 *      This is usually a simple action:
 *      *  Joystick values are usually directly translated into power levels for
 *         a motor or position of a servo.
 *      *  Buttons are usually used to start/stop a motor or cause a servo to
 *         move to a specific position.
 *   4. Repeat the loop.
 *
 * Your program needs to continuously loop because you need to continuously
 * respond to changes in the game controller settings.
 *
 * At the end of the tele-op period, the FMS will autonmatically abort (stop)
 * execution of the program.
 */
task main()
{
  initializeRobot(); // run the initialize routine to zero sensors and servos
  waitForStart();    // wait for start of tele-op phase

  while(true)
  {
    // TODO: place teleop code here
    // typically this will involve taking Joystick values and mapping them to
    // either speeds or functions of the robot
  }
}
