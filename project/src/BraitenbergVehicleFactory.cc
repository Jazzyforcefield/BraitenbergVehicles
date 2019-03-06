#include <iostream>

#include "src/BraitenbergVehicleFactory.h"

NAMESPACE_BEGIN(csci3081);

BraitenbergVehicleFactory::BraitenbergVehicleFactory() {};

void BraitenbergVehicleFactory::Create(__unused ArenaEntity ** ent) {
	std::cout << "Inside BraitenbergVehicle's create\n" << std::endl;
	// *ent = new BraitenbergVehicle();
}

BraitenbergVehicleFactory::~BraitenbergVehicleFactory() {};

NAMESPACE_END(csci3081);
