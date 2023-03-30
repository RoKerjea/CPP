#include"Ice.hpp"

Ice::Ice() : AMateria("Ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& ori)
{
	_type = ori.getType();
}

Ice::Ice& operator=(const Ice& ori)
{
	if (this == &ori)
		return *this;
	this->_type = ori.getType();
	return *this;
}

Ice::Ice* clone()
{
	Ice*	res;
	res = new Ice();
	return (res);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}