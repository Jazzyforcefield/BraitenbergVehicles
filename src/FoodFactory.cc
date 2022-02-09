// Copyright 2019, Michael Ung

#include <iostream>

#include "src/FoodFactory.h"
#include "src/food.h"

NAMESPACE_BEGIN(csci3081);

FoodFactory::FoodFactory() {}

void FoodFactory::Create(ArenaEntity ** ent, json_object* entity_config) {
  // std::cout << "Inside FoodFactory's create\n" << std::endl;
  *ent = new Food();
  (*ent)->LoadFromObject(entity_config);
}

FoodFactory::~FoodFactory() {}

NAMESPACE_END(csci3081);
