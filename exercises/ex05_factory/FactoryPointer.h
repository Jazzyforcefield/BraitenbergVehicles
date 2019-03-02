#ifndef FACTORYPOINTER_H_
#define FACTORYPOINTER_H_

#include <iostream>
#include <cstdlib>

#include "legged_robot.h"

class FactoryPointer {
	public:
		FactoryPointer();
	
		void Create(Robot ** r);
		
		void Create(LeggedRobot ** lr);

};

#endif /* FACTORYPOINTER_H_ */
