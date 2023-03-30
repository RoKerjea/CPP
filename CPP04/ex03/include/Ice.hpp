#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : virtual public AMateria
{
	Ice();
	Ice(const Ice& ori);
	~Ice();
	Ice& operator=(const Ice& ori);

	Ice* clone() const;
	void use(ICharacter& target);
};