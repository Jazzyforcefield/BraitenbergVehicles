#include <iostream>
#include <stdlib.h>

#include "quack.h"

QuackBehavior::QuackBehavior() : volume_(kDB_DEFAULT) {}

void QuackBehavior::Quack() {
  std::cout << "Generic Quack at " << volume_ << " decibels." << std::endl;
}
