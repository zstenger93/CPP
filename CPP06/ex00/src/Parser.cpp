#include "../includes/ScalarConverter.hpp"

/*__________________________________________ INITIALIZE _________________________________________*/

int ScalarConverter::type = 0;

/*__________________________________________ FUNCTIONS __________________________________________*/

bool ScalarConverter::argCount(int argc) {
	if (argc < 2) return std::cout << NOARG << std::endl, false;
	if (argc > 2) return std::cout << TOOMARG << std::endl, false;
	return true;
}

bool ScalarConverter::parser(std::string &input) {
	if (input.size() == 0) return false;
	if (ScalarConverter::containsOnlySpace(input)) return false;
	if (ScalarConverter::hasInvalidSpace(input)) return false;
	std::string trimmedInput = trimSpace(input, " ");
	if (ScalarConverter::isInf(trimmedInput)) return true;
	if (ScalarConverter::isValidNumber(trimmedInput)) return true;
	if (ScalarConverter::isValidCharString(trimmedInput)) return true;
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
	return false;
}

std::string ScalarConverter::trimSpace(std::string &input, std::string toTrim) {
	std::string::size_type start = input.find_first_not_of(toTrim);
	std::string::size_type end = input.find_last_not_of(toTrim);
	return input.substr(start, end - start + 1);
}

bool ScalarConverter::isInf(std::string &input) {
	std::string inf[8] = {"inf", "-inf", "+inf", "nan", "inff", "-inff", "+inff", "nanf"};
	for (int infType = 0; infType < 8; infType++)
		if (input.compare(inf[infType]) == 0) return type = INF, true;
	return false;
}

bool ScalarConverter::isValidNumber(std::string &input) {
	int dotCount = 0;
	if (input[input.size() - 1] == 'f') input.erase(input.size() - 1);
	for (std::string::size_type i = 0; i < input.length(); i++) {
		if (input[i] == '.') dotCount++;
		if ((input[i] > '9' || input[i] < '0') && input[i] != '.') return false;
		if (dotCount > 1) return false;
	}
	return type = NUMBER, true;
}

bool ScalarConverter::isValidCharString(std::string &input) {
	if (input.length() > 1) return false;
	for (std::string::size_type i = 0; i < input.length(); i++)
		if (input[i] < '!' || input[i] > '~') return false;
	return type = CHAR, true;
}
