// Copyright 2019, Michael Ung

#include "src/ExploreBehavior.h"

NAMESPACE_BEGIN(csci3081);

WheelVelocity ExploreBehavior::WheelUpdate(double lSens,
    double rSens, double sp) {
  return WheelVelocity(1/rSens, 1/lSens, sp);
}

NAMESPACE_END(csci3081);
