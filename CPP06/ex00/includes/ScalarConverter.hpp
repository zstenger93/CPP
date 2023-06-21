#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>

class ScalarConverter {
   public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &cpy);
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const &rhs);
};

#endif