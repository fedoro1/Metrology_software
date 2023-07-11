#include "Point.h"
#include "Line.h"
#include "Plane.h"
#include "Circle.h"
#include "Characteristic.h"
#include "Functions.h"
#include "Functions.cpp"



int main() {
	std::string path = "E:\\Downloads\\";
	std::string fileName = "myfile.txt";
	Plane a;
	a.ReadFromFile("E:\\Downloads\\", "myfile.txt");
	//WritePointsToFile(path, fileName, a);
	//Point a(1, 1, 1);
	//a.WriteToFile(path, fileName);
	//Point b(2, 0, 0);
	//Point c(3, 0, 0);
	//Point d(4, 0, 0);
	//a.PrintCoordinate();
	//a.GetId();
	//GetDistanceZ(a, b);
	//b.PrintCoordinate();
	//b.GetId();
	/*Point::GetDistance(a, b);
	Point::GetDistanceX(a, b);
	Point::GetDistanceY(a, b);
	Point::GetDistanceZ(a, b);*/
	/*Point::WriteToFile("E:\\Downloads\\", "myfile.txt", a);
	Point::WriteToFile("E:\\Downloads\\", "myfile.txt", b);
	Point::WriteToFile("E:\\Downloads\\", "myfile.txt", c);
	Point::WriteToFile("E:\\Downloads\\", "myfile.txt", d);*/
	//Line line1; 
	//line1.ReadFromFile(path, fileName);
	/*std::string path = "E:\\Downloads\\";
	std::string fileName = "myfile1.txt";
	Circle circle; 
	circle.ReadFromFile("E:\\Downloads\\", "myfile.txt");
	Circle::WriteToFile(path, fileName, circle); */

	
}