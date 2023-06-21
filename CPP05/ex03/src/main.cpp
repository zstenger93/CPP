#include <exception>

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

static void AvailableTestCases() {
	std::cout << BAD_INPUT << std::endl << std::endl;
	std::cout << TEST0 << std::endl;
	std::cout << TEST1 << std::endl;
	std::cout << TEST2 << std::endl;
	std::cout << TEST3 << std::endl;
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

static void TestShrubbery() {
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

static void TestRobotomy() {
	try {
		Bureaucrat loki("Loki", 30);
		RobotomyRequestForm everSaid("are_you_a_robot");

		std::cout << std::endl;
		loki.signForm(everSaid);
		everSaid.execute(loki);
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
}

static void TestPardon() {
	try {
		Bureaucrat loki("Loki", 2);
		PresidentialPardonForm everSaid("Loki");

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
			TestShrubbery();
			break;
		case 2:
			TestRobotomy();
			break;
		case 3:
			TestPardon();
			break;
		default:
			AvailableTestCases();
			break;
	}
}