/*
 * Curve.h
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#ifndef CURVE_H_
#define CURVE_H_

#include "Vector3.h"

class Curve{
protected:
	Vector3 position;

public:
	Curve(Vector3 position);
	virtual ~Curve();

	virtual Vector3 get_Point_At(double t)=0;
	virtual Vector3 get_Derivative_At(double t)=0;
};

#endif /* CURVE_H_ */
