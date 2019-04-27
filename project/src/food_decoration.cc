// Copyright 2019, Michael Ung

#include "src/food_decoration.h"
#include "src/food.h"

NAMESPACE_BEGIN(csci3081);

  void FoodDecoration::TimestepUpdate(unsigned int dt) {
    static_cast<Food *>(entity_)->TimestepUpdate(dt);
    entity_->TimestepUpdate(dt);
  };
  void FoodDecoration::Update() {
    entity_->Update();
  }
  void FoodDecoration::HandleCollision(__unused EntityType ent_type,
                                         __unused ArenaEntity * object) {
  }

NAMESPACE_END(csci3081);

/* Have Food food and bv inherit decorator?
then update predator to detect if type in update to only 

or derive decoration classes and aggregate each entity type e.g. Food decoration
to Food then set_type and call Update

use this = new FoodDecoration(this); ???
arena calls timestep update and then update is called, so might need to override
timestepupdate to call Food->timestepupdate AND entity_->Update(), which 
requires update to be overridden to call other updates
So the current wrapper calls timestepupdate which calls the wrapper update
think more about handlecollision, when encountering a disguised predator maybe
implement an Identify() function */
