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

Character(const Character& ori)
{
	_name = ori.getName();
	//need copy of bag in current state
	//bag = 
}

Character::~Character()
{
	//need delete content of bag
}

std::string const & getName() const
{
	return (_name);
}

void	equip(AMateria* m)
{
	//equip given materia in first open slot
	//if no slot open, no action taken
}

void	unequip(int idx)
{
	//unequip from selected slot, but not deleted
}

void	use(int idx, ICharacter& target)
{
	//use materia use(target)
}