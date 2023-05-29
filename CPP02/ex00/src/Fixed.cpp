#include "../includes/Fixed.hpp"

Fixed::Fixed() : _fixed(0) { std::cout << CONSTRUCTOR << std::endl; }

/*
to make a copy of an object, creating a new object with the same values as the original.
*/
Fixed::Fixed(Fixed const &number) {
	std::cout << COPYCONS << std::endl;
	*this = number;
}

Fixed &Fixed::operator=(Fixed const &number) {
	std::cout << COPYASSIGN << std::endl;
	if (this != &number) this->_fixed = number.getRawBits();
	return *this;
}

Fixed::~Fixed() { std::cout << DESTRUCTOR << std::endl; }

void Fixed::setRawBits(int const raw) {
	std::cout << SETRAWBITS << std::endl;
	_fixed = raw;
}

int Fixed::getRawBits(void) const { return std::cout << GETRAWBITS << std::endl, _fixed; }
