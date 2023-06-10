#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat") { std::cout << type << CONSTRUCTOR << std::endl; }

Cat::Cat(Cat const &rhs) {
	std::cout << type << COPYCON << std::endl;
	*this = rhs;
}

Cat::~Cat() { std::cout << type << DESTRUCTOR << std::endl; }

Cat &Cat::operator=(Cat const &rhs) {
	std::cout << type << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		type = rhs.type;
	}
	return *this;
}

void Cat::makeSound() const { std::cout << " does: meow" << std::endl; }