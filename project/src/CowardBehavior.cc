// Copyright 2019, Michael Ung

#include "CowardBehavior.h"

NAMESPACE_BEGIN(csci3081);

WheelVelocity CowardBehavior::WheelUpdate(double lSens, double rSens, double sp) {
  return WheelVelocity(lSens, rSens, sp);
}

NAMESPACE_END(csci3081);
