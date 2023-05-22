#include "../includes/phonebook.hpp"

int main() {
    PhoneBook contacts[8];
    int max = 0;
    std::string option;
    std::string input;

    while (true) {
        std::cout << CHOOSE_OPTION;
        getline(std::cin, option);
        if (option == "ADD")
            max = AddNewContact(contacts, max);
        else if (option == "SEARCH")
            FindContactToPrint(contacts, max);
        else if (option == "EXIT")
            break;
        else
		{
            std::cerr << INVALID_OPTION << option << std::endl;
            std::cout << AVAILABLE << std::endl;
            std::cout << ADD << std::endl;
            std::cout << SEARCH << std::endl;
            std::cout << EXIT << std::endl;
		}
    }
    return 0;
}
