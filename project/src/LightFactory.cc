// Copyright 2019, Michael Ung

#include <iostream>

#include "src/LightFactory.h"
#include "src/light.h"

NAMESPACE_BEGIN(csci3081);

LightFactory::LightFactory() {}

void LightFactory::Create(ArenaEntity ** ent) {
  // std::cout << "Inside LightFactory's create\n" << std::endl;
  *ent =  new Light();
}

LightFactory::~LightFactory() {}

NAMESPACE_END(csci3081);
