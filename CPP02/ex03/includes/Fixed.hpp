#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>

#define COLOR_Y "\033[1;33m"
#define COLOR_END "\033[0;39m"

#define ASINT " as integer"
#define DESTRUCTOR "Destructor called"
#define INT_CALL "Int constructor called"
#define COPYCONS "Copy constructor called"
#define FLOAT_CALL "Float constructor called"
#define CONSTRUCTOR "Default constructor called"
#define COPYASSIGN "Copy assignment operator called"
#define GETRAWBITS "getRawBits member function called"
#define SETRAWBITS "setRawBits member function called"

class Fixed {
   public:
    Fixed();
    ~Fixed();
    Fixed(int const number);
    Fixed(float const number);
    Fixed(Fixed const &number);
    Fixed &operator=(Fixed const &number);
    int toInt(void) const;
    float toFloat(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed operator+(Fixed const &number) const;
    Fixed operator-(Fixed const &number) const;
    Fixed operator*(Fixed const &number) const;
    Fixed operator/(Fixed const &number) const;
    Fixed operator++(int);
    Fixed operator--(int);
    Fixed &operator++(void);
    Fixed &operator--(void);
    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed const &max(Fixed const &a, const Fixed &b);
    static Fixed const &min(Fixed const &a, const Fixed &b);

   private:
    int _fixed;
    static const int _fractional = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed_num);

#endif