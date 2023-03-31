#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		known_materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (known_materia[i])
			delete known_materia[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& ori)
{
	for (int i = 0; i < 4; i++)
	{
		if (ori.known_materia[i])
			known_materia[i] = ori.known_materia[i]->clone();
		else
			known_materia[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ori)
{
	if (this != &ori)
	{
		for (int i = 0; i < 4; i++)
		{
			if (known_materia[i])
				delete known_materia[i];
			if (ori.known_materia[i])
				known_materia[i] = ori.known_materia[i]->clone();
			else
				known_materia[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (known_materia[i] == NULL)
		{
			known_materia[i] = m;
			return;
		}
	}
	return;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (known_materia[i]->getType() == type)
			return (known_materia[i]->clone());
	}
	return 0;
}