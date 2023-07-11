#pragma once
#include "Element.h"

class Line : public Element {
public:
	using Element::Element;

	void ReadFromFile(const std::string& path, const std::string& fileName);
	
	
private:
	//vector <Element> container;
	double length;
	int minNumberOfElement = 2;
	double CalculateLenght(const std::vector<Element>& container);
	void CalculateLine(const std::vector<Element>& container);
};

