#pragma once
#include "Element.h"

class Plane : public Element {
public:
	using Element::Element;
	void ReadFromFile(const std::string& path, const std::string& fileName);
private:
	double standardDeviation; 
	int minNumberOfElement = 3;
	void Calculate(const std::vector<Element>& container);
};

