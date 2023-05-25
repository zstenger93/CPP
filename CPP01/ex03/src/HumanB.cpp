#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}
HumanB::~HumanB(void) {}
void HumanB::SetWeapon(Weapon &weapon) { _weapon = &weapon; }
void HumanB::Attack(void) {
    if (_weapon == NULL)
        std::cout << _name << NO_WEAPON << std::endl;
    else
        std::cout << _name << ATTACK << _weapon->GetType() << std::endl;
}
