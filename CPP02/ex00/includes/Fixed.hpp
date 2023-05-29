#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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
	int getRawBits(void) const;
	void setRawBits(int const raw);

   private:
	int _fixed;
	static const int _fractional = 8;
};

#endif