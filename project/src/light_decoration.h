// Copyright 2019, Michael Ung

#ifndef SRC_LIGHT_DECORATION_H_
#define SRC_LIGHT_DECORATION_H_

#include <string>
#include "src/entity_decorator.h"
#include "src/light.h"

NAMESPACE_BEGIN(csci3081);

class LightDecoration : public EntityDecorator {
 public:
  explicit LightDecoration(ArenaMobileEntity * ent) : EntityDecorator(ent) {
    set_type(kLight);
    set_core(kPredator);
    set_color({255, 255, 255});
    set_radius(LIGHT_RADIUS);
    set_pose(entity_->get_pose());
    set_stime(entity_->get_stime() + 1);
    set_dbv(entity_->get_dbv());
    set_dlight(entity_->get_dlight());
    set_dfood(entity_->get_dfood());
  }

  LightDecoration(const LightDecoration&) = delete;
  LightDecoration& operator=(const LightDecoration&) = delete;

  void TimestepUpdate(__unused unsigned int dt) override;
  void Update() override;
  void HandleCollision(__unused EntityType ent_type,
                               __unused ArenaEntity * object) override;
  std::string get_name() const override { return "Light Predator"; }
};

NAMESPACE_END(csci3081);

#endif  // SRC_LIGHT_DECORATION_H_


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
