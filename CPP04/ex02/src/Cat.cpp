#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain;
	std::cout << "It's a Cat\n";
}

Cat::Cat(const Cat &ori) : Animal(ori)
{
	brain = new Brain(*(ori.brain));
	std::cout << "There's more Cats now\n";
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Oh no, the kitty!\n";
}

Cat& Cat::operator=(const Cat &ori)
{
	if (this != &ori)
	{
		type = ori.getType();
		(*brain) = *(ori.brain);
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miaou !\n";
}