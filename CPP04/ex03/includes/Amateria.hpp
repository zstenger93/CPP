#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#define COLOR_Y "\033[1;33m"
#define COLOR_R "\033[1;91m"
#define COLOR_END "\033[0;39m"

#define AM_COPYCON "AMateria copy constructor called"
#define AM_ASSIGN "AMateria assignment operator called"
#define AM_STRINGCON "AMateria string constructor called"
#define AM_DESTRUCTOR "\033[1;91mAMateria Destructor called\033[0;39m"
#define AM_CONSTRUCTOR "\033[1;33mAMateria Default Constructor is called\033[0;39m"

class ICharacter;

class AMateria {
   public:
	AMateria();
	AMateria(std::string const &type);	// AMateria string constructor
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