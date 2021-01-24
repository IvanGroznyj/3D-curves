/*
 * main.cpp
 *
 *  Created on: Jan 23, 2021
 *      Author: Ivan Khodyrev
 */

#include "Circle.h"
#include "Helix.h"
#include "Ellipse.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <time.h>
#include <iterator>
#include <algorithm>
using namespace std;

#define N_CURVES 100

bool compare_asc(Curve *left, Curve *right){
	return left->compare_To(*right) == -1;
}

int main() {
	srand(time(0));

	vector<Curve*> all_curves = vector<Curve*>();

	int cur_curve_type;
	int n_circles, n_ellipses, n_helixes;
	n_circles = n_ellipses = n_helixes = 0;
	for (int i = 0; i < N_CURVES; i++) {
		cur_curve_type = rand() % 3;
		switch (cur_curve_type) {
		case 0:
			all_curves.push_back(
					new Circle(
							Vector3(rand() % 100, rand() % 100, rand() % 100),
							rand() % 10 + 1));
			n_circles++;
			break;
		case 1:
			all_curves.push_back(
					new Ellipse(
							Vector3(rand() % 100, rand() % 100, rand() % 100),
							rand() % 10 + 1, rand() % 10 + 1));
			n_ellipses++;
			break;
		case 2:
			all_curves.push_back(
					new Helix(Vector3(rand() % 100, rand() % 100, rand() % 100),
							rand() % 10 + 1, rand() % 10 + 1));
			n_helixes++;
			break;
		default:
			break;
		}
	}

	all_curves.resize(N_CURVES);

	cout << "Circles: " << n_circles << endl;
	cout << "Ellipses: " << n_ellipses << endl;
	cout << "Helixes: " << n_helixes << endl;

	Vector3 tmp;

	double t = M_PI / 4;

	for (vector<Curve*>::iterator itr = all_curves.begin(); itr != all_curves.end(); itr++) {
		tmp = (*itr)->get_Point_At(t);
		cout << "x = " << tmp.x << "; y= " << tmp.y << "; z = "
				<< tmp.z << ";";
		tmp = (*itr)->get_Derivative_At(t);
		cout << " dx = " << tmp.x << "; dy= " << tmp.y << "; dz = "
				<< tmp.z << ";"<<endl;
	}

	vector<Curve*> circles = vector<Curve*>();
	for (vector<Curve*>::iterator itr = all_curves.begin(); itr != all_curves.end(); itr++) {
		if(typeid(**itr)==typeid(Circle)){
			circles.push_back(*itr);
		}
	}

	cout<<"Circles found: "<<circles.size()<<endl;

	sort(circles.begin(), circles.end(), compare_asc);
	for (vector<Curve*>::iterator itr = circles.begin(); itr != circles.end(); itr++) {
		cout<<"R = "<<((Circle*)(*itr))->get_Radius()<<endl;
	}


	double radii_sum = 0;
	for (vector<Curve*>::iterator itr = circles.begin(); itr != circles.end(); itr++) {
		radii_sum += ((Circle*)(*itr))->get_Radius();
	}

	cout<<"radii sum: "<<radii_sum<<endl;

	// free memory
	for (vector<Curve*>::iterator itr = all_curves.begin(); itr != all_curves.end(); itr++){
		delete (*itr);
	}

	return 0;
}
