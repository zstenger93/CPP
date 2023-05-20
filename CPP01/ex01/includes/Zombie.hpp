#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define AMOUNT 15
#include <iostream>

class Zombie {
   private:
    std::string _name;

   public:
    Zombie(std::string name);
    Zombie(void);
    ~Zombie(void);
    void announce(void);
    void give_name(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif