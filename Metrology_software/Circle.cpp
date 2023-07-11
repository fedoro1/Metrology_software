#include "Circle.h"

double Circle::GetRadius() {
    return this->radius;
}

double Circle::GetDiameter() {
    return this-> radius*2;
}

void Circle::ReadFromFile(const std::string& path, const std::string& fileName) {
    std::fstream fs = Element::OpenFile(path, fileName);
    TakeDataFromFile(fs, this->container);
    if (container.size() < minNumberOfElement) {
        std::cout << "Error, line needs minimun " << minNumberOfElement << " points" << std::endl;
        return;
    }
    CalculateCircle(this->container);
}

void Circle::CalculateCircle(const std::vector<Element>& container) {
    const int numPoints = container.size();

    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> A(numPoints, 4); 
    Eigen::Matrix<double, Eigen::Dynamic, 1> B(numPoints, 1);
    for (size_t i = 0; i < numPoints; i++) {
        A.row(i) << container.at(i).GetX(), container.at(i).GetY(), container.at(i).GetZ(), 1;
    }

    B = A.col(0).array().square() + A.col(1).array().square() + A.col(2).array().square();

    Eigen::Vector4d solution = A.jacobiSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(B);

    // Вывод результатов
    // Извлекаем параметры окружности
    double x = solution(0);
    double y = solution(1);
    double z = solution(2);
    double r = std::sqrt(solution(3));
    //double r = std::sqrt(x*x+y*y+z*z- solution(3));
    //double radius = std::sqrt(center.squaredNorm() - solution(3));
    std::cout << "Midle point (cx, cy, cz): (" << x << ", " << y << ", " << z << ")" << std::endl;
    std::cout << "(r): " << r << std::endl;
}