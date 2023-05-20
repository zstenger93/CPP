#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}
HumanB::~HumanB(void) {}
void HumanB::SetWeapon(Weapon &weapon) { _weapon = &weapon; }
void HumanB::Attack(void) {
    if (_weapon == NULL)
        std::cout << _name << " doesn't have weapon yet, but you can see it" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->GetType() << std::endl;
}
