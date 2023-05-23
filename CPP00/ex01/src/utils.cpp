#include <cctype>

#include "../includes/phonebook.hpp"

int IsAllNum(std::string number) {
	for (unsigned long i = 0; i < number.length(); i++)
		if (number[i] < '0' || number[i] > '9') {
			std::cout << WRONG_PHONE_NUMBER;
			return 1;
		}
	return 0;
}

void ShortPrint(std::string contact_details) {
	int i = 0, max_char = 10;
	int len = contact_details.length();

	max_char = max_char - len;
	if (max_char > 0)
		for (int j = 0; j < max_char; j++)
			std::cout << "\033[1;4;37m"
					  << " ";
	while (contact_details[i] && i < 9 && (i + max_char < 9)) {
		std::cout << "\033[1;4;37m" << contact_details[i];
		i++;
	}
	if (contact_details[i + 1])
		std::cout << "\033[1;4;37m" << '.';
	else
		std::cout << "\033[1;4;37m" << contact_details[i];
}

int IndexCheck(std::string index) {
	unsigned int size;

	size = index.length();
	for (size_t i = 0; i < size; i++)
		if (std::isdigit(index.at(i)) == 0) return 1;
	if (size > 1) return 1;
	return 0;
}

int IsOnlySpace(std::string str) {
	for (unsigned int i = 0; i < str.length(); i++)
		if (!std::isspace(str[i])) return 0;
	return 1;
}

int IsValid(std::string input) {
	if (input[0] == '\0') {
		std::cout << INPUT_REQUIRED << std::endl;
		return 1;
	}
	else if (IsOnlySpace(input) == 1) {
		std::cout << INVALID_INPUT << std::endl;
		return 1;
	}
	return 0;
}
