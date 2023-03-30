#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
	frag.attack("bob");
	frag.takeDamage(5);
	frag.beRepaired(10);
	frag.highFivesGuys();
	}
	{
	DiamondTrap gem("gem");
	gem.self_diagnostic();
	gem.takeDamage(5);
	gem.beRepaired(10);
	gem.attack("serge");
	gem.whoAmI();
	}
	{
	DiamondTrap quartz;
	quartz.self_diagnostic();
	quartz.takeDamage(5);
	quartz.beRepaired(10);
	quartz.attack("serge");
	quartz.whoAmI();
	}
}