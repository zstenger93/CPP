#ifndef BRAIN_HPP
#define BRAIN_HPP

#define IDEAS 100

#include <cstdlib>
#include <iostream>

#include "AbstractAnimal.hpp"

class Brain {
   public:
	Brain();
	Brain(Brain const &rhs);
	~Brain();
	Brain &operator=(Brain const &rhs);
	void GenerateIdea(std::string const &idea);
	void PrintIdea() const;

   protected:
	std::string ideas[IDEAS];

   private:
	int IdeaIndex;
};

#endif