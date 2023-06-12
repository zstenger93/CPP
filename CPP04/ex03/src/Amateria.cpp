#include "../includes/AMateria.hpp"

/*____________________________ CONSTRUCTORS / DESTRUCTOR ____________________________*/

AMateria::AMateria() {/* std::cout << AM_CONSTRUCTOR << std::endl;*/ }

AMateria::AMateria(AMateria const &cpy) {
	// std::cout << AM_COPYCON << std::endl;
	*this = cpy;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	/*std::cout << AM_STRINGCON << std::endl;*/
}

AMateria::~AMateria() { /*std::cout << AM_DESTRUCTOR << std::endl;*/ }

/*________________________________ OPERATOR OVERLOAD ________________________________*/

AMateria &AMateria::operator=(AMateria const &rhs) {
	// std::cout << AM_ASSIGN << std::endl;
	if (this != &rhs) _type = rhs._type;
	return *this;
}

/*____________________________________ FUNCTIONS ____________________________________*/

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) { (void)target; }