#include "../includes/array.h"
#include <iostream>
#include <stdexcept>

void FigureArray::addFigure(std::shared_ptr<Figure> figure) {
    figures.push_back(figure);
}

void FigureArray::removeFigure(size_t index) {
    if (index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

void FigureArray::printAll() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i << ": ";
        figures[i]->print(std::cout);
        std::cout << ", Center: (" << figures[i]->geometricCenter().x 
                  << ", " << figures[i]->geometricCenter().y 
                  << "), Area: " << figures[i]->area() << std::endl;
    }
}

double FigureArray::totalArea() const {
    double total = 0;
    for (const auto& figure : figures) {
        total += figure->area();
    }
    return total;
}

size_t FigureArray::size() const {
    return figures.size();
}

std::shared_ptr<Figure> FigureArray::operator[](size_t index) const {
    if (index >= figures.size()) {
        throw std::out_of_range("Index out of range");
    }
    return figures[index];
}