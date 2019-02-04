#include <cmath>
#include <string>

#include "point2.h"

Point2::Point2(): x_(0), y_(0) {}
Point2::Point2(float x, float y): x_(x), y_(y) {}
int Point2::Quadrant() {
	if (x_ == 0 and y_ == 0) {
		return 0;		
	}
	else if (x_ > 0 and y_ == 0) {
		return 1;
	}
	else if (x_ == 0 and y_ > 0) {
		return 2;
	}
	else if (x_ < 0 and y_ == 0) {
		return 3;
	}
	else if (x_ == 0 and y_ < 0) {
		return 4;
	}
	else if (x_ > 0 and y_ > 0) {
		return 1;
	}
	else if (x_ < 0 and y_ > 0) {
		return 2;
	}
	else if (x_ < 0 and y_ < 0) {
		return 3;
	}
	else /* if (x > 0 and y < 0) */{
		return 4;
	}
}

void Point2::Print() {
	std::cout << "(" << x_ << "," << y_ << ")" << std::endl;
}
	
float Point2::DistanceBetween(Point2& other) {
	return sqrt(pow(other.x_ - this->x_, 2) + pow(other.y_ - this->y_, 2));
}


