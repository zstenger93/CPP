#include "../includes/DiamondTrap.hpp"

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
	ScavTrap LakatosRonaldo("LakatosRonaldo");
	FragTrap Maunika("Maunika");
	DiamondTrap	CopyPaste("CopyPaste");

	KingOfBlaha.attack("Saaannyyiii");
	Saaannyyiii.takeDamage(5);
	KingOfBlaha.beRepaired(1);
	VanegyCigid.attack("FogatlanVampir");

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

	std::cout << std::endl;

	CopyPaste.attack("LakatosRonaldo");
	CopyPaste.takeDamage(20);
	CopyPaste.beRepaired(10);
	CopyPaste.guardGate();
	CopyPaste.highFivesGuys();
	CopyPaste.whoAmI();

	return std::cout << std::endl, 0;
}

