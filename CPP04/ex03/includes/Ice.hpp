#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "Amateria.hpp"

class Ice : public Amateria {
   public:
	Ice(std::string const& type);
	std::string const& getType() const;	 // Returns the materia type
	Amateria* clone() const;
	void use(ICharacter& target);

   protected:
   private:
};

#endif