#include "config.h"
#include "helpers.c"

/**
 * initializeRobot zero out sensors, and set servos to starting positions.
 */
void initializeRobot()
{
  return;
}

task main()
{
  initializeRobot();
  waitForStart(); // TODO: potentially remove this line

  // TODO: place autonomous code here
}
