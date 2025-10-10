#ifndef OCTAL_HPP
#define OCTAL_HPP

#include <iostream>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

class Octal {
private:
    unsigned char *data;
    size_t size;
    
    void remove_leading_zeros();
    bool valid_octal_digit(unsigned char digit) const;

public:
    Octal();
    Octal(const size_t &n, unsigned char value = 0);
    Octal(const std::initializer_list<unsigned char> & values);
    Octal(const std::string &value);
    Octal(const Octal &other);
    Octal(Octal &&other) noexcept;
    virtual ~Octal() noexcept;

    Octal add(const Octal &other) const;
    Octal subtract(const Octal &other) const;
    Octal copy() const;

    bool equals(const Octal &other) const;
    bool less_than(const Octal &other) const;
    bool greater_than(const Octal &other) const;

    std::string to_string() const;
    size_t get_size() const;
    unsigned char get_digit(size_t index) const;
};

#endif