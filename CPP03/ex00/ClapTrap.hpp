#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
	std::string name;
	int	hit_point;
	int	energy_points;
	int	attack_dmg;

	public:

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &ori);
	ClapTrap&	operator=(const ClapTrap& ori);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	get_name(void) const;
	int	get_pv(void) const;
	int	get_energy(void) const;
	int	get_damage(void) const;
};

#endif