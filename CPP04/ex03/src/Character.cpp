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
	//need copy of bag in current state
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
	//need delete content of bag
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
	//equip given materia in first open slot
	//if no slot open, no action taken
	for (int i = 0; i < 4; i++)
	{
		if (!bag[i])
		{
			bag[i] = m;
			return;
		}
	}
	return;
}

void	Character::unequip(int idx)
{
	//unequip from selected slot, but not deleted
	if (idx >= 0 && idx <= 3 && bag[idx])
		bag[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && bag[idx])
		bag[idx]->use(target);
}