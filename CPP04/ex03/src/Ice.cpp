#include"Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& ori)
{
	_type = ori.getType();
}

Ice& Ice::operator=(const Ice& ori)
{
	if (this != &ori)
		_type = ori.getType();
	return *this;
}

Ice* Ice::clone() const
{
	return new Ice();
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}