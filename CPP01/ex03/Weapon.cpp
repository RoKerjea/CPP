/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:45:38 by rokerjea          #+#    #+#             */
/*   Updated: 2023/02/05 14:36:30 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon(std::string weapon_type)
{
	_type = weapon_type;
}

void	Weapon::setType(std::string type_to_set)
{
	_type = type_to_set;
}

std::string	const &Weapon::getType() const
{
	std::string	const &res_type = _type;
	return (res_type);
}