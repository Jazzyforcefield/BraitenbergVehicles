#ifndef FLY_WITH_WINGS_H_
#define FLY_WITH_WINGS_H_

#include <iostream>
#include <cstdlib>

#include "fly.h"

class FlyWithWings : public FlyBehavior {
public:
  FlyWithWings() {}
  void Fly() {
    std::cout << "Fly with wings at speed of ";
    std::cout << miles_per_hour_ << " mph." << std::endl;
  }
};

#endif
