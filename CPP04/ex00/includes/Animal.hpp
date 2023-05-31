#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define CONSTRUCTOR_A "Default animal is cunstructed"
#define DESTRUCTOR_A " type of animal was destructed"
#define COPYCON_A "Animal copy constructor called"
#define CONSTRUCTED_A " type of animal is constructed"
#define ASSIGNMENT " assignment operator overload called"

#include <iostream>

class Animal {
	public:
		Animal();
		Animal(std::string const &type);
		Animal(Animal const &rhs);
		~Animal();
		Animal &operator=(Animal const &rhs);
		void makeSound() const;
	protected:
		std::string type;
};

#endif