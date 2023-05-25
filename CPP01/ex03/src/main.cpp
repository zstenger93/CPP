#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int main(void) {
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