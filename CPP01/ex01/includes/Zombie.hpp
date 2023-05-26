#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define AMOUNT 15
#define NAME "Sanyiii"
#define DESTROY " is destroyed"
#define BRAIN ": BraiiiiiiinnnzzzZ..."
#define NO_ARG "\033[1;31mThis program doesn't take any arguments\033[0m"

#include <iostream>

class Zombie {
   public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
	void announce(void);
	void give_name(std::string name);

   private:
	std::string _name;
};

Zombie *zombieHorde(int N, std::string name);

#endif