#include"Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure& ori)
{
	_type = ori.getType();
}

Cure& Cure::operator=(const Cure& ori)
{
	if (this != &ori)
		_type = ori.getType();
	return *this;
}

Cure* Cure::clone() const
{
	Cure*	res;
	res = new Cure();
	return (res);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}