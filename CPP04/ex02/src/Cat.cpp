#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	brain = new Brain();
	std::cout << type << CONSTRUCTOR << std::endl;
}

Cat::Cat(Cat const &rhs) : Animal(rhs) {
	brain = NULL;
	std::cout << type << COPYCON << std::endl;
	*this = rhs;
}

Cat::~Cat() {
	delete brain;
	std::cout << type << DESTRUCTOR << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
	std::cout << type << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		type = rhs.type;
		delete brain;
		brain = new Brain(*rhs.brain);
	}
	return *this;
}

void Cat::makeSound() const { std::cout << type << " does: Meow" << std::endl; }

void Cat::GenerateIdea(std::string const &idea) { brain->GenerateIdea(idea); }

void Cat::PrintIdea() const { brain->PrintIdea(); }
