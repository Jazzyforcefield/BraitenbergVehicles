#include <iostream>

#include "src/LightFactory.h"

NAMESPACE_BEGIN(csci3081);

LightFactory::LightFactory() {};

void LightFactory::Create(__unused ArenaEntity ** ent) {
	std::cout << "Inside LightFactory's create\n" << std::endl;
	// *ent = new Light();
}

LightFactory::~LightFactory() {};

NAMESPACE_END(csci3081);
