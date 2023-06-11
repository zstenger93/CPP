#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../includes/ICharacter.hpp"
#include "Amateria.hpp"

#define INVENTORY_SIZE 4
#define C_DESTRUCTOR "Character Destructor called"
#define C_CONSTRUCTOR "Character Default Constructor is called"
#define C_COPYCON "Character copy constructor called"
#define C_ASSIGN "Character assignment operator called"
#define CHARCON "Character is constructed"

class Character : public ICharacter {
   public:
	Character();
	Character(Character const &cpy);
	Character(std::string const &name);
	virtual ~Character();
	Character &operator=(Character const &rhs);
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;

   private:
	std::string _name;
	AMateria *inventory[INVENTORY_SIZE];
};

#endif