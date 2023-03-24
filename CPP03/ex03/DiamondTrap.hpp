#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "Fragtrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:

	std::string name;
	// ClapTrap::name;

	public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &ori);
	DiamondTrap&	operator=(const DiamondTrap &ori);
	~DiamondTrap();

	void	whoAmI();
	//"using" to define attack method to herit from Scavtrap
};

#endif