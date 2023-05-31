#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#define CONSTRUCTOR " is cunstructed"
#define DESTRUCTOR " was destructed"
#define COPYCON " copy constructor called"
#define ASSIGNMENT " assignment operator overload called"

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &rhs);
		~WrongCat();
		WrongCat &operator=(WrongCat const &rhs);
		void makeSound() const;
};

#endif