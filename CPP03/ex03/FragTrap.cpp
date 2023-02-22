#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hit_point = 100;
	energy_points = 100;
	attack_dmg = 30;
	std::cout << "Overclocking " << name << " to FragTrap !" << "\n";
}

FragTrap::FragTrap(std::string name_to_set) : ClapTrap(name_to_set)
{
	hit_point = 100;
	energy_points = 100;
	attack_dmg = 30;
	std::cout << "Overclocking " << name << " to FragTrap !" << "\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< name << " out!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ori) : ClapTrap(ori)
{
	std::cout << "Copying FragTrap " << name << " !" << "\n";
}

// void	FragTrap::attack(const std::string& target)
// {
// 	if (hit_point <= 0)
// 	{
// 		std::cout << "No HP, can't move" << "\n";
// 		return ;
// 	}
// 	if (energy_points <= 0)
// 	{
// 		std::cout << "No energy, can't move" << "\n";
// 		return ;
// 	}
// 	energy_points --;
// 	std::cout << "FragTrap " << name << " is gonna frag "<< target << ", for ";
// 	std::cout << attack_dmg << " points of damage!" << "\n";
// }

void	FragTrap::highFivesGuys(void)
{
	if (hit_point <= 0)
	{
		std::cout << "No HP, can't move" << "\n";
		return ;
	}
	if (energy_points <= 0)
	{
		std::cout << "No energy, can't move" << "\n";
		return ;
	}
	energy_points --;
	std::cout << "Guys? Guys? ... Guys? Come on, Guys? Guys? ..." << std::endl;
}