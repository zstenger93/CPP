#include "../includes/AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal() : type("AbstractAnimal") { std::cout << CONSTRUCTOR_A << std::endl; }

AbstractAnimal::AbstractAnimal(std::string const &type) : type(type) {
	std::cout << type << CONSTRUCTED_A << std::endl;
}

AbstractAnimal::AbstractAnimal(AbstractAnimal const &rhs) {
	std::cout << COPYCON_A << std::endl;
	*this = rhs;
}

AbstractAnimal::~AbstractAnimal() { std::cout << type << DESTRUCTOR_A << std::endl; }

AbstractAnimal &AbstractAnimal::operator=(AbstractAnimal const &rhs) {
	std::cout << type << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		type = rhs.type;
	}
	return *this;
}