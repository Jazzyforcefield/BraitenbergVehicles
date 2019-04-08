// Copyright 2019, Michael Ung

#include <gtest/gtest.h>
#include "src/arena.h"
#include "src/entity_type.h"
#include "src/params.h"
#include "src/pose.h"
#include "src/braitenberg_vehicle.h"
#include "src/wheel_velocity.h"
#include "src/behavior_enum.h"
#include "src/light.h"
#include "src/food.h"

class bv_test : public ::testing::Test {

 protected:
  virtual void SetUp() {
    arena = new csci3081::Arena(); // l f bv
    fgh = dynamic_cast<csci3081::Food * >(arena->get_entities()[1]);
    fgh->set_pose(csci3081::Pose(510, 500, 0));
    zxc = dynamic_cast<csci3081::Light * >(arena->get_entities()[0]);
    zxc->set_pose(csci3081::Pose(510, 500, 0));
    asd = dynamic_cast<csci3081::BraitenbergVehicle * >(arena->get_entities()[2]);
  }
  virtual void TearDown() {
    delete arena;
  }
  csci3081::Food * fgh;
  csci3081::Light * zxc;
  csci3081::BraitenbergVehicle * asd;
  csci3081::Arena * arena;

};

TEST_F(bv_test, DefaultWV) {
  asd->CalculateWheelVelocity();
  EXPECT_EQ(csci3081::WheelVelocity(0, 0).left, asd->get_wheel_velocity().left);
  EXPECT_EQ(csci3081::WheelVelocity(0, 0).right, asd->get_wheel_velocity().right);
};

TEST_F(bv_test, Behaviors) {
  asd->set_light_behavior(csci3081::kExplore);
  asd->set_food_behavior(csci3081::kAggressive);
  asd->Update();
  EXPECT_EQ(2.50005, asd->get_wheel_velocity().left);
  EXPECT_EQ(2.50005, asd->get_wheel_velocity().right);

  asd->set_light_behavior(csci3081::kLove);
  asd->set_food_behavior(csci3081::kLove);
  asd->set_bv_behavior(csci3081::kLove);
  asd->Update();
  EXPECT_EQ(5, asd->get_wheel_velocity().left);
  EXPECT_EQ(5, asd->get_wheel_velocity().right);

  
  asd->set_light_behavior(csci3081::kAggressive);
  asd->set_food_behavior(csci3081::kAggressive);
  asd->set_bv_behavior(csci3081::kAggressive);
  asd->Update();
  EXPECT_EQ(0.0001, asd->get_wheel_velocity().left);
  EXPECT_EQ(0.0001, asd->get_wheel_velocity().right);

  asd->set_light_behavior(csci3081::kExplore);
  asd->set_food_behavior(csci3081::kCoward);
  asd->set_bv_behavior(csci3081::kAggressive);
  asd->Update();
  EXPECT_NEAR(1.66673, asd->get_wheel_velocity().left, 0.0001);
  EXPECT_NEAR(1.66673, asd->get_wheel_velocity().right, 0.0001);

};
