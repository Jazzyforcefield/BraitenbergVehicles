#include <cmath>

#include "sensors.h"

struct Velocity {
  int angle_;
  int speed_;
  Velocity(int angle=0, int speed=0) :
    angle_(angle), speed_(speed) {}
  Velocity(const Velocity& vel) {
    angle_ = vel.angle_;
    speed_ = vel.speed_;
  }
};
struct Position {
  float x_;
  float y_;
  Position(int x=0, int y=0) : x_(x), y_(y) {}
  Position(const Position& pos) {
    x_ = pos.x_;
    y_ = pos.y_;
  }
};

class Robot {
public:
  Robot() {
    velocity_ = new Velocity(45,5);
    position_ = new Position;
  }
  // Perform the motion to move the robot
  virtual void UpdatePosition(int time) {
    int distance = time*get_velocity().speed_;
    Position current_position = get_position();
    //int right_signal = sensors_.get_right();
    //int left_signal = sensors_.get_left();
    int new_x = current_position.x_ + distance*cos(get_velocity().angle_);
    int new_y = current_position.y_ + distance*sin(get_velocity().angle_);
    set_position(Position(new_x,new_y));
    std::cout << "Moved to [" << new_x << "," << new_y << "]" << std::endl;
  };

  virtual void Turn(float degrees) {
      velocity_->angle_ += degrees;
  }
  // setters and getters for private member variables
  void set_position(Position pos) {
    position_->x_ = pos.x_;
    position_->y_ = pos.y_;
  }
  Position get_position() { return *position_; }
  void set_velocity(Velocity vel) {
    velocity_->angle_ = vel.angle_;
    velocity_->speed_ = vel.speed_;
  }
  Velocity get_velocity() { return *velocity_; }
protected:
  Position * position_;
  Velocity * velocity_;
  Sensors sensors_;
};
