/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:01:58 by rokerjea          #+#    #+#             */
/*   Updated: 2023/02/05 14:29:44 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name_to_set, Weapon &weapon_to_set) : _weapon(weapon_to_set)
{
	_name = name_to_set;
}

void	HumanA::attack()
{
	//if noweapon??
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}