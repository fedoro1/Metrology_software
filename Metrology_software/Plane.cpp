#include "Plane.h"

void Plane::ReadFromFile(const std::string& path, const std::string& fileName) {
    std::fstream fs = Element::OpenFile(path, fileName);
    TakeDataFromFile(fs, this->container);
    if (container.size() < minNumberOfElement) {
        std::cout << "Error, plane needs minimun " << minNumberOfElement << " points" << std::endl;
        return;
    }
    CalculatePlane(this->container);
}

void Plane::Calculate(const std::vector<Element>& container) {
    const int numPoints = container.size();

    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> A(numPoints, 3);
    Eigen::Matrix<double, Eigen::Dynamic, 1> B(numPoints, 1);
   
    for (size_t i = 0; i < numPoints; i++) {
		A.row(i) << container.at(i).GetX(), container.at(i).GetY(), container.at(i).GetZ();
        B.row(i) << -1;
    }

    std::cout << A << std::endl;
    std::cout << B << std::endl;

    //Eigen::Vector3d x = A.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(B);
    Eigen::VectorXd x = (A.transpose() * A).ldlt().solve(A.transpose() * B);
    Eigen::Vector3d nV = x.normalized();

    this->nx = nV(0);
    this->ny = nV(1);
    this->nz = nV(2);

}