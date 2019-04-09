// Copyright 2019, Michael Ung

#ifndef SRC_EXPLOREBEHAVIOR_H_
#define SRC_EXPLOREBEHAVIOR_H_

#include "src/WheelBehavior.h"

NAMESPACE_BEGIN(csci3081);

class ExploreBehavior : public WheelBehavior {
 public:
  ~ExploreBehavior() {}
  WheelVelocity WheelUpdate(double lSens, double rSens, double sp) override;
};

NAMESPACE_END(csci3081);

#endif  // SRC_EXPLOREBEHAVIOR_H_
