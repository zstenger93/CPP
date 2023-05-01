#include "../includes/phonebook.hpp"

int	IsAllNum(std::string number)
{
	for(unsigned long i = 0; i < number.length(); i++)
		if (number[i] < '0' ||  number[i] > '9')
		{
			std::cout << WRONG_PHONE_NUMBER;
			return 1;
		}
	return 0;
}

void ShortPrint(std::string contact_details)
{
	int i = 0;

	while (contact_details[i] && i < 9)
	{
		std::cout << contact_details[i];
		i++;
	}
	if (i != 9 && contact_details.length() < 10)
	{
		for(int k = i; k < 9; k++)
		{
			i++;
			std::cout << " ";
		}
	}
	if (contact_details[i + 1])
		std::cout << '.';
	else
		std::cout << contact_details[i];
}

int	IndexCheck(std::string index)
{
	unsigned int	size;

	size = index.length();
	for(size_t i = 0; i < size; i++)
		if (std::isdigit(index.at(i)) == 0)
			return 1;
	if (size > 1)
		return 1;
	return 0;
}