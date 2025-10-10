#include "../includes/octal.hpp"

Octal::Octal() : data(nullptr), size(0) {}

Octal::Octal(const size_t &n, unsigned char value) : size(n) {
    if (!valid_octal_digit(value)) {
        throw std::invalid_argument("Invalid octal digit");
    }
    
    if (n > 0) {
        data = new unsigned char[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = value;
        }
    } else {
        data = nullptr;
    }
}

Octal::Octal(const std::initializer_list<unsigned char> &values) : size(values.size()) {
    if (size > 0) {
        data = new unsigned char[size];
        size_t i = 0;
        for (auto it = values.begin(); it != values.end(); ++it, ++i) {
            if (!valid_octal_digit(*it)) {
                delete[] data;
                throw std::invalid_argument("Invalid octal digit in initializer list");
            }
            data[i] = *it;
        }
        remove_leading_zeros();
    } else {
        data = nullptr;
    }
}

Octal::Octal(const std::string &value) {
    if (value.empty()) {
        size = 0;
        data = nullptr;
        return;
    }
    
    size = value.length();
    data = new unsigned char[size];
    
    for (size_t i = 0; i < size; ++i) {
        char c = value[size - 1 - i];
        if (c < '0' || c > '7') {
            delete[] data;
            throw std::invalid_argument("Invalid octal digit in string");
        }
        data[i] = c - '0';
    }
    remove_leading_zeros();
}

Octal::Octal(const Octal &other) : size(other.size) {
    if (size > 0) {
        data = new unsigned char[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    } else {
        data = nullptr;
    }
}

Octal::Octal(Octal &&other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

Octal::~Octal() noexcept {
    delete[] data;
}

void Octal::remove_leading_zeros() {
    if (size == 0 || data == nullptr) return;
    
    size_t new_size = size;
    while (new_size > 1 && data[new_size - 1] == 0) {
        --new_size;
    }
    
    if (new_size != size) {
        if (new_size > 0) {
            unsigned char *new_data = new unsigned char[new_size];
            for (size_t i = 0; i < new_size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            size = new_size;
        } else {
            delete[] data;
            data = nullptr;
            size = 0;
        }
    }
}

bool Octal::valid_octal_digit(unsigned char digit) const {
    return digit >= 0 && digit <= 7;
}

Octal Octal::add(const Octal &other) const {
    size_t max_size = std::max(size, other.size);
    unsigned char *result_data = new unsigned char[max_size + 1]();
    
    unsigned char carry = 0;
    for (size_t i = 0; i < max_size; ++i) {
        unsigned char sum = carry;
        if (i < size) sum += data[i];
        if (i < other.size) sum += other.data[i];
        
        result_data[i] = sum % 8;
        carry = sum / 8;
    }
    
    if (carry > 0) {
        result_data[max_size] = carry;
    }
    
    Octal result;
    delete[] result.data;
    result.data = result_data;
    result.size = carry > 0 ? max_size + 1 : max_size;
    result.remove_leading_zeros();
    return result;
}

Octal Octal::subtract(const Octal &other) const {
    if (less_than(other)) {
        throw std::invalid_argument("Cannot subtract larger number from smaller");
    }
    
    if (equals(other)) {
        return Octal();
    }
    
    size_t max_size = size;
    unsigned char *result_data = new unsigned char[max_size]();
    
    unsigned char borrow = 0;
    for (size_t i = 0; i < max_size; ++i) {
        int diff = data[i] - borrow;
        if (i < other.size) {
            diff -= other.data[i];
        }
        
        if (diff < 0) {
            diff += 8;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result_data[i] = diff;
    }
    
    Octal result;
    delete[] result.data;
    result.data = result_data;
    result.size = max_size;
    result.remove_leading_zeros();
    return result;
}

Octal Octal::copy() const {
    return Octal(*this);
}

bool Octal::equals(const Octal &other) const {
    if (size != other.size) return false;
    
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

bool Octal::less_than(const Octal &other) const {
    if (size != other.size) return size < other.size;
    
    for (int i = size - 1; i >= 0; --i) {
        if (data[i] != other.data[i]) {
            return data[i] < other.data[i];
        }
    }
    return false;
}

bool Octal::greater_than(const Octal &other) const {
    if (size != other.size) return size > other.size;
    
    for (int i = size - 1; i >= 0; --i) {
        if (data[i] != other.data[i]) {
            return data[i] > other.data[i];
        }
    }
    return false;
}

std::string Octal::to_string() const {
    if (size == 0 || data == nullptr) return "0";
    
    std::string result;
    for (int i = size - 1; i >= 0; --i) {
        result += std::to_string(data[i]);
    }
    return result;
}

size_t Octal::get_size() const {
    return size;
}

unsigned char Octal::get_digit(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}