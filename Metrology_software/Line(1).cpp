#include "Line.h"

void Line::ReadFromFile(const std::string& path, const std::string& fileName) {
    std::fstream fs = Element::OpenFile(path, fileName);
    TakeDataFromFile(fs, this->container);
    if (container.size() < minNumberOfElement) {
        std::cout << "Error, line needs minimun " << minNumberOfElement <<" points" << std::endl;
        return;
    }
    length = CalculateLenght(this->container);
    CalculateLine(this->container);
}

double Line::CalculateLenght(const std::vector<Element>& container) {
    Element first = container.front();
    Element last = container.back();
    return std::hypot((last.GetX() - first.GetX()), (last.GetY() - first.GetY()), (last.GetZ() - first.GetZ()));
}


void Line::CalculateLine(const std::vector<Element>& container) {
    const int numPoints = container.size();
 
    //Matrix A and Vector B
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> A(numPoints, 3);
    //Eigen::Matrix<double, Eigen::Dynamic, 1> B(numPoints, 1);
    Eigen::VectorXd B(numPoints);
    for (size_t i = 0; i < numPoints; i++) {
        A.row(i) << container.at(i).GetX(), container.at(i).GetY(), 1;
        B.row(i) << container.at(i).GetZ();
    }
    //std::cout << A << endl;
    //std::cout << B << endl;
    
    //Least squares
    Eigen::Vector3d x = A.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(B);
    Eigen::Vector3d nV = x.normalized();
 
    this->nx = nV(0);
    this->ny = nV(1);
    this->nz = nV(2);
}

