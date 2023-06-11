#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define INVENTORY_SIZE 4
#define ITEM "Item slot #"
#define FULL "Inventory is full."
#define ENULL "The equipment is NULL."
#define UNEQ " has been unequipped."
#define CHARCON "Character is constructed"
#define IIDXW "The inventory index is wrong."
#define ADDED " has been added to the inventory"
#define MISSING " is not found in the inventory."
#define C_DESTRUCTOR "Character Destructor called"
#define C_COPYCON "Character copy constructor called"
#define HASONE " is already present in the inventory."
#define C_ASSIGN "Character assignment operator called"
#define C_CONSTRUCTOR "Character Default Constructor is called"

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