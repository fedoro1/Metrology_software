#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <cmath>
#include <Eigen/Dense>

//using namespace std;

enum class TypeOfElement {
	Real,
	Theoretical
};

class Element {
public:
	Element();
	Element(double x, double y, double z);
	Element(double x, double y, double z, double nx, double ny, double nz);
	double GetId() const;
	double GetX() const;
	double GetY() const;
	double GetZ() const;
	const std::vector<Element>& GetContainer() const;
	void PrintCoordinate() const;
	void WriteToFile(const std::string& path, const std::string& fileName);
	friend std::ostream& operator<<(std::ostream& os, const Element& element);
	friend std::istream& operator>>(std::istream& is, Element& element);
	std::fstream OpenFile(const std::string& path, const std::string& fileName);
	std::vector<Element> TakeDataFromFile(std::fstream& fs, std::vector<Element>& container);

	static int count;
private:
	int id;
	TypeOfElement type;
	void Calculate(const std::vector<Element>& container);
protected: 
	double x, y, z, nx, ny, nz;
	std::vector <Element> container;
	double standardDeviation;
};

