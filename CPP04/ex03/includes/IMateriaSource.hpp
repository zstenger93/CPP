#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "Amateria.hpp"

class IMateriaSource {
   public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(Amateria*) = 0;
	virtual Amateria* createMateria(std::string const& type) = 0;
};

#endif