// Copyright 2019, Michael Ung

#ifndef SRC_FOODFACTORY_H_
#define SRC_FOODFACTORY_H_

#include <iostream>
#include <cstdlib>

#include "Factory.h"
#include "FoodFactory.h"

NAMESPACE_BEGIN(csci3081);

/**
 * @brief The derived factory class that creates Food
 */

class FoodFactory : public Factory {
 public:
/**
 * @brief FoodFactory constructor
 */
    FoodFactory();
/**
 * @brief FoodFactory destructor
 */
    ~FoodFactory();
/**
 * @brief Overrides factory create class
 *
 * @param ent ArenaEntity ** to create a new object
 * @param entity_config json_object with configuration
 *
 * Factories should assign a new type to *ent
 */
    void Create(ArenaEntity ** ent, json_object& entity_config) override;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FOODFACTORY_H_
