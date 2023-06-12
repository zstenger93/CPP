#include "../includes/BrainDamage.hpp"

/*____________________________ CONSTRUCTORS / DESTRUCTOR ____________________________*/

BrainDamage::BrainDamage()
	: AMateria("braindamage") { /*std::cout << BRAINDAMAGE_CONSTRUCTOR << std::endl;*/
}

BrainDamage::BrainDamage(BrainDamage const &cpy) : AMateria(cpy) {
	// std::cout << BRAINDAMAGE_COPYCON << std::endl;
	*this = cpy;
}

BrainDamage::~BrainDamage() { /*std::cout << BRAINDAMAGE_DESTRUCTOR << std::endl;*/
}

/*________________________________ OPERATOR OVERLOAD ________________________________*/

BrainDamage &BrainDamage::operator=(BrainDamage const &rhs) {
	// std::cout << BRAINDAMAGE_ASSIGN << std::endl;
	if (this != &rhs) this->_type = getType();
	return *this;
}

/*____________________________________ FUNCTIONS ____________________________________*/

std::string const &BrainDamage::getType() const { return _type; }

AMateria *BrainDamage::clone() const {
	AMateria *clone = new BrainDamage();
	return clone;
}

void BrainDamage::use(ICharacter &target) {
	std::cout << " causing " << BLUE << target.getName() << END << " braindamage.. *" << std::endl;
}