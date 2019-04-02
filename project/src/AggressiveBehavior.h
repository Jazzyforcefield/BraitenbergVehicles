// Copyright 2019, Michael Ung

#ifndef SRC_AGGRESSIVEBEHAVIOR_H_
#define SRC_AGGRESSIVEBEHAVIOR_H_


#include "src/WheelBehavior.h"

NAMESPACE_BEGIN(csci3081);

class AggressiveBehavior : public WheelBehavior {
 public:
  ~AggressiveBehavior() {};
  WheelVelocity WheelUpdate(double lSens, double rSens, double sp) override;
};

NAMESPACE_END(csci3081);

#endif // SRC_AGGRESSIVEBEHAVIOR_H_

