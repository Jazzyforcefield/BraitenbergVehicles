// Copyright 2019, Michael Ung

#ifndef SRC_OBSERVER_H_
#define SRC_OBSERVER_H_

#include <vector>
#include "src/wheel_velocity.h"

NAMESPACE_BEGIN(csci3081);

class Observer {
 public:
  virtual ~Observer() {}
  /**
   *  @brief Updates the current information in the observer class
   */
  virtual void Update(std::vector<WheelVelocity>) {}
};

NAMESPACE_END(csci3081);

#endif  // SRC_OBSERVER_H_
