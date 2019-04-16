// Copyright 2019, Michael Ung

#ifndef SRC_SUBJECT_H_
#define SRC_SUBJECT_H_

#include "src/Observer.h"

NAMESPACE_BEGIN(csci3081);

  /**
   *  @brief Abstract base subject class
   */
class Subject {
 public:
  virtual ~Subject() {}
  /**
   *  @brief Subscribes to an observer
   *  @param[in] Takes in the observer to subscribe to
   */
  virtual void Subscribe(__unused Observer * observer) {}

  /**
   *  @brief Unsubscribes to an observer
   */
  virtual void Unsubscribe() {}

  /**
   *  @brief Notifies observer of information update
   */
  virtual void Notify() {}
};

NAMESPACE_END(csci3081);

#endif  // SRC_SUBJECT_H_
