#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <exception>
#include <iostream>
#include <string>

#include "../includes/ScalarConverterDefines.hpp"

class ScalarConverter {
   public:
	static bool argCount(int argc);
	static bool parser(std::string &input);
	static void convert(std::string &input);

	class ScalarConverterWrongInputException : public std::exception {
	   public:
		virtual const char *what() const throw();
	};

	class ScalarWrongArgCountException : public std::exception {
	   public:
		virtual const char *what() const throw();
	};

   private:
	static bool containsOnlySpace(std::string &input);
	static bool hasInvalidSpace(std::string &input);
	static std::string trimSpace(std::string &input, std::string toTrim);
	static bool isInf(std::string &input);
	static bool isValidNumber(std::string &input);
};

#endif