#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <iostream>
#include <vector>

#include "observer.h"

class Observer;

class Subject {
public:
  Subject() {}
  void RegisterObserver(Observer* o);
  virtual void Notify() {}
protected:
  std::vector<Observer*> observers_;
};

#endif
