#include "../includes/FragTrap.hpp"

static void InputCheck(int argc, char **argv) {
	(void)argv;
	if (argc != 1) {
		std::cerr << NO_ARG << std::endl;
		exit(1);
	}
}

int main(int argc, char **argv) {
	InputCheck(argc, argv);
	ClapTrap KingOfBlaha("KingOfBlaha");
	ClapTrap VanegyCigid("VanegyCigid");
	ClapTrap Saaannyyiii("Saaannyyiii");
	ScavTrap LakatosRonaldo("Lakatos Ronaldo");
	FragTrap Maunika("Maunika");

	KingOfBlaha.attack("Saaannyyiii");
	Saaannyyiii.takeDamage(5);
	KingOfBlaha.beRepaired(1);
	VanegyCigid.attack("Fogatlan Vampir");

	std::cout << std::endl;

	LakatosRonaldo.attack("KingOfBlaha");
	KingOfBlaha.takeDamage(5);
	KingOfBlaha.attack("LakatosRonaldo");
	LakatosRonaldo.takeDamage(3);
	LakatosRonaldo.beRepaired(4);
	LakatosRonaldo.guardGate();

	std::cout << std::endl;

	Maunika.attack("KingOfBlaha");
	Maunika.takeDamage(80);
	Maunika.beRepaired(10);
	Maunika.highFivesGuys();

	return std::cout << std::endl, 0;
}
