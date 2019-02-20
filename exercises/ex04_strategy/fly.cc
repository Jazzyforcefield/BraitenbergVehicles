#include <iostream>
#include <stdlib.h>

#include "fly.h"

FlyBehavior::FlyBehavior() : miles_per_hour_(kMPH_DEFAULT) {}

void FlyBehavior::Fly() {
  std::cout << "Generic Flying at " << miles_per_hour_ << " mph." << std::endl;
}
