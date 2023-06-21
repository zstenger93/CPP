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
	AForm *form = nullptr;
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidental pardon"};

	for (caseId = -1; caseId < 3; caseId++)
		if (formName == forms[caseId]) break;
	switch (caseId) {
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << RED << DUMB << END << formName;
			throw(AForm::AFormCreationFailedException());
	}
	return form;
}