// Copyright 2019, Michael Ung

#include "src/braitenberg_decoration.h"

NAMESPACE_BEGIN(csci3081);

  void BraitenbergDecoration::TimestepUpdate(unsigned int dt) {
    entity_->TimestepUpdate(dt);
    set_stime(get_stime() + 1);
    if (get_stime() == 600) {
      fed_ = true;
      Update();
      return;
    }
    if (is_moving()) {
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
      entity_->set_pose(pose);
    }
    Update();
  }
  void BraitenbergDecoration::Update() {
    entity_->Update();
    if (collided_) {
      time_++;
    }
    if (time_ == 20) {
      set_heading(static_cast<int>((get_pose().theta + 225)) % 360);
      time_ = 0;
      collided_ = false;
    }
  }
  void BraitenbergDecoration::HandleCollision(EntityType ent_type,
                                         ArenaEntity * object) {
    if (ent_type == kBraitenberg && !static_cast<BraitenbergVehicle *>(object)->isDead()) {
      fed_ = true;
    }

    entity_->HandleCollision(ent_type, object);
    if (ent_type != kFood) {
      set_heading(static_cast<int>((get_pose().theta + 180)) % 360);
      collided_ = true;
    }
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
