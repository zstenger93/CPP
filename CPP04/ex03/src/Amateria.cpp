#include "../includes/Amateria.hpp"

/*____________________________ CONSTRUCTORS / DESTRUCTOR ____________________________*/

Amateria::Amateria() { std::cout << AM_CONSTRUCTOR << std::endl; }

Amateria::Amateria(Amateria const &cpy) {
	std::cout << AM_COPYCON << std::endl;
	*this = cpy;
}

Amateria::Amateria(std::string const &type) : _type(type) { std::cout << AM_STRINGCON << std::endl; }

Amateria::~Amateria() { std::cout << AM_DESTRUCTOR << std::endl; }

/*________________________________ OPERATOR OVERLOAD ________________________________*/

Amateria &Amateria::operator=(Amateria const &rhs) {
	std::cout << AM_ASSIGN << std::endl;
	if (this != &rhs) _type = rhs._type;
	return *this;
}

/*____________________________________ FUNCTIONS ____________________________________*/

std::string const &Amateria::getType() const { return _type; }

void Amateria::use(ICharacter &target) { (void)target; }