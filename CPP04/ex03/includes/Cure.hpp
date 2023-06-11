#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define CURE_DESTRUCTOR "Cure Destructor called"
#define CURE_CONSTRUCTOR "Cure Default Constructor"
#define CURE_COPYCON "Cure copy constructor called"
#define CURE_ASSIGN "Cure assignment operator called"

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

   protected:
   private:
};

#endif