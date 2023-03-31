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
			std::cout << "MateriaSource learned " << m->getType() << " in slot " << i << std::endl;
			known_materia[i] = m;
			return;
		}
	}
	std::cout << "MateriaSource can't learn that\n";
	return;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (known_materia[i]->getType() == type)
		{
			std::cout << "MateriaSource created a " << type << " materia from slot " << i << std::endl;
			return (known_materia[i]->clone());
		}
	}
	std::cout << "MateriaSource can't create that\n";
	return 0;
}