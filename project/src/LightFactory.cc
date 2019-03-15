// Copyright 2019, Michael Ung

#include <iostream>

#include "src/LightFactory.h"
#include "src/light.h"

NAMESPACE_BEGIN(csci3081);

LightFactory::LightFactory() {}

void LightFactory::Create(ArenaEntity ** ent, json_object& entity_config) {
  // std::cout << "Inside LightFactory's create\n" << std::endl;
  *ent =  new Light();
  (*ent)->LoadFromObject(entity_config);
}

LightFactory::~LightFactory() {}

NAMESPACE_END(csci3081);
