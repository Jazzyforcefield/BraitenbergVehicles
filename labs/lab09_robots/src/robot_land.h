/**
 * @file robot_land.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_LAND_H_
#define SRC_ROBOT_LAND_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the simulation of a 2D world with two robots.
 *
 * RobotViewer or Tests call \ref set_time and \ref advance_time to control the
 * simulation and use the get*() functions to read out the current state of the
 * simulation (i.e., the current positions and orientations of robots and
 * obstacles).
 *
 *  For now, RobotLand is hard coded to run a simulation of two robots running
 *  around in a circle. Their positions on the circle are determined by the
 *  simulation time, their speed, and initial position. You can see their
 *  sensors, but they don't yet respond to each other or to obstacles.
 */
class RobotLand {
 public:
  RobotLand(void) {}

  /**
   * @brief Set the simulation time for \ref RobotLand.
   *
   * This function will be used mainly for testing purposes, as time flows in a
   * steady forward direction in general simulation.
   *
   * @param[in] t The new simulation time.
   */
  void set_time(double t) {
    sim_time_ = t;
    std::cout << "Setting simulation time to " << sim_time_ << std::endl;
  }

  /**
   * @brief Advance the simulation by the specified # of steps.
   *
   * @param[in] dt The # of steps to increment by.
   */

  // Once the robot class is created, this should call a robot method to
  // advance its position and set the velocity based on dt
  void AdvanceTime(double dt) {
    sim_time_ += dt;
    std::cout << "Advancing simulation time to " << sim_time_ << std::endl;
  }

  /**
   * @brief Get the current simulation time.
   */
  double get_current_time(void) { return sim_time_; }

  /*
   * @brief Get the current # of robots in the arena. Hardcoded for now.
   */
  int get_num_robots(void) { return 2; }

  /**
   * @brief Get the current position of the specified robot.
   *
   * @param[in] id The ID of the robot.
   * @param[out] x_pos The X position of the robot.
   * @param[out] y_pos The Y position of the robot.
   *
   * @return, true if id was valid, otherwise false.
   */
  bool get_robot_pos(int id, double *x_pos, double *y_pos);

  /**
   * @brief Get the current velocity of the specified robot. Currently a stub.
   *
   * @param[in] id The ID of the robot.
   * @param[out] x_vel The X component of velocity.
   * @param[out] y_vel The Y component of velocity.
   */
  bool get_robot_vel(int id, double *x_vel, double *y_vel);

  /**
   * @brief Get the radius of the specified robot. Hardcoded for now.
   *
   * @return The robot's radius.
   */
  double get_robot_radius() { return 50; }

  /**
   * @brief Get the angle of the robots sensor, in radians. Hardcoded for now.
   *
   * @return The sensor angle in radians,
   */
  double get_robot_sensor_angle() { return 2.0; }

  /**
   * @brief Get the distance of a specified robot's sensor.
   *
   * @return The sensor distance.
   */
  double get_robot_sensor_range() {
    return 3.0 * get_robot_radius(); }


  /**
   * @brief Get the position of the obstacle.
   *
   * @param[out] x_pos The X component of the position.
   * @param[out] y_pos The Y component of the position.
   *
   */
  void get_obstacle_pos(double *x_pos, double *y_pos);

  /**
   * @brief Get the radius of the obstacle.
   *
   * @return The obstacle's radius.
   */
  double get_obstacle_radius() { return 75; }

 private:
  // Hard coding these robots to move in a circle
  double circle_x(double t) { return 512 + 200.0 * cos(t); }
  double circle_y(double t) { return 350 + 200.0 * sin(t); }

  double sim_time_{0.0};
};

#endif  // SRC_ROBOT_LAND_H_
