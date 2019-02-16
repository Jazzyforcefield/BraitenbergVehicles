#include <iostream>
#include <cstdlib>

#include "duck.h"

Duck::Duck() {}

void Duck::Display() {
  std::cout << "I am a duck." << std::endl;
}

void Duck::Fly() {
  fly_behavior_.Fly();
}

void Duck::Quack() {
  quack_behavior_.Quack();
}
