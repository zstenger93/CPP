#include <cstdlib>
#include <sstream>

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

#define ARRAY_LENGTH 10

static void pdf_example_test() {
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << std::endl;

	delete cat;
	delete dog;

	std::cout << std::endl;
}

static void BrainStorm(Dog *Brian, Cat *Tom) {
	std::cout << std::endl;
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		std::ostringstream oss;
		if (i % 2 == 0) {
			oss << COLOR_Y << "Brian's brainf*ck #" << i + 1 << COLOR_END;
			Brian->GenerateIdea(oss.str());
		} else {
			oss << COLOR_R << "Tom's brainf*ck #" << i + 1 << COLOR_END;
			Tom->GenerateIdea(oss.str());
		}
	}
}

static void Zoo() {
	Animal *animals[ARRAY_LENGTH];
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = ARRAY_LENGTH - 1; i > -1; i--) delete animals[i];
}

static void TestIdeas() {
	Dog Brian;
	Cat Tom;

	BrainStorm(&Brian, &Tom);
	Brian.PrintIdea();
	Tom.PrintIdea();
}

static void AvailableTestCases() {
	std::cout << BAD_INPUT << std::endl << std::endl;
	std::cout << TEST0 << std::endl;
	std::cout << TEST1 << std::endl;
	std::cout << TEST2 << std::endl;
}

static int GetId(int argc, char **argv, int TestCaseId) {
	if (argc > 1) {
		int input = std::atoi(argv[1]);
		if (input < 0 || input > 2) return AvailableTestCases(), exit(1), 1;
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

int main(int argc, char **argv) {
	int TestCaseId = GetId(argc, argv, 0);

	switch (TestCaseId) {
		case 1:
			Zoo();
			break;
		case 2:
			TestIdeas();
			break;
		default:
			pdf_example_test();
			break;
	}
	return 0;
}
