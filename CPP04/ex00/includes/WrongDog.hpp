#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#define CONSTRUCTOR "Default animal is cunstructed"
#define DESTRUCTOR " type of animal was destructed"
#define COPYCON "Animal copy constructor called"
#define ASSIGNMENT " assignment operator overload called"

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
	public:
		WrongDog();
		WrongDog(WrongDog const &rhs);
		~WrongDog();
		WrongDog &operator=(WrongDog const &rhs);
		void makeSound() const;
};

#endif