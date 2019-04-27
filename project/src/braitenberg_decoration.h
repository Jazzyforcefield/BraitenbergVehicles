// Copyright 2019, Michael Ung

#ifndef SRC_BRAITENBERG_DECORATION_H_
#define SRC_BRAITENBERG_DECORATION_H_

#include "src/arena_entity.h"
#include "src/entity_decorator.h"
#include "src/Predator.h"
#include "src/braitenberg_vehicle.h"

NAMESPACE_BEGIN(csci3081);

class BraitenbergDecoration : public EntityDecorator {
 public:
  BraitenbergDecoration(ArenaEntity * ent) : EntityDecorator(ent) {
    entity_ = ent;
    static_cast<Predator *>(entity_)->set_type(kBraitenberg);
    static_cast<Predator *>(entity_)->set_color({122, 0, 25});
    static_cast<Predator *>(entity_)->set_radius(14);
    static_cast<Predator *>(entity_)->set_food_behavior(RandomBehavior());
    static_cast<Predator *>(entity_)->set_light_behavior(RandomBehavior());
  }

  BraitenbergDecoration(const BraitenbergDecoration&) = delete;
  BraitenbergDecoration& operator=(const BraitenbergDecoration&) = delete;

  void TimestepUpdate(__unused unsigned int dt) override;
  void Update() override;
  void HandleCollision(__unused EntityType ent_type,
                                         __unused ArenaEntity * object) override;
  std::string get_name() const override { return "a"; }
  Behavior RandomBehavior() {
    int rand = (std::rand() % 4) + 1;
    if (rand == 1) {
      return kAggressive;
    } else if (rand == 2) {
      return kCoward;
    } else if (rand == 3) {
      return kExplore;
    } else if (rand == 4) {
      return kLove;
    } else {
      return kNone;
    }
  }

 protected:
  ArenaEntity * entity_{nullptr};
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_DECORATION_H_


/* Have light food and bv inherit decorator?
then update predator to detect if type in update to only 

or derive decoration classes and aggregate each entity type e.g. light decoration
to Braitenberg then set_type and call Update

use this = new BraitenbergDecoration(this); ???
arena calls timestep update and then update is called, so might need to override
timestepupdate to call Braitenberg->timestepupdate AND entity_->Update(), which 
requires update to be overridden to call other updates
So the current wrapper calls timestepupdate which calls the wrapper update
think more about handlecollision, when encountering a disguised predator maybe
implement an Identify() function */
