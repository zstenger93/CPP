#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << FT << COLOR_Y << name << COLOR_END << CONSTRUCTOR << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << FT << COLOR_Y << name << COLOR_END << CONSTRUCTED << std::endl;
}

FragTrap::FragTrap(FragTrap const &rhs) {
	std::cout << FT << COPY << std::endl;
	*this = rhs;
}

FragTrap::~FragTrap() {
	std::cout << FT << COLOR_Y << name << COLOR_END << DESTRUCTOR << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	std::cout << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		name = rhs.name;
		HitPoints = rhs.HitPoints;
		EnergyPoints = rhs.EnergyPoints;
		AttackDamage = rhs.AttackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << FT << HEY << COLOR_Y << name << COLOR_END HIGH5 << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (HitPoints == 0)
		std::cout << FT << COLOR_Y << name << COLOR_END << DEAD_NO_ATCK << COLOR_R << target
				  << COLOR_END << std::endl;
	else if (EnergyPoints == 0)
		std::cout << FT << COLOR_Y << name << COLOR_END << CANT_ATTACK << COLOR_R << target
				  << COLOR_END << std::endl;
	else if (HitPoints > 0 && EnergyPoints > 0) {
		std::cout << FT << COLOR_Y << name << COLOR_END << " attacks " << COLOR_R << target
				  << COLOR_END << " causing " << AttackDamage << " damage" << std::endl;
		EnergyPoints--;
	}
}