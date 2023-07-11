#pragma once
#include "Characteristic.h"

//----------------------------------------------------------------------------------------------------------------
double GetDistance(const Point& a, const Point& b) {
	double r = std::hypot(a.GetX() - b.GetX(), a.GetY() - b.GetY(), a.GetZ() - b.GetZ());
	std::cout << "Distance is: " << r << std::endl;
	return r;
}

double GetDistanceX(const Point& a, const Point& b) {
	double r = abs(a.GetX() - b.GetX());
	std::cout << "Distance X is: " << r << std::endl;
	return r;
}

double GetDistanceY(const Point& a, const Point& b) {
	double r = abs(a.GetY() - b.GetY());
	std::cout << "Distance Y is: " << r << std::endl;
	return r;
}

double GetDistanceZ(const Point& a, const Point& b) {
	double r = abs(a.GetZ() - b.GetZ());
	std::cout << "Distance Z is: " << r << std::endl;
	return r;
}

//----------------------------------------------------------------------------------------------------------------

