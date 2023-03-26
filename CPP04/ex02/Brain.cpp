#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Developped\n";
}

Brain::Brain(const Brain& ori)
{
	type = ori.get_type();
	std::cout << "Duplicate Brain\n";
}

Brain&	Brain::operator=(const	Brain& ori)
{
	if (this == &ori)
		return *this;
	this->~Brain();
	new (this) Brain(ori);
	return *this;
}

Brain::~Brain()
{
	std::cout << "So Long!\n";
}