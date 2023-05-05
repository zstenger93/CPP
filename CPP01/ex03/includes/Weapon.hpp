#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon{
private:
	std::string _type;
public:
	Weapon(void);
	~Weapon(void);
	Weapon(std::string type);
	std::string	&GetType(void);
	void		SetType(std::string type);
};

#endif