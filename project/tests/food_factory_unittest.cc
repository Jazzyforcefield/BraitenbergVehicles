#include <gtest/gtest.h>

#include <iostream>
#include <fstream>

#include "src/FoodFactory.h"
#include "src/common.h"

class FoodFactoryTest : public::testing::Test {
	public:
		void SetUp() {
			one = new csci3081::FoodFactory();
		}
		
	protected:
    json_value * config_;
		csci3081::FoodFactory * one;
};


TEST_F(FoodFactoryTest, ConstructorTests) {
	//ArenaEntity * test = new Food();

  std::ifstream t(std::string("./scenes/default.json").c_str());
  std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
  std::string json = str;
  config_ = new json_value();
  std::string err = parse_json(*config_, json);
  
  json_object& arena_config = config_->get<json_object>();
  json_array& entities = arena_config["entities"].get<json_array>();
  json_object& entity_config = entities[1].get<json_object>();

	csci3081::ArenaEntity * test2;
	one->Create(&test2, entity_config);
	ASSERT_EQ(test2->get_name(), "Food");
  ASSERT_EQ(test2->get_pose().x, 200);
  ASSERT_EQ(test2->get_pose().y, 200);
  ASSERT_EQ(test2->get_pose().theta, 0);
}
