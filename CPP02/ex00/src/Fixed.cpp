#include "../includes/Fixed.hpp"

Fixed::Fixed() { std::cout << CONSTRUCTOR << std::endl; }
Fixed::~Fixed() { std::cout << DESTRUCTOR << std::endl; }

Fixed::Fixed(Fixed const &number) {
    std::cout << COPYCONS << std::endl;
    *this = number;
}

int Fixed::getRawBits(void) const { return std::cout << GETRAWBITS << std::endl, _fixed; }
void Fixed::setRawBits(int const raw) {
    std::cout << SETRAWBITS << std::endl;
    _fixed = raw;
}

Fixed &Fixed::operator=(Fixed const &number) {
    std::cout << COPYASSIGN << std::endl;
    if (this != &number) this->_fixed = number.getRawBits();
    return *this;
}