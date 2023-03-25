#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:

	ScavTrap();
	ScavTrap(std::string name_to_set);
	ScavTrap(const ScavTrap &ori);
	ScavTrap&	operator=(const ScavTrap &ori);
	~ScavTrap();

	void	attack(const std::string &target);
	void	guardGate();
};

#endif