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
// Hard coded for 2 robots moving in circular patterns
int robot_land::get_num_robots(void) { return 2; }

// Hard coded for now...
// Once the robot class is added, this getter should call the robot getters
bool robot_land::get_robot_pos(int id, double *x_pos, double *y_pos) {
  if (id == 0) {
    *x_pos = circle_x(sim_time);
    *y_pos = circle_y(sim_time);
    return true;
  } else if (id == 1) {
    // make this robot slower
    double t = 0.75 * sim_time;
    *x_pos = circle_x(t);
    *y_pos = circle_y(t);
    return true;
  } else {
    return false;
  }
}

// Hard coded for now...
// Once the robot class is added, this getter should call the robot getters
// Notice the use of "id" -- how will you handle this in your robot class??
bool robot_land::get_robot_vel(int id, double *x_vel, double *y_vel) {
  double xnow, ynow, xprev, yprev;
  double delta = 0.1;
  if (id == 0) {
    xnow = circle_x(sim_time);
    ynow = circle_y(sim_time);
    xprev = circle_x(sim_time - delta);
    yprev = circle_y(sim_time - delta);

    *x_vel = xnow - xprev;
    *y_vel = ynow - yprev;
    return true;
  } else if (id == 1) {
    // make this robot slower
    double t = 0.75 * sim_time;
    xnow = circle_x(t);
    ynow = circle_y(t);
    xprev = circle_x(t - delta);
    yprev = circle_y(t - delta);

    *x_vel = xnow - xprev;
    *y_vel = ynow - yprev;
    return true;
  } else {
    return false;
  }
}

// Hard coded for now...
double robot_land::get_robot_radius() { return 50; }

// Hard coded for now...  in radians
double robot_land::get_robot_sensor_angle() { return 2.0; }

// Hard coded for now...
double robot_land::get_robot_sensor_distance() {
  return 3.0 * get_robot_radius();
}

// Hard coded for now...
int robot_land::get_num_obstacles() { return 1; }

// Hard coded for now...
bool robot_land::get_obstacle_pos(int id, double *x_pos, double *y_pos) {
  if (id == 0) {
    *x_pos = 200;
    *y_pos = 300;
    return true;
  }
  return false;
}

// Hard coded for now...
double robot_land::get_obstacle_radius() { return 75; }
