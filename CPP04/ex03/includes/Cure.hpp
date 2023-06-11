#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#include "Amateria.hpp"

class Cure : public Amateria {
   public:
	Cure(std::string const &type);
	std::string const &getType() const;	 // Returns the materia type
	Amateria *clone() const;
	void use(ICharacter &target);

   protected:
   private:
};

#endif