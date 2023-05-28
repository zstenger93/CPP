#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << ST << COLOR_Y << name << COLOR_END << CONSTRUCTOR << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << ST << COLOR_Y << name << COLOR_END << CONSTRUCTED << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &rhs) {
	std::cout << ST << COPY << std::endl;
	*this = rhs;
}

ScavTrap::~ScavTrap() {
	std::cout << ST << COLOR_Y << name << COLOR_END << DESTRUCTOR << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		name = rhs.name;
		HitPoints = rhs.HitPoints;
		EnergyPoints = rhs.EnergyPoints;
		AttackDamage = rhs.AttackDamage;
	}
	return *this;
}

void ScavTrap::guardGate(void) { std::cout << COLOR_Y << name << COLOR_END << GUARD << std::endl; }

void ScavTrap::attack(const std::string &target) {
	if (HitPoints == 0)
		std::cout << ST << COLOR_Y << name << COLOR_END << DEAD_NO_ATCK << COLOR_R << target
				  << COLOR_END << std::endl;
	else if (EnergyPoints == 0)
		std::cout << ST << COLOR_Y << name << COLOR_END << CANT_ATTACK << COLOR_R << target
				  << COLOR_END << std::endl;
	else if (HitPoints > 0 && EnergyPoints > 0) {
		std::cout << ST << COLOR_Y << name << COLOR_END << " attacks " << COLOR_R << target
				  << COLOR_END << " causing " << AttackDamage << " damage" << std::endl;
		EnergyPoints--;
	}
}