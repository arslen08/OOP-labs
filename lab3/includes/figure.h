#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual Point geometricCenter() const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend std::istream& operator>>(std::istream& is, Figure& figure);
    virtual operator double() const;
};

std::ostream& operator<<(std::ostream& os, const Figure& figure);
std::istream& operator>>(std::istream& is, Figure& figure);

#endif