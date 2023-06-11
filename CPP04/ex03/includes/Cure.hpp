#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define CURE_COPYCON "Cure copy constructor called"
#define CURE_ASSIGN "Cure assignment operator called"
#define CURE_DESTRUCTOR "\033[1;91mCure Destructor called\033[0;39m"
#define CURE_CONSTRUCTOR "\033[1;33mCure Default Constructor is called\033[0;39m"

class Cure : public AMateria {
   public:
	Cure();
	Cure(Cure const &cpy);
	~Cure();
	Cure &operator=(Cure const &rhs);
	Cure(std::string const &type);
	std::string const &getType() const;	 // Returns the materia type
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif