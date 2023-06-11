#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

#define IM_COPYCON "IMateriaSource copy constructor called"
#define IM_ASSIGN "IMateriaSource assignment operator called"
#define IM_DESTRUCTOR "\033[1;91mIMateriaSource Destructor called\033[0;39m"
#define IM_CONSTRUCTOR "\033[1;33mIMateriaSource Default Constructor is called\033[0;39m"

class IMateriaSource {
   public:
	virtual ~IMateriaSource();
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif