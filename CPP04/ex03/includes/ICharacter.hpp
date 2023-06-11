#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "Amateria.hpp"

#define IC_CONSTRUCTOR "ICharacter Default Constructor"
#define IC_DESTRUCTOR "ICharacter Destructor called"
#define IC_COPYCON "ICharacter copy constructor called"
#define IC_ASSIGN "ICharacter assignment operator called"
#define IC_STRINGCON "ICharacter string constructor called"

class ICharacter {
   public:
	ICharacter();
	ICharacter(const ICharacter &cpy);
	virtual ~ICharacter();
  	ICharacter &operator=(ICharacter const &rhs);
	virtual std::string const &getName() const = 0;
	virtual void equip(Amateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};

#endif