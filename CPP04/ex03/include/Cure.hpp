#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
	Cure();
	Cure(const Cure& ori);
	~Cure();
	Cure& operator=(const Cure& ori);

	Cure* clone() const;
	void use(ICharacter& target);
};

#endif