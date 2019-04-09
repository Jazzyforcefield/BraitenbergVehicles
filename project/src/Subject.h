// Copyright 2019, Michael Ung

#ifndef SRC_SUBJECT_H_
#define SRC_SUBJECT_H_

#include "src/Observer.h"

NAMESPACE_BEGIN(csci3081);

class Subject {
 public:
  virtual ~Subject() {}
  /**
   *  @brief Updates the current information in the observer class
   */
  virtual void Subscribe(__unused Observer * observer) {}

  /**
   *  @brief Updates the current information in the observer class
   */
  virtual void Unsubscribe() {}

  /**
   *  @brief Updates the current information in the observer class
   */
  virtual void Notify() {}
};

NAMESPACE_END(csci3081);

#endif  // SRC_SUBJECT_H_
