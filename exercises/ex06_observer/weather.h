#ifndef WEATHER_H_
#define WEATHER_H_

#include "state.h"
#include "subject.h"

class Weather : public Subject {
public:
  Weather(State s);
  void Notify();
  int TakeMeasurements();
private:
  State state_;
};

#endif
