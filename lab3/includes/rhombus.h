#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class Rhombus : public Figure {
private:
    Point center;
    double diagonal1, diagonal2; 
    
public:
    Rhombus();
    Rhombus(const Point& center, double d1, double d2);
    
    Point geometricCenter() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;
};

#endif