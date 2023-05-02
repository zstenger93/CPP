#ifndef PHONEBOOK_H
# define PHONEBOOK_H

// ERRORS AND INPUT REQUESTS
# define PIPE "\033[1;33m|\033[0m"
# define INVALID_OPTION "\033[1;31mInvalid option\033[0m"
# define CHOOSE_INDEX "\033[1;34mChoose One Index:	\033[0m"
# define CHOOSE_OPTION "\033[1;4;33mChoose an Option:\033[0m	"
# define NO_CONTACT "\033[1;31mNo Contact Found!\033[0m\n"
# define INVALID_INDEX "\033[1;31mInvalid Index!\033[0m\n"
# define OUT_OF_RANGE "\033[1;31mThe Requested Index Is Out Of Range\033[0m"
# define WRONG_PHONE_NUMBER "\033[1;31mError! Phone Number Should Contain Only Numbers!\033[0m\n"

// GET CONTACT COLORS
# define ENTER_FN "\033[1;34mEnter Your First Name:	\033[0m"
# define ENTER_LN "\033[1;34mEnter Your Last Name:	\033[0m"
# define ENTER_NN "\033[1;34mEnter Your Nick Name:	\033[0m"
# define ENTER_PN "\033[1;34mEnter Your Phone Number:	\033[0m"
# define ENTER_DS "\033[1;34mEnter Your Darkest Secret:	\033[0m"

// PRINTED CONTACT COLORS
# define FN "\033[1;96mFirst Name	:	\033[0m\033[1;30m"
# define LN "\033[1;96mLast Name	:	\033[0m\033[1;30m"
# define NN "\033[1;96mNick Name	:	\033[0m\033[1;30m"
# define PN "\033[1;96mPhone Number	:	\033[0m\033[1;30m"
# define DS "\033[1;96mDarkest Secret	:	\033[0m\033[1;30m"

#include <iostream>
#include <sstream>
#include <cstdlib>

class	Contact
{
	private:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_number;
		std::string		darkest_secret;

	public:
		void			SetFirstName(std::string input);
		void			SetLastName(std::string input);
		void			SetNickName(std::string input);
		void			SetPhoneNumber(std::string input);
		void			SetDarkestSecret(std::string input);
		std::string		GetFirstName();
		std::string 	GetLastName();
		std::string 	GetNickName();
		std::string		GetPhoneNumber();
		std::string		GetDarkestSecret();
};

class	PhoneBook
{
	private:
		int				index;
		class Contact	contact_list;

	public:
		void			SetContactIndex(int i);
		int				GetContactIndex();
		int				GetContactDetails();
		class Contact	GetContactData();
};

// EXEC OPTIONS
int		AddNewContact(PhoneBook *contacts, int max);
void	PrintBook(PhoneBook *contacts, int i);
void	FindContactToPrint(PhoneBook *contacts, int max);
void	PrintContactDetails(PhoneBook *contacts, int max);

// UTILS
int		IndexCheck(std::string index);
int		IsAllNum(std::string phone_number);
void	ShortPrint(std::string contact_details);

#endif