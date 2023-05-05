#include <iostream>

int	main(void) {
	std::string		str = "HI THIS IS BRAIN";
	std::string		*stringPTR = &str;
	std::string		stringREF = str;
	std::cout << std::endl;

	std::cout << "Address of str: \t\t" << &str << std::endl;
	std::cout << "Address held by stringPTR: \t" << stringPTR << std::endl;
	std::cout << "Address held by stringREF: \t" << stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "Value of str: \t\t\t" << str << std::endl;
	std::cout << "Value pointed by stringPTR: \t" << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF: \t" << stringREF << std::endl;

	return 0;
}