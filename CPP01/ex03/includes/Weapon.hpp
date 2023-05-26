#ifndef WEAPON_HPP
#define WEAPON_HPP

#define C_CLUB "crude spiked club"
#define ATTACK " attacks with their "
#define O_CLUB "some other type of club"
#define NO_WEAPON " doesn't have weapon yet, but you can see it"
#define NO_ARG "\033[1;31mThis program doesn't take any arguments\033[0m"

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