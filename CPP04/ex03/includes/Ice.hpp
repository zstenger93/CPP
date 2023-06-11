#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define SHOOT "* shoots an icebolt at "
#define ICE_DESTRUCTOR "Ice Destructor called"
#define ICE_CONSTRUCTOR "Ice Default Constructor is called"
#define ICE_COPYCON "Ice copy constructor called"
#define ICE_ASSIGN "Ice assignment operator called"

class Ice : public AMateria {
   public:
	Ice();
	Ice(Ice const &cpy);
	~Ice();
	Ice &operator=(Ice const &rhs);
	Ice(std::string const &type);
	std::string const &getType() const;	 // Returns the materia type
	AMateria *clone() const;
	void use(ICharacter &target);

   protected:
   private:
};

#endif