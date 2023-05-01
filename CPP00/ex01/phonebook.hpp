#include <iostream>

class	PhoneBook
{
	public:
		char	**contacts;
};


class	Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
	private:
		int			phone_number;
		std::string	darkest_secret;
};