#include "../includes/phonebook.hpp"

static void InputCheck(int argc, char **argv) {
	(void)argv;
	if (argc != 1) {
		std::cerr << NO_ARG << std::endl;
		exit(1);
	}
}

int main(int argc, char **argv) {
	InputCheck(argc, argv);
	PhoneBook contacts[8];
	int max = 0;
	std::string option;

	while (true) {
		if (std::cin.eof()) break;
		std::cout << CHOOSE_OPTION;
		getline(std::cin, option);
		if (option == "ADD")
			max = AddNewContact(contacts, max);
		else if (option == "SEARCH")
			FindContactToPrint(contacts, max);
		else if (option == "EXIT")
			break;
		else {
			std::cerr << INVALID_OPTION << option << std::endl;
			std::cout << AVAILABLE << ADD << SEARCH << EXIT << std::endl;
		}
	}
	std::cout << YOU_LEFT << std::endl;
	return 0;
}
