#include "../includes/Form.hpp"

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

static void TestFormSigning() {
	Bureaucrat loki;

	std::cout << std::endl;
	try {
		Bureaucrat loki("Loki", 42);
		Form everythingYouHaveEverSaid("EverythingYouHaveEverSaid", false, 42);

		loki.signForm(everythingYouHaveEverSaid);
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cerr << loki.getName() << RED << error.what() << END << std::endl;
	}
}

static void TestAlreadySigned() {
	Bureaucrat loki;
	Bureaucrat mobius;

	std::cout << std::endl;
	try {
		Bureaucrat loki("Loki", 42);
		Bureaucrat mobius("Mobius", 42);
		Form everythingYouHaveEverSaid("EverythingYouHaveEverSaid", false, 42);

		loki.signForm(everythingYouHaveEverSaid);
		mobius.signForm(everythingYouHaveEverSaid);
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cerr << loki.getName() << RED << error.what() << END << std::endl;
	}
}

static void TestRequirement() {
	Bureaucrat loki;
	Bureaucrat mobius;
	Form lokiIsAnnoying;

	std::cout << std::endl;
	try {
		Form lokiIsAnnoying("LokiIsAnnoying", false, -10);
		Form everythingYouHaveEverSaid("EverythingYouHaveEverSaid", false, 14);
		Bureaucrat loki("Loki", 42);
		Bureaucrat mobius("Mobius", 42);

		loki.signForm(everythingYouHaveEverSaid);
		mobius.signForm(lokiIsAnnoying);
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cerr << lokiIsAnnoying.Name() << RED << error.what() << END << std::endl;
	}
}

int main(int argc, char **argv) {
	int TestCaseId = GetId(argc, argv, 0);

	switch (TestCaseId) {
		case 1:
			TestFormSigning();
			break;
		case 2:
			TestAlreadySigned();
			break;
		case 3:
			TestRequirement();
			break;
		default:
			AvailableTestCases();
			break;
	}
	return 0;
}