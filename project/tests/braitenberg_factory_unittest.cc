#include <gtest/gtest.h>

#include <iostream>
#include <fstream>

#include "src/behavior_enum.h"
#include "src/BraitenbergVehicleFactory.h"
#include "src/common.h"


class BraitenbergVehicleFactoryTest : public::testing::Test {
	protected:
		void SetUp() {
			one = new csci3081::BraitenbergVehicleFactory();
    }

    json_value* config_ = NULL;
		csci3081::BraitenbergVehicleFactory * one;
};


TEST_F(BraitenbergVehicleFactoryTest, ConstructorTests) {
	//ArenaEntity * test = new BraitenbergVehicle();

  std::ifstream t(std::string("./scenes/default.json").c_str());
  std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
  std::string json = str;
  config_ = new json_value();
  std::string err = parse_json(config_, json);
  
  json_object& arena_config = config_->get<json_object>();
  json_array& entities = arena_config["entities"].get<json_array>();
  json_object& entity_config = entities[0].get<json_object>();

	csci3081::ArenaEntity * test2;
	one->Create(&test2, &entity_config);
	ASSERT_EQ(test2->get_name(), "Braitenberg 1");  
  ASSERT_EQ(test2->get_pose().x, 270);
  ASSERT_EQ(test2->get_pose().y, 270);
  ASSERT_EQ(test2->get_pose().theta, 215);
}
