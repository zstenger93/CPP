#include "../includes/Array.hpp"

int main() {
	try {
		Array<int> emptyArray;
		std::cout << "Empty array size: " << emptyArray.size() << std::endl;

		Array<int> intArray(5);
		std::cout << "Int array size: " << intArray.size() << std::endl;

		intArray[0] = 10;
		intArray[1] = 20;
		intArray[2] = 30;
		intArray[3] = 40;
		intArray[4] = 50;

		for (unsigned int i = 0; i < intArray.size(); ++i) {
			std::cout << intArray[i] << " ";
		}
		std::cout << std::endl;

		Array<int> copyArray = intArray;

		intArray[0] = 100;
		intArray[1] = 200;

		for (unsigned int i = 0; i < copyArray.size(); ++i) {
			std::cout << copyArray[i] << " ";
		}
		std::cout << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << std::endl;
	}

	return 0;
}
