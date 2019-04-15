#include <iostream>

#include "database.h"

void Database::Update(const State& state) {
  state_ = state;
  Save();
}

void Database::Save() {
  std::cout << "Database Report: saving new weather info" << std::endl;
}
