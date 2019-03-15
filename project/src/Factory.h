// Copyright 2019, Michael Ung

#ifndef SRC_FACTORY_H_
#define SRC_FACTORY_H_

#include <iostream>
#include <cstdlib>

#include "src/arena_entity.h"

NAMESPACE_BEGIN(csci3081);

class Factory {
 public:
    virtual void Create(ArenaEntity ** ent, json_object& entity_config) = 0;
    virtual ~Factory();
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_H_
