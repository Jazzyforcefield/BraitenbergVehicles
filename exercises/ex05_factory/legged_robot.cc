#include <iostream>
#include <cmath>

#include "legged_robot.h"

LeggedRobot::LeggedRobot(int leg_count) : Robot(), leg_count_(leg_count) {
  velocity_->speed_ = 2;
}

// Perform the motion to move the robot
void LeggedRobot::UpdatePosition(int time) {
  int distance = time*get_velocity().speed_;
  Position current_position = get_position();
  //int right_signal = sensors_.get_right();
  //int left_signal = sensors_.get_left();
  int new_x = current_position.x_ + distance*cos(get_velocity().angle_);
  int new_y = current_position.y_ + distance*sin(get_velocity().angle_);
  set_position(Position(new_x,new_y));
  std::cout << "Moved to [" << new_x << "," << new_y << "]" << std::endl;
}

void LeggedRobot::Turn(float degrees) {
  std::cout << "Turning in place." << std::endl;
  set_velocity(Velocity(get_velocity().angle_+degrees, get_velocity().speed_));
}
