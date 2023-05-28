#include "../includes/ClapTrap.hpp"

static void InputCheck(int argc, char **argv) {
	(void)argv;
	if (argc != 1) {
		std::cerr << NO_ARG << std::endl;
		exit(1);
	}
}

int main(int argc, char **argv) {
	InputCheck(argc, argv);
	ClapTrap trapA("Bela");
	ClapTrap trapB("Joska");
	ClapTrap trapC(trapB);

	trapA.attack("Sanyiii");
	trapA.takeDamage(5);
	trapA.beRepaired(1);
	trapA.takeDamage(10);
	trapA.attack("Fogatlan Vampir");

	std::cout << std::endl;

	trapB.attack("Lakatos Ronaldo");
	trapB.attack("tudorak");
	trapB.beRepaired(4);

	std::cout << std::endl;

	trapC.attack("vanegycigid");

	return std::cout << std::endl, 0;
}
