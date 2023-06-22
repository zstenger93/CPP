#include "../includes/ScalarConverter.hpp"

bool ScalarConverter::argCount(int argc) {
	if (argc < 2) return std::cout << NOARG << std::endl, false;
	if (argc > 2) return std::cout << TOOMARG << std::endl, false;
	return true;
}

bool ScalarConverter::parser(std::string &input) {
	if (input.size() == 0) return false;
	if (ScalarConverter::containsOnlySpace(input)) return false;
	if (ScalarConverter::hasInvalidSpace(input)) return false;
	if (ScalarConverter::isInf(input)) return true;
	if (ScalarConverter::isValidNumber(input)) return true;
	std::cout << input << std::endl;
	return false;
}

bool ScalarConverter::containsOnlySpace(std::string &input) {
	for (size_t i = 0; i < input.size(); i++)
		if (input[i] != ' ') return false;
	return true;
}

bool ScalarConverter::hasInvalidSpace(std::string &input) {
	std::string trimmedString = trimSpace(input, " ");
	if (trimmedString.find(" ") != std::string::npos) return true;
	//might trim float f off
	return false;
}

std::string ScalarConverter::trimSpace(std::string &input, std::string toTrim) {
	std::string::size_type start = input.find_first_not_of(toTrim);
	std::string::size_type end = input.find_last_not_of(toTrim);
	return input.substr(start, end - start + 1);
}

bool ScalarConverter::isInf(std::string &input) {
	std::string inf[4] = {"inf", "-inf", "+inf", "nan"};
	for (int type = 0; type < 4; type++)
		if (input.compare(inf[type]) == 0) return true;
	return false;
}

bool ScalarConverter::isValidNumber(std::string &input) {
	int dotCount = 0;
	for (std::string::size_type i = 0; i < input.length(); i++) {
		if (input[i] == '.') dotCount++;
		if (dotCount > 1) return false;
		if ((input[i] > '9' || input[i] < '0') && input[i] != '.') return false;
	}
	return true;
}
