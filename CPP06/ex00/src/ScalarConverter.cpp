#include "../includes/ScalarConverter.hpp"

/*_______________________________________ NESTED CLASSES ________________________________________*/

const char *ScalarConverter::ScalarConverterWrongInputException::what() const throw() {
	return WRONGINPUT;
}

const char *ScalarConverter::ScalarWrongArgCountException::what() const throw() { return ARGCOUNT; }

/*__________________________________________ FUNCTIONS __________________________________________*/

void ScalarConverter::convert(std::string &input) { (void)input; }