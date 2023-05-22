#include "../includes/Point.hpp"

Fixed::Fixed() : _fixed(0) {
    // std::cout << COLOR_Y << CONSTRUCTOR << COLOR_END << std::endl;
}

Fixed::~Fixed() {
    // std::cout << COLOR_Y << DESTRUCTOR << COLOR_END << std::endl;
}

int Fixed::toInt(void) const { return _fixed >> _fractional; }
float Fixed::toFloat(void) const { return float(_fixed) / (1 << _fractional); }

int Fixed::getRawBits(void) const {
    // std::cout << COLOR_Y << GETRAWBITS << COLOR_END << std::endl;
    return _fixed;
}

void Fixed::setRawBits(int const raw) {
    // std::cout << COLOR_Y << SETRAWBITS << COLOR_END << std::endl;
    _fixed = raw;
}

Fixed::Fixed(Fixed const &number) {
    // std::cout << COLOR_Y << COPYCONS << COLOR_END << std::endl;
    *this = number;
}

Fixed &Fixed::operator=(Fixed const &number) {
    // std::cout << COLOR_Y << COPYASSIGN << COLOR_END << std::endl;
    if (this != &number) this->_fixed = number.getRawBits();
    return *this;
}

Fixed::Fixed(int const number) {
    // std::cout << COLOR_Y << INT_CALL << COLOR_END << std::endl;
    _fixed = number << _fractional;
}

Fixed::Fixed(float const number) {
    // std::cout << COLOR_Y << FLOAT_CALL << COLOR_END << std::endl;
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