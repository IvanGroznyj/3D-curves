/*
 * Ellipse.h
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Curve.h"

class Ellipse: public Curve {
protected:
	double radius_x, radius_y;
public:
	Ellipse(Vector3 position, double radius_x, double radius_y);
	~Ellipse();

	double get_Radius_X();
	double get_Radius_Y();

	int compare_To(const Curve &curve);

	Vector3 get_Point_At(double t);
	Vector3 get_Derivative_At(double t);
};

#endif /* ELLIPSE_H_ */
