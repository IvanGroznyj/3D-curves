/*
 * Helix.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#include "Helix.h"
#include <cmath>

Helix::Helix(Vector3 position, double radius, double step):Circle(position, radius){
	position.z = 0;
	this->step = step;
}

Helix::~Helix(){}

Vector3 Helix::get_Point_At(double t){
	Vector3 result = Circle::get_Point_At(t);
	result.z = position.z + step*(t/(M_PI*2));
	return result;
}

Vector3 Helix::get_Derivative_At(double t){
	Vector3 result = Circle::get_Derivative_At(t);
	result.z = step/(M_PI*2);
	return result;
}
