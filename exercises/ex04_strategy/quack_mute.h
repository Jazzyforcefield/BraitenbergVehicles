#ifndef MUTE_H_
#define MUTE_H_

#include <iostream>
#include <cstdlib>

#include "quack.h"

class Mute : public QuackBehavior {
public:
  Mute() {
    volume_ = 0;
  }
  void Quack() {
    std::cout << "Cannot talk." << std::endl;
  }
};

#endif
