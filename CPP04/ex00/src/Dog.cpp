#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Puppy!\n";
}

Dog::Dog(const Dog &ori)
{
	type = ori.getType();
	std::cout << "There's more Dogs now\n";
}

Dog::~Dog()
{
	std::cout << "It's a dog's life you know!\n";
}

Dog& Dog::operator=(const Dog &ori)
{
	if (this != &ori)
		type = ori.getType();
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof !\n";
}	for (int i = 0; i < 4; i++)
	{
		if (known_materia[i])
			known_materia[i]->~AMateria();
	}