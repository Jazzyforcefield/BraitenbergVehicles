// Copyright 2019, Michael Ung

#ifndef SRC_FOOD_DECORATION_H_
#define SRC_FOOD_DECORATION_H_

#include <string>
#include "src/entity_decorator.h"
#include "src/food.h"

NAMESPACE_BEGIN(csci3081);

 /**
  * @brief Food disguise for the Predator
  */
class FoodDecoration : public EntityDecorator {
 public:
  explicit FoodDecoration(ArenaMobileEntity * ent) : EntityDecorator(ent) {
    set_type(kFood);
    set_color({0, 255, 0});
    set_radius(FOOD_RADIUS);
    set_core(kPredator);
    set_pose(entity_->get_pose());
    set_stime(entity_->get_stime() + 1);
    set_dbv(entity_->get_dbv());
    set_dlight(entity_->get_dlight());
    set_dfood(entity_->get_dfood());
  }

  FoodDecoration(const FoodDecoration&) = delete;
  FoodDecoration& operator=(const FoodDecoration&) = delete;

  void TimestepUpdate(__unused unsigned int dt) override;
  void Update() override;
  void HandleCollision(__unused EntityType ent_type,
                               __unused ArenaEntity * object) override;
  std::string get_name() const override { return "Food Predator"; }
};

NAMESPACE_END(csci3081);

#endif  // SRC_FOOD_DECORATION_H_
