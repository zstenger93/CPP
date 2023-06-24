#ifndef BASE_HPP
#define BASE_HPP

#include <exception>

#include "../includes/Base.hpp"

class Base;

class Identify {
   public:
	Identify();
	Identify(Identify const &cpy);
	~Identify();
	Identify &operator=(Identify const &rhs);
	Base *generate(void);
	void identify(Base *p);
	void identify(Base &p);
};

#endif