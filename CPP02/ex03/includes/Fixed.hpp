#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>

#define COLOR_Y "\033[1;33m"
#define COLOR_B "\033[1;34m"
#define COLOR_END "\033[0;39m"

#define ASINT " as integer"
#define FLOAT_CALL "Float constructor called"
#define INT_CALL "Int constructor called"
#define DESTRUCTOR "\033[1;31mDestructor called\033[0;39m"
#define COPYCONS "\033[1;37mCopy constructor called\033[0;39m"
#define CONSTRUCTOR "\033[1;33mDefault constructor called\033[0;39m"
#define COPYASSIGN "\033[1;32mCopy assignment operator called\033[0;39m"
#define GETRAWBITS "\033[1;34mgetRawBits member function called\033[0;39m"
#define SETRAWBITS "\033[1;34msetRawBits member function called\033[0;39m"

class Fixed {
   public:
    Fixed();
    Fixed(Fixed const &number);
    Fixed &operator=(Fixed const &number);
    ~Fixed();
    Fixed(int const number);
    Fixed(float const number);
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