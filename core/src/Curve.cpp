/*
 * Curve.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#include "Curve.h"
#include <cmath>

Curve::Curve(Vector3 position){
	this->position = position;
}

Curve::~Curve(){}

Vector3 Curve::get_Position(){
	return position;
}
