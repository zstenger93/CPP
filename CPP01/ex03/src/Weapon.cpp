#include "../includes/Weapon.hpp"

Weapon::Weapon(void) : _type(""){}
Weapon::Weapon(std::string type) : _type(type){}
Weapon::~Weapon(void) {}

std::string	&Weapon::GetType(void) {return _type;}
void	Weapon::SetType(std::string type) {_type = type;}