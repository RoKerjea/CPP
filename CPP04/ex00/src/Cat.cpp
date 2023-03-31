#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "It's a Cat\n";
}

Cat::Cat(const Cat &ori)
{
	type = ori.getType();
	std::cout << "There's more Cats now\n";
}

Cat::~Cat()
{
	std::cout << "Oh no, the kitty!\n";
}

Cat& Cat::operator=(const Cat &ori)
{
	if (this != &ori)
		type = ori.getType();
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou !\n";
}