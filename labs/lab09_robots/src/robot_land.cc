/**
 * @file robot_land.cc
 *
 * @copyright 201 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_land.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

Robot * RobotLand::get_robot(int id) {
  if (id == 0) {
    return robot0_;
  }
  return robot1_;
}

// Hard coded for now...
void RobotLand::get_obstacle_pos(double *x_pos, double *y_pos) {
  *x_pos = 200;
  *y_pos = 300;
}
