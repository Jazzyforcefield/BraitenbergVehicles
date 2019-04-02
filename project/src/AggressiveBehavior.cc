// Copyright 2019, Michael Ung

#include "AggressiveBehavior.h"

NAMESPACE_BEGIN(csci3081);

WheelVelocity AggressiveBehavior::WheelUpdate(double lSens, double rSens, double sp) {
  double t1 = lSens, t2 = rSens;
  if (t1 > sp) {
    t1 = sp;
  } 
  if (t2 > sp) {
    t2 = sp;
  }
  return WheelVelocity(t2, t1);
}

NAMESPACE_END(csci3081);
