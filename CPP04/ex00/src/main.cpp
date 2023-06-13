#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/WrongDog.hpp"

int main(void) {
	// create correct animals
	Animal *Animals[3];

	Animals[0] = new Animal();
	Animals[1] = new Dog();
	Animals[2] = new Cat();

	std::cout << std::endl << std::endl;
	// print the type of the animal and the sound it makes
	for (size_t type = 0; type < 3; type++) Animals[type]->GetType(), Animals[type]->makeSound();

	std::cout << std::endl << std::endl;

	// create wrong animals
	WrongAnimal *WrongAnimals[3];

	WrongAnimals[0] = new WrongAnimal();
	WrongAnimals[1] = new WrongDog();
	WrongAnimals[2] = new WrongCat();

	std::cout << std::endl << std::endl;

	for (size_t type = 0; type < 3; type++)
		WrongAnimals[type]->GetType(), WrongAnimals[type]->makeSound();

	std::cout << std::endl << std::endl;

	// free
	for (size_t i = 0; i < 3; i++) delete Animals[i];

	std::cout << std::endl << std::endl;

	for (size_t i = 0; i < 3; i++) delete WrongAnimals[i];

	return 0;
}
