/*
 * Helix.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#include "Helix.h"
#include <cmath>
#include <stdexcept>

Helix::Helix(Vector3 position, double radius, double step):Curve(position){
	position.z = 0;

	if (radius<=0) throw std::invalid_argument("radius must by positive");
	this->radius = radius;

	this->step = step;
}

Helix::~Helix(){}

double Helix::get_Radius(){
	return radius;
}

double Helix::get_Step(){
	return step;
}

int Helix::compare_To(const Curve &curve){
	if(typeid(curve) != typeid(*this)) throw std::invalid_argument("different type");

	if(radius < ((Helix*)const_cast<Curve*>(&curve))->get_Radius()) return -1;
	if(radius == ((Helix*)const_cast<Curve*>(&curve))->get_Radius()){
		if(step < ((Helix*)const_cast<Curve*>(&curve))->get_Step()) return -1;
		if(step == ((Helix*)const_cast<Curve*>(&curve))->get_Step()) return 0;
	}
	return 1;
}

Vector3 Helix::get_Point_At(double t){
	double x = position.x + cos(t)*radius;
	double y = position.y + sin(t)*radius;
	double z = position.z + step*(t/(M_PI*2));
	return Vector3(x,y,z);
}

Vector3 Helix::get_Derivative_At(double t){
	double dx = -sin(t)*radius;
	double dy = cos(t)*radius;
	double dz = step/(M_PI*2);
	return Vector3(dx,dy,dz);
}
