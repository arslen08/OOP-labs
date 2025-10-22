#include "../includes/trapezoid.h"
#include <stdexcept>

Trapezoid::Trapezoid() : points{Point(0,0), Point(1,0), Point(0.8,1), Point(0.2,1)} {}

Trapezoid::Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4) 
    : points{p1, p2, p3, p4} {}

Point Trapezoid::geometricCenter() const {
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < 4; ++i) {
        sum_x += points[i].x;
        sum_y += points[i].y;
    }
    return Point(sum_x / 4, sum_y / 4);
}

double Trapezoid::area() const {
    double base1 = std::abs(points[1].x - points[0].x);
    double base2 = std::abs(points[2].x - points[3].x);
    double height = std::abs(points[2].y - points[0].y);
    return (base1 + base2) * height / 2.0;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid vertices: ";
    for (int i = 0; i < 4; ++i) {
        os << "(" << points[i].x << ", " << points[i].y << ") ";
    }
}

void Trapezoid::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        if (!(is >> points[i].x >> points[i].y)) {
            throw std::runtime_error("Invalid input for Trapezoid");
        }
    }
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            points[i] = std::move(other.points[i]);
        }
    }
    return *this;
}