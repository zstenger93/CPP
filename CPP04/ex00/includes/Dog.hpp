#ifndef DOG_HPP
#define DOG_HPP

#define CONSTRUCTOR "Default animal is cunstructed"
#define DESTRUCTOR " type of animal was destructed"
#define COPYCON "Animal copy constructor called"
#define ASSIGNMENT " assignment operator overload called"

#include "animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(Dog const &rhs);
		~Dog();
		Dog &operator=(Dog const &rhs);
		void makeSound() const;
};

#endif