#include "../includes/Bureaucrat.hpp"

static void AvailableTestCases() {
	std::cout << BAD_INPUT << std::endl << std::endl;
	std::cout << TEST0 << std::endl;
	std::cout << TEST1 << std::endl;
	std::cout << TEST2 << std::endl;
	std::cout << TEST3 << std::endl;
	std::cout << TEST4 << std::endl;
	std::cout << TEST5 << std::endl;
	std::cout << TEST6 << std::endl;
	std::cout << std::endl;
}

static int GetId(int argc, char **argv, int TestCaseId) {
	if (argc > 1) {
		int input = std::atoi(argv[1]);
		if (input < 1 || input > 6) return AvailableTestCases(), exit(1), 1;
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

static void TestIncrement() {
	Bureaucrat tva("TVA", 120);

	std::cout << tva;
	tva.IncrementGrade();
	std::cout << tva;
	tva.IncrementGrade();
	std::cout << tva;
	tva.IncrementGrade();
	std::cout << tva << std::endl;
}

static void TestDecrement() {
	Bureaucrat loki("Loki", 10);

	std::cout << loki;
	loki.DecrementGrade();
	std::cout << loki;
	loki.DecrementGrade();
	std::cout << loki;
	loki.DecrementGrade();
	std::cout << loki << std::endl;
}

static void TestGradeRangeIncrement() {
	Bureaucrat loki("Loki", 140);
	try {
		while (true) {
			std::cout << loki;
			loki.IncrementGrade();
		}
	} catch (const std::exception &error) {
		std::cerr << loki.getName() << RED << error.what() << END << std::endl;
	}
}

static void TestGradeRangeDecrement() {
	Bureaucrat loki("Loki", 10);
	try {
		while (true) {
			std::cout << loki;
			loki.DecrementGrade();
		}
	} catch (const std::exception &error) {
		std::cerr << loki.getName() << RED << error.what() << END << std::endl;
	}
}

static void TestTooHighGrade() {
	Bureaucrat loki;
	try {
		Bureaucrat loki("Loki", 0);
		while (true) {
			std::cout << loki;
			loki.IncrementGrade();
		}
	} catch (const std::exception &error) {
		std::cerr << loki.getName() << RED << error.what() << END << std::endl;
	}
}

static void TestTooLowGrade() {
	Bureaucrat loki;
	try {
		Bureaucrat loki("Loki", 151);
		while (true) {
			std::cout << loki;
			loki.DecrementGrade();
		}

	} catch (const std::exception &error) {
		std::cerr << loki.getName() << RED << error.what() << END << std::endl;
	}
}

int main(int argc, char **argv) {
	int TestCaseId = GetId(argc, argv, 0);

	switch (TestCaseId) {
		case 1:
			TestIncrement();
			break;
		case 2:
			TestDecrement();
			break;
		case 3:
			TestGradeRangeIncrement();
			break;
		case 4:
			TestGradeRangeDecrement();
			break;
		case 5:
			TestTooLowGrade();
			break;
		case 6:
			TestTooHighGrade();
			break;
		default:
			AvailableTestCases();
			break;
	}
	return 0;
}