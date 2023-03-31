#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"


#define RESET "\e[0m"
#define RED "\e[0;31m"

int main()
{
	std::cout << std::endl << RED << "test du sujet" << RESET << std::endl;	
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	const WrongAnimal	*wa = new WrongAnimal();
	const WrongAnimal	*wcat1 = new WrongCat();
	const WrongCat		*wcat2 = new WrongCat();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();
	std::cout << std::endl;
	wa->makeSound();
	wcat1->makeSound();
	wcat2->makeSound();
	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;
	delete wa;
	delete wcat1;
	delete wcat2;

	return 0;
}

//only "concept" particular in this exercise
//is the virtual keyword for makeSound() method
//to add to Animal and remove from WrongAnimal