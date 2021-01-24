/*
 * Helix.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#include "Helix.h"
#include <cmath>
#include <stdexcept>

Helix::Helix(Vector3 position, double radius, double step):Curve(position), basement(position, radius){
	this->step = step;
}

Helix::~Helix(){}

double Helix::get_Radius(){
	return basement.get_Radius();
}

double Helix::get_Step(){
	return step;
}

int Helix::compare_To(const Curve &curve){
	if(typeid(curve) != typeid(*this)) throw std::invalid_argument("different type");

	if(basement.get_Radius() < ((Helix*)const_cast<Curve*>(&curve))->get_Radius()) return -1;
	if(basement.get_Radius() == ((Helix*)const_cast<Curve*>(&curve))->get_Radius()){
		if(step < ((Helix*)const_cast<Curve*>(&curve))->get_Step()) return -1;
		if(step == ((Helix*)const_cast<Curve*>(&curve))->get_Step()) return 0;
	}
	return 1;
}

Vector3 Helix::get_Point_At(double t){
	Vector3 result = basement.get_Point_At(t);
	result.z = position.z + step*(t/(M_PI*2));
	return result;
}

Vector3 Helix::get_Derivative_At(double t){
	Vector3 result = basement.get_Derivative_At(t);
	result.z = step/(M_PI*2);
	return result;
}
