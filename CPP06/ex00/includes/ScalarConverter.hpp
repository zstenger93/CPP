#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "../includes/ScalarConverterDefines.hpp"

class ScalarConverter {
   public:
	static bool argCount(int argc);
	static bool parser(std::string &input);
	static void convert(std::string &input);

	class WrongInputException : public std::exception {
	   public:
		const char *what() const throw();
	};

	class ArgCountException : public std::exception {
	   public:
		const char *what() const throw();
	};

   private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &cpy);
	~ScalarConverter();
	ScalarConverter &operator=(ScalarConverter const &rhs);
	static int type;
	enum types { CHAR, NUMBER, INF };
	static bool containsOnlySpace(std::string &input);
	static bool hasInvalidSpace(std::string &input);
	static std::string trimSpace(std::string &input, std::string toTrim);
	static bool isInf(std::string &input);
	static bool isValidNumber(std::string &input);
	static bool isValidCharString(std::string &input);
	static void convertChar(std::string &input);
	static void convertNumber(std::string &input);
	static void convertInt(double &number);
	static void convertFloat(double &number);
	static void convertDouble(double &number);
	static void convertInfinity(std::string &input);
};

#endif