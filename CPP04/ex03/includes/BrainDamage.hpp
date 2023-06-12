#ifndef BRAINDAMAGE_HPP
#define BRAINDAMAGE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define BRAINDAMAGE_COPYCON "BrainDamage copy constructor called"
#define BRAINDAMAGE_ASSIGN "BrainDamage assignment operator called"
#define BRAINDAMAGE_DESTRUCTOR "\033[1;91mBrainDamage Destructor called\033[0;39m"
#define BRAINDAMAGE_CONSTRUCTOR "\033[1;33mBrainDamage Default Constructor is called\033[0;39m"

class BrainDamage : public AMateria {
   public:
	BrainDamage();
	BrainDamage(BrainDamage const &cpy);
	~BrainDamage();
	BrainDamage &operator=(BrainDamage const &rhs);
	BrainDamage(std::string const &type);
	std::string const &getType() const;	 // Returns the materia type
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif