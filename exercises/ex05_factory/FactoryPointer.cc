#include "FactoryPointer.h"
#include <iostream>

using namespace std;

FactoryPointer::FactoryPointer(void) {}

void FactoryPointer::Create(Robot ** r) {
	cout << "Inside Create(Robot ** r)" << endl;
	*r = new Robot();
}

void FactoryPointer::Create(LeggedRobot ** lr) {
	cout << "Inside Create(LeggedRobot ** lr)" << endl;
	*lr = new LeggedRobot();
}
