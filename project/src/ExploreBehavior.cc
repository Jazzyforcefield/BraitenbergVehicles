// Copyright 2019, Michael Ung

#include "ExploreBehavior.h"

NAMESPACE_BEGIN(csci3081);

WheelVelocity ExploreBehavior::WheelUpdate(double lSens, double rSens, double sp) {
    double t1 = 1/lSens, t2 = 1/rSens;
  if (t1 > sp) {
    t1 = sp;
  } 
  if (t2 > sp) {
    t2 = sp;
  }
  
    return WheelVelocity(t2, t1);
}

NAMESPACE_END(csci3081);
