// Copyright 2019

#ifndef SRC_BRAITENBERGVEHICLEFACTORY_H_
#define SRC_BRAITENBERGVEHICLEFACTORY_H_

#include <iostream>
#include <cstdlib>

#include "Factory.h"

NAMESPACE_BEGIN(csci3081);

class BraitenbergVehicleFactory : public Factory {
 public:
    BraitenbergVehicleFactory();
    ~BraitenbergVehicleFactory();
    void Create(ArenaEntity ** ent, json_object& entity_config) override;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERGVEHICLEFACTORY_H_
