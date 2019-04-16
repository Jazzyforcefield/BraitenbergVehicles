// Copyright 2019, Michael Ung

#ifndef SRC_AGGRESSIVEBEHAVIOR_H_
#define SRC_AGGRESSIVEBEHAVIOR_H_


#include "src/WheelBehavior.h"

NAMESPACE_BEGIN(csci3081);

  /**
   *  @brief Aggressive behavior used to calculate wheel velocity in vehicles
   */
class AggressiveBehavior : public WheelBehavior {
 public:
  ~AggressiveBehavior() {}

  /**
   *  @brief Calcualtes wheel velocity for given parameters
   *  @param[in] Sensor reading right
   *  @param[in] Sensor reading left
   *  @param[in] maxSpeed
   */
  WheelVelocity WheelUpdate(double lSens, double rSens, double sp) override;
};

NAMESPACE_END(csci3081);

#endif  // SRC_AGGRESSIVEBEHAVIOR_H_

