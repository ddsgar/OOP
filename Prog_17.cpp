#include <iostream>
#include <cmath>

class Polar {
public:
    Polar(double radius = 0.0, double angle = 0.0) : radius(radius), angle(angle) {}

    Polar operator+(const Polar& other) const {
        double x1 = radius * cos(angle);
        double y1 = radius * sin(angle);

        double x2 = other.radius * cos(other.angle);
        double y2 = other.radius * sin(other.angle);

        double xSum = x1 + x2;
        double ySum = y1 + y2;

        double radiusSum = sqrt(xSum * xSum + ySum * ySum);
        double angleSum = atan2(ySum, xSum);

        return Polar(radiusSum, angleSum);
    }

    void display() const {
        std::cout << "Radius: " << radius << ", Angle: " << angle << std::endl;
    }

private:
    double radius;
    double angle;
};

int main() {
    Polar p1(2.0, 0.5);
    Polar p2(1.0, 1.2);

    Polar sum = p1 + p2;
    sum.display();

    return 0;
}
