#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){}
HumanA::~HumanA(void){}
void	HumanA::Attack(void) {
	std::cout << _name << " attacks with their " << _weapon.GetType() << std::endl;
}
