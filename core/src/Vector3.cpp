/*
 * Vector.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#include "Vector3.h"

Vector3::Vector3() {
	x = y = z = 0;
}

Vector3::Vector3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3(){}

Vector3& Vector3::operator=(const Vector3 &right) {
	if (this != &right) {
		this->x = right.x;
		this->y = right.y;
		this->z = right.z;
	}
	return *this;
}

Vector3 operator+(const Vector3 &left, const Vector3 &right) {
	return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3 operator-(const Vector3 &left, const Vector3 &right) {
	return Vector3(left.x - right.x, left.y - right.y, left.z - right.z);
}

bool operator==(const Vector3 &left, const Vector3 &right) {
	return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
}

bool operator!=(const Vector3 &left, const Vector3 &right) {
	return (left.x != right.x) || (left.y != right.y) || (left.z != right.z);
}
