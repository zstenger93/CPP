#include "../includes/Zombie.hpp"

int main(void) {
    Zombie stack1("ZombieOnStack1"); // allocate memory for a short-lived object
    Zombie stack2("ZombieOnStack2"); // managed automatically by the compiler
    Zombie stack3("ZombieOnStack3"); // managed and destroyed in a single function
    Zombie stack4("ZombieOnStack4");

    stack1.announce();
    stack2.announce();
    stack3.announce();
    stack4.announce();

    std::cout << std::endl;

    Zombie* heap1 = newZombie("ZombieOnHeap1"); // managed manually
    Zombie* heap2 = newZombie("ZombieOnHeap2"); // created by new
    Zombie* heap3 = newZombie("ZombieOnHeap3"); // and deleted with delete
    Zombie* heap4 = newZombie("ZombieOnHeap4");

    heap1->announce();
    heap2->announce();
    heap3->announce();
    heap4->announce();

    std::cout << std::endl;

    randomChump("Random Champ");
    std::cout << std::endl;

	delete heap4;
	delete heap3;
    delete heap2;
    delete heap1;

    return (0);
}