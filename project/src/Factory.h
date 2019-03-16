// Copyright 2019, Michael Ung

#ifndef SRC_FACTORY_H_
#define SRC_FACTORY_H_

#include <iostream>
#include <cstdlib>

#include "src/arena_entity.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief The base abstract factory that other factories are created from.
 *
 * Factories should be derived from this class
 */

class Factory {
 public:
  /**
 * @brief Pure virtual create class to override.
 *
 * @param ent ArenaEntity ** to create a new object
 * @param entity_config json_object with configuration
 *
 * Factories should assign a new type to *ent
 */
    virtual void Create(ArenaEntity ** ent, json_object* entity_config) = 0;

  /**
 * @brief Virtual destructor
 */
    virtual ~Factory();
};

NAMESPACE_END(csci3081);

#endif  // SRC_FACTORY_H_
