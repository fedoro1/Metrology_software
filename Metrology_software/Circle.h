#pragma once
#include "Element.h"

class Circle :public Element {
public:
	using Element::Element;

	void ReadFromFile(const std::string& path, const std::string& fileName);
	double GetRadius();
	double GetDiameter();


private:
	std::vector <Element> container;
	double standardDeviation;
	double radius;
	int minNumberOfElement = 3;
	void CalculateCircle(const std::vector<Element>& container);
};

