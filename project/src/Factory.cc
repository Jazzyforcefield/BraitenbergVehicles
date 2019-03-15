// Copyright 2019, Michael Ung

#include <iostream>

#include "src/Factory.h"

NAMESPACE_BEGIN(csci3081);

void Factory::Create(__unused ArenaEntity ** ent,
                    __unused json_object& entity_config) {
  std::cout << "Inside Create(Robot ** ent)" << std::endl;
}

Factory::~Factory() {}

NAMESPACE_END(csci3081);
