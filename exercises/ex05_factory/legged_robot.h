#include "robot.h"

class LeggedRobot : public Robot {
public:
  LeggedRobot() : leg_count_(4) {}
  LeggedRobot(int leg_count);

  // Perform the motion to move the robot
  void UpdatePosition(int time);
  void Turn(float degrees);

  void set_leg_count_(int legs) {leg_count_ = legs;}
  int get_leg_count_() {return leg_count_;}

private:
  int leg_count_;
};
