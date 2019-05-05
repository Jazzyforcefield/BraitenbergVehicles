// Copyright 2019, Michael Ung

#ifndef SRC_ENTITY_DECORATOR_H_
#define SRC_ENTITY_DECORATOR_H_

#include "src/arena_entity.h"
#include "src/Predator.h"

NAMESPACE_BEGIN(csci3081);

class EntityDecorator : public ArenaEntity {
 public:
  EntityDecorator() : entity_(nullptr) {}
  explicit EntityDecorator(ArenaEntity * ent) : entity_(ent) { }

  EntityDecorator(const EntityDecorator&) = delete;
  EntityDecorator& operator=(const EntityDecorator&) = delete;
  EntityType get_type() const { return entity_->get_type(); }
  int get_stime() { return entity_->get_stime(); }
  EntityType Disguise() {
    std::cout << "Disguising as ";
    bool changed = false;
if (entity_->get_type() != kPredator) {
    while ((static_cast<EntityDecorator *>(entity_)->get_dlight() != true ||
      static_cast<EntityDecorator *>(entity_)->get_dfood() != true ||
      static_cast<EntityDecorator *>(entity_)->get_dbv() != true) && !changed) {
      int random = (std::rand() % 3) + 1;
      if (random == 1 && static_cast<EntityDecorator *>(entity_)->get_dlight() == false) {
        static_cast<EntityDecorator *>(entity_)->set_dlight();
        changed = true;
        std::cout << "kLight" << std::endl;
        return kLight;
      } else if (random == 2 && static_cast<EntityDecorator *>(entity_)->get_dfood() == false) {
        static_cast<EntityDecorator *>(entity_)->set_dfood();
        changed = true;
        std::cout << "kFood" << std::endl;
        return kFood;
      } else if (random == 3 && static_cast<EntityDecorator *>(entity_)->get_dbv() == false) {
        static_cast<EntityDecorator *>(entity_)->set_dbv();
        changed = true;
        std::cout << "kBraitenberg" << std::endl;
        return kBraitenberg;
      }
    }
    return kUndefined;
    } else { 
          while ((static_cast<Predator *>(entity_)->get_dlight() == true &&
            static_cast<Predator *>(entity_)->get_dfood() == true &&
            static_cast<Predator *>(entity_)->get_dbv() == true) || !changed) {
            int random = (std::rand() % 3) + 1;
            if (random == 1 && static_cast<Predator *>(entity_)->get_dlight() == false) {
              static_cast<Predator *>(entity_)->set_dlight();
              changed = true;
              std::cout << "kLight" << std::endl;
              return kLight;
            } else if (random == 2 && static_cast<Predator *>(entity_)->get_dfood() == false) {
              static_cast<Predator *>(entity_)->set_dfood();
              changed = true;
              std::cout << "kFood" << std::endl;
              return kFood;
            } else if (random == 3 && static_cast<Predator *>(entity_)->get_dbv() == false) {
              static_cast<Predator *>(entity_)->set_dbv();
              changed = true;
              std::cout << "kBraitenberg" << std::endl;
              return kBraitenberg;
            }
          }
          return kUndefined;
    }
  }
  void set_food_behavior(Behavior behavior) {
    if (entity_->get_type() != kPredator) {
      static_cast<EntityDecorator *>(entity_)->set_food_behavior(behavior);
    } else {
      static_cast<Predator *>(entity_)->set_food_behavior(behavior);
    }
  }
  void set_light_behavior(Behavior behavior) {
    if (entity_->get_type() != kPredator) {
      static_cast<EntityDecorator *>(entity_)->set_light_behavior(behavior);
    } else {
      static_cast<Predator *>(entity_)->set_light_behavior(behavior);
    }
  }
  void TimestepUpdate(__unused unsigned int dt) override = 0;
  void Update() override = 0;
  virtual void HandleCollision(__unused EntityType ent_type,
                                         __unused ArenaEntity * object) override = 0;
  bool get_dlight() {
    if (entity_->get_type() != kPredator) {
      return static_cast<EntityDecorator *>(entity_)->get_dlight();
    } return static_cast<Predator *>(entity_)->get_dlight();
  }
  void set_dlight() {
    if (entity_->get_type() != kPredator) {
      static_cast<EntityDecorator *>(entity_)->set_dlight();
    } else {
      static_cast<Predator *>(entity_)->set_dlight();
    }
  }

  bool get_dfood() {
    if (entity_->get_type() != kPredator) {
      return static_cast<EntityDecorator *>(entity_)->get_dfood();
    } return static_cast<Predator *>(entity_)->get_dfood();
  }
  void set_dfood() {
    if (entity_->get_type() != kPredator) {
      static_cast<EntityDecorator *>(entity_)->set_dfood();
    } else {
      static_cast<Predator *>(entity_)->set_dfood();
    }
  }

  bool get_dbv() {
    if (entity_->get_type() != kPredator) {
      return static_cast<EntityDecorator *>(entity_)->get_dbv();
    } return static_cast<Predator *>(entity_)->get_dbv();
  }
  void set_dbv() {
    if (entity_->get_type() != kPredator) {
      static_cast<EntityDecorator *>(entity_)->set_dbv();
    } else {
      static_cast<Predator *>(entity_)->set_dbv();
    }
  }

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
