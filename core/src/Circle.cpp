/*
 * Circle.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#include "Circle.h"
#include <cmath>

Circle::Circle(Vector3 position, double radius):Curve(position){
	position.z = 0;
	this->radius = radius;
}

Circle::~Circle(){}

Vector3 Circle::get_Point_At(double t){
	double x = position.x + cos(t)*radius;
	double y = position.y + sin(t)*radius;
	return Vector3(x, y, position.z);
}

Vector3 Circle::get_Derivative_At(double t){
	double dx = -sin(t)*radius;
	double dy = cos(t)*radius;
	return Vector3(dx, dy, 0);
}
