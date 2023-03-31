#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas [i] = "*nothing*";
	std::cout << "Brain Developped\n";
}

Brain::Brain(const Brain& ori)
{
	*this = ori;
	std::cout << "Duplicate Brain\n";
}

Brain&	Brain::operator=(const	Brain& ori)
{
	if (this != &ori)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = ori.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "So Long!" << std::endl;
}