/**
 * @file braitenberg_vehicle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_BRAITENBERG_VEHICLE_H_
#define SRC_BRAITENBERG_VEHICLE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <ctime>
#include <string>
#include <vector>
#include "src/common.h"
#include "src/arena_mobile_entity.h"
#include "src/motion_behavior_differential.h"
#include "src/wheel_velocity.h"
#include "src/behavior_enum.h"
#include "src/WheelBehavior.h"
#include "src/AggressiveBehavior.h"
#include "src/LoveBehavior.h"
#include "src/ExploreBehavior.h"
#include "src/CowardBehavior.h"
#include "src/Subject.h"
#include "src/Observer.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/** 
 * @brief Entity class to represent a Braitenberg Vehicle
 *
 * A braitenberg vehicle is a simple machine that is used to show how simple
 * concepts (in this case wiring) can give way to complex looking behavior. In
 * this simulation, Braitenberg vehicles contain sensors, which can be hooked
 * up in four different ways, and thus they can exhibit four different behaviors
 */

class BraitenbergVehicle : public ArenaMobileEntity, public Subject {
 public:
  /**
   * @brief Default constructor.
   */
  BraitenbergVehicle();

  /**
   * @brief Deleting the copy assignment and copy constructor. required now with
   *  inclusion of references to sensors and motion_handler/behavior
   */
  BraitenbergVehicle(const BraitenbergVehicle & rhs) = delete;
  /**
   * @brief Copy constructor of BV
   */
  BraitenbergVehicle operator=(const BraitenbergVehicle & rhs) = delete;

  /**
   * @brief Update the BraitenbergVehicle's position and velocity after the
   * specified duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(unsigned int dt) override;

  void Update() override;

  /**
   * @brief Change the movement state of the BraitenbergVehicle.
   * @param ent_type EntityType of collision entity
   * @param object ArenaEntity * is the collision object
   */
  void HandleCollision(EntityType ent_type,
                       ArenaEntity * object = NULL) override;

  /**
   * @brief Gets the closest entity
   *
   * Depends on what type of entity is input as the parameter
   */
  void SenseEntity(const ArenaEntity& entity);

  std::string get_name() const override;
  /**
   * @brief Gets the const Pose of the light sensors
   * @return Returns the const Pose of the light sensors
   */
  std::vector<Pose> get_light_sensors_const() const;
  /**
   * @brief Gets the Pose of the light sensors
   * @return Returns the Pose of the light sensors
   */
  std::vector<Pose> get_light_sensors();

  /**
   * @brief Updates the Pose of the light sensors
   */
  void UpdateLightSensors();
  /**
   * @brief Initializes an object using JSON configuration
   * @param entity_config Takes in entity configuration json
   * Calls UpdateLightSensors() afterward
   */
  void LoadFromObject(json_object* entity_config) override;
  /**
   * @brief Gets the behavior toward lights
   * @return Returns the behavior toward light
   */
  Behavior get_light_behavior() { return light_behavior_; }
  /**
   * @brief Sets the behavior towards light
   * @param behavior Sets the behavior toward food to behavior
   */
  void set_light_behavior(Behavior behavior) {
    light_behavior_ = behavior;
    switch (behavior) {
      case kLove:
        wheel_light_ = new LoveBehavior();
        break;
      case kAggressive:
        wheel_light_ = new AggressiveBehavior();
        break;
      case kCoward:
        wheel_light_ = new CowardBehavior();
        break;
      case kExplore:
        wheel_light_ = new ExploreBehavior();
        break;
      case kNone:
      default:
        wheel_light_ = NULL;
        break;
    }
  }
  /**
   * @brief Gets the behavior towards food
   * @return Returns the behavior towards food

   */
  Behavior get_food_behavior() { return food_behavior_; }
  /**
   * @brief Sets the behavior towards food
   * @param behavior Food behavior
   */
  void set_food_behavior(Behavior behavior) {
    food_behavior_ = behavior;
    switch (behavior) {
      case kLove:
        wheel_food_ = new LoveBehavior();
       break;
      case kAggressive:
        wheel_food_ = new AggressiveBehavior();
       break;
     case kCoward:
       wheel_food_ = new CowardBehavior();
       break;
      case kExplore:
       wheel_food_ = new ExploreBehavior();
       break;
      case kNone:
      default:
        wheel_food_ = NULL;
        break;
    }
  }

  /**
   * @brief Gets the behavior towards bv
   * @return Returns the behavior towards bv

   */
  Behavior get_bv_behavior() { return bv_behavior_; }

  /**
   * @brief Sets the behavior towards bv
   * @param behavior bv behavior
   */
  void set_bv_behavior(Behavior behavior) {
    bv_behavior_ = behavior;
    switch (behavior) {
      case kLove:
        wheel_bv_ = new LoveBehavior();
        break;
      case kAggressive:
        wheel_bv_ = new AggressiveBehavior();
        break;
      case kCoward:
        wheel_bv_ = new CowardBehavior();
        break;
      case kExplore:
        wheel_bv_ = new ExploreBehavior();
        break;
      case kNone:
      default:
        wheel_bv_ = NULL;
        break;
    }
  }

  /**
   * @brief Gets the reading from the left sensor
   * @param behavior The behavior to set
   * Gets the strength of the reading of a specific entity
   */
  double get_sensor_reading_left(const ArenaEntity* entity);
  /**
   * @brief Gets the reading from the right sensor
   * @param entity Another arena entity
   * Gets the strength of the reading of a specific entity
   */
  double get_sensor_reading_right(const ArenaEntity* entity);
  /**
   * @brief Returns wheel velocity
   * @return Returns wheel_velocity
   */
  WheelVelocity get_wheel_velocity() { return wheel_velocity_; }

  /**
   * @brief Calculates the constituent wheel velocities for the BV
   */
  void CalculateWheelVelocity();

  /**
   * @brief Subscribes to observer
   * @param[in] Passes in an observer to subscribe to
   */
  void Subscribe(Observer * observer) override;

  /**
   * @brief Unsubscribes to observer
   */
  void Unsubscribe() override;

  /**
   * @brief Notifies observer of changes
   */
  void Notify() override;

  /**
   * @brief Kills the BV (turns into ghost)
   */
  void Die();

  /**
   * @brief Checks if BV is a ghost
   * @param[out] Returns a boolean
   */
  bool isDead();

  /**
   * @brief Number of BraitenbergVehicle objects exist
   */
  static int count;

 private:
  std::vector<Pose> light_sensors_;
  MotionBehaviorDifferential * motion_behavior_{nullptr};
  WheelVelocity wheel_velocity_;
  std::vector<WheelVelocity> wv_;   // l - 0, f - 1, bv - 2
  Behavior light_behavior_;
  Behavior food_behavior_;
  Behavior bv_behavior_;
  WheelBehavior * wheel_light_;
  WheelBehavior * wheel_food_;
  WheelBehavior * wheel_bv_;
  const ArenaEntity* closest_light_entity_;
  const ArenaEntity* closest_food_entity_;
  const ArenaEntity* closest_bv_entity_;
  double defaultSpeed_;
  int time_;
  int stime_;
  bool collided_;
  Observer * obs_;
  bool dead_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_VEHICLE_H_
