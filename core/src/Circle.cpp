/*
 * Circle.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#include "Circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(Vector3 position, double radius):Curve(position){
	position.z = 0;
	if (radius<=0) throw std::invalid_argument("radius must by positive");
	this->radius = radius;
}

Circle::~Circle(){}

double Circle::get_Radius(){
	return radius;
}

int Circle::compare_To(const Curve &curve){
	if(typeid(curve) != typeid(*this)) throw std::invalid_argument("different type");

	if(radius < ((Circle*)const_cast<Curve*>(&curve))->get_Radius()) return -1;
	if(radius == ((Circle*)const_cast<Curve*>(&curve))->get_Radius()) return 0;
	return 1;
}

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
