#ifndef CAT_HPP
#define CAT_HPP

#define CONSTRUCTOR " is cunstructed"
#define DESTRUCTOR " was destructed"
#define COPYCON " copy constructor called"
#define ASSIGNMENT " assignment operator overload called"

#include "animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &rhs);
		~Cat();
		Cat &operator=(Cat const &rhs);
		void makeSound() const;
};

#endif