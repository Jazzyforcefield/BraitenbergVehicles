// Copyright 2019, Michael Ung

#include "src/light_decoration.h"
#include "src/light.h"

NAMESPACE_BEGIN(csci3081);

  void LightDecoration::TimestepUpdate(unsigned int dt) {
    entity_->TimestepUpdate(dt);
    printf("inside ldec time\n");
    set_stime(get_stime() + 1);

    if (is_mobile()) {
        Pose pose = get_pose();

        // Movement is always along the heading_angle (i.e. the hypotenuse)
        double new_x =
          pose.x + std::cos(pose.theta * M_PI / 180.0) * 5 * dt;
        double new_y =
          pose.y + std::sin(pose.theta * M_PI / 180.0) * 5 * dt;

        /* Heading angle remaings the same */
        pose.x = new_x;
        pose.y = new_y;
        set_pose(pose);
    }

    Update();
  }
  void LightDecoration::Update() {
    printf("inside ldec update\n");
      entity_->Update();
    if (entity_->get_type() == kLight) {
      set_pose(entity_->get_pose());
    }
  }
  void LightDecoration::HandleCollision(__unused EntityType ent_type,
                                         __unused ArenaEntity * object) {
    printf("inside ldec handle\n");
    entity_->HandleCollision(ent_type, object);
    if (entity_->get_type() == kLight) {
    entity_->set_heading(static_cast<int>(entity_->get_pose().theta + 180) % 360); }
  }


NAMESPACE_END(csci3081);

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
