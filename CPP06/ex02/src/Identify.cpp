#include "../includes/Identify.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Identify::Identify() {}
Identify::Identify(Identify const &cpy) { *this = cpy; }
Identify::~Identify() {}

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

Identify &Identify::operator=(Identify const &rhs) {
	if (this != &rhs) *this = rhs;
	return *this;
}
