// Copyright 2019, Michael Ung

#ifndef SRC_LOVEBEHAVIOR_H_
#define SRC_LOVEBEHAVIOR_H_

#include "src/WheelBehavior.h"

NAMESPACE_BEGIN(csci3081);

  /**
   *  @brief Love behavior used to calculate wheel velocity in vehicles
   */
class LoveBehavior : public WheelBehavior {
 public:
  ~LoveBehavior() {}

  /**
   *  @brief Calcualtes wheel velocity for given parameters
   *  @param[in] Sensor reading right
   *  @param[in] Sensor reading left
   *  @param[in] maxSpeed
   */
  WheelVelocity WheelUpdate(double lSens, double rSens, double sp) override;
};

NAMESPACE_END(csci3081);

#endif  // SRC_LOVEBEHAVIOR_H_
