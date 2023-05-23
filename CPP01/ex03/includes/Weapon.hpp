#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
   public:
	Weapon(void);
	~Weapon(void);
	Weapon(std::string type);
	std::string &GetType(void);
	void SetType(std::string type);

   private:
	std::string _type;
};

#endif