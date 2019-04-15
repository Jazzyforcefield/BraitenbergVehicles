#ifndef VIEWER_H_
#define VIEWER_H_

#include "state.h"
#include "observer.h"
#include "subject.h"

class Viewer : public Observer {
public:
  Viewer(Subject * subject) : Observer(subject) {}
  void Update(const State& state);
  void Display();
private:
  State state_;
};

#endif
