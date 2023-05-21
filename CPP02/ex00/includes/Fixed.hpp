#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#define DESTRUCTOR "Destructor called"
#define COPYCONS "Copy constructor called"
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
    Fixed(Fixed const &number);
    Fixed &operator=(Fixed const &number);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif