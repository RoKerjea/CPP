#include "Animal.hpp"

Animal::Animal()
{
	type = "proto";
	std::cout << "Animal Birthed\n";
}

Animal::Animal(const Animal& ori)
{
	type = ori.getType();
	std::cout << "Duplicate Animal\n";
}

Animal&	Animal::operator=(const	Animal& ori)
{
	if (this != &ori)
		type = ori.getType ();
	return *this;
}

Animal::~Animal()
{
	std::cout << "It Happen..\n";
}

void	Animal::makeSound() const
{
	std::cout << "...\n";
}

std::string	Animal::getType() const
{
	return (type);
}