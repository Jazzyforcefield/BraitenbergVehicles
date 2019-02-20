#include <iostream>
#include <cstdlib>

#include "duck_mallard.h"
#include "fly_with_wings.h"
#include "quack_quacking.h"

Mallard::Mallard() {
  // Mallards have typical flying and quacking behavior.
  set_fly(FlyWithWings());
  set_quack(Quacking());
}

void Mallard::Display() {
  std::cout << "I am a Mallard." << std::endl;
}
