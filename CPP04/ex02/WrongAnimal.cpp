#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "proto"
	std::cout << "WrongAnimal Birthed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& ori)
{
	type = ori.get_type();
	std::cout << "Duplicate WrongAnimal\n";
}

WrongAnimal&	WrongAnimal::operator=(const	WrongAnimal& ori)
{
	if (this == &ori)
		return *this;
	this->~WrongAnimal();
	new (this) WrongAnimal(ori);
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Died\n";
}

void	makeSound()
{
	std::cout << "Blurgh\n";
}

std::string	get_type()
{
	return (type);
}