// Copyright 2019, Michael Ung

#include <iostream>

#include "Factory.h"

NAMESPACE_BEGIN(csci3081);

void Factory::Create(__unused ArenaEntity ** ent) {
  std::cout << "Inside Create(Robot ** ent)" << std::endl;
}

Factory::~Factory() {}

NAMESPACE_END(csci3081);
