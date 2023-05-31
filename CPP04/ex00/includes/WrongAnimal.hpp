#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#define CONSTRUCTOR_WA "Default WrongAnimal is cunstructed"
#define DESTRUCTOR_WA " type of WrongAnimal was destructed"
#define COPYCON_W "WrongAnimal copy constructor called"
#define CONSTRUCTED_WA " type of WrongAnimal is constructed"
#define ASSIGNMENT " assignment operator overload called"

#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(std::string const &type);
		WrongAnimal(WrongAnimal const &rhs);
		~WrongAnimal();
		WrongAnimal &operator=(WrongAnimal const &rhs);
		void makeSound() const;
	protected:
		std::string type;
};

#endif