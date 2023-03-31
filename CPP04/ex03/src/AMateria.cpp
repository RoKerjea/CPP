#include "AMateria.hpp"

AMateria::AMateria()
{
	_type = "empty";
}

AMateria::AMateria(std::string const & type)
{
	_type = type;
}

AMateria::~AMateria()
{}

AMateria::AMateria(const AMateria& ori)
{
	_type = ori.getType();
}

AMateria& AMateria::operator=(const AMateria& ori)
{
	if (this != &ori)
		_type = ori.getType();
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void	AMateria::use (ICharacter& target) {

	std::cout << "*do ?? to" << target.getName () << " *" << std::endl;
}