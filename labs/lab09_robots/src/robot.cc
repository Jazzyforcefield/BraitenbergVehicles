#include <cmath>

#include "robot.h"

	//Robot::Robot();	

	Robot::Robot(int id, double radius, Point origin, double speed) : 
		id_(id), radius_(radius), origin_(origin), speed_(speed) {
		
		Point position(origin_.x_ + 200.0 * cos(0), origin_.y_ + 200.0 * sin(0));
		position_ = position;
		sensor_range_ = 3.0 * radius_;
		sensor_angle_ = 2.0;
		direction_ = 0;
		
	}
	
	void Robot::Update(double time) {
		double new_x = origin_.x_ + 200.0 * cos(speed_ * time);
		double new_y = origin_.y_ + 200.0 * sin(speed_ * time);
		double delta_x =  new_x - position_.x_;
		double delta_y =  new_y - position_.y_;
		direction_ = atan2(delta_y, delta_x);
		Point new_pos = Point(new_x, new_y);
		position_ = new_pos;
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

