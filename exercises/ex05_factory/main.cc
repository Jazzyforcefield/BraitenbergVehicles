#include <iostream>
#include <cstdlib>

#include "FactoryPointer.h"

int main() {
	Robot * robot;
	LeggedRobot * legged;
	FactoryPointer * robot_factory = new FactoryPointer();
	
	robot_factory->Create(&robot);
	robot_factory->Create(&legged);

  for (int i=0; i<2; i++) {
		robot->UpdatePosition(1);
		legged->UpdatePosition(1);	
  }
}
