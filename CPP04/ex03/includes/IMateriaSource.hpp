#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

#define IM_DESTRUCTOR "IMateriaSource Destructor called"
#define IM_CONSTRUCTOR "IMateriaSource Default Constructor"
#define IM_COPYCON "IMateriaSource copy constructor called"
#define IM_ASSIGN "IMateriaSource assignment operator called"

class IMateriaSource {
   public:
	IMateriaSource();
	IMateriaSource(const IMateriaSource &cpy);
	virtual ~IMateriaSource();
	IMateriaSource &operator=(IMateriaSource const &Rhs);
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif