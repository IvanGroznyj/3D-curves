/*
 * Vector3.h
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

struct Vector3 {
	double x, y, z;

	Vector3();
	Vector3(double x, double y, double z);
	~Vector3();

	Vector3& operator=(const Vector3 &right);

	friend Vector3 operator+(const Vector3 &left, const Vector3 &right);
	friend Vector3 operator-(const Vector3 &left, const Vector3 &right);

	friend bool operator==(const Vector3 &left, const Vector3 &right);
	friend bool operator!=(const Vector3 &left, const Vector3 &right);
};

#endif /* VECTOR3_H_ */
