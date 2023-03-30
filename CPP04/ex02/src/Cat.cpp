#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "It's a Cat\n";
}

Cat::Cat(const Cat &ori)
{
	type = ori.getType();
	brain = ori.brain;
	std::cout << "There's more Cats now\n";
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Oh no, the kitty!\n";
}

Cat& Cat::operator=(const Cat &ori)
{
	if (this == &ori)
		return *this;
	this->~Cat();
	new (this) Cat(ori);
	brain = ori.brain;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou !\n";
}