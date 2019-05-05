// Copyright 2019, Michael Ung

#ifndef SRC_ENTITY_DECORATOR_H_
#define SRC_ENTITY_DECORATOR_H_

#include "src/arena_entity.h"
#include "src/Predator.h"

NAMESPACE_BEGIN(csci3081);

class EntityDecorator : public ArenaMobileEntity {
 public:
  EntityDecorator() : entity_(nullptr) {}
  explicit EntityDecorator(ArenaMobileEntity * ent) : entity_(ent) { }

  EntityDecorator(const EntityDecorator&) = delete;
  EntityDecorator& operator=(const EntityDecorator&) = delete;
  EntityType get_type() const { return entity_->get_type(); }
  int get_stime() { return entity_->get_stime(); }

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
 protected:
  ArenaMobileEntity * entity_{nullptr};
};

NAMESPACE_END(csci3081);

#endif  // SRC_ENTITY_DECORATOR_H_
