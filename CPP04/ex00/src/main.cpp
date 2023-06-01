#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongDog.hpp"
#include "../includes/WrongCat.hpp"

int main(void) {
  Animal *Animals[3];

  Animals[0] = new Animal();
  Animals[1] = new Dog();
  Animals[2] = new Cat();

  std::cout << std::endl << std::endl;

  for (size_t i = 0; i < 3; i++)
      Animals[i]->makeSound();

  std::cout << std::endl << std::endl;

  WrongAnimal *WrongAnimals[3];

  WrongAnimals[0] = new WrongAnimal();
  WrongAnimals[1] = new WrongDog();
  WrongAnimals[2] = new WrongCat();

  return 0;
}
