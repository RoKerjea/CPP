#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:

	std::string name;

	public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &ori);
	DiamondTrap&	operator=(const DiamondTrap &ori);
	~DiamondTrap();

	void	whoAmI();
	void	self_diagnostic();
	//"using" to define attack method to herit from Scavtrap
	using ScavTrap::attack;
};

#endif