#include <gtest/gtest.h>

#include <iostream>

#include "src/BraitenbergVehicleFactory.h"


class BraitenbergVehicleFactoryTest : public::testing::Test {
	protected:
		void SetUp() {
			one = new csci3081::BraitenbergVehicleFactory();
		}
		csci3081::BraitenbergVehicleFactory * one;
};


TEST_F(BraitenbergVehicleFactoryTest, ConstructorTests) {
	//ArenaEntity * test = new BraitenbergVehicle();
	csci3081::ArenaEntity * test2;
	one->Create(&test2);
	ASSERT_EQ(test2->get_name(), "Braitenberg 0");  // Will segfault since it isn't created yet
}
