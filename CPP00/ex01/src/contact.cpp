#include "../includes/phonebook.hpp"

void Contact::SetFirstName(std::string input) { first_name = input; }
void Contact::SetLastName(std::string input) { last_name = input; }
void Contact::SetNickName(std::string input) { nickname = input; }
void Contact::SetPhoneNumber(std::string input) { phone_number = input; }
void Contact::SetDarkestSecret(std::string input) { darkest_secret = input; }

std::string Contact::GetFirstName() { return first_name; }
std::string Contact::GetLastName() { return last_name; }
std::string Contact::GetNickName() { return nickname; }
std::string Contact::GetPhoneNumber() { return phone_number; }
std::string Contact::GetDarkestSecret() { return darkest_secret; }
