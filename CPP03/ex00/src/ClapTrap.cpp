#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapTrap"), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << COLOR_Y << name << COLOR_END << CONSTRUCTOR << std::endl;
}

ClapTrap::ClapTrap(std::string const &name)
	: name("ClapTrap"), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << COLOR_Y << name << COLOR_END << CONSTRUCTED << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &rhs) {
	std::cout << COPY << std::endl;
	*this = rhs;
}

ClapTrap::~ClapTrap() { std::cout << COLOR_Y << name << COLOR_END << DESTRUCTOR << std::endl; }

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		name = rhs.name;
		HitPoints = rhs.HitPoints;
		EnergyPoints = rhs.EnergyPoints;
		AttackDamage = rhs.AttackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (HitPoints == 0)
		std::cout << COLOR_Y << name << COLOR_END << DEAD_NO_ATCK << COLOR_R << target << COLOR_END
				  << std::endl;
	else if (EnergyPoints == 0)
		std::cout << COLOR_Y << name << COLOR_END << CANT_ATTACK << COLOR_R << target << COLOR_END
				  << std::endl;
	else if (HitPoints > 0 && EnergyPoints > 0) {
		std::cout << COLOR_Y << name << COLOR_END << " attacks " << COLOR_R << target << COLOR_END
				  << " causing " << AttackDamage << " damage" << std::endl;
		EnergyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (HitPoints == 0)
		std::cout << COLOR_Y << name << COLOR_END << DEAD << std::endl;
	else if (HitPoints > (long)amount) {
		HitPoints -= amount;
		std::cout << COLOR_Y << name << COLOR_END << HITPOINTS_LEFT << HitPoints << std::endl;
	} else {
		HitPoints = 0;
		std::cout << COLOR_Y << name << COLOR_END << DEATH << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (HitPoints == 0)
		std::cout << COLOR_Y << name << COLOR_END << CANT_REPAIR << std::endl;
	else if (EnergyPoints == 0) {
		std::cout << COLOR_Y << name << COLOR_END << NO_ENERGY << std::endl;
	} else if (HitPoints > 0 && EnergyPoints > 0) {
		HitPoints += amount;
		EnergyPoints--;
		std::cout << COLOR_Y << name << COLOR_END << REPAIRED << HitPoints << std::endl;
	}
}