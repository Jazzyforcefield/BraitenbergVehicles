// Copyright 2019, Michael Ung

#include "LoveBehavior.h"

NAMESPACE_BEGIN(csci3081);

WheelVelocity LoveBehavior::WheelUpdate(double lSens, double rSens, double sp) {
  double t1 = 1/lSens, t2 = 1/rSens;
  if (t1 > sp) {
    t1 = sp;
  } 
  if (t2 > sp) {
    t2 = sp;
  }
  
    return WheelVelocity(t1, t2);
}

NAMESPACE_END(csci3081);
