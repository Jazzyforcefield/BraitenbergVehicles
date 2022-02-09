/**
 * @file food.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_FOOD_H_
#define SRC_FOOD_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "src/arena_immobile_entity.h"
#include "src/common.h"
#include "src/entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a immobile food within the Arena.
 *
 * Food can enhance a Robot. If a Robot touches the Food, it becomes
 * a super robot.
 *
 * Food have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events.
 *
 */
class Food : public ArenaImmobileEntity {
 public:
  /**
   * @brief Constructor.
   *
   * @param params A food_params passed down from main.cc for the
   * initialization of the Food.
   */
  Food();

  /**
   * @brief Reset the Food using the initialization parameters received
   * by the constructor.
   */
  void Reset() override;

  /**
   * @brief Only thing necessary is to update any subscribered sensors
   */
  void TimestepUpdate(__unused unsigned int dt) override {
    if (time_ == 100) {
      time_ = 0;
      inactive_ = false;
      set_color(FOOD_COLOR);
    }
    if (inactive_) {
      time_++;
      set_color({200, 0, 200});
    }
    Update();
  }

  /**
   * @brief Get the name of the Food for visualization purposes, and to
   * aid in debugging.
   *
   * @return Name of the Food.
   */
  std::string get_name() const override { return "Food"; }

  /**
   * @brief Checks if active
   */
  bool active() { return !inactive_; }

  /**
   * @brief Sets activity of food
   */
  void set_inactive() { inactive_ = true; }

  static int count;

 private:
  int time_;
  bool inactive_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_FOOD_H_
