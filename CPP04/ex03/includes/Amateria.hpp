#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <cstdlib>
#include <string>

#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define END "\033[1;39m"

#define BAD_INPUT "Wrong testcase ID. Available options are:"
#define TEST0 "      nothing -> test from the PDF"
#define TEST1 "         1    -> test for wrong spells passed to createMateria()"
#define TEST2 "         2    -> test for wrong index in use()"
#define TEST3 "         3    -> test for the item not being in the inventory for use()"
#define TEST4 "         4    -> test for unequip() from the inventory"
#define TEST5                                                                                 \
	"         5    -> test for inventory or spellbook being full\n                 for this " \
	"values has to be changed in the header files"

#define AM_COPYCON "AMateria copy constructor called"
#define AM_ASSIGN "AMateria assignment operator called"
#define AM_STRINGCON "AMateria string constructor called"
#define AM_DESTRUCTOR "\033[1;91mAMateria Destructor called\033[0;39m"
#define AM_CONSTRUCTOR "\033[1;33mAMateria Default Constructor is called\033[0;39m"

class ICharacter;

class AMateria {
   public:
	AMateria();
	AMateria(std::string const &type);	// materia type
	AMateria(AMateria const &cpy);		// copycon
	virtual ~AMateria();
	AMateria &operator=(AMateria const &rhs);  // overload
	std::string const &getType() const;		   // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

   protected:
	std::string _type;
};

#endif