#include "includes/octal.hpp"

int main() {
    try {
        std::cout << "Octal Class" << std::endl;

        Octal default_num;
        Octal size_num(5, 3);
        Octal list_num({1, 2, 3, 4});
        Octal string_num("12345");
        Octal copy_num(string_num);
        Octal move_num(std::move(Octal("777")));
        
        std::cout << "\nConstructors:" << std::endl;
        std::cout << "Default: " << default_num.to_string() << std::endl;
        std::cout << "Size+value: " << size_num.to_string() << std::endl;
        std::cout << "Initializer list: " << list_num.to_string() << std::endl;
        std::cout << "From string: " << string_num.to_string() << std::endl;
        std::cout << "Copy: " << copy_num.to_string() << std::endl;
        std::cout << "Move: " << move_num.to_string() << std::endl;
    
        std::cout << "\nArithmetic operations:" << std::endl;
        Octal a("12");
        Octal b("7");
        Octal sum = a.add(b);
        Octal diff = a.subtract(b);
        Octal copy = a.copy();
        
        std::cout << a.to_string() << " + " << b.to_string() << " = " << sum.to_string() << std::endl;
        std::cout << a.to_string() << " - " << b.to_string() << " = " << diff.to_string() << std::endl;
        std::cout << "Copy of " << a.to_string() << " = " << copy.to_string() << std::endl;
        
        std::cout << "\nComparison operations:" << std::endl;
        std::cout << a.to_string() << " == " << b.to_string() << " : " 
                  << (a.equals(b) ? "true" : "false") << std::endl;
        std::cout << a.to_string() << " < " << b.to_string() << " : " 
                  << (a.less_than(b) ? "true" : "false") << std::endl;
        std::cout << a.to_string() << " > " << b.to_string() << " : " 
                  << (a.greater_than(b) ? "true" : "false") << std::endl;
  
        std::cout << "\nImmutability check:" << std::endl;
        std::cout << "Original a: " << a.to_string() << std::endl;
        std::cout << "Original b: " << b.to_string() << std::endl;
        std::cout << "After operations - a: " << a.to_string() << ", b: " << b.to_string() << std::endl;
    
        std::cout << "\nDynamic memory:" << std::endl;
        std::cout << "Size of " << string_num.to_string() << ": " << string_num.get_size() << " digits" << std::endl;
        std::cout << "Digit at index 0: " << (int)string_num.get_digit(0) << " (LSB)" << std::endl;
  
        std::cout << "\nException handling:" << std::endl;
        try {
            Octal invalid(3, 8);
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
        std::cout << "\nAll demonstrations completed successfully!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}