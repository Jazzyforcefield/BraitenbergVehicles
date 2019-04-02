// Copyright 2019, Michael Ung

#include "AggressiveBehavior.h"

NAMESPACE_BEGIN(csci3081);

WheelVelocity AggressiveBehavior::WheelUpdate(double lSens, double rSens, double sp) {
  return WheelVelocity(rSens, lSens, sp);
}

NAMESPACE_END(csci3081);
