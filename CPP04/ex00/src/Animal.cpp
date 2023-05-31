#include "../includes/Animal.hpp"

Animal::Animal() : type("Animal") { std::cout << CONSTRUCTOR_A << std::endl; }

Animal::Animal(std::string const &type) : type(type) {
	std::cout << type << CONSTRUCTED_A << std::endl;
}

Animal::Animal(Animal const &rhs) {
	std::cout << COPYCON_A << std::endl;
	*this = rhs;
}

Animal::~Animal() { std::cout << type << DESTRUCTOR_A << std::endl; }

Animal &Animal::operator=(Animal const &rhs) {
	std::cout << type << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		type = rhs.type;
	}
	return *this;
}

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }