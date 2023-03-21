#include "Animal.hpp"

Animal::Animal()
{
	type = "proto"
	std::cout << "Animal Birthed\n";
}

Animal::Animal(const Animal& ori)
{
	type = ori.get_type();
	std::cout << "Duplicate Animal\n";
}

Animal&	Animal::operator=(const	Animal& ori)
{
	this->~Animal();
	new (this) Animal(ori);
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Died\n";
}

void	makeSound()
{
	std::cout << "...\n";
}