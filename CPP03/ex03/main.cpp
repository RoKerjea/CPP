#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	{
	ClapTrap bob("bob");
	bob.attack("serge");
	bob.takeDamage(5);
	bob.beRepaired(2);
	}
	{
	ScavTrap clp("scav");
	clp.attack("bob");
	clp.takeDamage(5);
	clp.beRepaired(10);
	clp.guardGate();
	}
	{
	FragTrap frag("Fragman");
	// frag.attack("bob");
	frag.takeDamage(5);
	frag.beRepaired(10);
	frag.highFivesGuys();
	}
}