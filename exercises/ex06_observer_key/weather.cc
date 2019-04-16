#include <iostream>

#include "weather.h"

Weather::Weather(State s) : state_(s) {}

void Weather::Notify() {
  for (auto obs : observers_) {
    obs->Update(state_);
  }
}

int Weather::TakeMeasurements() {
  std::cout << "Temperature Change: ";
  std::cin >> state_.temperature;
  if ( state_.temperature < -100 ) {
    return 0;
  } else {
    Notify();
  }
  return 1;
}
