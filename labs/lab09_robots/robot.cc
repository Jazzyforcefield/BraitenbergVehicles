#include "robot.h"

class Robot {

public
	Robot::Robot(int id, double radius, Point origin, double speed) : 
		id_(id), radius_(radius), origin_(origin), speed_(speed) {}
	
	void Update(double time) {
	}
	
	bool get_color() {
		return color_;
	}
	
	int get_id() {
		return id_;
	}
	
	double get_radius() {
		return radius_;
	}

	Point get_position() {
		return position_;
	}
	
	double get_direction() {
		return direction_;
	}
	
	double get_speed() {
		return speed_;
	}
	
	double get_sensor_angle() {
		return sensor_angle_;
	}
	
	double get_sensor_range() {
		return sensor_range_;
	}
	
	void set_color(bool color) {
		color_ = color;
	}
}
