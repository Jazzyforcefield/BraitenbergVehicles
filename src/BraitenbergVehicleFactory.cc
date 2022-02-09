// Copyright 2019, Michael Ung

#include <iostream>

#include "src/BraitenbergVehicleFactory.h"
#include "src/braitenberg_vehicle.h"

NAMESPACE_BEGIN(csci3081);

BraitenbergVehicleFactory::BraitenbergVehicleFactory() {}

void BraitenbergVehicleFactory::Create(ArenaEntity ** ent,
                                      json_object* entity_config) {
  // std::cout << "Inside BraitenbergVehicle's create\n" << std::endl;
  *ent = new BraitenbergVehicle();
  (*ent)->LoadFromObject(entity_config);
}

BraitenbergVehicleFactory::~BraitenbergVehicleFactory() {}

NAMESPACE_END(csci3081);
