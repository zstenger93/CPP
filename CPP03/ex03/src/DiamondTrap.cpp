#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("defClapTrap"), ScavTrap(), FragTrap(), _name("Default") {
	std::cout << DT << CONSTRUCTOR << std::endl;
	EnergyPoints = ScavTrap::EnergyPoints;
}

DiamondTrap::DiamondTrap(std::string const &name)
	: ClapTrap(name + "_clap_trap"), ScavTrap(), FragTrap(), _name(name) {
	std::cout << DT << COLOR_Y << name << COLOR_END << CONSTRUCTOR << std::endl;
	EnergyPoints = ScavTrap::EnergyPoints;
}

DiamondTrap::DiamondTrap(DiamondTrap const &rhs) {
	std::cout << DT << COPY << std::endl;
	*this = rhs;
}

DiamondTrap::~DiamondTrap() {
	std::cout << DT << COLOR_Y << _name << COLOR_END << DESTRUCTOR << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		_name = rhs._name;
		HitPoints = rhs.HitPoints;
		EnergyPoints = rhs.EnergyPoints;
		AttackDamage = rhs.AttackDamage;
	}
	return *this;
}

void DiamondTrap::whoAmI(void) {
	std::cout << DT << COLOR_Y << _name << COLOR_END << " is " << CT << COLOR_Y << name << COLOR_END
			  << std::endl;
}

void DiamondTrap::attack(const std::string &target) { ScavTrap::attack(target); }