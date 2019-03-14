#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <iostream>
#include <vector>

#include "observer.h"

class Observer;

/*
The Observer pattern requires a Remove(Observer*) for this class.
Removing elements from a vector is not as straight-forward as it seems that it should be. Can you think of a way to use a flag to indicate whether or not the observer in the vector is actively observing?
*/
class Subject {
public:
  Subject() {}
  void RegisterObserver(Observer* o);
  virtual void Notify() = 0;
protected:
  std::vector<Observer*> observers_;
};

#endif
