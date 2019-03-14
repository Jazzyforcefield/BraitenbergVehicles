#include <iostream>

#include "weather.h"

Weather::Weather(State s) : state_(s) {}

void Weather::Notify() {
  for (auto obs : observers_) {
    obs->Update(state_);
  }
}

int Weather::TakeMeasurements() {
  double current;
  std::cout << "Current Temperature: ";
  std::cin >> current;
  if (state_.temperature < -99) {
    return 0; // use -100 as exit condition
  }
  if ( state_.temperature != current ) {
    // There is a weather change to report.
    state_.temperature = current;
    Notify();
  }
  return 1;
}
