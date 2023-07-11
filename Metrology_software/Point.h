#pragma once
#include "Element.h"

class Point : public Element{
public:
	using Element::Element;
private: 
	int minNumberOfElement = 1;
};


