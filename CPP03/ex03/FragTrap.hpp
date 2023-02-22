#ifndef FRAGTAP_HPP
# define FRAGTAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:

	FragTrap();
	FragTrap(std::string name_to_set);
	FragTrap(const FragTrap &ori);
	FragTrap&	operator=(const FragTrap &ori);
	~FragTrap();

	void	highFivesGuys(void);
};

#endif