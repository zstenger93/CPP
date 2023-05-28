#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#define HEY "Hey guys, I'm "
#define HIGH5 ". GIVE ME A HIIGHH FIIIVEE!"

#include "../includes/ScavTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &rhs);
		~FragTrap();
		FragTrap &operator=(FragTrap const &rhs);
		void highFivesGuys(void);
		void attack(const std::string &target);
};

#endif