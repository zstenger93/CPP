#include "../includes/Ice.hpp"

/*____________________________ CONSTRUCTORS / DESTRUCTOR ____________________________*/

Ice::Ice() : AMateria("ice") { /*std::cout << ICE_CONSTRUCTOR << std::endl;*/
}

Ice::Ice(Ice const &cpy) {
	// std::cout << ICE_COPYCON << std::endl;
	*this = cpy;
}

Ice::~Ice() { /* std::cout << ICE_DESTRUCTOR << std::endl;*/
}

/*________________________________ OPERATOR OVERLOAD ________________________________*/

Ice &Ice::operator=(Ice const &rhs) {
	// std::cout << ICE_ASSIGN << std::endl;
	if (this != &rhs) this->_type = getType();
	return *this;
}

/*____________________________________ FUNCTIONS ____________________________________*/

std::string const &Ice::getType() const { return _type; }

AMateria *Ice::clone() const {
	AMateria *clone = new Ice();
	return clone;
}

void Ice::use(ICharacter &target) {
	std::cout << SHOOT << BLUE << target.getName() << END << " *" << std::endl;
}