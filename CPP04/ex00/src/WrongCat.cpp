#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << type << CONSTRUCTOR_W << std::endl; }

WrongCat::WrongCat(WrongCat const &rhs) {
	std::cout << type << COPYCON_WA << std::endl;
	*this = rhs;
}

WrongCat::~WrongCat() { std::cout << type << DESTRUCTOR_W << std::endl; }

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	std::cout << type << ASSIGNMENT_W << std::endl;
	if (this != &rhs) {
		type = rhs.type;
	}
	return *this;
}

void WrongCat::makeSound() const { std::cout << "WrongMeow" << std::endl; }