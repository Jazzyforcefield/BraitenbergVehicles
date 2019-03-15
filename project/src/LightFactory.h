// Copyright 2019, Michael Ung

#ifndef SRC_LIGHTFACTORY_H_
#define SRC_LIGHTFACTORY_H_

#include <iostream>
#include <cstdlib>

#include "Factory.h"

NAMESPACE_BEGIN(csci3081);

class LightFactory : public Factory {
 public:
    LightFactory();
    ~LightFactory();
    void Create(ArenaEntity ** ent, json_object& entity_config) override;
};

NAMESPACE_END(csci3081);

#endif  // SRC_LIGHTFACTORY_H_
