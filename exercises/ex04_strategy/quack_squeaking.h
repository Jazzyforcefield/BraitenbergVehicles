#ifndef SQUEAKING_H_
#define SQUEAKING_H_

#include <iostream>
#include <cstdlib>

#include "quack.h"

class Squeaking : public QuackBehavior {
public:
  Squeaking() {}
  Squeaking(int d) {
    volume_ = d;
  }
  void Quack() {
    std::cout << "Squeak at " << volume_ << " decibels." << std::endl;
  }
};

#endif
