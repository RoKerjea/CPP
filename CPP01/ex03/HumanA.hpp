/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <rokerjea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:53:04 by rokerjea          #+#    #+#             */
/*   Updated: 2023/02/05 14:27:57 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	private:
		std::string	_name;
		Weapon	&_weapon;
	public:
		void	attack();
		HumanA(std::string name, Weapon &weapon_to_set);
};

#endif