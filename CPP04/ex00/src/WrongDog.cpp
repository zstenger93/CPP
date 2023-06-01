#include "../includes/WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("WrongDog") { std::cout << type << CONSTRUCTOR_W << std::endl; }

WrongDog::WrongDog(WrongDog const &rhs) {
	std::cout << type << COPYCON_WA << std::endl;
	*this = rhs;
}

WrongDog::~WrongDog() { std::cout << type << DESTRUCTOR_W << std::endl; }

WrongDog &WrongDog::operator=(WrongDog const &rhs) {
	std::cout << type << ASSIGNMENT_W << std::endl;
	if (this != &rhs) {
		type = rhs.type;
	}
	return *this;
}

void WrongDog::makeSound() const { std::cout << "WrongBark" << std::endl; }