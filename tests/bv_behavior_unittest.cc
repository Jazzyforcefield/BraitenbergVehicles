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
    agg = new csci3081::AggressiveBehavior();
    cow = new csci3081::CowardBehavior();
    exp = new csci3081::ExploreBehavior();
    lov = new csci3081::LoveBehavior();
  }
  virtual void TearDown() {
  }

  csci3081::WheelBehavior * agg;
  csci3081::WheelBehavior * cow;
  csci3081::WheelBehavior * exp;
  csci3081::WheelBehavior * lov;

};

TEST_F(bv_test, AggressiveTests) {
  EXPECT_EQ(agg->WheelUpdate(0, 0, 5).left, 0) << "Incorrect left velocity";
  EXPECT_EQ(agg->WheelUpdate(0, 0, 5).right, 0) << "Incorrect right velocity";

  EXPECT_EQ(agg->WheelUpdate(800, 800, 5).left, 5) << "Incorrect left velocity";
  EXPECT_EQ(agg->WheelUpdate(800, 800, 5).right, 5)
    << "Incorrect right velocity";

  EXPECT_EQ(agg->WheelUpdate(0.640, 0.813, 5).left, 0.813)
    << "Incorrect left velocity";
  EXPECT_EQ(agg->WheelUpdate(0.640, 0.813, 5).right, 0.640)
    << "Incorrect right velocity";
};

TEST_F(bv_test, CowardTests) {
  EXPECT_EQ(cow->WheelUpdate(0, 0, 5).left, 0) << "Incorrect left velocity";
  EXPECT_EQ(cow->WheelUpdate(0, 0, 5).right, 0) << "Incorrect right velocity";

  EXPECT_EQ(cow->WheelUpdate(800, 800, 5).left, 5) << "Incorrect left velocity";
  EXPECT_EQ(cow->WheelUpdate(800, 800, 5).right, 5)
    << "Incorrect right velocity";

  EXPECT_EQ(cow->WheelUpdate(0.640, 0.813, 5).left, 0.640)
    << "Incorrect left velocity";
  EXPECT_EQ(cow->WheelUpdate(0.640, 0.813, 5).right, 0.813)
    << "Incorrect right velocity";
};

TEST_F(bv_test, ExploreTests) {
  EXPECT_EQ(exp->WheelUpdate(0.001, 0.001, 5).left, 5)
    << "Incorrect left velocity";
  EXPECT_EQ(exp->WheelUpdate(0.001, 0.001, 5).right, 5)
    << "Incorrect right velocity";

  EXPECT_EQ(exp->WheelUpdate(800, 800, 5).left, 0.00125)
    << "Incorrect left velocity";
  EXPECT_EQ(exp->WheelUpdate(800, 800, 5).right, 0.00125);

  EXPECT_NEAR(exp->WheelUpdate(0.640, 0.813, 5).left, 1.230, 0.001)
    << "Incorrect right velocity";
  EXPECT_EQ(exp->WheelUpdate(0.640, 0.813, 5).right, 1.5625)
    << "Incorrect left velocity";
};

TEST_F(bv_test, LoveTests) {
  EXPECT_EQ(lov->WheelUpdate(0.001, 0.001, 5).left, 5)
    << "Incorrect left velocity";
  EXPECT_EQ(lov->WheelUpdate(0.001, 0.001, 5).right, 5)
    << "Incorrect right velocity";

  EXPECT_EQ(lov->WheelUpdate(800, 800, 5).left, 0.00125)
    << "Incorrect left velocity";
  EXPECT_EQ(lov->WheelUpdate(800, 800, 5).right, 0.00125)
    << "Incorrect right velocity";

  EXPECT_EQ(lov->WheelUpdate(0.640, 0.813, 5).left, 1.5625);
  EXPECT_NEAR(lov->WheelUpdate(0.640, 0.813, 5).right, 1.230, 0.001)
    << "Incorrect right velocity";
};
