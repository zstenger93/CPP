#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define COLOR_Y "\033[1;33m"
#define COLOR_G "\033[1;32m"
#define COLOR_R "\033[1;91m"
#define COLOR_END "\033[0;39m"

#define CONSTRUCTOR_A "Default animal is being cunstructed"
#define DESTRUCTOR_A " type of animal was destructed"
#define COPYCON_A "Animal copy constructor called"
#define CONSTRUCTED_A "\033[1;33m type of animal is being constructed\033[0;39m"
#define ASSIGNMENT " assignment operator overload called"
#define CONSTRUCTOR "\033[1;32m is cunstructed\033[0;39m"
#define DESTRUCTOR "\033[1;31m was destructed\033[0;39m"
#define COPYCON "Animal copy constructor called"

#include <iostream>

class Animal {
   public:
	Animal();
	Animal(std::string const &type);
	Animal(Animal const &rhs);
	virtual ~Animal();
	Animal &operator=(Animal const &rhs);
	virtual void makeSound() const;

   protected:
	std::string type;
};

#endif