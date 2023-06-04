#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class Amateria {
   public:
	Amateria(std::string const& type);
	std::string const& getType() const;	 // Returns the materia type
	virtual Amateria* clone() const = 0;
	virtual void use(ICharacter& target);

   protected:
   private:
};

#endif