#include <gtest/gtest.h>

#include <iostream>
#include <fstream>

#include "src/LightFactory.h"


class LightFactoryTest : public::testing::Test {
	public:
		void SetUp() {
			one = new csci3081::LightFactory();
		}
		
	protected:
    json_value * config_;
		csci3081::LightFactory * one;
};


TEST_F(LightFactoryTest, ConstructorTests) {
	//ArenaEntity * test = new Light();

  std::ifstream t(std::string("./scenes/default.json").c_str());
  std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
  std::string json = str;
  config_ = new json_value();
  std::string err = parse_json(config_, json);
  
  json_object& arena_config = config_->get<json_object>();
  json_array& entities = arena_config["entities"].get<json_array>();
  json_object& entity_config = entities[2].get<json_object>();

	csci3081::ArenaEntity * test2;
	one->Create(&test2, &entity_config);
	ASSERT_EQ(test2->get_name(), "Light 1");
  ASSERT_EQ(test2->get_pose().x, 150);
  ASSERT_EQ(test2->get_pose().y, 300);
  ASSERT_EQ(test2->get_pose().theta, 0);
}
