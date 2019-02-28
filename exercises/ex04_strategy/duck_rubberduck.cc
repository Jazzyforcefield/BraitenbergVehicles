#include <iostream>
#include <cstdlib>

#include "duck_rubberduck.h"
#include "fly_nofly.h"
#include "quack_squeaking.h"

RubberDuck::RubberDuck() {
  set_fly(NoFly());
  set_quack(Squeaking(2));
}

void RubberDuck::Display() {
  std::cout << "I am a Rubber Duck." << std::endl;
}
