#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "Amateria.hpp"

#define IM_CONSTRUCTOR "IMateriaSource Default Constructor"
#define IM_DESTRUCTOR "IMateriaSource Destructor called"
#define IM_COPYCON "IMateriaSource copy constructor called"
#define IM_ASSIGN "IMateriaSource assignment operator called"
#define IM_STRINGCON "IMateriaSource string constructor called"

class IMateriaSource {
   public:
	IMateriaSource();
	IMateriaSource(const IMateriaSource &cpy);
	virtual ~IMateriaSource();
	IMateriaSource &operator=(IMateriaSource const &Rhs);
	virtual void learnMateria(Amateria *) = 0;
	virtual Amateria *createMateria(std::string const &type) = 0;
};

#endif