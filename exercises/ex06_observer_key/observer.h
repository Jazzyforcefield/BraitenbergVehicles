#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <iostream>

#include "state.h"
#include "subject.h"

class Subject;

class Observer {
public:
  Observer(Subject * subject) : subject_(subject) {}
  virtual void Update(const State& state) {}
protected:
  Subject * subject_;
};

#endif
