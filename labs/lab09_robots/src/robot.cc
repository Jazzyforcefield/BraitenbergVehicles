#include <cmath>

#include "robot.h"

	Robot::Robot(int id, double radius, Point origin, double speed) : 
		id_(id), radius_(radius), origin_(origin), speed_(speed) {
		
		Point position(origin_.x_ + speed_ * cos(0), origin_.y_ + speed_ * sin(0));
		position_ = position;
		sensor_range_ = 3.0 * radius_;
		sensor_angle_ = 2.0;
		direction_ = 0;
		
	}
	
	void Robot::Update(double time) {
		double delta_x = origin_.x_ + speed_ * cos(time);
		double delta_y = origin_.y_ + speed_ * sin(time);
		direction_ = atan2(delta_x, delta_y);
	}
	
	bool Robot::get_color() {
		return color_;
	}
	
	int Robot::get_id() {
		return id_;
	}
	
	double Robot::get_radius() {
		return radius_;
	}

	Point Robot::get_position() {
		return position_;
	}
	
	double Robot::get_direction() {
		return direction_;
	}
	
	double Robot::get_sensor_angle() {
		return sensor_angle_;
	}
	
	double Robot::get_sensor_range() {
		return sensor_range_;
	}
	
	void Robot::set_color(bool color) {
		color_ = color;
	}

