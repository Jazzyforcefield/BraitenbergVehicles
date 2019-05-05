// Copyright 2019, Michael Ung

#ifndef SRC_BRAITENBERG_DECORATION_H_
#define SRC_BRAITENBERG_DECORATION_H_

#include <string>
#include "src/entity_decorator.h"

NAMESPACE_BEGIN(csci3081);

 /**
  * @brief Braitenberg Vehicle disguise for the Predator
  */
class BraitenbergDecoration : public EntityDecorator {
 public:
  explicit BraitenbergDecoration(ArenaMobileEntity * ent) :
    EntityDecorator(ent) {
    // set_type(kBraitenberg);  // Causes bad_alloc for some reason
    set_pose(entity_->get_pose());
    set_color({122, 0, 25});
    set_radius(14);
    set_stime(get_stime() + 1);
    set_core(kPredator);
    set_dbv(entity_->get_dbv());
    set_dlight(entity_->get_dlight());
    set_dfood(entity_->get_dfood());

    if (entity_->get_type() == kPredator) {
      static_cast<EntityDecorator *>(entity_)->
        set_food_behavior(RandomBehavior());
      static_cast<EntityDecorator *>(entity_)->
        set_light_behavior(RandomBehavior());
    }
  }

  BraitenbergDecoration(const BraitenbergDecoration&) = delete;
  BraitenbergDecoration& operator=(const BraitenbergDecoration&) = delete;

  void TimestepUpdate(__unused unsigned int dt) override;
  void Update() override;
  void HandleCollision(__unused EntityType ent_type,
                               __unused ArenaEntity * object) override;
  std::string get_name() const override { return "Braitenberg Predator"; }

 /**
  * @brief Function to obtain a random behavior
  * @param[out] Returns a random behavior
  */
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
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_DECORATION_H_
