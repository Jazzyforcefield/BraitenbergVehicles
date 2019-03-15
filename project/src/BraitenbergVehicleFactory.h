// Copyright 2019

#ifndef PROJECT_SRC_BRAITENBERGVEHICLEFACTORY_H_
#define PROJECT_SRC_BRAITENBERGVEHICLEFACTORY_H_

#include <iostream>
#include <cstdlib>

#include "Factory.h"

NAMESPACE_BEGIN(csci3081);

class BraitenbergVehicleFactory : public Factory {
 public:
    BraitenbergVehicleFactory();
    ~BraitenbergVehicleFactory();
    void Create(ArenaEntity ** ent) override;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_SRC_BRAITENBERGVEHICLEFACTORY_H_
