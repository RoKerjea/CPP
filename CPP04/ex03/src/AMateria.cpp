#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	_type = type;
	//message?
}

AMateria::~AMateria()
{}

AMateria::AMateria(const AMateria& ori)
{
	_type = ori.getType();
}

AMateria::AMateria& operator=(const AMateria& ori)
{
	if (this == &ori)
		return (*this);
	this._type = ori.getType();
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (_type);
}