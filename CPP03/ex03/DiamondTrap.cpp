#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap("noname_clap_name"),
	FragTrap("noname"),
	ScavTrap("noname"),
	name("noname")
{
	std::cout << "Crystalizing " << name << " to DiamondTrap !" << "\n";
}

DiamondTrap::DiamondTrap(std::string name_to_set) :
	ClapTrap(name_to_set + "_clap_name"),
	FragTrap(name_to_set),
	ScavTrap(name_to_set),
	name(name_to_set)
{
	std::cout << "Crystalizing " << name << " to DiamondTrap !" << "\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap "<< name << " fractured!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& ori) : ClapTrap(ori)
{
	std::cout << "Copying DiamondTrap " << name << " !" << "\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& ori)
{
	if (this == &ori)
		return *this;
	this->~DiamondTrap();
	new (this) DiamondTrap(ori);
	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "HeLloO, I'm \"" << name << "\", AlsO KnoWN aS \"" << ClapTrap::name << "\"\n";
}

void	DiamondTrap::self_diagnostic()
{
	whoAmI();
	std::cout << "HP = " << hit_point << "\n";
	std::cout << "MP = " << energy_points << "\n";
	std::cout << "ATT = " << attack_dmg << "\n";
}