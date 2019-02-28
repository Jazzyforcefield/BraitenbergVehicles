#ifndef QUACK_H_
#define QUACK_H_

#include <iostream>
#include <cstdlib>

const int kDB_DEFAULT=10;

class QuackBehavior {
public:
  QuackBehavior();
  void Quack();
protected:
  float volume_;
};


#endif
