#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("noname", 100, 50, 20)
{
	energy_points = 50;
	std::cout << "Upgrading " << name << " to ScavTrap !" << "\n";
}

ScavTrap::ScavTrap(std::string name_to_set) : ClapTrap(name_to_set, 100, 50, 20)
{
	energy_points = 50;
	std::cout << "Upgrading " << name << " to ScavTrap !" << "\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap "<< name << " downgraded!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ori) : ClapTrap(ori)
{
	std::cout << "Copying ScavTrap " << name << " !" << "\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& ori)
{
	this->~ScavTrap();
	if (this == &ori)
		return *this;
	new (this) ScavTrap(ori);
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hit_point == 0)
	{
		std::cout << "No HP, can't move" << "\n";
		return ;
	}
	if (energy_points == 0)
	{
		std::cout << "No energy, can't move" << "\n";
		return ;
	}
	energy_points --;
	std::cout << "ScavTrap " << name << " is gonna hurt "<< target << ", for ";
	std::cout << attack_dmg << " points of damage!" << "\n";
}

void	ScavTrap::guardGate()
{
	if (hit_point == 0)
	{
		std::cout << "No HP, can't move" << "\n";
		return ;
	}
	if (energy_points < 10)
	{
		std::cout << "Not enough energy, can't move" << "\n";
		return ;
	}
	energy_points -= 10;
	std::cout << "ScavTrap " << name << " entered Gate Keeper mode!";
	std::cout << " Energy left : " << energy_points << std::endl;
}