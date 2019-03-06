#include <gtest/gtest.h>

#include <iostream>

#include "src/LightFactory.h"


class LightFactoryTest : public::testing::Test {
	public:
		void SetUp() {
			one = new csci3081::LightFactory();
		}
		
	protected:
		csci3081::LightFactory * one;
};


TEST_F(LightFactoryTest, ConstructorTests) {
	//ArenaEntity * test = new Light();
	csci3081::ArenaEntity * test2;
	one->Create(&test2);
	ASSERT_EQ(test2->get_name(), "Light 0");
}
