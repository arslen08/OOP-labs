#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

class Trapezoid : public Figure {
private:
    Point points[4];
    
public:
    Trapezoid();
    Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    
    Point geometricCenter() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
};

#endif