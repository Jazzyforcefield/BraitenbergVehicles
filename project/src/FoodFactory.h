#ifndef SRC_FOODFACTORY_H_
#define SRC_FOODFACTORY_H_

#include <iostream>
#include <cstdlib>

#include "src/Factory.h"

NAMESPACE_BEGIN(csci3081);

class FoodFactory : public Factory {
	public:
		FoodFactory();
		~FoodFactory();
		void Create(ArenaEntity ** ent) override;
};

NAMESPACE_END(csci3081);

#endif /* SRC_FOODFACTORY_H_ */
