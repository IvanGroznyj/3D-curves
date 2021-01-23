/*
 * Helix.h
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#ifndef HELIX_H_
#define HELIX_H_

#include "Circle.h"

class Helix: public Circle{
protected:
	double step;
public:
	Helix(Vector3 position, double radius, double step);
	~Helix();

	Vector3 get_Point_At(double t);
	Vector3 get_Derivative_At(double t);
};



#endif /* HELIX_H_ */
