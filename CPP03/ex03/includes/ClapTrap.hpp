#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define COLOR_Y "\033[1;33m"
#define COLOR_R "\033[1;91m"
#define COLOR_END "\033[0;39m"
#define DEAD " is already dead"
#define DEATH " was attacked and died"
#define COPY "Copy constructor called"
#define CONSTRUCTED " was constructed"
#define CT "\033[1;32mClapTrap \033[0;39m"
#define ST "\033[1;37mScavTrap \033[0;39m"
#define FT "\033[1;96mFragTrap \033[0;39m"
#define GUARD " is now in Gate keeper mode"
#define DT "\033[1;34mDiamondTrap \033[0;39m"
#define REPAIRED " was repaired. Hit points: "
#define DESTRUCTOR " default destructor called"
#define ASSIGNMENT "Assignment operator called"
#define CONSTRUCTOR " default constructor called"
#define DEAD_NO_ATCK " is dead and cannot attack "
#define HITPOINTS_LEFT " attacked. Hit points left: "
#define CANT_ATTACK " has no energy points to attack "
#define NO_ENERGY " has no energy points to be repaired"
#define CANT_REPAIR " is already dead and cannot be repaired"
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

   protected:
	std::string name;
	int HitPoints;
	int EnergyPoints;
	int AttackDamage;
};

#endif