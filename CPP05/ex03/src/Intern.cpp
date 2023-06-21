#include "../includes/Intern.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Intern::Intern() { std::cout << "Intern" << CONSTRUCTOR << std::endl; }
Intern::Intern(Intern const &cpy) {
	(void)cpy;
	std::cout << "Intern" << COPYCON << std::endl;
}
Intern::~Intern() { std::cout << "Intern" << DESTRUCTOR << std::endl; }

/*______________________________________ OPERATOR OVERLOAD ______________________________________*/

Intern &Intern::operator=(Intern const &rhs) {
	(void)rhs;
	std::cout << "Intern" << ASSIGNMENT << std::endl;
	return *this;
}

/*__________________________________________ FUNCTIONS __________________________________________*/

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const {
	int caseId;
	AForm *form = NULL;
	switch (caseId) {
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		default:
			throw(AForm::AFormCreationFailedException());
	}
	return form;
}