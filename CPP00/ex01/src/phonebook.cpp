#include "../includes/phonebook.hpp"

int PhoneBook::GetContactIndex() { return index; }
void PhoneBook::SetContactIndex(int i) { index = i; }
class Contact PhoneBook::GetContactData() { return contact_list; }

int PhoneBook::GetContactDetails() {
    std::string input;

    std::cout << ENTER_FN;
    getline(std::cin, input);
    if (input[0] == '\0')
        return 1;
    contact_list.SetFirstName(input);

    std::cout << ENTER_LN;
    getline(std::cin, input);
    if (input[0] == '\0')
        return 1;
    contact_list.SetLastName(input);

    std::cout << ENTER_NN;
    getline(std::cin, input);
    if (input[0] == '\0')
        return 1;
    contact_list.SetNickName(input);

    std::cout << ENTER_PN;
    getline(std::cin, input);
    if (input[0] == '\0')
        return 1;
    if (IsAllNum(input) == 1)
        return 1;
    contact_list.SetPhoneNumber(input);

    std::cout << ENTER_DS;
    getline(std::cin, input);
    if (input[0] == '\0')
        return 1;
    contact_list.SetDarkestSecret(input);

    return 0;
}
