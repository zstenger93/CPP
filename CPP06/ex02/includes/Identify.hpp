#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <cstdlib>
#include <exception>
#include <iostream>

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/Base.hpp"
#include "../includes/C.hpp"

#define RED "\033[1;31m"
#define END "\033[1;39m"
#define BLUE "\033[1;34m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CREATED "\033[1;33m was randomly created.\033[1;39m"
#define IS "\033[1;34m pointer is identified as: \033[1;39m"
#define REF "\033[1;34m reference is from class: \033[1;39m"

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