#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include "../includes/ScalarConverterDefines.hpp"

class ScalarConverter {
	public:
	  ScalarConverter();
	  ScalarConverter(ScalarConverter const &cpy);
	  ~ScalarConverter();
	  ScalarConverter &operator=(ScalarConverter const &rhs);

};

#endif