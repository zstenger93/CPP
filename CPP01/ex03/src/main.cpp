#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

static void InputCheck(int argc, char **argv) {
	(void)argv;
	if (argc != 1) {
		std::cerr << NO_ARG << std::endl;
		exit(1);
	}
}

int main(int argc, char **argv) {
	InputCheck(argc, argv);
    {
        Weapon club = Weapon(C_CLUB);

        HumanA bob("Bob", club);
        bob.Attack();
        club.SetType(O_CLUB);
        bob.Attack();
    }
    {
        Weapon club = Weapon(C_CLUB);
        HumanB jim("Jim");
        jim.SetWeapon(club);
        jim.Attack();
        club.SetType(O_CLUB);
        jim.Attack();
    }

    return (0);
}