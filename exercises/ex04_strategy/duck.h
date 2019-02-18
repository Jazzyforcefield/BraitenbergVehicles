#ifndef DUCK_H_
#define DUCK_H_

#include <iostream>
#include <cstdlib>

#include "fly.h"
#include "quack.h"

class Duck {
public:
  Duck();
  void Display();
  void Fly();
  void Quack();
  void set_fly(FlyBehavior fly) {fly_behavior_ = fly; }
  void set_quack(QuackBehavior quack) {quack_behavior_ = quack; }
  //FlyBehavior get_fly() { return fly_behavior_; }
  //QuackBehavior get_quack() { return quack_behavior_; }
private:
  FlyBehavior fly_behavior_;
  QuackBehavior quack_behavior_;
};

#endif
