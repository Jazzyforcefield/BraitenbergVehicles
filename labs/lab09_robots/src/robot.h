#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "point.h"

/**
 * @brief An entity in RobotLand that moves around the window.
 *
 * Its id, size, initial position, and velocity are fixed.
 * The position and direction are updated at each frame refresh.
 * The color can be changed via a user button in the RobotViewer.
 */
class Robot {

public:
  /**
   * @brief A Robot is instantiated with a user-defined id, radius, and origin.
   * The constructor must also set the position, direction, color,
   * and sensor range and angle.
   *
   * @param[in] id The identifying number of the robot (now just 0 or 1)
   * @param[in] radius The radius of the graphics circle representing the robot.
   * @param[in] origin The {x,y} position around which the robot rotates.
   * @param[in] speed It controls the speed at which robot moves in circle
   */
	Robot(int id, double radius, Point origin, double speed);

  /**
    * @brief Given time, update the {x,y} position and direction angle of the Robot.
    *
    * @param[in] time The sim_time since the start of the simulator.
    */    
  void Update(double time);

  bool get_color();
  void set_color(bool color);
  int get_id();
  double get_radius();
  Point get_position();
  double get_direction();
  double get_sensor_angle();
  double get_sensor_range();

private:
  int id_;
  double radius_;  // pixel units for size of robot in graphics window.
  bool color_;     // "true" will color in the robot, "false" leaves it white.
  Point origin_;   // center of circle around which robot is rotating
  double speed_;    // fixed constant to control rate of movement
  Point position_; // current {x,y} position in graphics window
  double direction_; // current directional angle in radians
  double sensor_angle_; // angle between sensors relative to robot center.
  double sensor_range_;  // distance range of sensor.
};

#endif /* SRC_ROBOT_H_ */
