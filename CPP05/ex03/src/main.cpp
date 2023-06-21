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
	AForm *shrubberyCreation = NULL;
	AForm *robotomyRequest = NULL;
	AForm *presidentalPardon = NULL;
	AForm *iDontExist = NULL;

	try {
		shrubberyCreation = brainDamage.makeForm("shrubbery creation", "home");
		robotomyRequest = brainDamage.makeForm("robotomy request", "idiotTasks");
		presidentalPardon = brainDamage.makeForm("presidental pardon", "TVA");
		iDontExist = brainDamage.makeForm("dontexist", "nope");
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
	std::cout << std::endl << std::endl;
	loki.signForm(*shrubberyCreation);
	loki.signForm(*robotomyRequest);
	loki.signForm(*presidentalPardon);
	loki.executeForm(*shrubberyCreation);
	loki.executeForm(*robotomyRequest);
	loki.executeForm(*presidentalPardon);
	loki.signForm(*iDontExist);
	std::cout << std::endl << std::endl;
	delete shrubberyCreation;
	delete robotomyRequest;
	delete presidentalPardon;
	delete iDontExist;
}

static void TestMakeMoreForm() {
	try {
		Bureaucrat loki("Loki", 130);
		ShrubberyCreationForm everSaid("kocsogfa");

		std::cout << std::endl;
		loki.signForm(everSaid);
		everSaid.execute(loki);
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
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