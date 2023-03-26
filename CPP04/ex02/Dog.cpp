#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Puppy!\n";
}

Dog::Dog(const Dog &ori)
{
	std::cout << "There's more Dogs now\n";
}

~Dog::Dog()
{
	std::cout << "It's a dog's life you know!\n";
}

Dog& operator=(const Dog &ori)
{
	if (this == &ori)
		return *this;
	this->~Dog();
	new (this) Dog(ori);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof ()\n";
}