#include "../includes/Cure.hpp"

/*____________________________ CONSTRUCTORS / DESTRUCTOR ____________________________*/

Cure::Cure() : AMateria("cure") { /*std::cout << CURE_CONSTRUCTOR << std::endl;*/
}

Cure::Cure(Cure const &cpy) : AMateria(cpy) {
	// std::cout << CURE_COPYCON << std::endl;
	*this = cpy;
}

Cure::~Cure() { /*std::cout << CURE_DESTRUCTOR << std::endl;*/
}

/*________________________________ OPERATOR OVERLOAD ________________________________*/

Cure &Cure::operator=(Cure const &rhs) {
	// std::cout << CURE_ASSIGN << std::endl;
	if (this != &rhs) this->_type = getType();
	return *this;
}

/*____________________________________ FUNCTIONS ____________________________________*/

std::string const &Cure::getType() const { return _type; }

AMateria *Cure::clone() const {
	AMateria *clone = new Cure();
	return clone;
}

void Cure::use(ICharacter &target) {
	std::cout << " heals " << BLUE << target.getName() << END << "'s wounds *" << std::endl;
}