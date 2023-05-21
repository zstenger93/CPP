#include "../includes/Fixed.hpp"

int main(void) {
    Fixed a, b(a), c;

    c = b;
    return std::cout << a.getRawBits() << b.getRawBits() << c.getRawBits() << std::endl, 0;
}