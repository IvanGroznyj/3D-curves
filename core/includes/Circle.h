/*
 * Circle.h
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Curve.h"

class Circle: public Curve{
protected:
	double radius;
public:
	Circle(Vector3 position, double radius);
	~Circle();

	double get_Radius();

	int compare_To(const Curve &curve);

	Vector3 get_Point_At(double t);
	Vector3 get_Derivative_At(double t);
};


#endif /* CIRCLE_H_ */
