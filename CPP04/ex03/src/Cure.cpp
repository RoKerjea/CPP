#include"Cure.hpp"

Cure::Cure() : AMateria("Cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& ori)
{
	_type = ori.getType();
}

Cure::Cure& operator=(const Cure& ori)
{
	if (this == &ori)
		return *this;
	this->_type = ori.getType();
	return *this;
}

Cure::Cure* clone()
{
	Cure*	res;
	res = new Cure();
	return (res);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}