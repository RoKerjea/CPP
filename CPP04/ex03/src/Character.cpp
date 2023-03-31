#include "Character.hpp"

Character::Character()
{
	_name = "noname";
	for (int i = 0; i < 4; i++)
		bag[i] = NULL;
}

Character::Character(std::string name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
		bag[i] = NULL;
}

Character::Character(const Character& ori)
{
	_name = ori.getName();
	for (int i = 0; i < 4; i++)
	{
		if (ori.bag[i])
			bag[i] = ori.bag[i]->clone();
		else
			bag[i] = NULL;
	}
}

Character& Character::operator=(const Character& ori)
{
	if (this == &ori)
		return (*this);
	_name = ori.getName();
	for (int i = 0; i < 4; i++)
	{
		if (bag[i])
			delete bag[i];
		if (ori.bag[i])
			bag[i] = ori.bag[i]->clone();
		else
			bag[i] = NULL;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (bag[i])
			delete bag[i];
	}
}

std::string const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!bag[i] && m)
		{
			std::cout << _name << " equipped " << m->getType() << " in slot " << i << std::endl;
			bag[i] = m;
			return;
		}
	}
	std::cout << _name << " can't equip that\n";
	return;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && bag[idx])
	{
		std::cout << _name << " unequipped " << bag[idx]->getType() << " in slot " << idx << std::endl;
		bag[idx] = NULL;
	}
	else
		std::cout << _name << " can't unequip that\n";
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && bag[idx])
	{
		std::cout << _name;
		bag[idx]->use(target);
	}
	else
		std::cout << _name << " can't use that\n";
}