#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "noname";
	hit_point = 10;
	energy_points = 10;
	attack_dmg = 0;
	std::cout << "Building Claptrap " << name << " !" << "\n";
}

ClapTrap::ClapTrap(std::string name_to_set)
{
	name = name_to_set;
	hit_point = 10;
	energy_points = 10;
	attack_dmg = 0;
	std::cout << "Building Claptrap " << name << " !" << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& ori)
{
	name = ori.get_name();
	hit_point = ori.get_pv();
	energy_points = ori.get_energy();
	attack_dmg = ori.get_damage();
	std::cout << "Building Claptrap " << name << " !" << "\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& ori)
{
	this->~ClapTrap();
	if (this == &ori)
		return *this;
	new (this) ClapTrap(ori);
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << name << " died" << "\n";
}

void	ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " << name << " attacks "<< target << ", causing ";
	std::cout << attack_dmg << " points of damage!" << "\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	//need check if negatif
	hit_point -= amount;
	std::cout << "ClapTrap " << name << " takes "<< amount << " of damages, hp left = ";
	std::cout << hit_point << "\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
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
	energy_points--;
	//need check is > unsi int max
	hit_point += amount;
	std::cout << "ClapTrap " << name << " heal for "<< amount << " of damages, hp left = ";
	std::cout << hit_point << "\n";
}

std::string ClapTrap::get_name() const
{
	return (name);
}

int	ClapTrap::get_pv() const
{
	return (hit_point);
}

int	ClapTrap::get_energy() const
{
	return (energy_points);
}

int	ClapTrap::get_damage() const
{
	return (attack_dmg);
}