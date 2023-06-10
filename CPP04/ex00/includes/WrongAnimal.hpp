#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#define CONSTRUCTOR_WA "Default WrongAnimal is cunstructed"
#define DESTRUCTOR_WA " type of WrongAnimal was destructed"
#define COPYCON_W "WrongAnimal copy constructor called"
#define CONSTRUCTED_WA "\033[1;33m type of WrongAnimal is being constructed\033[0;39m"
#define ASSIGNMENT_W " assignment operator overload called"
#define CONSTRUCTOR_W "\033[1;32m is cunstructed\033[0;39m"
#define DESTRUCTOR_W "\033[1;31m was destructed\033[0;39m"
#define COPYCON_WA " copy constructor called"

#include <iostream>

class WrongAnimal {
   public:
	WrongAnimal();
	WrongAnimal(std::string const &type);
	WrongAnimal(WrongAnimal const &rhs);
	~WrongAnimal();
	WrongAnimal &operator=(WrongAnimal const &rhs);
	void makeSound() const;
	void GetType() const;

   protected:
	std::string type;
};

#endif