#ifndef WEAPON_HPP
#define WEAPON_HPP

#define C_CLUB "crude spiked club"
#define ATTACK " attacks with their "
#define O_CLUB "some other type of club"
#define NO_WEAPON " doesn't have weapon yet, but you can see it"

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