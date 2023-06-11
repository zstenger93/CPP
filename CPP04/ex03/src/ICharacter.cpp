#include "../includes/ICharacter.hpp"

/*____________________________ CONSTRUCTORS / DESTRUCTOR ____________________________*/

ICharacter::ICharacter() { std::cout << IC_CONSTRUCTOR << std::endl; }

ICharacter::ICharacter(const ICharacter &cpy) {
	std::cout << IC_COPYCON << std::endl;
	*this = cpy;
}

ICharacter::~ICharacter() { std::cout << IC_DESTRUCTOR << std::endl; }

/*________________________________ OPERATOR OVERLOAD ________________________________*/

ICharacter &ICharacter::operator=(ICharacter const &rhs) {
	(void)rhs;
	return *this;
}