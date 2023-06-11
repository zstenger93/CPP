#include "../includes/Character.hpp"

/*____________________________ CONSTRUCTORS / DESTRUCTOR ____________________________*/

Character::Character() { std::cout << C_CONSTRUCTOR << std::endl; }

Character::Character(Character const &cpy) {
	std::cout << C_COPYCON << std::endl;
	*this = cpy;
}

Character::Character(std::string const &name) : _name(name) {
	std::cout << CHARCON << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++) inventory[i] = NULL;
}

Character::~Character() { std::cout << C_DESTRUCTOR << std::endl; }

/*________________________________ OPERATOR OVERLOAD ________________________________*/

Character &Character::operator=(Character const &rhs) {
	std::cout << C_ASSIGN << std::endl;
	if (this != &rhs) {
		_name = rhs.getName();
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (inventory[i] != NULL) delete inventory[i];
			if (rhs.inventory[i] != NULL)
				inventory[i] = rhs.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return *this;
}

/*____________________________________ FUNCTIONS ____________________________________*/

void Character::use(int idx, ICharacter &target) {
	if (inventory[idx] != NULL && idx > -1 && idx < 4)
		inventory[idx]->use(target);
	else if (inventory[idx] == NULL)
		std::cout << "Item #" << idx << " is not found" << std::endl;
	else
		std::cout << "wrong index" << std::endl;
}

void Character::equip(AMateria *m) {

}

void Character::unequip(int idx) {
	
}