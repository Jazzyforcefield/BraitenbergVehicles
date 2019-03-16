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

class BraitenbergVehicle : public ArenaMobileEntity {
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
  void set_light_behavior(Behavior behavior) { light_behavior_ = behavior; }
  /**
   * @brief Gets the behavior towards food
   * @return Returns the behavior towards light

   */
  Behavior get_food_behavior() { return food_behavior_; }
  /**
   * @brief Sets the behavior towards food
   * @param behavior Food behavior
   */
  void set_food_behavior(Behavior behavior) { food_behavior_ = behavior; }
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
   * @brief Number of BraitenbergVehicle objects exist
   */
  static int count;

 private:
  std::vector<Pose> light_sensors_;
  MotionBehaviorDifferential * motion_behavior_{nullptr};
  WheelVelocity wheel_velocity_;
  Behavior light_behavior_;
  Behavior food_behavior_;
  const ArenaEntity* closest_light_entity_;
  const ArenaEntity* closest_food_entity_;
  double defaultSpeed_;
  int time_;
  bool collided_;
};

NAMESPACE_END(csci3081);

#endif  // SRC_BRAITENBERG_VEHICLE_H_
