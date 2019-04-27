// Copyright 2019, Michael Ung

#include "src/braitenberg_decoration.h"
#include "src/braitenberg_vehicle.h"

NAMESPACE_BEGIN(csci3081);

  void BraitenbergDecoration::TimestepUpdate(unsigned int dt) {
    static_cast<BraitenbergVehicle *>(entity_)->TimestepUpdate(dt);
    entity_->TimestepUpdate(dt);
  }
  void BraitenbergDecoration::Update() {
    static_cast<BraitenbergVehicle *>(entity_)->Update();
    entity_->Update();
  }
  void BraitenbergDecoration::HandleCollision(EntityType ent_type,
                                         ArenaEntity * object) {
    static_cast<BraitenbergVehicle *>(entity_)->HandleCollision(
      ent_type, object);
  }

NAMESPACE_END(csci3081);

/* Have Braitenberg food and bv inherit decorator?
then update predator to detect if type in update to only 

or derive decoration classes and aggregate each entity type e.g. Braitenberg decoration
to Braitenberg then set_type and call Update

use this = new BraitenbergDecoration(this); ???
arena calls timestep update and then update is called, so might need to override
timestepupdate to call Braitenberg->timestepupdate AND entity_->Update(), which 
requires update to be overridden to call other updates
So the current wrapper calls timestepupdate which calls the wrapper update
think more about handlecollision, when encountering a disguised predator maybe
implement an Identify() function */
