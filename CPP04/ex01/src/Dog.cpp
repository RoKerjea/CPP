#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Puppy!\n";
}

Dog::Dog(const Dog &ori)
{
	type = ori.getType();
	brain = ori.brain;
	std::cout << "There's more Dogs now\n";
}

Dog::~Dog()
{
	delete brain;
	std::cout << "It's a dog's life you know!\n";
}

Dog& Dog::operator=(const Dog &ori)
{
	if (this == &ori)
		return *this;
	this->~Dog();
	new (this) Dog(ori);
	brain = ori.brain;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof ()\n";
}