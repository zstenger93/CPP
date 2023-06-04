#ifndef ABSTRACTANIMAL_HPP
#define ABSTRACTANIMAL_HPP

#define COLOR_Y "\033[1;33m"
#define COLOR_G "\033[1;32m"
#define COLOR_R "\033[1;91m"
#define COLOR_END "\033[0;39m"

#define CONSTRUCTOR_A "Default AbstractAnimal is being cunstructed"
#define DESTRUCTOR_A " type of AbstractAnimal was destructed"
#define COPYCON_A "AbstractAnimal copy constructor called"
#define CONSTRUCTED_A "\033[1;33m type of AbstractAnimal is being constructed\033[0;39m"
#define ASSIGNMENT " assignment operator overload called"
#define CONSTRUCTOR "\033[1;32m is cunstructed\033[0;39m"
#define DESTRUCTOR "\033[1;31m was destructed\033[0;39m"
#define COPYCON "AbstractAnimal copy constructor called"

#include <iostream>

class AbstractAnimal {
   public:
	virtual ~AbstractAnimal();
	virtual void makeSound() const = 0;

   protected:
	std::string type;
	AbstractAnimal(std::string const &type);

   private:
	AbstractAnimal();
	AbstractAnimal(AbstractAnimal const &rhs);
	AbstractAnimal &operator=(AbstractAnimal const &rhs);
};

#endif