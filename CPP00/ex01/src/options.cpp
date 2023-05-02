#include "../includes/phonebook.hpp"

int	AddNewContact(PhoneBook *contacts, int max)
{
	static int i;
	int	error = 0;

	contacts[i].SetContactIndex(i + 1);
	if (contacts[i].GetContactDetails() == 1)
		error = 1;
	if (i >= 7)
	{
		i = 0;
		max = 7;
	}
	else if (max != 7 && error == 0)
	{
		i++;
		max++;
	}
	else if (error == 0)
		i++;
	return max;
}

void	FindContactToPrint(PhoneBook *contacts, int max)
{
	if (max == 0)
		std::cout << NO_CONTACT;
	else
	{
		for(int k = 0; k < max; k++)
			PrintBook(contacts, k);
		PrintContactDetails(contacts, max);
	}
}

void	PrintBook(PhoneBook *contacts, int i)
{
	std::cout << contacts[i].GetContactIndex() << PIPE;
	ShortPrint(contacts[i].GetContactData().GetFirstName());
	std::cout << PIPE;
	ShortPrint(contacts[i].GetContactData().GetLastName());
	std::cout << PIPE;
	ShortPrint(contacts[i].GetContactData().GetNickName());
	std::cout << PIPE << std::endl;
}

void	PrintContactDetails(PhoneBook *contacts, int max)
{
	std::string	str;
	std::string input;
	int index;

	std::cout << CHOOSE_INDEX;
	std::getline(std::cin, input);
	std::stringstream ss(input);
	ss >> str;
	index = std::atoi(str.c_str());
	if (IndexCheck(str) == 0 && (index < 9 && index > 0) && index <= max)
	{
		std::cout << FN << contacts[index - 1].GetContactData().GetFirstName() << std::endl;
		std::cout << LN << contacts[index - 1].GetContactData().GetLastName() << std::endl;
		std::cout << NN << contacts[index - 1].GetContactData().GetNickName() << std::endl;
		std::cout << PN << contacts[index - 1].GetContactData().GetPhoneNumber() << std::endl;
		std::cout << DS << contacts[index - 1].GetContactData().GetDarkestSecret() << std::endl;
	}
	else
		std::cout << OUT_OF_RANGE << std::endl;
}
