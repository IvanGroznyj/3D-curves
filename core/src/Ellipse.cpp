/*
 * Ellipse.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#include "Ellipse.h"
#include <cmath>
#include <stdexcept>

Ellipse::Ellipse(Vector3 position, double radius_x, double radius_y):Curve(position){
	position.z = 0;

	if(radius_x<=0) throw std::invalid_argument("radius_x must by positive");
	this->radius_x = radius_x;

	if(radius_y<=0) throw std::invalid_argument("radius_y must by positive");
	this->radius_y = radius_y;
}

Ellipse::~Ellipse(){}

double Ellipse::get_Radius_X(){
	return radius_x;
}

double Ellipse::get_Radius_Y(){
	return radius_y;
}

int Ellipse::compare_To(const Curve &curve){
	if(typeid(curve) != typeid(*this)) throw std::invalid_argument("different type");

	if(radius_x < ((Ellipse*)const_cast<Curve*>(&curve))->get_Radius_X()) return -1;
	if(radius_x == ((Ellipse*)const_cast<Curve*>(&curve))->get_Radius_X()){
		if(radius_y < ((Ellipse*)const_cast<Curve*>(&curve))->get_Radius_Y()) return -1;
		if(radius_y == ((Ellipse*)const_cast<Curve*>(&curve))->get_Radius_Y()) return 0;
	}
	return 1;
}

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
