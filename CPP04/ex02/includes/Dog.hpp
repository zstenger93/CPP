#ifndef DOG_HPP
#define DOG_HPP

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Dog : public AbstractAnimal {
   public:
	Dog();
	Dog(Dog const &rhs);
	virtual ~Dog();
	Dog &operator=(Dog const &rhs);
	virtual void makeSound() const;
	void GenerateIdea(std::string const &idea);
	void PrintIdea() const;

   private:
	Brain *brain;
};

#endif