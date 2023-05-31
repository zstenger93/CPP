#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << type << CONSTRUCTOR << std::endl; }

WrongCat::WrongCat(WrongCat const &rhs) {
	std::cout << type << COPYCON << std::endl;
	*this = rhs;
}

WrongCat::~WrongCat() { std::cout << type << DESTRUCTOR << std::endl; }

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	std::cout << type << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		type = rhs.type;
	}
	return *this;
}

void WrongCat::makeSound() const { std::cout << "WrongMeow" << std::endl; }