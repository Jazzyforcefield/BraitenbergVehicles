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
#include "src/braitenberg_vehicle.h"
#include "src/params.h"
#include "src/food.h"
#include "src/Predator.h"

class SensorLightLove;

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

int BraitenbergVehicle::count = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/

BraitenbergVehicle::BraitenbergVehicle() :
  light_sensors_(), wheel_velocity_(), wv_(), light_behavior_(kNone),
  food_behavior_(kNone), bv_behavior_(kNone), wheel_light_(NULL),
  wheel_food_(NULL), wheel_bv_(NULL), closest_light_entity_(NULL),
  closest_food_entity_(NULL), closest_bv_entity_(NULL),
  defaultSpeed_(5.0), time_(0), stime_(0), collided_(false), obs_(),
  dead_(false) {
  set_type(kBraitenberg);
  set_core(kBraitenberg);
  motion_behavior_ = new MotionBehaviorDifferential(this);
  light_sensors_.push_back(Pose());
  light_sensors_.push_back(Pose());
  wv_.push_back(WheelVelocity());
  wv_.push_back(WheelVelocity());
  wv_.push_back(WheelVelocity());
  set_color(BRAITENBERG_COLOR);
  set_pose(ROBOT_INIT_POS);

  wheel_velocity_ = WheelVelocity(0, 0);

  // Set ID
  count++;
  set_id(count);
}

void BraitenbergVehicle::TimestepUpdate(__unused unsigned int dt) {
  if (is_moving()) {
    motion_behavior_->UpdatePose(dt, wheel_velocity_);
  }
  UpdateLightSensors();
}

void BraitenbergVehicle::HandleCollision(EntityType ent_type,
                                         ArenaEntity * object) {
  if (!dead_) {
    if (ent_type == kPredator) {
      Die();
      static_cast<Predator *>(object)->HandleCollision(kBraitenberg, this);
      return;
    } else if (ent_type == kFood) {
      if (static_cast<Food *>(object)->active()) {
        stime_ = 0;
        static_cast<Food *>(object)->set_inactive();
      }
      return;
    } else if (ent_type == kBraitenberg) {
      BraitenbergVehicle * bvref = dynamic_cast<BraitenbergVehicle *>(object);
      if (bvref->isDead()) {
        return;
      }
    }  else if (ent_type == kLight) {
      return;
    }
    set_heading(static_cast<int>((get_pose().theta + 180)) % 360);
    collided_ = true;
  }
}

void BraitenbergVehicle::SenseEntity(const ArenaEntity& entity) {
  if (isDead()) {
    return;
  }
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
  if (closest_distance > 100.0) {
    *closest_entity_ = NULL;
  }
  if (entity.get_type() == kBraitenberg) {
    if (closest_distance < 1 || const_cast<BraitenbergVehicle *>(
      static_cast<const BraitenbergVehicle *>(&entity))->isDead()) {
      *closest_entity_ = NULL;
    }
  }
}

void BraitenbergVehicle::Update() {
  if (dead_) {
    set_color({150, 150, 150});
    wheel_velocity_ = WheelVelocity(0, 0);
    Notify();
    return;
  } else if (light_behavior_ != kNone && food_behavior_ == kNone) {
    set_color({255, 204, 51});
  } else if (light_behavior_ == kNone && food_behavior_ != kNone) {
    set_color({0, 0, 255});
  } else {
    set_color({122, 0, 25});
  }

  if (collided_) {
    time_++;
  }

  stime_++;

  if (time_ == 20) {
    set_heading(static_cast<int>((get_pose().theta + 225)) % 360);
    time_ = 0;
    collided_ = false;
  }

  if (stime_ == 600) {
    dead_ = true;
    Notify();
  }

  CalculateWheelVelocity();
  if (obs_) {
    Notify();
  }
}

void BraitenbergVehicle::CalculateWheelVelocity() {
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
  if (stime_ > 350) {
    wv_[0] = WheelVelocity(0, 0);
    wv_[1] = WheelVelocity(
      food_wheel_velocity.left + defaultSpeed_/2,
      food_wheel_velocity.right + defaultSpeed_/2,
      defaultSpeed_);
    wv_[2] = WheelVelocity(0, 0);
    wheel_velocity_ = WheelVelocity(
      food_wheel_velocity.left + defaultSpeed_/2,
      food_wheel_velocity.right + defaultSpeed_/2,
      defaultSpeed_);
  } else if (numBehaviors) {
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

std::string BraitenbergVehicle::get_name() const {
  return "Braitenberg " + std::to_string(get_id());
}

std::vector<Pose> BraitenbergVehicle::get_light_sensors_const() const {
  return light_sensors_;
}

std::vector<Pose> BraitenbergVehicle::get_light_sensors() {
  return light_sensors_;
}

double BraitenbergVehicle::get_sensor_reading_left(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[0]).Length());
  }

  return 0.0001;
}

double BraitenbergVehicle::get_sensor_reading_right(const ArenaEntity* entity) {
  if (entity) {
    return 1800.0/std::pow(
      1.08, (entity->get_pose()-light_sensors_[1]).Length());
  }

  return 0.0001;
}

void BraitenbergVehicle::UpdateLightSensors() {
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

void BraitenbergVehicle::Subscribe(Observer * observer) {
  obs_ = observer;
}

void BraitenbergVehicle::Unsubscribe() {
  obs_ = NULL;
}

void BraitenbergVehicle::Notify() {
  if (obs_) {
    obs_->Update(wv_);
  }
}

void BraitenbergVehicle::Die() {
  dead_ = true;
}

bool BraitenbergVehicle::isDead() {
  return dead_;
}

void BraitenbergVehicle::LoadFromObject(json_object* entity_config) {
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
  if ((*entity_config).find("braitenberg_behavior") != (*entity_config).end()) {
      bv_behavior_ = get_behavior_type(
        (*entity_config)["braitenberg_behavior"].get<std::string>());
      set_bv_behavior(bv_behavior_);
  }

  UpdateLightSensors();
}

NAMESPACE_END(csci3081);
