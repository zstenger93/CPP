#include "../includes/Fixed.hpp"

Fixed::Fixed() : _fixed(0) { std::cout << CONSTRUCTOR << std::endl; }

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

int Fixed::toInt(void) const { return _fixed >> _fractional; }

float Fixed::toFloat(void) const { return float(_fixed) / (1 << _fractional); }

void Fixed::setRawBits(int const raw) {
	std::cout << SETRAWBITS << std::endl;
	_fixed = raw;
}

int Fixed::getRawBits(void) const { return std::cout << GETRAWBITS << std::endl, _fixed; }

Fixed::Fixed(int const number) {
	std::cout << INT_CALL << std::endl;
	_fixed = number << _fractional;
}

Fixed::Fixed(float const number) {
	std::cout << FLOAT_CALL << std::endl;
	_fixed = roundf(number * (1 << _fractional));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed_num) {
	return os << fixed_num.toFloat();
}

Fixed Fixed::operator+(Fixed const &number) const {
	Fixed res;
	res.setRawBits(this->getRawBits() + number.getRawBits());
	return res;
}

Fixed Fixed::operator-(Fixed const &number) const {
	Fixed res;
	res.setRawBits(this->getRawBits() - number.getRawBits());
	return res;
}

Fixed Fixed::operator*(Fixed const &number) const {
	Fixed res;
	res.setRawBits((this->getRawBits() * number.getRawBits()) >> _fractional);
	return res;
}

Fixed Fixed::operator/(Fixed const &number) const {
	Fixed res;
	res.setRawBits((this->getRawBits() << _fractional) / number.getRawBits());
	return res;
}

Fixed Fixed::operator++(int) {
	Fixed before(*this);
	_fixed++;
	return before;
}

Fixed Fixed::operator--(int) {
	Fixed before(*this);
	_fixed--;
	return before;
}

Fixed &Fixed::operator++(void) { return _fixed++, *this; }
Fixed &Fixed::operator--(void) { return _fixed--, *this; }

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() >= b.getRawBits()) return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() <= b.getRawBits()) return a;
	return b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() >= b.getRawBits()) return a;
	return b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() <= b.getRawBits()) return a;
	return b;
}
