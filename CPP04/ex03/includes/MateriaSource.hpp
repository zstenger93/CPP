#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define SLOTS 4
#define ISNULL "Materia is NULL."
#define BOOKFULL "The spellbook is full"
#define NOTFOUND " materia is not available."
#define M_CREATED " materia has been created."
#define M_COPYCON "MateriaSource copy constructor called"
#define M_ASSIGN "MateriaSource assignment operator called"
#define M_DESTRUCTOR "\033[1;91mMateriaSource Destructor called\033[0;39m"
#define M_CONSTRUCTOR "\033[1;33mMateriaSource Default Constructor is called\033[0;39m"

class MateriaSource : public IMateriaSource {
   public:
	MateriaSource();
	MateriaSource(AMateria *m);
	MateriaSource(MateriaSource const &cpy);
	virtual ~MateriaSource();
	MateriaSource &operator=(MateriaSource const &rhs);
	void InitSpellBook();
	void DeleteSpellBook();
	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);

   private:
	AMateria *spellbook[4];
};

#endif