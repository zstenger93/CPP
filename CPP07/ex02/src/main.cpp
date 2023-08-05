#include "../includes/Array.hpp"

#define MAX_VAL 750

void testFile() {
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	// SCOPE
	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return;
		}
	}
	try {
		numbers[-2] = 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	delete[] mirror;  //
}

int main() {
	try {
		Array<int> emptyArray;
		std::cout << "\033[1;31mEmpty array size:\033[0;39m " << emptyArray.size() << std::endl
				  << std::endl;

		Array<int> intArray(5);
		std::cout << "\033[1;31mInt array size:\033[0;39m " << intArray.size() << std::endl
				  << std::endl;

		intArray[0] = 10;
		intArray[1] = 20;
		intArray[2] = 30;
		intArray[3] = 40;
		intArray[4] = 50;

		std::cout << "\033[1;31mOriginal array:\033[0;39m ";
		for (unsigned int i = 0; i < intArray.size(); ++i) {
			std::cout << intArray[i] << " ";
		}
		std::cout << std::endl << std::endl;

		Array<int> copyArray = intArray;

		intArray[0] = 100;
		intArray[1] = 200;

		std::cout << "\033[1;31mCopied array:\033[0;39m ";
		for (unsigned int i = 0; i < copyArray.size(); ++i) {
			std::cout << copyArray[i] << " ";
		}
		std::cout << std::endl << std::endl;
	} catch (const std::exception& error) {
		std::cout << RED << error.what() << std::endl;
	}
	std::cout << "\033[1;31mTest from the provided file\033[0;39m(should throw exception)" << std::endl << std::endl;
	testFile();

	return 0;
}
