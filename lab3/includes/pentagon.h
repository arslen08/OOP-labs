#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"

class Pentagon : public Figure {
private:
    Point center;
    double radius;
    
public:
    Pentagon();
    Pentagon(const Point& center, double radius);
    
    Point geometricCenter() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
};

#endif