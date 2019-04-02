// Copyright 2019, Michael Ung

#ifndef SRC_COWARDBEHAVIOR_H_
#define SRC_COWARDBEHAVIOR_H_

#include "src/WheelBehavior.h"

NAMESPACE_BEGIN(csci3081);

class CowardBehavior : public WheelBehavior {
 public:
  ~CowardBehavior() {};
  WheelVelocity WheelUpdate(double lSens, double rSens, double sp) override;
};

NAMESPACE_END(csci3081);

#endif  // SRC_COWARDBEHAVIOR_H_
