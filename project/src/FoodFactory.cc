#include <iostream>

#include "src/FoodFactory.h"

NAMESPACE_BEGIN(csci3081);

FoodFactory::FoodFactory() {};

void FoodFactory::Create(__unused ArenaEntity ** ent) {
	std::cout << "Inside FoodFactory's create\n" << std::endl;
	// *ent = new Food();
}

FoodFactory::~FoodFactory() {};

NAMESPACE_END(csci3081);
