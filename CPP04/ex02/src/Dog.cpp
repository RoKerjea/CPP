#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain;
	std::cout << "Puppy!\n";
}

Dog::Dog(const Dog &ori) : Animal(ori)
{
	brain = new Brain(*(ori.brain));
	std::cout << "There's more Dogs now\n";
}

Dog::~Dog()
{
	std::cout << "It's a dog's life you know!\n";
	delete brain;
}

Dog& Dog::operator=(const Dog &ori)
{
	if (this != &ori)
	{
		type = ori.getType();
		(*brain) = *(ori.brain);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof ()\n";
}