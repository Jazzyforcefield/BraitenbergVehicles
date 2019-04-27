// Copyright 2019, Michael Ung

#ifndef SRC_FOOD_DECORATION_H_
#define SRC_FOOD_DECORATION_H_

#include "src/arena_entity.h"
#include "src/entity_decorator.h"
#include "src/Predator.h"
#include "src/food.h"

NAMESPACE_BEGIN(csci3081);

class FoodDecoration : public EntityDecorator {
 public:
  FoodDecoration(ArenaEntity * ent) : EntityDecorator(ent) {
    entity_ = ent;
    static_cast<EntityDecorator *>(entity_)->set_type(kFood);
    static_cast<Predator *>(entity_)->set_color({0, 255, 0});
    static_cast<Predator *>(entity_)->set_radius(FOOD_RADIUS);
  }

  FoodDecoration(const FoodDecoration&) = delete;
  FoodDecoration& operator=(const FoodDecoration&) = delete;

  void TimestepUpdate(__unused unsigned int dt) override;
  void Update() override;
  void HandleCollision(__unused EntityType ent_type,
                                         __unused ArenaEntity * object) override;
  std::string get_name() const override { return "a"; }

 protected:
  ArenaEntity * entity_{nullptr};
};

NAMESPACE_END(csci3081);

#endif  // SRC_FOOD_DECORATION_H_


/* Have light food and bv inherit decorator?
then update predator to detect if type in update to only 

or derive decoration classes and aggregate each entity type e.g. light decoration
to Food then set_type and call Update

use this = new FoodDecoration(this); ???
arena calls timestep update and then update is called, so might need to override
timestepupdate to call Food->timestepupdate AND entity_->Update(), which 
requires update to be overridden to call other updates
So the current wrapper calls timestepupdate which calls the wrapper update
think more about handlecollision, when encountering a disguised predator maybe
implement an Identify() function */
