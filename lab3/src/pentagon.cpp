#include "../includes/pentagon.h"
#include <stdexcept>
#include <cmath>

Pentagon::Pentagon() : center(0, 0), radius(1) {}

Pentagon::Pentagon(const Point& center, double radius) 
    : center(center), radius(radius) {}

Point Pentagon::geometricCenter() const {
    return center;
}

double Pentagon::area() const {
    double side = 2 * radius * sin(M_PI / 5);
    return (5 * side * side) / (4 * tan(M_PI / 5));
}

void Pentagon::print(std::ostream& os) const {
    os << "Pentagon center: (" << center.x << ", " << center.y 
       << "), radius: " << radius;
}

void Pentagon::read(std::istream& is) {
    if (!(is >> center.x >> center.y >> radius)) {
        throw std::runtime_error("Invalid input for Pentagon");
    }
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        center = other.center;
        radius = other.radius;
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        center = std::move(other.center);
        radius = other.radius;
    }
    return *this;
}