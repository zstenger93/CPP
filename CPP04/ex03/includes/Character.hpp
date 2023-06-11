#ifndef CHARACTER_HPP
#define CHARACTER_HPP

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
	~Character();
	Character &operator=(Character const &rhs);
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

   private:
	std::string _name;
	AMateria *inventory[INVENTORY_SIZE];
};

#endif