/*
 * main.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#include "Circle.h"

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	cout<<"Hello world!"<<endl;
	Curve *circle = new Circle(Vector3(0,0,0), 1);

	Vector3 tmp;

	for(int i=0; i<10; i++){
		tmp = circle->get_Point_At(M_PI*i);
		cout<<"i = "<<i<<"; x = "<<tmp.x<<"; y= "<<tmp.y<<"; z = "<<tmp.z<<endl;
	}
	return 0;
}
