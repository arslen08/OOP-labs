#ifndef ARRAY_H
#define ARRAY_H

#include "figure.h"
#include <vector>
#include <memory>

class FigureArray {
private:
    std::vector<std::shared_ptr<Figure>> figures;
    
public:
    void addFigure(std::shared_ptr<Figure> figure);
    void removeFigure(size_t index);
    void printAll() const;
    double totalArea() const;
    size_t size() const;
    std::shared_ptr<Figure> operator[](size_t index) const;
};

#endif