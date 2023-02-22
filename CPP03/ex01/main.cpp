#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap bob("bob");
	bob.attack("serge");
	bob.takeDamage(5);
	bob.beRepaired(2);

	ScavTrap clp("scav");
	clp.attack("bob");
	clp.takeDamage(5);
	clp.beRepaired(10);
	clp.guardGate();
}