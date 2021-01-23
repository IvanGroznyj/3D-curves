/*
 * Ellipse.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(Vector3 position, double radius_x, double radius_y):Curve(position){
	position.z = 0;
	this->radius_x = radius_x;
	this->radius_y = radius_y;
}

Ellipse::~Ellipse(){}

Vector3 Ellipse::get_Point_At(double t){
	double x = position.x + cos(t)*radius_x;
	double y = position.y + sin(t)*radius_y;
	return Vector3(x, y, position.z);
}

Vector3 Ellipse::get_Derivative_At(double t){
	double dx = -sin(t)*radius_x;
	double dy = cos(t)*radius_y;
	return Vector3(dx, dy, 0);
}
