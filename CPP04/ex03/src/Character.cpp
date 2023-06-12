#include "../includes/Character.hpp"

/*____________________________ CONSTRUCTORS / DESTRUCTOR ____________________________*/

Character::Character(Character const &cpy) {
	// std::cout << C_COPYCON << std::endl;
	*this = cpy;
}

Character::Character(std::string const &name) : _name(name) {
	// std::cout << C_CONSTRUCTOR << std::endl;
	InitSavedPointers();
	InitInventory();
}

Character::~Character() {
	// std::cout << C_DESTRUCTOR << std::endl;
	DeleteSavedPointers();
	DeleteInventory();
}

/*________________________________ OPERATOR OVERLOAD ________________________________*/

Character &Character::operator=(Character const &rhs) {
	// std::cout << C_ASSIGN << std::endl;
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

std::string const &Character::getName() const { return _name; }

void Character::InitInventory() {
	for (int i = 0; i < INVENTORY_SIZE; i++) inventory[i] = NULL;
}

void Character::DeleteInventory() {
	for (int i = 0; i < INVENTORY_SIZE; i++) delete inventory[i];
}

void Character::InitSavedPointers() {
	for (int i = 0; i < INVENTORY_SIZE; i++) SavedPointer[i] = NULL;
}

void Character::DeleteSavedPointers() {
	for (int i = 0; i < INVENTORY_SIZE; i++) delete SavedPointer[i];
}

void Character::SavePointer(int idx) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (SavedPointer[i] != NULL)
			i++;
		else {
			SavedPointer[i] = inventory[idx];
			break;
		}
	}
}

void Character::use(int idx, ICharacter &target) {
	if (inventory[idx] != NULL && idx > -1 && idx < 4) {
		std::cout << "* " << RED << _name << END;
		inventory[idx]->use(target);
	} else if (inventory[idx] == NULL)
		std::cout << YELLOW << ITEM << idx << MISSING << END << std::endl;
	else
		std::cout << RED << IIDXW << END << std::endl;
}

void Character::equip(AMateria *materia) {
	if (materia != NULL) {
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (inventory[i] == NULL) {
				std::cout << YELLOW << _name << END << ": " << materia->getType() << ADDED
						  << std::endl;
				inventory[i] = materia;
				return;
			} else if (inventory[i] == materia) {
				std::cout << _name << materia->getType() << HASONE << std::endl;
				return;
			}
		}
		std::cout << FULL << std::endl;
	} else
		std::cout << ENULL << std::endl;
}

void Character::unequip(int idx) {
	if (inventory[idx] != NULL && idx > -1 && idx < 4) {
		SavePointer(idx);
		inventory[idx] = NULL;
		std::cout << ITEM << idx << UNEQ << std::endl;
	} else if (inventory[idx] == NULL)
		std::cout << YELLOW << ITEM << idx << MISSING << END << std::endl;
	else
		std::cout << RED << IIDXW << END << std::endl;
}