// Copyright 2019, Michael Ung

#ifndef PROJECT_SRC_LIGHTFACTORY_H_
#define PROJECT_SRC_LIGHTFACTORY_H_

#include <iostream>
#include <cstdlib>

#include "Factory.h"

NAMESPACE_BEGIN(csci3081);

class LightFactory : public Factory {
 public:
    LightFactory();
    ~LightFactory();
    void Create(ArenaEntity ** ent) override;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_SRC_LIGHTFACTORY_H_
