#include <gtest/gtest.h>

#include <iostream>

#include "src/FoodFactory.h"


class FoodFactoryTest : public::testing::Test {
	public:
		void SetUp() {
			one = new csci3081::FoodFactory();
		}
		
	protected:
		csci3081::FoodFactory * one;
};


TEST_F(FoodFactoryTest, ConstructorTests) {
	//ArenaEntity * test = new Food();
	csci3081::ArenaEntity * test2;
	one->Create(&test2);
	ASSERT_EQ(test2->get_name(), "Food");
}
