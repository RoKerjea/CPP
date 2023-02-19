#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap bob("bob");
	bob.attack("serge");
	bob.takeDamage(5);
	bob.beRepaired(2);
}