// Copyright 2019, Michael Ung

#ifndef SRC_LOVEBEHAVIOR_H_
#define SRC_LOVEBEHAVIOR_H_

#include "src/WheelBehavior.h"

NAMESPACE_BEGIN(csci3081);

class LoveBehavior : public WheelBehavior {
 public:
  ~LoveBehavior() {};
  WheelVelocity WheelUpdate(double lSens, double rSens, double sp) override;
};

NAMESPACE_END(csci3081);

#endif // SRC_LOVEBEHAVIOR_H_
