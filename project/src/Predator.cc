/**
 * @file braitenberg_vehicle.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <ctime>
#include "src/Predator.h"
#include "src/params.h"
#include "src/braitenberg_vehicle.h"

class SensorLightLove;

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

int Predator::count = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

Predator::Predator() :
  light_sensors_(), wheel_velocity_(), wv_(), light_behavior_(kNone),
  food_behavior_(kNone), bv_behavior_(kNone), wheel_light_(NULL),
  wheel_food_(NULL), wheel_bv_(NULL), closest_light_entity_(NULL),
  closest_food_entity_(NULL), closest_bv_entity_(NULL),
  defaultSpeed_(5.0), time_(0), stime_(0), collided_(false),
  obs_(), dead_(false), dlight_(false), dfood_(false), dbv_(false) {
  set_type(kPredator);
  set_core(kPredator);
  motion_behavior_ = new MotionBehaviorDifferential(this);
  light_sensors_.push_back(Pose());
  light_sensors_.push_back(Pose());
  wv_.push_back(WheelVelocity());
  wv_.push_back(WheelVelocity());
  wv_.push_back(WheelVelocity());
  set_color(PREDATOR_COLOR);
  set_pose(ROBOT_INIT_POS);

  wheel_velocity_ = WheelVelocity(0, 0);

  // Set ID
  count++;
  set_id(count);
}

void Predator::TimestepUpdate(__unused unsigned int dt) {
  if (is_moving()) {
    motion_behavior_->UpdatePose(dt, wheel_velocity_);
  }
  UpdateLightSensors();
  if (collided_) {
    time_++;
  }
  if (!isDead()) {
    stime_++;
  }
}

void Predator::HandleCollision(EntityType ent_type,
                                         ArenaEntity * object) {
  if (ent_type == kBraitenberg) {
    if (!static_cast<BraitenbergVehicle *>(object)->isDead()) {
      stime_ = 0;
    }
    static_cast<BraitenbergVehicle *>(object)->Die();
  } else if (ent_type == kFood || ent_type == kLight) {
    return;
  } else {
    set_heading(static_cast<int>((get_pose().theta + 180)) % 360);
    collided_ = true;
  }
}

void Predator::SenseEntity(const ArenaEntity& entity) {
  const ArenaEntity** closest_entity_ = NULL;
  if (entity.get_type() == kLight) {
    closest_entity_ = &closest_light_entity_;
  } else if (entity.get_type() == kFood) {
    closest_entity_ = &closest_food_entity_;
  } else if (entity.get_type() == kBraitenberg) {
    closest_entity_ = &closest_bv_entity_;
  }

  if (!closest_entity_ || *closest_entity_ == this) {
    return;
  }

  if (!*closest_entity_) {
    *closest_entity_ = &entity;
  }

  double distance = (this->get_pose()-entity.get_pose()).Length();
  double closest_distance =
  (this->get_pose()-(*closest_entity_)->get_pose()).Length();
  if (distance < closest_distance) {
    *closest_entity_ = &entity;
    closest_distance = distance;
  }
  if (closest_distance > 100.0 || closest_distance < 1) {
    *closest_entity_ = NULL;
  }
  if (entity.get_type() == kBraitenberg) {
    if (const_cast<BraitenbergVehicle *>(
      static_cast<const BraitenbergVehicle *>(&entity))->isDead()) {
      *closest_entity_ = NULL;
    }
  }
}

void Predator::Update() {
  if (dead_) {
    set_color({150, 150, 150});
    wheel_velocity_ = WheelVelocity(0, 0);
    Notify();
    return;
  }

  // if (light_behavior_ != kNone && food_behavior_ == kNone) {
    // set_color(PREDATOR_COLOR);
  // }


  if (time_ == 20) {
    set_heading(static_cast<int>((get_pose().theta + 225)) % 360);
    time_ = 0;
    collided_ = false;
  }

  if (stime_ == 600) {
    Die();
  }

  CalculateWheelVelocity();
  if (obs_) {
    Notify();
  }
  // For some reason only changes to kBraitenberg
  if (this->get_type() == kFood) {
    std::cout << "kFood" << std::endl;
    wheel_velocity_ = WheelVelocity(0, 0);
  }
}

void Predator::CalculateWheelVelocity() {
  int numBehaviors = 3;

  WheelVelocity light_wheel_velocity = WheelVelocity(0, 0);
  switch (light_behavior_) {
    case kNone:
      numBehaviors--;
      break;
    case kLove:
    case kAggressive:
    case kCoward:
    case kExplore:
    default:
      light_wheel_velocity = wheel_light_->WheelUpdate(
        get_sensor_reading_left(closest_light_entity_),
        get_sensor_reading_right(closest_light_entity_), defaultSpeed_);
        wv_[0] = light_wheel_velocity;
      break;
  }

  WheelVelocity food_wheel_velocity = WheelVelocity(0, 0);
  switch (food_behavior_) {
    case kNone:
      numBehaviors--;
      break;
    case kLove:
    case kAggressive:
    case kCoward:
    case kExplore:
    default:
      food_wheel_velocity = wheel_food_->WheelUpdate(
        get_sensor_reading_left(closest_food_entity_),
        get_sensor_reading_right(closest_food_entity_), defaultSpeed_);
        wv_[1] = food_wheel_velocity;
      break;
  }

  WheelVelocity bv_wheel_velocity = WheelVelocity(0, 0);
  switch (bv_behavior_) {
    case kNone:
      numBehaviors--;
      break;
    case kLove:
    case kAggressive:
    case kCoward:
    case kExplore:
    default:
      bv_wheel_velocity = wheel_bv_->WheelUpdate(
        get_sensor_reading_left(closest_bv_entity_),
        get_sensor_reading_right(closest_bv_entity_), defaultSpeed_);
        wv_[2] = bv_wheel_velocity;
      break;
  }

  if (numBehaviors) {
    wheel_velocity_ = WheelVelocity(
      (light_wheel_velocity.left +
    food_wheel_velocity.left + bv_wheel_velocity.left)/numBehaviors,
      (light_wheel_velocity.right +
    food_wheel_velocity.right + bv_wheel_velocity.right)/numBehaviors,
      defaultSpeed_);
  } else {
    wheel_velocity_ = WheelVelocity(0, 0);
  }
}

std::string Predator::get_name() const {
  return "Predator " + std::to_string(get_id());
}

std::vector<Pose> Predator::get_light_sensors_const() const {
  return light_sensors_;
}

std::vector<Pose> Predator::get_light_sensors() {
  return light_sensors_;
}

double Predator::get_sensor_reading_left(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[0]).Length());
  }

  return 0.0001;
}

double Predator::get_sensor_reading_right(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[1]).Length());
  }

  return 0.0001;
}

void Predator::UpdateLightSensors() {
  for (unsigned int f = 0; f < light_sensors_.size(); f++) {
    Pose& pos = light_sensors_[f];
    if (f == 0) {
      pos.x = get_pose().x + get_radius() * cos(deg2rad(get_pose().theta - 40));
      pos.y = get_pose().y + get_radius() * sin(deg2rad(get_pose().theta - 40));
    } else {
      pos.x = get_pose().x + get_radius() * cos(deg2rad(get_pose().theta + 40));
      pos.y = get_pose().y + get_radius() * sin(deg2rad(get_pose().theta + 40));
    }
  }
}

void Predator::Subscribe(Observer * observer) {
  obs_ = observer;
}

void Predator::Unsubscribe() {
  obs_ = NULL;
}

void Predator::Notify() {
  if (obs_) {
    obs_->Update(wv_);
  }
}

void Predator::Die() {
  dead_ = true;
}

bool Predator::isDead() {
  return dead_;
}

EntityType Predator::Disguise() {
  std::cout << "Disguising as ";
  bool changed = false;
  while ((dlight_ != true && dfood_ != true && dbv_ != true) || !changed) {
    int random = (std::rand() % 3) + 1;
    if (random == 1 && dlight_ == false) {
      dlight_ = true;
      changed = true;
      std::cout << "kLight" << std::endl;
      return kLight;
    } else if (random == 2 && dfood_ == false) {
      dfood_ = true;
      changed = true;
      std::cout << "kFood" << std::endl;
      return kFood;
    } else if (random == 3 && dbv_ == false) {
      dbv_ = true;
      changed = true;
      std::cout << "kBraitenberg" << std::endl;
      return kBraitenberg;
    }
  }
  return kUndefined;
}

void Predator::LoadFromObject(json_object* entity_config) {
  ArenaEntity::LoadFromObject(entity_config);

  if ((*entity_config).find("light_behavior") != (*entity_config).end()) {
      light_behavior_ = get_behavior_type(
        (*entity_config)["light_behavior"].get<std::string>());
      set_light_behavior(light_behavior_);
  }
  if ((*entity_config).find("food_behavior") != (*entity_config).end()) {
      food_behavior_ = get_behavior_type(
        (*entity_config)["food_behavior"].get<std::string>());
      set_food_behavior(food_behavior_);
  }
  if ((*entity_config).find("robot_behavior") != (*entity_config).end()) {
      bv_behavior_ = get_behavior_type(
        (*entity_config)["robot_behavior"].get<std::string>());
      set_bv_behavior(bv_behavior_);
  }

  UpdateLightSensors();
}

NAMESPACE_END(csci3081);
