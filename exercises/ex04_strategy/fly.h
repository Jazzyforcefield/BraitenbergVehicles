#ifndef FLY_H_
#define FLY_H_

#include <iostream>
#include <cstdlib>

const int kMPH_DEFAULT=5;

//-----------------------------------------------
//   FLYING

class FlyBehavior {
public:
  FlyBehavior();
  void Fly();
protected:
  float miles_per_hour_;
};

#endif
