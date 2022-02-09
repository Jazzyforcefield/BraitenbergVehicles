// Copyright 2019, Michael Ung

#ifndef SRC_LIGHTFACTORY_H_
#define SRC_LIGHTFACTORY_H_

#include <iostream>
#include <cstdlib>

#include "Factory.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief The derived factory class that creates Lights
 */

class LightFactory : public Factory {
 public:
/**
 * @brief LightFactory constructor
 */
    LightFactory();
/**
 * @brief LightFactory destructor
 */
    ~LightFactory();
/**
 * @brief Overrides factory create class
 *
 * @param ent ArenaEntity ** to create a new object
 * @param entity_config json_object with configuration
 *
 * Factories should assign a new type to *ent
 */
    void Create(ArenaEntity ** ent, json_object* entity_config) override;
};

NAMESPACE_END(csci3081);

#endif  // SRC_LIGHTFACTORY_H_
