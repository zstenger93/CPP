#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
   public:
	Cat();
	Cat(Cat const &rhs);
	virtual ~Cat();
	Cat &operator=(Cat const &rhs);
	virtual void makeSound() const;
	void GenerateIdea(std::string const &idea);
	void PrintIdea() const;

   private:
	Brain *brain;
};

#endif