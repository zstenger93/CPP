#include "../includes/Point.hpp"

Fixed::Fixed() : _fixed(0) {}

Fixed::Fixed(Fixed const &number) { *this = number; }

Fixed &Fixed::operator=(Fixed const &number) {
	if (this != &number) this->_fixed = number.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

int Fixed::toInt(void) const { return _fixed >> _fractional; }

float Fixed::toFloat(void) const { return float(_fixed) / (1 << _fractional); }

int Fixed::getRawBits(void) const { return _fixed; }

void Fixed::setRawBits(int const raw) { _fixed = raw; }

Fixed::Fixed(int const number) { _fixed = number << _fractional; }

Fixed::Fixed(float const number) { _fixed = roundf(number * (1 << _fractional)); }

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