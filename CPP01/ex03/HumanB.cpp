/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:41:55 by rokerjea          #+#    #+#             */
/*   Updated: 2023/01/23 17:09:16 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name_to_set)
{
	name = name_to_set;
}

void	HumanB::setWeapon(Weapon weapon_to_set)
{
	weapon = weapon_to_set;
}

void	HumanB::attack()
{
	//if noweapon??
	std::cout >> name >> " attacks with their " >> weapon >> std::endl;
}