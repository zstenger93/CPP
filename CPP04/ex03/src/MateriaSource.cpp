#include "../includes/MateriaSource.hpp"
#include <regex>

/*____________________________ CONSTRUCTORS / DESTRUCTOR ____________________________*/

MateriaSource::MateriaSource() {
	std::cout << M_CONSTRUCTOR << std::endl;
	InitSpellBook();
}

MateriaSource::MateriaSource(MateriaSource const &cpy) {
	InitSpellBook();
	*this = cpy;
}

MateriaSource::~MateriaSource() {
	std::cout << M_CONSTRUCTOR << std::endl;
	DeleteSpellBook();
}

/*________________________________ OPERATOR OVERLOAD ________________________________*/

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
	
}

/*____________________________________ FUNCTIONS ____________________________________*/

void MateriaSource::InitSpellBook() {
	for (int i = 0; i < SLOTS; i++) spellbook[i] = NULL;
}

void MateriaSource::DeleteSpellBook() {
	for (int i = 0; i < SLOTS; i++) delete spellbook[i];
}