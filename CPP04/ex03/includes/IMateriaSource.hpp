#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

#define IM_DESTRUCTOR "\033[1;91mIMateriaSource Destructor called\033[0;39m"

class IMateriaSource {
   public:
	virtual ~IMateriaSource() {};
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif