#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define SHOOT "* shoots an icebolt at "
#define ICE_COPYCON "Ice copy constructor called"
#define ICE_ASSIGN "Ice assignment operator called"
#define ICE_DESTRUCTOR "\033[1;91mIce Destructor called\033[0;39m"
#define ICE_CONSTRUCTOR "\033[1;33mIce Default Constructor is called\033[0;39m"

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
};

#endif