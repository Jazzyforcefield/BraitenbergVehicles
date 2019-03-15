// Copyright 2019, Michael Ung

#ifndef PROJECT_SRC_FACTORY_H_
#define PROJECT_SRC_FACTORY_H_

#include <iostream>
#include <cstdlib>

#include "src/arena_entity.h"

NAMESPACE_BEGIN(csci3081);

class Factory {
 public:
    virtual void Create(ArenaEntity ** ent) = 0;
    virtual ~Factory();
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_SRC_FACTORY_H_
