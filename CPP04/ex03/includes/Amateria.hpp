#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#define AM_CONSTRUCTOR "AMateria Default Constructor"
#define AM_DESTRUCTOR "AMateria Destructor called"
#define AM_COPYCON "AMateria copy constructor called"
#define AM_ASSIGN "AMateria assignment operator called"
#define AM_STRINGCON "AMateria string constructor called"

class ICharacter;

class Amateria {
   public:
	Amateria();
	Amateria(std::string const &type);	// amateria string constructor
	Amateria(Amateria const &cpy);		// copycon
	virtual ~Amateria();
	Amateria &operator=(Amateria const &rhs);  // overload
	std::string const &getType() const;		   // Returns the materia type
	virtual Amateria *clone() const = 0;
	virtual void use(ICharacter &target);

   protected:
	std::string _type;
};

#endif