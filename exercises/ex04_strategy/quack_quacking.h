#ifndef QUACKING_H_
#define QUACKING_H_

#include <iostream>
#include <cstdlib>

#include "quack.h"

class Quacking : public QuackBehavior {
public:
  Quacking() {}
  void Quack() {
    std::cout << "Quack at " << volume_ << " decibels." << std::endl;
  }
};

#endif
