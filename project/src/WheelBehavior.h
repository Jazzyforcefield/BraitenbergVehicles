// Copyright 2019, Michael Ung

#ifndef SRC_WHEELBEHAVIOR_H_
#define SRC_WHEELBEHAVIOR_H_

#include "src/wheel_velocity.h"

NAMESPACE_BEGIN(csci3081);

class WheelBehavior {
 public:
  virtual ~WheelBehavior() {}

  /**
   *  @brief Calcualtes wheel velocity for given parameters
   *  @param[in] Sensor reading right
   *  @param[in] Sensor reading left
   *  @param[in] maxSpeed
   */
  virtual WheelVelocity WheelUpdate(double h, double s, double sp) = 0;
};

NAMESPACE_END(csci3081);

#endif  // SRC_WHEELBEHAVIOR_H_ //
