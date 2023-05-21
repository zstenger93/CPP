#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <ostream>

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
   private:
    int _fixed;
    static const int _fractional = 8;

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
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed_num);

#endif