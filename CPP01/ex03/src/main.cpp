#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int main(void) {
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.Attack();
        club.SetType("some other type of club");
        bob.Attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.SetWeapon(club);
        jim.Attack();
        club.SetType("some other type of club");
        jim.Attack();
    }

    return (0);
}