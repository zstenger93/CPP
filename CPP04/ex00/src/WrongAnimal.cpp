#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") { std::cout << CONSTRUCTOR_WA << std::endl; }

WrongAnimal::WrongAnimal(std::string const &type) : type(type) {
	std::cout << type << CONSTRUCTED_WA << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &rhs) {
	std::cout << COPYCON_W << std::endl;
	*this = rhs;
}

WrongAnimal::~WrongAnimal() { std::cout << type << DESTRUCTOR_WA << std::endl; }

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
	std::cout << type << ASSIGNMENT_W << std::endl;
	if (this != &rhs) {
		type = rhs.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const { std::cout << "WrongAnimal sound" << std::endl; }