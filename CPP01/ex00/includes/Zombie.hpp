#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define DESTROY " is destroyed"
#define BRAIN ": BraiiiiiiinnnzzzZ..."
#define NO_ARG "\033[1;31mThis program doesn't take any arguments\033[0m"

#include <iostream>

class Zombie {
   public:
	Zombie(void);
	~Zombie(void);
	Zombie(std::string name);
	void announce(void);

   private:
	std::string _name;
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif