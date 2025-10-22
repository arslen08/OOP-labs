#include "../includes/rhombus.h"
#include <stdexcept>

Rhombus::Rhombus() : center(0, 0), diagonal1(2), diagonal2(1) {}

Rhombus::Rhombus(const Point& center, double d1, double d2) 
    : center(center), diagonal1(d1), diagonal2(d2) {}

Point Rhombus::geometricCenter() const {
    return center;
}

double Rhombus::area() const {
    return (diagonal1 * diagonal2) / 2.0;
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus center: (" << center.x << ", " << center.y 
       << "), diagonals: " << diagonal1 << ", " << diagonal2;
}

void Rhombus::read(std::istream& is) {
    if (!(is >> center.x >> center.y >> diagonal1 >> diagonal2)) {
        throw std::runtime_error("Invalid input for Rhombus");
    }
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        center = other.center;
        diagonal1 = other.diagonal1;
        diagonal2 = other.diagonal2;
    }
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        center = std::move(other.center);
        diagonal1 = other.diagonal1;
        diagonal2 = other.diagonal2;
    }
    return *this;
}