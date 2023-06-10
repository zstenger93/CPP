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

int main(void) {
	Dog Brian;
	Cat Tom;

	for (int i = 0; i < ARRAY_LENGTH; i++) {
		std::ostringstream oss;
		if (i % 2 == 0) {
			oss << COLOR_Y << "Brian's brainf*ck #" << i + 1 << COLOR_END;
			Brian.GenerateIdea(oss.str());
		} else {
			oss << COLOR_R << "Tom's brainf*ck #" << i + 1 << COLOR_END;
			Tom.GenerateIdea(oss.str());
		}
	}
	Brian.PrintIdea();
	Tom.PrintIdea();

	pdf_example_test();

	return 0;
}
