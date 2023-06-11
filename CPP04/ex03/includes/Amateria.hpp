#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#define AM_DESTRUCTOR "AMateria Destructor called"
#define AM_CONSTRUCTOR "AMateria Default Constructor"
#define AM_COPYCON "AMateria copy constructor called"
#define AM_ASSIGN "AMateria assignment operator called"
#define AM_STRINGCON "AMateria string constructor called"

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