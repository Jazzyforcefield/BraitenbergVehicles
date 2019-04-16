#include <iostream>

#include "state.h"
#include "weather.h"
#include "viewer.h"
#include "database.h"

int main() {
  State state(20, 70, 30.4);
  Weather * weather = new Weather(state);

  Viewer * viewer = new Viewer(weather);
  weather->RegisterObserver(viewer);

  Database * db = new Database( weather );
  weather->RegisterObserver(db);

  while (true) {
    if (0==weather->TakeMeasurements()) {
      return 1;
    }
  }
}
