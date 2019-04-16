// Copyright 2019, Michael Ung

#include "src/LoveBehavior.h"

NAMESPACE_BEGIN(csci3081);

WheelVelocity LoveBehavior::WheelUpdate(double lSens, double rSens, double sp) {
  return WheelVelocity(1/lSens, 1/rSens, sp);
}

NAMESPACE_END(csci3081);
