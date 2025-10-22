#include "includes/figure.h"
#include "includes/trapezoid.h"
#include "includes/rhombus.h"
#include "includes/pentagon.h"
#include "includes/array.h"
#include <iostream>
#include <memory>
#include <limits>

void showMenu() {
    std::cout << "\n=== Figure Management System ===" << std::endl;
    std::cout << "1. Add Trapezoid" << std::endl;
    std::cout << "2. Add Rhombus" << std::endl;
    std::cout << "3. Add Pentagon" << std::endl;
    std::cout << "4. Remove Figure" << std::endl;
    std::cout << "5. Print All Figures" << std::endl;
    std::cout << "6. Calculate Total Area" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Choose option: ";
}

int main() {
    FigureArray array;
    int choice;
    
    while (true) {
        showMenu();
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }
        
        try {
            switch (choice) {
                case 1: {
                    auto trapezoid = std::make_shared<Trapezoid>();
                    std::cout << "Enter 4 points for trapezoid (x1 y1 x2 y2 x3 y3 x4 y4): ";
                    std::cin >> *trapezoid;
                    array.addFigure(trapezoid);
                    std::cout << "Trapezoid added successfully." << std::endl;
                    break;
                }
                case 2: {
                    auto rhombus = std::make_shared<Rhombus>();
                    std::cout << "Enter center (x y) and two diagonals (d1 d2) for rhombus: ";
                    std::cin >> *rhombus;
                    array.addFigure(rhombus);
                    std::cout << "Rhombus added successfully." << std::endl;
                    break;
                }
                case 3: {
                    auto pentagon = std::make_shared<Pentagon>();
                    std::cout << "Enter center (x y) and radius for pentagon: ";
                    std::cin >> *pentagon;
                    array.addFigure(pentagon);
                    std::cout << "Pentagon added successfully." << std::endl;
                    break;
                }
                case 4: {
                    if (array.size() == 0) {
                        std::cout << "No figures to remove." << std::endl;
                        break;
                    }
                    std::cout << "Enter index to remove (0-" << array.size()-1 << "): ";
                    size_t index;
                    std::cin >> index;
                    if (index < array.size()) {
                        array.removeFigure(index);
                        std::cout << "Figure removed successfully." << std::endl;
                    } else {
                        std::cout << "Invalid index." << std::endl;
                    }
                    break;
                }
                case 5:
                    if (array.size() == 0) {
                        std::cout << "No figures to display." << std::endl;
                    } else {
                        array.printAll();
                    }
                    break;
                case 6:
                    std::cout << "Total area of all figures: " << array.totalArea() << std::endl;
                    break;
                case 7:
                    std::cout << "Goodbye!" << std::endl;
                    return 0;
                default:
                    std::cout << "Invalid option. Please try again." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    return 0;
}