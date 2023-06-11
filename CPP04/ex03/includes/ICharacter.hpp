#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"

#define IC_COPYCON "ICharacter copy constructor called"
#define IC_ASSIGN "ICharacter assignment operator called"
#define IC_DESTRUCTOR "\033[1;91mICharacter Destructor called\033[0;39m"
#define IC_CONSTRUCTOR "\033[1;33mICharacter Default Constructor is called\033[0;39m"

class ICharacter {
   public:
	virtual ~ICharacter();
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};

#endif