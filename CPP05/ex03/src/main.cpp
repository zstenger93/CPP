#include <exception>

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

static void AvailableTestCases() {
	std::cout << BAD_INPUT << std::endl << std::endl;
	std::cout << TEST0 << std::endl;
	std::cout << TEST1 << std::endl;
	std::cout << TEST2 << std::endl;
	std::cout << std::endl;
}

static int GetId(int argc, char **argv, int TestCaseId) {
	if (argc > 1) {
		int input = std::atoi(argv[1]);
		if (input < 1 || input > 3) return AvailableTestCases(), exit(1), 1;
		for (int i = 1; i >= 0; i++) {
			if (i == input) {
				TestCaseId = i;
				return TestCaseId;
				;
			}
		}
	}
	return TestCaseId;
}

static void TestMakeForm() {
	Bureaucrat loki("Loki", 1);
	Intern brainDamage;
	AForm *shrubberyCreation = nullptr;
	AForm *robotomyRequest = nullptr;
	AForm *presidentalPardon = nullptr;

	try {
		shrubberyCreation = brainDamage.makeForm("shrubbery creation", "home");
		robotomyRequest = brainDamage.makeForm("robotomy request", "idiotTasks");
		presidentalPardon = brainDamage.makeForm("presidental pardon", "TVA");
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
	std::cout << std::endl << std::endl;
	loki.signForm(*shrubberyCreation);
	loki.executeForm(*shrubberyCreation);
	std::cout << std::endl;
	loki.signForm(*robotomyRequest);
	loki.executeForm(*robotomyRequest);
	std::cout << std::endl;
	loki.signForm(*presidentalPardon);
	loki.executeForm(*presidentalPardon);
	std::cout << std::endl << std::endl;
	delete presidentalPardon;
	delete robotomyRequest;
	delete shrubberyCreation;
}

static void TestMakeMoreForm() {
	Bureaucrat loki("Loki", 1);
	Intern brainDamage;
	AForm *shrubberyCreation = NULL;
	AForm *robotomyRequest = NULL;
	AForm *presidentalPardon = NULL;
	AForm *iDontExist = NULL;

	try {
		shrubberyCreation = brainDamage.makeForm("shrubbery creation", "home");
		robotomyRequest = brainDamage.makeForm("robotomy request", "idiotTasks");
		presidentalPardon = brainDamage.makeForm("presidental pardon", "TVA");
		std::cout << std::endl << std::endl;
		iDontExist = brainDamage.makeForm("dontexist", "nope");
		std::cout << std::endl << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
	std::cout << std::endl << std::endl;
	loki.signForm(*shrubberyCreation);
	loki.executeForm(*shrubberyCreation);
	std::cout << std::endl;
	loki.signForm(*robotomyRequest);
	loki.executeForm(*robotomyRequest);
	std::cout << std::endl;
	loki.signForm(*presidentalPardon);
	loki.executeForm(*presidentalPardon);
	std::cout << std::endl;
	try {
		if (iDontExist == NULL) throw(AForm::AFormIsNullException());
		loki.signForm(*iDontExist);
		loki.executeForm(*iDontExist);
	} catch (const std::exception &error) {
		std::cout << "iDontExist" << RED << error.what() << END << std::endl << std::endl;
	}
	delete iDontExist;
	delete presidentalPardon;
	delete robotomyRequest;
	delete shrubberyCreation;
}

int main(int argc, char **argv) {
	int TestCaseId = GetId(argc, argv, 0);

	switch (TestCaseId) {
		case 1:
			TestMakeForm();
			break;
		case 2:
			TestMakeMoreForm();
			break;
		default:
			AvailableTestCases();
			break;
	}
}