#include <iostream>
#include <vector>

#include "subject.h"

void Subject::RegisterObserver(Observer* o) {
  observers_.push_back(o);
}
