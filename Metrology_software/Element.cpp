#include "Element.h"
#include "Plane.h"


int Element::count = 0;

Element::Element() {
	x = y = z = ny = nz=  0;
	nx = 1;
	this->type = TypeOfElement::Real;
	id = count;
	count++;
}

Element::Element(double x, double y, double z) : Element() {
	this->x = x;
	this->y = y;
	this->z = z;
}

Element::Element(double x, double y, double z, double nx, double ny, double nz) : Element(x, y, z) {
	this->nx = nx;
	this->ny = ny;
	this->nz = nz;
}

double Element::GetId() const {
	std::cout << "ID: " << id << std::endl;
	return this->id;
}

double Element::GetX() const {
	return this->x;
}

double Element::GetY() const {
	return this->y;
}

double Element::GetZ() const {
	return this->z;
}

const std::vector<Element>& Element::GetContainer() const {
	return this->container;
}

//----------------------------------------------------------------------------------------------------------------

std::fstream Element::OpenFile(const std::string& path, const std::string& fileName) {
	std::fstream fs;
	fs.exceptions(std::fstream::badbit | std::fstream::failbit);
	try {
		fs.open(path + fileName);
	}
	catch (const std::fstream::failure& exception) {
		std::cout << "Error! File was not found" << std::endl;
		std::cout << exception.what() << std::endl;
		throw;
	}
	return fs;
}

std::vector<Element> Element::TakeDataFromFile(std::fstream& fs, std::vector<Element>& container) {
	Element element;
	while (!fs.eof()) {
		fs >> element;
		container.push_back(element);
	}
	fs.close();
	return container;
}

void Element::Calculate(const std::vector<Element>& container) {}

void Element::PrintCoordinate() const {
	std::cout << "X: " << x << "\t" << "Y: " << y << "\t" << "Z: " << z << std::endl;
}

void Element::WriteToFile(const std::string& path, const std::string& fileName) {
	std::fstream fs;
	fs.open(path + fileName, std::fstream::app); 
	fs << this->GetX() << "\t" << this->GetY() << "\t" << this->GetZ() << "\n";
	fs.close();
}


//----------------------------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const Element& element) {
	os << element.x << "\t" << element.y << "\t" << element.z << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Element& element) {
	is >> element.x >> element.y >> element.z;
	return is; 
}