#include "DiamondTrap.hpp"

// DiamondTrap::DiamondTrap() : ClapTrap()
// {

// 	std::cout << "Crystalizing " << name << " into a DiamondTrap !" << "\n";
// }

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
	this->~DiamondTrap();
	if (this == &ori)
		return *this;
	new (this) DiamondTrap(ori);
	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	//
}