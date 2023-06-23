#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv) {
	try {
		if (!ScalarConverter::argCount(argc)) throw(ScalarConverter::ArgCountException());
		std::string input(argv[1]);
		if (!ScalarConverter::parser(input)) throw(ScalarConverter::WrongInputException());
		ScalarConverter::convert(input);
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
	return 0;
}