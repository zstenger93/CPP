#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>

class	PhoneBook
{
	private:
		int				index;
		class Contact	phone;
	public:

};


class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void		SetFirstName(std::string input);
		void		SetLastName(std::string input);
		void		SetNickName(std::string input);
		void		SetPhoneNumber(std::string input);
		void		SetDarkestSecret(std::string input);
		std::string	GetFirstName();
		std::string GetLastName();
		std::string GetNickName();
		std::string	GetPhoneNumber();
		std::string	GetDarkestSecret();
};

#endif