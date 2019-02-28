#include <iostream>
#include <cstdlib>

#include "legged_robot.h"

int main() {
  Robot * robots[3];
  robots[0] = new Robot;
  robots[1] = new LeggedRobot;
  robots[2] = new LeggedRobot(3);

  for (int i=0; i<3; i++) {
    robots[i]->UpdatePosition(1);
  }
}
