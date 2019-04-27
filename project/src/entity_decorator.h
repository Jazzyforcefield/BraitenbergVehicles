// Copyright 2019, Michael Ung

#ifndef SRC_ENTITY_DECORATOR_H_
#define SRC_ENTITY_DECORATOR_H_

#include "src/arena_entity.h"

NAMESPACE_BEGIN(csci3081);

class EntityDecorator : public ArenaEntity {
 public:
  EntityDecorator() : entity_(nullptr) {}
  EntityDecorator(ArenaEntity * ent) : entity_(ent) {}

  EntityDecorator(const EntityDecorator&) = delete;
  EntityDecorator& operator=(const EntityDecorator&) = delete;

  virtual void TimestepUpdate(__unused unsigned int dt) override = 0;
  virtual void Update() override = 0;
  virtual void HandleCollision(__unused EntityType ent_type,
                                         __unused ArenaEntity * object) = 0;

 protected:
  ArenaEntity * entity_{nullptr};
};

NAMESPACE_END(csci3081);

#endif  // SRC_ENTITY_DECORATOR_H_


/* Have light food and bv inherit decorator?
then update predator to detect if type in update to only 

or derive decoration classes and aggregate each entity type e.g. light decoration
to Light then set_type and call Update

use this = new LightDecoration(this); ???
arena calls timestep update and then update is called, so might need to override
timestepupdate to call Light->timestepupdate AND entity_->Update(), which 
requires update to be overridden to call other updates
So the current wrapper calls timestepupdate which calls the wrapper update
think more about handlecollision, when encountering a disguised predator maybe
implement an Identify() function */
