#include "../includes/Zombie.hpp"

void ZombieHordeTester();

int main(void) {
    ZombieHordeTester();
    return 0;
}

void ZombieHordeTester() {
    Zombie *horde = zombieHorde(AMOUNT, "SanyibBazmeg");

    for (int i = 0; i < AMOUNT; i++) {
        std::cout << i << " ";
        horde[i].announce();
    }
    delete[] horde;
}