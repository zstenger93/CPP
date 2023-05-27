#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define COLOR_Y "\033[1;33m"
#define COLOR_R "\033[1;91m"
#define COLOR_END "\033[0;39m"

#define CONSTRUCTOR " default constructor called"
#define DESTRUCTOR " default destructor called"
#define COPY "Copy constructor called"
#define CONSTRUCTED " was constructed"
#define ASSIGNMENT "Assignment operator called"
#define NO_ENERGY " has no energy points to be repaired"
#define DEAD " is already dead"
#define DEAD_NO_ATCK " is dead and cannot attack "
#define CANT_ATTACK " has no energy points to attack "
#define CANT_REPAIR " is already dead and cannot be repaired"
#define REPAIRED " was repaired. Hit points: "
#define HITPOINTS_LEFT " attacked. Hit points left: "
#define DEATH " was attacked and died"
#define NO_ARG "\033[1;31mThis program doesn't take any arguments\033[0m"

#include <iostream>

class ClapTrap {
   public:
	ClapTrap();
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &rhs);
	~ClapTrap();
	ClapTrap &operator=(ClapTrap const &rhs);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

   private:
	std::string name;
	int HitPoints;
	int EnergyPoints;
	int AttackDamage;
};

#endif