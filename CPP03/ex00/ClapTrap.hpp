#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:

	std::string name;
	unsigned int	hit_point;
	unsigned int	energy_points;
	unsigned int	attack_dmg;

	public:

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name_to_set, unsigned int hp, unsigned int ep, unsigned int attack);
	ClapTrap(const ClapTrap &ori);
	ClapTrap&	operator=(const ClapTrap &ori);
	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	get_name(void) const;
	unsigned int	get_pv(void) const;
	unsigned int	get_energy(void) const;
	unsigned int	get_damage(void) const;
};

#endif