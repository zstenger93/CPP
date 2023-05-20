#include "../includes/Zombie.hpp"

Zombie::Zombie(void) : _name("") {}
Zombie::Zombie(std::string name) : _name(name) {}
Zombie::~Zombie(void) { std::cout << _name << " is destroyed" << std::endl; }
void Zombie::announce(void) { std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl; }
