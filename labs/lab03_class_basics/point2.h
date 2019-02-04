#ifndef POINT2_H_
#define POINT2_H_

#include <iostream>

class Point2 {
public:
	// constructor
	Point2();
	Point2(float x, float y);

	// class methods
	float DistanceBetween(Point2& other);
	int Quadrant();
	void Print();
	
private:
	// member variables
	float x_;
	float y_;	
};


#endif
